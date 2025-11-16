#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Table
{
public:
	Table();
	Table(int m, int n); // m - row ,n - column
	Table(int m, int n, const T& value);
	//Copy constructor will be taken from std::vector
	~Table();

	Table<T>& operator=(Table<T> rhs);
	T& operator()(int m, int n); // read/write opeartions
	const T& operator()(int m, int n) const; // read only

	int getNumRows() const { return mNumRows; }
	int getNumCols() const { return mNumCols; }

	void resize(int m, int n);
	void resize(int m, int n, const T& value);

	int linearSearch(const T& searchItem) const;
	void print() const;

private:
	// Make private because this method should only be used 
	//internally by the class
	int index_2d_to_1d(int i, int j) const;
	friend void swap(Table<T>& first, Table<T>& second) noexcept;

private:
	int mNumRows;
	int mNumCols;
	std::vector<T> mData;
};

template <typename T>
int Table<T>::index_2d_to_1d(int i, int j) const
{
	// i - row, j - column
	return i * mNumCols + j;
}

template <typename T>
void swap(Table<T>& first, Table<T>& second) noexcept
{
	std::swap(first.mData, second.mData);

	std::swap(first.mNumRows, second.mNumRows);
	std::swap(first.mNumCols, second.mNumCols);
}

template <typename T>
Table<T>::Table() : mNumRows(0), mNumCols(0)
{
}

template <typename T>
Table<T>::Table(int m, int n) : mNumRows(m), mNumCols(n), mData(m * n)
{
}

template <typename T>
Table<T>::Table(int m, int n, const T& value) : mNumRows(m), mNumCols(n), mData(m * n, value)
{
	//mData calls vector constructor
	//std::vector<T>::vector(size_type count, const T& value);
}

template <typename T>
Table<T>::~Table()
{
}

template <typename T>
Table<T>& Table<T>::operator=(Table<T> rhs)
{
	std::swap(*this, rhs);

	return *this;
}

template <typename T>
T& Table<T>::operator()(int i, int j)
{
	return mData[index_2d_to_1d(i,j)];
}


template <typename T>
const T& Table<T>::operator()(int i, int j) const
{
	return mData[index_2d_to_1d(i, j)];
}

template <typename T>
void Table<T>::resize(int m, int n)
{
	mNumRows = m;
	mNumCols = n;

	mData.resize(m * n);
}

template<typename T>
void Table<T>::resize(int m, int n, const T& value)
{
	mNumRows = m;
	mNumCols = n;

	mData.resize(m * n, value);
}

template <typename T>
int Table<T>::linearSearch(const T& searchItem) const
{
	for (int i = 0; i < mNumRows; ++i)
	{
		for (int j = 0; j < mNumCols; ++j)
		{
			int index_1d = index_2d_to_1d(i, j);

			if (mData[index_1d] == searchItem)
			{
				return index_1d;
			}
		}
	}
	return -1;
}

template <typename T>
void Table<T>::print() const
{
	for (int i = 0; i < mNumRows; ++i)
	{
		for (int j = 0; j < mNumCols; ++j)
		{
			std::cout << mData [index_2d_to_1d(i, j)] << " ";
		}
		std::cout << "\n";
	}
}

#endif //TABLE_H
