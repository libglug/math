#include <glug/math/line.h>
#include <glug/math/float.h>
#include <glug/math/mat2.h>
#include <glug/math/vec3.h>

#include <math.h>
#include <float.h>

void glug_line_from_points(struct glug_line *dst, const struct glug_vec3 *p1, const struct glug_vec3 *p2)
{    
    struct glug_vec3 v;
    glug_vec3_sub(&v, p2, p1);
    *dst = (struct glug_line){
        .r0 = *p1,
        .v  = v,
    };
}

glug_bool_t glug_line_equal(const struct glug_line *a, const struct glug_line *b)
{

}

void glug_line_at_t(const struct glug_line *l, float t, struct glug_vec3 *dst)
{
    struct glug_vec3 p = l->v;
    glug_vec3_mul(&p, t);
    glug_vec3_add(&p, &l->r0);

    *dst = p;
}

float glug_line_distance_to(const struct glug_line *l1, const struct glug_line *l2)
{
    struct glug_vec3 p1, p2;
    glug_line_closest_points(l1, l2, &p1, &p2);

    return glug_vec3_dist(&p1, &p2);
}

void glug_line_closest_points(const struct glug_line *l1, const struct glug_line *l2, struct glug_vec3 *p1, struct glug_vec3 *p2)
{
    // d = |L2(t2) - L1(t1)|
    // v1 * d = v2 * d = 0 => v1(-v2t2) + v1t1 = v1(r02 - r01), v2(-v2t2) + (v1t1) = v2(r02-r01)
    // [v1^2 -v1v2] [t1] = [v1(r02-r01)]
    // [v1v2 -v2^2] [t2]   [v2(r02-r01)] --> t1, t2
    // p1 = L1(t1)
    // p2 = L2(t2)

    struct glug_mat2 v = {{
        { glug_vec3_dot(&l1->v, &l1->v), -glug_vec3_dot(&l1->v, &l2->v) },
        { glug_vec3_dot(&l1->v, &l2->v), -glug_vec3_dot(&l2->v, &l2->v) },
    }};

    float det = glug_mat2_determinant(&v);
    // lines are skew or intersect
    if (fabsf(det) > FLT_MIN)
    {
        v = (struct glug_mat2) {{
            {  v.els[1][1], -v.els[0][1] },
            { -v.els[1][0],  v.els[0][0] }
        }};
        glug_mat2_div(&v, det);

        struct glug_vec3 d;
        glug_vec3_sub(&d, &l2->r0, &l1->r0);

        struct glug_vec2 dr = {
            glug_vec3_dot(&d, &l1->v),
            glug_vec3_dot(&d, &l2->v),
        };
        glug_mat2_mulv(&v, &dr);

        struct glug_vec3 r1, r2;
        glug_line_at_t(l1, dr.x, &r1);
        glug_line_at_t(l2, dr.y, &r2);

        *p1 = r1;
        *p2 = r2;
        return;
    }

    // lines are parallel
    struct glug_vec3 r1on2 = l1->r0;
    glug_line_project_point(l2, &r1on2, &r1on2);

    *p1 = l1->r0;
    *p2 = r1on2;
}

float glug_line_distance_to_point(const struct glug_line *l, const struct glug_vec3 *p)
{
    struct glug_vec3 rej;
    glug_vec3_sub(&rej, p, &l->r0);
    glug_vec3_reject(&rej, &rej, &l->v);

    return glug_vec3_len(&rej);
}

void glug_line_project_point(const struct glug_line *l, struct glug_vec3 *dst, const struct glug_vec3 *p)
{
    struct glug_vec3 proj;
    glug_vec3_sub(&proj, p, &l->r0);
    glug_vec3_project(&proj, &proj, &l->v);
    glug_vec3_add(&proj, &l->r0);

    *dst = proj;
}
