#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/circle.h>
#include "add_test.h"
#include "asserts.h"

static void test_set(void)
{
    struct glug_circle cir;
    float r = 1.74f;
    struct glug_vec2 c = { 7.77f, 9.12f };
    struct glug_circle exp = { c, r };

    glug_circle_set(&cir, &c, r);
    ASSERT_CIRC_EQUAL(&cir, &exp, 0.f);
}

static void test_contains_pt(void)
{
    struct glug_circle c = { { 0.f, 1.f }, 1.5f };
    struct glug_vec2 p = { 1.f, 1.f };
    int contains = glug_circle_contains_point(&c, &p);

    CU_ASSERT_TRUE(contains);

    p.y = -1.f;
    contains = glug_circle_contains_point(&c, &p);
    CU_ASSERT_FALSE(contains);
}

static void test_expansion(void)
{
    struct glug_circle c = { { 0.f, 0.f }, 0.f };
    struct glug_vec2 p = { 1.f, 1.f };
    struct glug_circle exp = { { 0.5f, 0.5f }, 0.7071f };

    struct glug_circle expanded = glug_circle_expansion(&c, &p);
    ASSERT_CIRC_EQUAL(&expanded, &exp, 0.0001f);

    c.center.x = exp.center.x = 0.5f;
    c.center.y = exp.center.y = 1.f;
    c.radius = exp.radius = 1.5f;
    expanded = glug_circle_expansion(&c, &p);
    ASSERT_CIRC_EQUAL(&expanded, &exp, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    exp.center.x = 2.f;
    exp.center.y = 1.f;
    exp.radius = 3.f;
    expanded = glug_circle_expansion(&c, &p);
    ASSERT_CIRC_EQUAL(&expanded, &exp, 0.f);
}

static void test_expand(void)
{
    struct glug_circle c = { { 0.f, 0.f }, 0.f };
    struct glug_vec2 p = { 1.f, 1.f };
    struct glug_circle exp = { { 0.5f, 0.5f }, 0.7071f };

    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.0001f);

    c.center.x = exp.center.x = 0.5f;
    c.center.y = exp.center.y = 1.f;
    c.radius = exp.radius = 1.5f;
    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    exp.center.x = 2.f;
    exp.center.y = 1.f;
    exp.radius = 3.f;
    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.f);

    c.center.x = c.center.y = 0.f;
    c.radius = 1.f;
    p.x = -2.f;
    p.y = 0.f;
    exp.center.x = -0.5f;
    exp.center.y = 0.f;
    exp.radius = 1.5f;
    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.f);
}

static void test_intersects(void)
{
    struct glug_circle c1 = { { 0.f, 1.f }, 2.5f };
    struct glug_circle c2 = { { -1.f, -2.f }, 0.5f };

    int intersect = glug_circle_intersects_circle(&c1, &c2);
    CU_ASSERT_FALSE(intersect);

    c2.radius = 0.67f;
    intersect = glug_circle_intersects_circle(&c1, &c2);
    CU_ASSERT_TRUE(intersect);
}

static void test_union(void)
{
    struct glug_circle c1 = { { 0.f, 0.f }, 0.5f };
    struct glug_circle c2 = { { 0.f, 0.f }, 1.f };
    struct glug_circle exp = { { 0.f, 0.f }, 1.f };

    // c1 fully encompassed by c2
    struct glug_circle dst = glug_circle_union(&c1, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.f);

    c1.center.x = -0.5f;
    c1.center.y = 1.f;
    c1.radius = 1.f;
    c2.center.x = 1.f;
    c2.center.y = 1.5f;
    exp.center.x = 1.9486f;
    exp.center.y = 1.8162f;
    exp.radius = 1.7905f;

    dst = glug_circle_union(&c1, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.0001f);
}

static void test_unionize(void)
{
    struct glug_circle dst = { { 0.f, 0.f }, 1.f };
    struct glug_circle c1 = { { 0.f, 0.f }, 0.5f };
    struct glug_circle c2 = { { 0.f, 0.f }, 1.f };
    struct glug_circle exp = { { 0.f, 0.f }, 1.f };

    // dst fully encompasses c1
    glug_circle_unionize(&dst, &c1);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.f);

    // dst fully encompassed by c2
    dst = c1;
    glug_circle_unionize(&dst, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.f);

    dst.center.x = -0.5f;
    dst.center.y = 1.f;
    c2.center.x = 1.f;
    c2.center.y = 1.5f;
    exp.center.x = 1.9486f;
    exp.center.y = 1.8162f;
    exp.radius = 1.7905f;

    glug_circle_unionize(&dst, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.0001f);
}

static void test_clamped(void)
{
    struct glug_circle c = { { 2.5f, 7.f }, 2.5f };
    struct glug_vec2 p = { 3.5f, 10.f };
    struct glug_vec2 exp = { 3.290f, 9.371f };

    struct glug_vec2 cp = glug_circle_clamped_point(&c, &p);
    ASSERT_VEC2_EQUAL(&cp, &exp, 0.001f);
}

static void test_clamp(void)
{
    struct glug_circle c = { { 2.5f, 7.f }, 2.5f };
    struct glug_vec2 p = { 3.5f, 10.f };
    struct glug_vec2 exp = { 3.290f, 9.371f };

    glug_circle_clamp_point(&c, &p);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.001f);
}

CU_pSuite create_circ_suite()
{
    CU_pSuite circ_suite = CU_add_suite("circle", NULL, NULL);
    if (!circ_suite) return NULL;

    ADD_TEST(circ_suite, set);
    ADD_TEST(circ_suite, contains_pt);
    ADD_TEST(circ_suite, expansion);
    ADD_TEST(circ_suite, expand);
    ADD_TEST(circ_suite, intersects);
    ADD_TEST(circ_suite, union);
    ADD_TEST(circ_suite, unionize);
    ADD_TEST(circ_suite, clamped);
    ADD_TEST(circ_suite, clamp);

    return circ_suite;
}
