// MyMatricies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include "Matrix.h"

int ROW_COUNT = 3;
int COL_COUNT = 3;

int main()
{
	std::vector<std::vector<double>> v1{ {1, 0, 1}, { 0, 1, 1 }, { 1, 0, 1 } };
	std::vector<std::vector<double>> v2{ {1, 1, 1}, { 1, 1, 1 }, { 1, 1, 1 } };
	std::vector<std::vector<int>> v3{
		{0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0 } };;
	//add
	Matrix a = Matrix(v1);
	Matrix b = Matrix(v2);

	Matrix x = a + b;

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