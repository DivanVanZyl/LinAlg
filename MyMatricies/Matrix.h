#pragma once
#include<vector>
class Matrix
{
	std::vector<std::vector<double>> _m;
	int _rows;
	int _columns;

public:
	Matrix()
	{
		_m = { {} };
		_rows = 0;
		_columns = 0;
	}

	Matrix(std::vector<std::vector<double>> a)
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
	}

	int rowCount() { return _rows; }
	int colCount() { return _columns; }

	double setElement(int row, int col, double val)
	{
		return _m[row][col] = val;
	}

	double getElement(int row, int col)
	{
		return _m[row][col];
	}

	std::vector<std::vector<double>> getVector()
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
		return Matrix();
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