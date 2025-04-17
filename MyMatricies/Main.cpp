// MyMatricies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"

void addition()
{
	std::vector<std::vector<double>> A{ {1, 0, 1}, { 0, 1, 1 }, { 1, 0, 0 } };
	std::vector<std::vector<double>> B{ {1, 1}, { 1, 1,1 }, { 1, 1 } };
	//add
	auto a = Matrix<double>(A);
	auto b = Matrix<double>(B);

	Matrix<double> x = a + b;

	std::cout << "X = A + B" << std::endl;

	std::cout << "A" << std::endl;
	for (auto&& i : a.getVector())
	{
		for (auto&& j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "B" << std::endl;
	for (auto&& i : b.getVector())
	{
		for (auto&& j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;


	std::cout << "X" << std::endl;
	for (auto&& i : x.getVector())
	{
		for (auto&& j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

int main()
{
	addition();
}