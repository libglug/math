#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/line3.h>
#include "add_test.h"
#include "asserts.h"

#include <float.h>

static void test_from_points(void)
{
    struct glug_vec3 a = { 0.f, 1.f, 2.f };
    struct glug_vec3 b = { 1.f, 3.f, 5.f };
    struct glug_line3 l = glug_line3_from_points(&a, &b);
    struct glug_line3 exp = { { 1.f, 2.f, 3.f }, { 0.f, 1.f, 2.f } };

    ASSERT_LINE3_EQUAL(&l, &exp, 0.f);
}

static void test_set_by_points(void)
{
    struct glug_vec3 a = { 0.f, 1.f, 2.f };
    struct glug_vec3 b = { 1.f, 3.f, 5.f };
    struct glug_line3 dst;
    glug_line3_set_by_points(&dst, &a, &b);
    struct glug_line3 exp = { { 1.f, 2.f, 3.f }, { 0.f, 1.f, 2.f } };

    ASSERT_LINE3_EQUAL(&dst, &exp, 0.f);
}

static void test_at_t(void)
{
    struct glug_line3 l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    float t = 0;
    struct glug_vec3 exp = { 0.f, 1.f, 1.f };

    struct glug_vec3 r = glug_line3_at_t(&l, t);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);

    t = -1.f;
    exp.x = -1.f;
    exp.y = -1.f;
    exp.z = 2.f;

    r = glug_line3_at_t(&l, t);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);

    t = 2.5f;
    exp.x = 2.5f;
    exp.y = 6.f;
    exp.z = -1.5f;

    r = glug_line3_at_t(&l, t);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);
}

static void test_distance(void)
{
    struct glug_line3 l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    float exp = 0.91287f;
    float dist = glug_line3_distance_to_point(&l, &p);

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.00001f);
}

static void test_closest_point(void)
{
    struct glug_line3 l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { 0.15214f, 1.30429f, 0.84785f };
    struct glug_vec3 r = glug_line3_closest_point(&l, &p);

    ASSERT_VEC3_EQUAL(&r, &exp, 0.00001f);
}

static void test_project_point(void)
{
    struct glug_line3 l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    struct glug_vec3 dst = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { 0.15214f, 1.30429f, 0.84785f };

    glug_line3_project_point(&l, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

CU_pSuite create_line3_suite()
{
    CU_pSuite line3_suite = CU_add_suite("line", NULL, NULL);
    if (!line3_suite) return NULL;

    ADD_TEST(line3_suite, from_points);
    ADD_TEST(line3_suite, set_by_points);
    ADD_TEST(line3_suite, at_t);
    ADD_TEST(line3_suite, distance);
    ADD_TEST(line3_suite, closest_point);
    ADD_TEST(line3_suite, project_point);

    return line3_suite;
}
