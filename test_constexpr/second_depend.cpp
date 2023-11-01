#include "const_multiply.h"

void use_const_multiply()
{
	{
		constexpr auto a = std::array{2, 4, 6};
		constexpr auto b = std::array{1, 2, 3};
		constexpr auto c = multiply(a, b);

		static_assert(c[0] == 2);
		static_assert(c[1] == 8);
		static_assert(c[2] == 18);
	}
}