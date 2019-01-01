#include <glug/math/box.h>
#include <glug/math/vec3.h>

void GLUG_LIB_API glug_box_set(struct glug_box *dst, const struct glug_vec3 *min, const struct glug_vec3 *max)
{
    glug_vec3_copy(&dst->min, min);
    glug_vec3_copy(&dst->max, max);
}

void GLUG_LIB_API glug_box_copy(struct glug_box *dst, const struct glug_box *src)
{
    glug_box_set(dst, &src->min, &src->max);
}

int GLUG_LIB_API glug_box_equal(const struct glug_box *a, const struct glug_box *b)
{

}

int GLUG_LIB_API glug_box_is_empty(const struct glug_box *b)
{
    struct glug_vec3 dim = glug_vec3_diff(&b->max, &b->min);

    return dim.x < 0 || dim.y < 0 || dim.z < 0;
}

int GLUG_LIB_API glug_box_contains_point(const struct glug_box *b, const struct glug_vec3 *p)
{
    return b->min.x <= p->x && p->x <= b->max.x &&
           b->min.y <= p->y && p->y <= b->max.y &&
           b->min.z <= p->z && p->z <= b->max.z;
}

struct glug_box GLUG_LIB_API glug_box_expansion(const struct glug_box *r, const struct glug_vec3 *p)
{
    struct glug_box dst = *r;
    glug_box_expand_to(&dst, p);

    return dst;
}

void GLUG_LIB_API glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p)
{
    glug_vec3_maximize(&dst->max, p);
    glug_vec3_minimize(&dst->min, p);
}

int GLUG_LIB_API glug_box_intersects_box(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_vec3 dmax = glug_vec3_diff(&a->max, &b->min);
    struct glug_vec3 dmin = glug_vec3_diff(&a->min, &b->max);

    return glug_vec3_dot(&dmax, &dmin) <= 0;
}

struct glug_box GLUG_LIB_API glug_box_intersection(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_box dst = *a;
    glug_box_intersect(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_box_intersect(struct glug_box *dst, const struct glug_box *b)
{
    glug_vec3_minimize(&dst->max, &b->max);
    glug_vec3_maximize(&dst->min, &b->min);
}

struct glug_box GLUG_LIB_API glug_box_union(const struct glug_box *a, const struct glug_box *b)
{
    struct glug_box dst = *a;
    glug_box_unionize(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_box_unionize(struct glug_box *dst, const struct glug_box *b)
{
    glug_vec3_maximize(&dst->max, &b->max);
    glug_vec3_minimize(&dst->min, &b->min);
}

struct glug_vec3 GLUG_LIB_API glug_box_clamped_point(const struct glug_box *b, const struct glug_vec3 *p)
{
    struct glug_vec3 dst = *p;
    glug_box_clamp_point(b, &dst);

    return dst;
}

void GLUG_LIB_API glug_box_clamp_point(const struct glug_box *b, struct glug_vec3 *dst)
{
    glug_vec3_minimize(dst, &b->max);
    glug_vec3_maximize(dst, &b->min);
}
