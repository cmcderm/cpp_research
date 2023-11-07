#include <iostream>
#include <string>
#include <thread>
#include <array>
#include <vector>
#include <random>

#include "threaded_mult.h"

void task(std::string something)
{
	std::cout << "Hello " << something << std::endl;
}

int main(int argc, char **argv)
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

	auto num_threads = 4;
	auto num_integers = 100;
	if (argc >= 2)
	{
		std::string n_input = argv[1];

		printf("input %d\n", n_input);

		int input_num;
		if (argc >= 3)
		{
			std::string threads_input = argv[1];
			try
			{
				input_num = std::stoi(threads_input);
			}
			catch (std::exception &e)
			{
				std::cout << "Error parsing number of threads, using default: " << num_threads << std::endl;
				num_integers = input_num;
			}
		}

		try
		{
			input_num = std::stoi(n_input);
		}
		catch (std::exception &e)
		{
			std::cout << "Error parsing number of integers, using default: " << num_threads << std::endl;
			num_threads = input_num;
		}
	}

	printf("Integers: %d Threads: %d\n", num_integers, num_threads);

	std::vector<int> data;
	for (std::size_t i = 0; i < num_integers; ++i)
	{
		data.push_back(rand());
	}

	ThreadedMath threaded(num_threads, &data);

	threaded.add(5);

	return 0;
}