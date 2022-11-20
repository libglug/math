#include "asserts.h"
#include <CUnit/Assert.h>

void ASSERT_BOX_EQUAL(struct glug_box *b1, struct glug_box *b2, float delta)
{
    ASSERT_VEC3_EQUAL(&b1->max, &b2->max, delta);
    ASSERT_VEC3_EQUAL(&b1->min, &b2->min, delta);
}

void ASSERT_LINE_EQUAL(struct glug_line *l1, struct glug_line *l2, float delta)
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


void ASSERT_SPHERE_EQUAL(struct glug_sphere *s1, struct glug_sphere *s2, float delta)
{
    ASSERT_VEC3_EQUAL(&s1->center, &s2->center, delta);
    CU_ASSERT_DOUBLE_EQUAL(s1->radius, s2->radius, delta);
}

void ASSERT_TRI_EQUAL(struct glug_triangle *t1, struct glug_triangle *t2, float delta)
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
