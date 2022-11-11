#include <glug/math/rect.h>
#include <glug/math/vec2.h>

glug_bool_t glug_rect_equal(const struct glug_rect *r1, const struct glug_rect *r2)
{

}

glug_bool_t glug_rect_is_empty(const struct glug_rect *r)
{
    return (r->max.x < r->min.x) || (r->max.y < r->min.y);
}

glug_bool_t glug_rect_contains_point(const struct glug_rect *r, const struct glug_vec2 *p)
{
    if (glug_rect_is_empty(r)) return glug_false;

    return r->min.x <= p->x && p->x <= r->max.x &&
           r->min.y <= p->y && p->y <= r->max.y;
}

void glug_rect_expand_to(struct glug_rect *dst, const struct glug_vec2 *p)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_max(&dst->max, p);
    glug_vec2_min(&dst->min, p);
}

glug_bool_t glug_rect_intersects_rect(const struct glug_rect *r1, const struct glug_rect *r2)
{
    if (glug_rect_is_empty(r1) || glug_rect_is_empty(r2)) return glug_false;

    struct glug_vec2 dmax = r1->max, dmin = r1->min;
    glug_vec2_sub(&dmax, &r2->min);
    glug_vec2_sub(&dmin, &r2->max);

    return glug_vec2_dot(&dmax, &dmin) <= 0;
}

void glug_rect_intersect(struct glug_rect *dst, const struct glug_rect *r2)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_min(&dst->max, &r2->max);
    glug_vec2_max(&dst->min, &r2->min);
}

void glug_rect_union(struct glug_rect *dst, const struct glug_rect *r2)
{
    if (glug_rect_is_empty(dst)) return;

    glug_vec2_max(&dst->max, &r2->max);
    glug_vec2_min(&dst->min, &r2->min);
}

void glug_rect_clamp_point(const struct glug_rect *r, struct glug_vec2 *dst)
{
    if (glug_rect_is_empty(r)) return;

    glug_vec2_min(dst, &r->max);
    glug_vec2_max(dst, &r->min);
}
