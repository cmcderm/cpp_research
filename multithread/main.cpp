#include <iostream>
#include <string>
#include <thread>
#include <array>
#include <vector>

void task(std::string something)
{
	std::cout << "Hello " << something << std::endl;
}

int main()
{
	std::thread task_world(task, "World!");

	std::cout << "Race condition! Who prints first??" << std::endl;

	task_world.join();

	std::cout << "Let's make a couple threads" << std::endl;

	std::array<std::string, 3> arr{"Bae", "Toffee", "Mocha"};

	std::vector<std::thread> tasks;

	for (std::size_t i = 0; i < arr.size(); ++i)
	{
		tasks.push_back(std::thread(task, arr[i]));
	}

	for (std::size_t i = 0; i < 3; ++i)
	{
		tasks[i].join();
	}

	return 0;
}