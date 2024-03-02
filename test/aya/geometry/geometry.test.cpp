import aya;

#include "gtest/gtest.h"
#include <type_traits>

using namespace aya::geometry;
using point = point2d<int>;

TEST(point2d, default_initialize) {
	point p;

	EXPECT_EQ(0, p.x);
	EXPECT_EQ(0, p.y);
}

TEST(point2d, is_copyable) {
	EXPECT_EQ(true, std::is_copy_constructible_v<point>);
	EXPECT_EQ(true, std::is_copy_assignable_v<point>);
}

TEST(point2d, is_moveable) {
	EXPECT_EQ(true, std::is_move_constructible_v<point>);
	EXPECT_EQ(true, std::is_move_assignable_v<point>);
}

TEST(point2d, initialize) {
	point p{2, 5};

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
}

TEST(point2d, operator_addeq_rhs) {
	point p{2, 5};

	auto& a = p += {4, 2};

	EXPECT_EQ(2 + 4, p.x);
	EXPECT_EQ(5 + 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_subeq_rhs) {
	point p{2, 5};

	auto& a = p -= {4, 2};

	EXPECT_EQ(2 - 4, p.x);
	EXPECT_EQ(5 - 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_muleq_rhs) {
	point p{2, 5};

	auto& a = p *= {4, 2};

	EXPECT_EQ(2 * 4, p.x);
	EXPECT_EQ(5 * 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_diveq_rhs) {
	point p{2, 5};

	auto& a = p /= {4, 2};

	EXPECT_EQ(2 / 4, p.x);
	EXPECT_EQ(5 / 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_addeq_scalar) {
	point p{2, 5};

	auto& a = p += 2;

	EXPECT_EQ(2 + 2, p.x);
	EXPECT_EQ(5 + 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_subeq_scalar) {
	point p{2, 5};

	auto& a = p -= 2;

	EXPECT_EQ(2 - 2, p.x);
	EXPECT_EQ(5 - 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_muleq_scalar) {
	point p{2, 5};

	auto& a = p *= 2;

	EXPECT_EQ(2 * 2, p.x);
	EXPECT_EQ(5 * 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_diveq_scalar) {
	point p{2, 5};

	auto& a = p /= 2;

	EXPECT_EQ(2 / 2, p.x);
	EXPECT_EQ(5 / 2, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_unary_preinc) {
	point p{2, 5};

	auto& a = ++p;

	EXPECT_EQ(2 + 1, p.x);
	EXPECT_EQ(5 + 1, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_unary_predec) {
	point p{2, 5};

	auto& a = --p;

	EXPECT_EQ(2 - 1, p.x);
	EXPECT_EQ(5 - 1, p.y);
	EXPECT_EQ(&p, &a);
}

TEST(point2d, operator_unary_postinc) {
	point p{2, 5};

	auto a = p++;

	EXPECT_EQ(2 + 1, p.x);
	EXPECT_EQ(5 + 1, p.y);
	EXPECT_EQ(2, a.x);
	EXPECT_EQ(5, a.y);
}

TEST(point2d, operator_unary_postdec) {
	point p{2, 5};

	auto a = p--;

	EXPECT_EQ(2 - 1, p.x);
	EXPECT_EQ(5 - 1, p.y);
	EXPECT_EQ(2, a.x);
	EXPECT_EQ(5, a.y);
}

TEST(point2d, operator_eq) {
	point p1{2, 5};
	point p2 = p1;

	auto a = p1 == p2;

	EXPECT_EQ(true, a);
}

TEST(point2d, operator_noteq) {
	point p1{2, 5};
	point p2 = p1;

	auto a = p1 != p2;

	EXPECT_EQ(false, a);
}

TEST(point2d, operator_add_rhs) {
	point p{2, 5};

	auto a = p + point{4, 2};

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 + 4, a.x);
	EXPECT_EQ(5 + 2, a.y);
}

TEST(point2d, operator_sub_rhs) {
	point p{2, 5};

	auto a = p - point{4, 2};

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 - 4, a.x);
	EXPECT_EQ(5 - 2, a.y);
}

TEST(point2d, operator_mul_rhs) {
	point p{2, 5};

	auto a = p * point{4, 2};

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 * 4, a.x);
	EXPECT_EQ(5 * 2, a.y);
}

TEST(point2d, operator_div_rhs) {
	point p{2, 5};

	auto a = p / point{4, 2};

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 / 4, a.x);
	EXPECT_EQ(5 / 2, a.y);
}

TEST(point2d, operator_add_prescalar) {
	point p{2, 5};

	auto a = 2 + p;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 + 2, a.x);
	EXPECT_EQ(5 + 2, a.y);
}

TEST(point2d, operator_mul_prescalar) {
	point p{2, 5};

	auto a = 2 * p;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 * 2, a.x);
	EXPECT_EQ(2 * 5, a.y);
}

TEST(point2d, operator_add_postscalar) {
	point p{2, 5};

	auto a = p + 2;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 + 2, a.x);
	EXPECT_EQ(5 + 2, a.y);
}

TEST(point2d, operator_sub_postscalar) {
	point p{2, 5};

	auto a = p - 2;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 - 2, a.x);
	EXPECT_EQ(5 - 2, a.y);
}

TEST(point2d, operator_mul_postscalar) {
	point p{2, 5};

	auto a = p * 2;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 * 2, a.x);
	EXPECT_EQ(5 * 2, a.y);
}

TEST(point2d, operator_div_postscalar) {
	point p{2, 5};

	auto a = p / 2;

	EXPECT_EQ(2, p.x);
	EXPECT_EQ(5, p.y);
	EXPECT_EQ(2 / 2, a.x);
	EXPECT_EQ(5 / 2, a.y);
}
