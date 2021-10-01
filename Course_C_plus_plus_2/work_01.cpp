/*
#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Matrix {
public:
	Matrix() {
		rows = 0;
		columns = 0;
	}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int num_rows, int num_cols) {
			if (num_rows < 0 || num_cols < 0)
				throw out_of_range("");
			if (num_rows == 0 || num_cols == 0)
				num_rows = num_cols = 0;
			rows = num_rows;
			columns = num_cols;
			matrix.assign(rows, vector<int>(columns));
	}

	int At(int num_rows, int num_cols) const {
		return matrix.at(num_rows).at(num_cols);

	}

	int& At(int num_rows, int num_cols) {
		return matrix.at(num_rows).at(num_cols);
	}

	int GetNumRows() const {
		return rows;
	}

	int GetNumColumns() const {
		return columns;
	}

private:
	int rows, columns;
	vector<vector<int>> matrix;
};

istream& operator>>(istream& stream, Matrix& matrix) {
	int rows, columns;
	stream >> rows >> columns;

	matrix.Reset(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			stream >> matrix.At(i, j);
		}
	}
	return stream;
}
ostream& operator<<(ostream& stream, const Matrix& matrix) {
	int tmp, rows = matrix.GetNumRows(), columns = matrix.GetNumColumns();
	stream << rows << " " << columns << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			stream << matrix.At(i, j) << ' ';
		}
		stream << endl;
	}
	return stream;
}

bool operator==(const Matrix& larg, const Matrix& rarg) {
	if (larg.GetNumRows() != rarg.GetNumRows() || larg.GetNumColumns() != rarg.GetNumColumns()) {
		return false;
	}

	for (int row = 0; row < larg.GetNumRows(); row++) {
		for (int col = 0; col < larg.GetNumColumns(); col++) {
			if (larg.At(row, col) != rarg.At(row, col)) {
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(const Matrix& larg, const Matrix& rarg) {
		if (larg.GetNumRows() != rarg.GetNumRows() || larg.GetNumColumns() != rarg.GetNumColumns()) {
			throw invalid_argument("");
		}
		int tmp, rows = larg.GetNumRows(), columns = larg.GetNumColumns();
		Matrix sum(rows, columns);
		for (int i = 0; i < sum.GetNumRows(); i++)
		{
			for (int j = 0; j < sum.GetNumColumns(); j++)
			{
				sum.At(i, j) = larg.At(i, j) + rarg.At(i, j);
			}
		}
		return sum;

}
