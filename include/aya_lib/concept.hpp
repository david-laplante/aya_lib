#pragma once
#include <type_traits>

namespace aya::concepts
{

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

}
