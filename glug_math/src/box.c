#include <glug/math/box.h>
#include <glug/math/vec3.h>

void glug_box_set(struct glug_box *dst, const struct glug_vec3 *min, const struct glug_vec3 *max)
{
    dst->min = *min;
    dst->max = *max;
}

glug_bool_t glug_box_equal(const struct glug_box *a, const struct glug_box *b)
{

}

glug_bool_t glug_box_is_empty(const struct glug_box *b)
{
    struct glug_vec3 dim = glug_vec3_diff(&b->max, &b->min);

    return dim.x < 0 || dim.y < 0 || dim.z < 0;
}

glug_bool_t glug_box_contains_point(const struct glug_box *b, const struct glug_vec3 *p)
{
    if (glug_box_is_empty(b)) return glug_false;

    return b->min.x <= p->x && p->x <= b->max.x &&
           b->min.y <= p->y && p->y <= b->max.y &&
           b->min.z <= p->z && p->z <= b->max.z;
}

struct glug_box glug_box_expansion(const struct glug_box *r, const struct glug_vec3 *p)
{
    struct glug_box dst = *r;
    glug_box_expand_to(&dst, p);

    return dst;
}

void glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_maximize(&dst->max, p);
    glug_vec3_minimize(&dst->min, p);
}

glug_bool_t glug_box_intersects_box(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_vec3 dmax, dmin;

    if (glug_box_is_empty(a) || glug_box_is_empty(b)) return glug_false;

    dmax = glug_vec3_diff(&a->max, &b->min);
    dmin = glug_vec3_diff(&a->min, &b->max);

    return glug_vec3_dot(&dmax, &dmin) <= 0;
}

struct glug_box glug_box_intersection(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_box dst = *a;
    glug_box_intersect(&dst, b);

    return dst;
}

void glug_box_intersect(struct glug_box *dst, const struct glug_box *b)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_minimize(&dst->max, &b->max);
    glug_vec3_maximize(&dst->min, &b->min);
}

struct glug_box glug_box_union(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_box dst = *a;
    glug_box_unionize(&dst, b);

    return dst;
}

void glug_box_unionize(struct glug_box *dst, const struct glug_box *b)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_maximize(&dst->max, &b->max);
    glug_vec3_minimize(&dst->min, &b->min);
}

struct glug_vec3 glug_box_clamped_point(const struct glug_box *b, const struct glug_vec3 *p)
{
    struct glug_vec3 dst = *p;
    glug_box_clamp_point(b, &dst);

    return dst;
}

void glug_box_clamp_point(const struct glug_box *b, struct glug_vec3 *dst)
{
    if (glug_box_is_empty(b)) return;

    glug_vec3_minimize(dst, &b->max);
    glug_vec3_maximize(dst, &b->min);
}
