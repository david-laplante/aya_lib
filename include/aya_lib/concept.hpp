#pragma once
#include <type_traits>

namespace aya_lib::concepts {
	template <typename T>
	concept arithmetic = std::is_arithmetic_v<T>;
}
