#pragma once
#include <aya_lib/concept.hpp>

namespace aya_lib::geometry {
	template<concepts::arithmetic T>
	struct point2d {
		T x{};
		T y{};

		constexpr point2d() noexcept = default;
		constexpr point2d(T const x, T const y) noexcept : x{x}, y{y} {}

		constexpr point2d& operator+=(point2d const rhs) noexcept { x += rhs.x; y += rhs.y; return *this; }
		constexpr point2d& operator-=(point2d const rhs) noexcept { x -= rhs.x; y -= rhs.y; return *this; }
		constexpr point2d& operator*=(point2d const rhs) noexcept { x *= rhs.x; y *= rhs.y; return *this; }
		constexpr point2d& operator/=(point2d const rhs) noexcept { x /= rhs.x; y /= rhs.y; return *this; }

		constexpr point2d& operator+=(T const scalar) noexcept { x += scalar; y += scalar; return *this; }
		constexpr point2d& operator-=(T const scalar) noexcept { x -= scalar; y -= scalar; return *this; }
		constexpr point2d& operator*=(T const scalar) noexcept { x *= scalar; y *= scalar; return *this; }
		constexpr point2d& operator/=(T const scalar) noexcept { x /= scalar; y /= scalar; return *this; }

		constexpr point2d& operator++() noexcept { ++x; ++y; return *this; }
		constexpr point2d& operator--() noexcept { --x; --y; return *this; }
		[[nodiscard]] constexpr point2d operator++(T) noexcept { point2d prev = *this; ++x; ++y; return prev; }
		[[nodiscard]] constexpr point2d operator--(T) noexcept { point2d prev = *this; --x; --y; return prev; }

		[[nodiscard]] constexpr friend bool operator==(point2d const lhs, point2d const rhs) noexcept { return lhs.x == rhs.x && lhs.y == rhs.y; }

		[[nodiscard]] constexpr friend point2d operator+(point2d const lhs, point2d const rhs) noexcept { return {lhs.x + rhs.x, lhs.y + rhs.y}; }
		[[nodiscard]] constexpr friend point2d operator-(point2d const lhs, point2d const rhs) noexcept { return {lhs.x - rhs.x, lhs.y - rhs.y}; }
		[[nodiscard]] constexpr friend point2d operator*(point2d const lhs, point2d const rhs) noexcept { return {lhs.x * rhs.x, lhs.y * rhs.y}; }
		[[nodiscard]] constexpr friend point2d operator/(point2d const lhs, point2d const rhs) noexcept { return {lhs.x / rhs.x, lhs.y / rhs.y}; }

		[[nodiscard]] constexpr friend point2d operator+(point2d const lhs, T const scalar) noexcept { return {lhs.x + scalar, lhs.y + scalar}; }
		[[nodiscard]] constexpr friend point2d operator-(point2d const lhs, T const scalar) noexcept { return {lhs.x - scalar, lhs.y - scalar}; }
		[[nodiscard]] constexpr friend point2d operator*(point2d const lhs, T const scalar) noexcept { return {lhs.x * scalar, lhs.y * scalar}; }
		[[nodiscard]] constexpr friend point2d operator/(point2d const lhs, T const scalar) noexcept { return {lhs.x / scalar, lhs.y / scalar}; }
		[[nodiscard]] constexpr friend point2d operator+(T const scalar, point2d const lhs) noexcept { return {scalar + lhs.x, scalar + lhs.y}; }
		[[nodiscard]] constexpr friend point2d operator*(T const scalar, point2d const lhs) noexcept { return {scalar * lhs.x, scalar * lhs.y}; }
	};
}
