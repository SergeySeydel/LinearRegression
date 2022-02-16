#pragma once
#include <random>
template <typename T>
class RandomGenerator2
{
	std::random_device _rd;
	std::mt19937 _mt;
public:
	T generateInRange(T from, T to)
	{
		std::uniform_real_distribution<T> dist(from, to);
		return dist(_mt);
	}
	
};
template <>
class RandomGenerator2<int>
{
	std::random_device _rd;
	std::mt19937 _mt;
public:
	int generateInRange(int from, int to)
	{
		std::uniform_int_distribution<> dist(from, to);
		return dist(_mt);
	}

};
