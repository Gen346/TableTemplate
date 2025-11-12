#pragma once
#ifndef TABLE_H
#define TABLE_H

template <typename T>
class Table
{
public: 
	Table();
	Table (int m, int n); // m - row ,n - column
	Table(int m, int n, const T& value);
	Table(const Table<T>& rhs); // Copy constructor
	~Table();

	Table<T> operator=(const Table& rhs);
	T& operator()(int m, int n);

	int numRows() const;
	int numCols() const;

	void resize(int m, int n);
	void resize(int m, int n, const T& value);

private:
	// Make private because this method should only be used 
	//internally by the class
	void destroy();
private:
	int mNumRows;
	int mNumCols;
	T** mDataMatrix;
};

template <typename T>
Table<T>::Table() : mNumRows(0), mNumCols(0), mDataMatrix(0)
{
}

template <typename T>
Table<T>::Table(int m, int n)
{
	mNumRows = 0;
	mNumCols = 0;
	mDataMatrix = 0;
	resize(m, n, T());
}

template <typename T>
Table<T>::Table(const Table& rhs)
{
	mNumRows = 0;
	mNumCols = 0;
	mDataMatrix = 0;
	*this = rhs;
}

#endif //TABLE_H
