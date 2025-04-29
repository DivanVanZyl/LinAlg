#pragma once
#include<vector>
#include <limits>

template<typename T>
class Matrix
{
	std::vector<std::vector<T>> _m;
	int _rows;
	int _columns;

public:
	bool empty()
	{
		return _rows + _columns == 0;
	}

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

		//Build matrix based on input
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _columns; j++)
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

	//multiply (operator overloading)
	friend Matrix operator * (Matrix& a, Matrix& b)
	{
		if (canMultiply(a, b))
		{
			Matrix<T> newMatrix = std::vector<std::vector<T>>(a.rowCount(), std::vector<T>(b.colCount()));;
			for (int col = 0; col < newMatrix.colCount(); col++)
			{
				for (int row = 0; row < newMatrix.rowCount(); row++)
				{
					int bRow = 0;
					for (int aCol = 0; aCol < a.colCount(); aCol++)
					{
						newMatrix.setElement(row, col, newMatrix.getElement(row, col) + (a.getElement(row, aCol) * b.getElement(bRow, col)));
						bRow++;
					}
				}
			}
			return newMatrix;
		}
		else
		{
			return Matrix();
		}
	}

	//can X
	static bool canMultiply(Matrix a, Matrix b)
	{
		return a.colCount() == b.rowCount();
	}

	static bool canAdd(Matrix a, Matrix b)
	{
		return a.colCount() == b.colCount() and a.rowCount() == b.rowCount();
	}

	bool isRowEchelon()
	{
		//bool result = true;
		bool zeroAbove = false;
		int prevLeadingColumn = std::numeric_limits<int>::max();
		int prevLeadingRow = std::numeric_limits<int>::max();
		for (int c = 0; c < _columns; c++)
		{
			zeroAbove = false;
			for (int r = 0; r < _rows; r++)
			{
				if (_m[r][c] == 0 and zeroAbove == false)
				{
					zeroAbove = true;
					if (c > prevLeadingColumn and r < prevLeadingRow)
					{
						return false;
					}
					else
					{
						prevLeadingColumn = c;
						prevLeadingRow = r;
					}
				}
				else if (_m[r][c] != 0 and zeroAbove == true)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool isRowReducedEchelon();
};