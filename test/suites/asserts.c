#include "asserts.h"
#include <CUnit/Assert.h>

void ASSERT_BOX_EQUAL(struct glug_box *b1, struct glug_box *b2, float delta)
{
    ASSERT_VEC3_EQUAL(&b1->min, &b2->min, delta);
    ASSERT_VEC3_EQUAL(&b1->max, &b2->max, delta);
}

void ASSERT_CIRC_EQUAL(struct glug_circle *c1, struct glug_circle *c2, float delta)
{
    ASSERT_VEC2_EQUAL(&c1->center, &c2->center, delta);
    CU_ASSERT_DOUBLE_EQUAL(c1->radius, c2->radius, delta);
}

void ASSERT_LINE2_EQUAL(struct glug_line2 *l1, struct glug_line2 *l2, float delta)
{
    ASSERT_VEC2_EQUAL(&l1->v, &l2->v, delta);
    ASSERT_VEC2_EQUAL(&l1->r0, &l2->r0, delta);
}

void ASSERT_LINE3_EQUAL(struct glug_line3 *l1, struct glug_line3 *l2, float delta)
{
    ASSERT_VEC3_EQUAL(&l1->v, &l2->v, delta);
    ASSERT_VEC3_EQUAL(&l1->r0, &l2->r0, delta);
}

void ASSERT_MAT2_EQUAL(struct glug_mat2 *m1, struct glug_mat2 *m2, float delta)
{
    CU_ASSERT_DOUBLE_EQUAL(m1->els[0][0], m2->els[0][0], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[0][1], m2->els[0][1], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[1][0], m2->els[1][0], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[1][1], m2->els[1][1], delta);
}

void ASSERT_PLANE_EQUAL(struct glug_plane *p1, struct glug_plane *p2, float delta)
{
    ASSERT_VEC3_EQUAL(&p1->normal, &p2->normal, delta);
    CU_ASSERT_DOUBLE_EQUAL(p1->offset, p2->offset, delta);
}

void ASSERT_RECT_EQUAL(struct glug_rect *r1, struct glug_rect *r2, float delta)
{
    ASSERT_VEC2_EQUAL(&r1->max, &r2->max, delta);
    ASSERT_VEC2_EQUAL(&r1->min, &r2->min, delta);
}

void ASSERT_SPHERE_EQUAL(struct glug_sphere *s1, struct glug_sphere *s2, float delta)
{
    ASSERT_VEC3_EQUAL(&s1->center, &s2->center, delta);
    CU_ASSERT_DOUBLE_EQUAL(s1->radius, s2->radius, delta);
}

void ASSERT_TRI2_EQUAL(struct glug_triangle2 *t1, struct glug_triangle2 *t2, float delta)
{
    ASSERT_VEC2_EQUAL(&t1->a, &t2->a, delta);
    ASSERT_VEC2_EQUAL(&t1->b, &t2->b, delta);
    ASSERT_VEC2_EQUAL(&t1->c, &t2->c, delta);
}

void ASSERT_TRI3_EQUAL(struct glug_triangle3 *t1, struct glug_triangle3 *t2, float delta)
{
    ASSERT_VEC3_EQUAL(&t1->a, &t2->a, delta);
    ASSERT_VEC3_EQUAL(&t1->b, &t2->b, delta);
    ASSERT_VEC3_EQUAL(&t1->c, &t2->c, delta);
}

void ASSERT_VEC2_EQUAL(struct glug_vec2 *v1, struct glug_vec2 *v2, float delta)
{
    CU_ASSERT_DOUBLE_EQUAL(v1->x, v2->x, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->y, v2->y, delta);
}

void ASSERT_VEC3_EQUAL(struct glug_vec3 *v1, struct glug_vec3 *v2, float delta)
{
    CU_ASSERT_DOUBLE_EQUAL(v1->x, v2->x, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->y, v2->y, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->z, v2->z, delta);
}

void ASSERT_VEC4_EQUAL(struct glug_vec4 *v1, struct glug_vec4 *v2, float delta)
{
    CU_ASSERT_DOUBLE_EQUAL(v1->x, v2->x, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->y, v2->y, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->z, v2->z, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->w, v2->w, delta);
}
