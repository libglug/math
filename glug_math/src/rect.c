#include <glug/math/rect.h>
#include <glug/math/vec2.h>

void GLUG_LIB_API glug_rect_set(struct glug_rect *dst, const struct glug_vec2 *min, const struct glug_vec2 *max)
{
    glug_vec2_copy(&dst->min, min);
    glug_vec2_copy(&dst->max, max);
}

void GLUG_LIB_API glug_rect_copy(struct glug_rect *dst, const struct glug_rect *src)
{
    glug_rect_set(dst, &src->min, &src->max);
}

int GLUG_LIB_API glug_rect_equal(const struct glug_rect *a, const struct glug_rect *b)
{

}

int GLUG_LIB_API glug_rect_contains_point(const struct glug_rect *r, const struct glug_vec2 *p)
{
    return p->x <= r->max.x && p->y <= r->max.y && p->x >= r->min.x && p->y >= r->min.y;
}

struct glug_rect GLUG_LIB_API glug_rect_expansion(const struct glug_rect *r, const struct glug_vec2 *p)
{
    struct glug_rect dst = *r;
    glug_rect_expand_to(&dst, p);

    return dst;
}

void GLUG_LIB_API glug_rect_expand_to(struct glug_rect *dst, const struct glug_vec2 *p)
{
    glug_vec2_maximize(&dst->max, p);
    glug_vec2_minimize(&dst->min, p);
}

int GLUG_LIB_API glug_rect_intersects_rect(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_vec2 dmax = glug_vec2_diff(&a->max, &b->min);
    struct glug_vec2 dmin = glug_vec2_diff(&a->min, &b->max);

    return glug_vec2_dot(&dmax, &dmin) <= 0;
}

struct glug_rect GLUG_LIB_API glug_rect_intersection(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_rect dst = *a;
    glug_rect_intersect(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_rect_intersect(struct glug_rect *dst, const struct glug_rect *b)
{
    glug_vec2_minimize(&dst->max, &b->max);
    glug_vec2_maximize(&dst->min, &b->min);
}

struct glug_rect GLUG_LIB_API glug_rect_union(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_rect dst = *a;
    glug_rect_unionize(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_rect_unionize(struct glug_rect *dst, const struct glug_rect *b)
{
    glug_vec2_maximize(&dst->max, &b->max);
    glug_vec2_minimize(&dst->min, &b->min);
}

struct glug_vec2 GLUG_LIB_API glug_rect_clamped_point(const struct glug_rect *r, const struct glug_vec2 *p)
{
    struct glug_vec2 dst = *p;
    glug_rect_clamp_point(r, &dst);

    return dst;
}

void GLUG_LIB_API glug_rect_clamp_point(const struct glug_rect *r, struct glug_vec2 *dst)
{
    glug_vec2_minimize(dst, &r->max);
    glug_vec2_maximize(dst, &r->min);
}
