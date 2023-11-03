#pragma once

#include <vector>
#include <functional>

template <typename T>
class ThreadedMath
{
private:
	int num_threads;
	std::vector<T> *data;

	void thread(std::function<void(int &)>);

public:
	ThreadedMath(int, std::vector<T> *);

	void add(int);
	void subtract(int);
	void multiply(int);
	const std::vector<T> *get_data();
};