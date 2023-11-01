#include <cassert>

#include "const_multiply.h"
#include "second_depend.h"

int main(int argc, char **argv)
{
	{
		constexpr auto a = std::array{2, 4, 6};
		constexpr auto b = std::array{1, 2, 3};
		constexpr auto c = multiply(a, b);

		static_assert(c[0] == 2);
		static_assert(c[1] == 8);
		static_assert(c[2] == 18);
	}
	{
		auto a = std::array{2, 4, 6};
		auto b = std::array{1, 2, 3};
		auto c = multiply(a, b);

		assert(c[0] == 2);
		assert(c[1] == 8);
		assert(c[2] == 18);
	}
}