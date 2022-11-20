#ifndef GLUG_ASSERTS_H
#define GLUG_ASSERTS_H

#include <glug/math/box_t.h>
#include <glug/math/line_t.h>
#include <glug/math/mat2_t.h>
#include <glug/math/plane_t.h>
#include <glug/math/sphere_t.h>
#include <glug/math/triangle_t.h>
#include <glug/math/vec2_t.h>
#include <glug/math/vec3_t.h>
#include <glug/math/vec4_t.h>

void ASSERT_BOX_EQUAL(struct glug_box *b1, struct glug_box *b2, float delta);
void ASSERT_LINE_EQUAL(struct glug_line *l1, struct glug_line *l2, float delta);
void ASSERT_MAT2_EQUAL(struct glug_mat2 *m1, struct glug_mat2 *m2, float delta);
void ASSERT_PLANE_EQUAL(struct glug_plane *p1, struct glug_plane *p2, float delta);
void ASSERT_SPHERE_EQUAL(struct glug_sphere *s1, struct glug_sphere *s2, float delta);
void ASSERT_TRI_EQUAL(struct glug_triangle *t1, struct glug_triangle *t2, float delta);
void ASSERT_VEC2_EQUAL(struct glug_vec2 *v1, struct glug_vec2 *v2, float delta);
void ASSERT_VEC3_EQUAL(struct glug_vec3 *v1, struct glug_vec3 *v2, float delta);
void ASSERT_VEC4_EQUAL(struct glug_vec4 *v1, struct glug_vec4 *v2, float delta);

#endif // GLUG_ASSERTS_H
