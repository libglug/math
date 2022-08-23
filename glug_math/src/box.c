#include <glug/math/box.h>
#include <glug/math/vec3.h>

void glug_box_from_size(struct glug_box *dst, const struct glug_vec3 *c, const struct glug_vec3 *s)
{
    struct glug_vec3 s2 = *s;
    glug_vec3_mul(&s2, 0.5f);

    struct glug_vec3 max = *c, min;
    glug_vec3_add(&max, &s2);
    glug_vec3_sub(&min, c, &s2);

    *dst = (struct glug_box){
        .max = max,
        .min = min,
    };
}

glug_bool_t glug_box_equal(const struct glug_box *b1, const struct glug_box *b2)
{

}

glug_bool_t glug_box_is_empty(const struct glug_box *b)
{
    struct glug_vec3 dim;
    glug_vec3_sub(&dim, &b->max, &b->min);

    return dim.x < 0 || dim.y < 0 || dim.z < 0;
}

glug_bool_t glug_box_contains_point(const struct glug_box *b, const struct glug_vec3 *p)
{
    if (glug_box_is_empty(b)) return glug_false;

    return b->min.x <= p->x && p->x <= b->max.x &&
           b->min.y <= p->y && p->y <= b->max.y &&
           b->min.z <= p->z && p->z <= b->max.z;
}

void glug_box_clamp_point(const struct glug_box *b, struct glug_vec3 *dst)
{
    if (glug_box_is_empty(b)) return;

    glug_vec3_min(dst, &b->max);
    glug_vec3_max(dst, &b->min);
}

void glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_max(&dst->max, p);
    glug_vec3_min(&dst->min, p);
}

glug_bool_t glug_box_intersects_box(const struct glug_box *b1, const struct glug_box *b2)
{
    if (glug_box_is_empty(b1) || glug_box_is_empty(b2)) return glug_false;

    struct glug_vec3 dmax, dmin;
    glug_vec3_sub(&dmax, &b1->max, &b2->min);
    glug_vec3_sub(&dmin, &b1->min, &b2->max);

    return glug_vec3_dot(&dmax, &dmin) <= 0;
}

void glug_box_intersect(struct glug_box *dst, const struct glug_box *b2)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_min(&dst->max, &b2->max);
    glug_vec3_max(&dst->min, &b2->min);
}

void glug_box_union(struct glug_box *dst, const struct glug_box *b2)
{
    if (glug_box_is_empty(dst)) return;

    glug_vec3_max(&dst->max, &b2->max);
    glug_vec3_min(&dst->min, &b2->min);
}
