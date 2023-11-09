#include <iostream>
#include <array>
#include <thread>
#include <functional>

#include "threaded_mult.h"

typedef std::vector<int>::iterator vec_iter;

template <typename T>
ThreadedMath<T>::ThreadedMath(
		int num_threads,
		std::vector<T> *data)
{
	this->data = data;
	this->num_threads = num_threads > 0 ? num_threads : 4;
}

template <typename T>
void ThreadedMath<T>::add(int addend)
{
	this->thread([addend](T &b)
							 { b = addend + b; });
}

template <typename T>
void ThreadedMath<T>::multiply(int multiplier)
{
	this->thread([multiplier](T &b)
							 { b = multiplier * b; });
}

template <typename T>
const std::vector<T> *ThreadedMath<T>::get_data()
{
	return this->data;
}

void thread_task(
		std::function<void(int &)> operation,
		vec_iter start, vec_iter end)
{
	std::cout << "thread_task start" << std::endl;
	for (vec_iter m = start; m < end; ++m)
	{
		operation(*m);
	}
}

template <typename T>
void ThreadedMath<T>::thread(std::function<void(int &)> operation)
{
	std::vector<std::thread *> threads;

	int step_size = this->data->size() / num_threads;

	for (std::size_t i = 0; i < this->num_threads; ++i)
	{
		int start_i = i * step_size;
		int end_i = start_i + step_size;

		vec_iter start = this->data->begin() + start_i;
		vec_iter end = this->data->begin() + end_i;

		if (end + 1 == this->data->end())
		{
			++end;
		}

		printf("Starting task range: %d - %d\n", start_i, end_i);
		std::thread *task = new std::thread(thread_task, operation, start, end);

		threads.push_back(task);
	}

	for (std::size_t i = 0; i < threads.size(); ++i)
	{
		threads[i]->join();
	}
}

template class ThreadedMath<int>;