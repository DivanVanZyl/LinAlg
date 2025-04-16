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
		_rows = 0;
		_columns = 0;
		_m = a;
		for (auto&& i : a)
		{
			for (auto&& j : i)
			{
				_columns++;
			}
			_rows++;
		}
		_columns = _columns / _rows;
		std::cout << "This matrix has: " << _rows;
		std::cout << " rows and " << _columns << " columns.";
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

	//multiply


};