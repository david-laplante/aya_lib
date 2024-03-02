module;
#include <aya_lib/geometry/geometry.hpp>

export module aya:geometry;

template<aya_lib::concepts::arithmetic T>
using impl = aya_lib::geometry::point2d<T>;

export namespace aya::geometry {
	template<aya_lib::concepts::arithmetic T>
	struct point2d : public impl<T> {
		constexpr point2d() noexcept : impl<T>() {};
		constexpr point2d(T const x, T const y) noexcept : impl<T>(x, y) {}
	};
}
