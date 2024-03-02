#pragma once
#include "../aya_lib.hpp"

namespace aya_lib::display {
	class window {
		public:
		AYA_LIB_API window() noexcept;
		AYA_LIB_API bool update() noexcept;
	};
}
