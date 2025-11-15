#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <utility>

// Move implementation from .cpp into .h!!!
template <typename T>
class Table
{
public:
	Table();
	Table(int m, int n); // m - row ,n - column
	Table(int m, int n, const T& value);
	Table(const Table<T>& rhs); // Copy constructor
	~Table();

	Table<T>& operator=(const Table& rhs);
	const T& operator()(int m, int n) const;

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
//TODO
template <typename T>
Table<T>& Table<T>::operator=(const Table<T>& rhs)
{
	swap(*this, rhs&);

	return *this;
}

template <typename T>
const T& Table<T>::operator()(int i, int j) const
{
	return mData[index_2d_to_1d(i, j)];
}
//TODO
template <typename T>
void Table<T>::resize(int m, int n)
{
	resize(m, n, T());
}
//TODO
template<typename T>
void Table<T>::resize(int m, int n, const T& value)
{

	////destroy the previous data;
	//destroy();

	//// Save dimension
	//mNumRows = m;
	//mNumCols = n;

	//// Allocate a row of pointers
	//mDataMatrix = new T * [mNumRows];

	//// Now, loop through each pointer in this wor array
	//for (int i = 0; i < mNumRows; ++i)
	//{
	//	// And allocate a column(array) for the ith row to build the table
	//	mDataMatrix[i] = new T[mNumCols];

	//	// Now loop through each element in this row[i] and copy 'value' to it;
	//	for (int j = 0; j < mNumCols; ++j)
	//	{
	//		mDataMatrix[i][j] = value;
	//	}
	//}
}
//TODO
template <typename T>
int Table<T>::linearSearch(const T& searchItem) const
{
	for (int i = 0; i < mNumRows; ++i)
	{
		for (int j = 0; j < mNumCols; ++j)
		{
			if (dataArray[j] == searchItem)
			{
				return i * mNumCols + j;
			}
		}
	}
	return -1;
}
//TODO
template <typename T>
void Table<T>::print() const
{
	for (int i = 0; i < mNumRows; ++i)
	{
		for (int j = 0; j < mNumCols; ++j)
		{
			std::cout << mDataMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//template<typename T>
//void Table<T>::destroy()
//{
//	//Data matrix exist?
//	if (mDataMatrix)
//	{
//		//Itarate over each row i
//		for (int i = 0; i < mNumRows; ++i)
//		{
//			// Does the ith column array exist?
//			if (mDataMatrix[i])
//			{
//				//Yes, delete it
//				delete[]mDataMatrix[i];
//				mDataMatrix[i] = 0;
//			}
//		}
//		delete[] mDataMatrix;
//		mDataMatrix = 0;
//	}
//	mNumRows = 0;
//	mNumCols = 0;
//}

#endif //TABLE_H
