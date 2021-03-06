#include <glug/math/rect.h>
#include <glug/math/vec2.h>

void glug_rect_set(struct glug_rect *dst, const struct glug_vec2 *min, const struct glug_vec2 *max)
{
    dst->min = *min;
    dst->max = *max;
}

glug_bool_t glug_rect_equal(const struct glug_rect *a, const struct glug_rect *b)
{

}

glug_bool_t glug_rect_is_empty(const struct glug_rect *r)
{
    struct glug_vec2 dim = glug_vec2_diff(&r->max, &r->min);

    return dim.x < 0 || dim.y < 0;
}

glug_bool_t glug_rect_contains_point(const struct glug_rect *r, const struct glug_vec2 *p)
{
    if (glug_rect_is_empty(r)) return glug_false;

    return r->min.x <= p->x && p->x <= r->max.x &&
           r->min.y <= p->y && p->y <= r->max.y;
}

struct glug_rect glug_rect_expansion(const struct glug_rect *r, const struct glug_vec2 *p)
{
    struct glug_rect dst = *r;
    glug_rect_expand_to(&dst, p);

    return dst;
}

void glug_rect_expand_to(struct glug_rect *dst, const struct glug_vec2 *p)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_maximize(&dst->max, p);
    glug_vec2_minimize(&dst->min, p);
}

glug_bool_t glug_rect_intersects_rect(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_vec2 dmax, dmin;

    if (glug_rect_is_empty(a) || glug_rect_is_empty(b)) return glug_false;

    dmax = glug_vec2_diff(&a->max, &b->min);
    dmin = glug_vec2_diff(&a->min, &b->max);

    return glug_vec2_dot(&dmax, &dmin) <= 0;
}

struct glug_rect glug_rect_intersection(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_rect dst = *a;
    glug_rect_intersect(&dst, b);

    return dst;
}

void glug_rect_intersect(struct glug_rect *dst, const struct glug_rect *b)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_minimize(&dst->max, &b->max);
    glug_vec2_maximize(&dst->min, &b->min);
}

struct glug_rect glug_rect_union(const struct glug_rect *a, const struct glug_rect *b)
{
    struct glug_rect dst = *a;
    glug_rect_unionize(&dst, b);

    return dst;
}

void glug_rect_unionize(struct glug_rect *dst, const struct glug_rect *b)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_maximize(&dst->max, &b->max);
    glug_vec2_minimize(&dst->min, &b->min);
}

struct glug_vec2 glug_rect_clamped_point(const struct glug_rect *r, const struct glug_vec2 *p)
{
    struct glug_vec2 dst = *p;
    glug_rect_clamp_point(r, &dst);

    return dst;
}

void glug_rect_clamp_point(const struct glug_rect *r, struct glug_vec2 *dst)
{
    if (glug_rect_is_empty(r)) return;

    glug_vec2_minimize(dst, &r->max);
    glug_vec2_maximize(dst, &r->min);
}
