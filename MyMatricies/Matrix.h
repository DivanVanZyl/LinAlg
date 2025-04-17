#pragma once
#include<vector>
template<typename T>
class Matrix
{
	std::vector<std::vector<T>> _m;
	int _rows;
	int _columns;

public:
	Matrix()
	{
		_m = { {} };
		_rows = 0;
		_columns = 0;
	}

	Matrix(std::vector<std::vector<T>> a)
	{
		//Determine max rows/columns
		int tmpCol = 0;
		for (auto&& i : a)
		{
			for (auto&& j : i)
			{
				tmpCol++;
			}
			if (tmpCol > _columns) { _columns = tmpCol; }
			tmpCol = 0;
			_rows++;
		}

		_m = std::vector < std::vector<T>>(_rows, std::vector<T>(_columns));

		//Build matrix based on input and max rows/columns
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0;j < _columns;j++)
			{
				if (j < a[i].size())
				{
					_m[i][j] = a[i][j];
				}
				else
				{
					_m[i][j] = 0;
				}
			}
		}
	}

	int rowCount() { return _rows; }
	int colCount() { return _columns; }

	T setElement(int row, int col, T val)
	{
		return _m[row][col] = val;
	}

	T getElement(int row, int col)
	{
		return _m[row][col];
	}

	std::vector<std::vector<T>> getVector()
	{
		return _m;
	}

	//add (operator overloading)
	friend Matrix operator + (Matrix& a, Matrix& b)
	{
		if (canAdd(a, b))
		{
			Matrix temp = a;
			for (int row = 0; row < b._rows; row++)
			{
				for (int col = 0; col < b._columns; col++)
				{
					temp.setElement(row, col, temp.getElement(row, col) + b.getElement(row, col));
				}
			}
			return temp;
		}
		else
		{
			return Matrix();
		}
	}

	//can multiply
	static bool canMultiply(Matrix a, Matrix b)
	{
		return a.colCount() == b.rowCount();
	}

	static bool canAdd(Matrix a, Matrix b)
	{
		return a.colCount() == b.colCount() and a.rowCount() == b.rowCount();
	}
};