#ifndef GLUG_ASSERTS_H
#define GLUG_ASSERTS_H

#include <glug/math/box_t.h>
#include <glug/math/circle_t.h>
#include <glug/math/line2_t.h>
#include <glug/math/line3_t.h>
#include <glug/math/mat2_t.h>
#include <glug/math/plane_t.h>
#include <glug/math/rect_t.h>
#include <glug/math/sphere_t.h>
#include <glug/math/triangle2_t.h>
#include <glug/math/triangle3_t.h>
#include <glug/math/vec2_t.h>
#include <glug/math/vec3_t.h>
#include <glug/math/vec4_t.h>

void ASSERT_BOX_EQUAL(struct glug_box *b1, struct glug_box *b2, float delta);
void ASSERT_CIRC_EQUAL(struct glug_circle *c1, struct glug_circle *c2, float delta);
void ASSERT_LINE2_EQUAL(struct glug_line2 *l1, struct glug_line2 *l2, float delta);
void ASSERT_LINE3_EQUAL(struct glug_line3 *l1, struct glug_line3 *l2, float delta);
void ASSERT_MAT2_EQUAL(struct glug_mat2 *m1, struct glug_mat2 *m2, float delta);
void ASSERT_PLANE_EQUAL(struct glug_plane *p1, struct glug_plane *p2, float delta);
void ASSERT_RECT_EQUAL(struct glug_rect *r1, struct glug_rect *r2, float delta);
void ASSERT_SPHERE_EQUAL(struct glug_sphere *s1, struct glug_sphere *s2, float delta);
void ASSERT_TRI2_EQUAL(struct glug_triangle2 *t1, struct glug_triangle2 *t2, float delta);
void ASSERT_TRI3_EQUAL(struct glug_triangle3 *t1, struct glug_triangle3 *t2, float delta);
void ASSERT_VEC2_EQUAL(struct glug_vec2 *v1, struct glug_vec2 *v2, float delta);
void ASSERT_VEC3_EQUAL(struct glug_vec3 *v1, struct glug_vec3 *v2, float delta);
void ASSERT_VEC4_EQUAL(struct glug_vec4 *v1, struct glug_vec4 *v2, float delta);

#endif // GLUG_ASSERTS_H
