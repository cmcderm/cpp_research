#include <iostream>
#include <array>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// O(n^2)
// Memory O(1), Swaps O(n * z) (z = number of zeroes)
// Outer loop traverses the whole array no matter what
// Inner loop traverses from the outer array's index to the next zero, and then bubbles it back until i is pointing to a 0
template<size_t N>
void moveZeroes(std::array<int, N>& nums) {
	for (auto i = nums.end() - 1; i != nums.begin(); --i) {
		if (*i != 0) {
			auto j = i - 1;
			while (*i != 0) {
				if (j == nums.begin() - 1) {
					return;
				}
				if (*j == 0) {
					swap(j, j+1);
					j++;
				} else {
					j--;
				}
			}
		}
	}
}

template<size_t N>
void printArray(const std::array<int, N>& nums) {
	std::cout << '[';
	for (size_t i = 0; i < N; ++i) {
		std::cout << nums[i];
		if (i != N-1) {
			std::cout << ", ";
		}
	}
	std::cout << ']' << std::endl;
}

int main (int argc, char** argv) {
	std::array<int, 5> arr1 = {0, 1, 0, 3, 12};
	std::array<int, 5> arr1_expected = {0, 1, 0, 3, 12};
	moveZeroes(arr1);
	printArray(arr1); // Expected output [1, 3, 12, 0, 0]

	std::array<int, 1> arr2 = {0};
	moveZeroes(arr2);
	printArray(arr2); // Expected output [0]

	// We could delete the zero and push_back a zero at the end, but std::vector::erase() is not magic, it's still O(n)
}