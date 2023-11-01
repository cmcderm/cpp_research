#include <array>

template <class T, std::size_t N>
constexpr std::array<T, N> multiply(
		const std::array<T, N> &a,
		const std::array<T, N> &b)
{
	std::array<T, N> ret{};
	for (std::size_t n = 0; n < N; ++n)
	{
		ret[n] = a[n] * b[n];
	}
	return ret;
}