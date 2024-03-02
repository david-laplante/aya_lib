module;
#include "../include/aya_lib/display/window.hpp"

export module aya:display;

using impl = aya_lib::display::window;

export namespace aya::display {
	class window : public impl {
		public:
		window() noexcept : impl() {}
	};
}
