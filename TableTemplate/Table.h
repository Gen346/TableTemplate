#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>

// Move implementation from .cpp into .h!!!
template <typename T>
class Table
{
public: 
	Table();
	Table (int m, int n); // m - row ,n - column
	Table(int m, int n, const T& value);
	Table(const Table<T>& rhs); // Copy constructor
	~Table();

	Table<T>& operator=(const Table& rhs);
	T& operator()(int m, int n);

	int getNumRows() const;
	int getNumCols() const;

	void resize(int m, int n);
	void resize(int m, int n, const T& value);

	int linearSearch(T dataArray[], int arraySize, T searchItems);
	void print(T data[], int arraySize);

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
Table<T>::Table(int m, int n) : mNumRows(0), mNumCols(0), mDataMatrix(0)
{
	resize(m, n, T());
}

template <typename T>
Table<T>::Table(int m, int n, const T& value) : mNumRows(0), mNumCols(0), mDataMatrix(0)
{
	resize(m, n, value);
}

template <typename T>
Table<T>::Table(const Table& rhs) : mNumRows(0), mNumCols(0), mDataMatrix(0)
{
	*this = rhs;
}

template <typename T>
Table<T>::~Table()
{
	// Destroy the previous
	destroy();
}

template <typename T>
int Table<T>::getNumRows() const
{
	return mNumRows;
}

template <typename T>
int Table<T>::getNumCols() const
{
	return mNumCols;
}

template <typename T>
Table<T>& Table<T>::operator=(const Table<T>& rhs)
{
	// Check for self assigment
	if (this == &rhs)
	{
		return *this;
	}
	// Reallocate the table based on rhs info
	resize(rhs.mNumRows, rhs.mNumCols);

	// Copy the entries over element-by-element
	for (int i = 0; i < mNumRows; ++i)
	{
		for (int j = 0; j < mNumCols; ++j)
		{
			mDataMatrix[i][j] = rhs.mDataMatrix[i][j];
		}
	}
	// return a reference to *this so we can do chain
	// assignments: x = y = z = w = ...
	return *this;
}

template <typename T>
T& Table<T>::operator()(int i, int j)
{
	return mDataMatrix[i][j];
}

template <typename T>
void Table<T>::resize(int m, int n)
{
	resize(m, n, T());
}

template<typename T>
void Table<T>::resize(int m, int n, const T& value)
{
	//destroy the previous data;
	destroy();

	// Save dimension
	mNumRows = m;
	mNumCols = n;

	// Allocate a row of pointers
	mDataMatrix = new T * [mNumRows];

	// Now, loop through each pointer in this wor array
	for (int i = 0; i < mNumRows; ++i)
	{
		// And allocate a column(array) for the ith row to build the table
		mDataMatrix[i] = new T[mNumCols];

		// Now loop through each element in this row[i] and copy 'value' to it;
		for (int j = 0; j < mNumCols; ++j)
		{
			mDataMatrix[i][j] = value;
		}
	}
}

template <typename T>
int linearSearch(T dataArray[], int numRows, int numCols, T searchItem)
{
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numCols; ++j)
		{
			if (dataArray[j] == searchItem)
			{
				return i * numRows + numCols;
			}
		}
	}
	return -1;
}

template <typename T>
void print(T data[], int numRows, int numCols)
{
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numCols; ++j)
		{
			std::cout << data[i][j] << std::endl;
		}
	}
}

template<typename T>
void Table<T>::destroy()
{
	//Data matrix exist?
	if (mDataMatrix)
	{
		//Itarate over each row i
		for (int i = 0; i < mNumRows; ++i)
		{
			// Does the ith column array exist?
			if (mDataMatrix[i])
			{
				//Yes, delete it
				delete[]mDataMatrix[i];
				mDataMatrix[i] = 0;
			}
		}
		delete[] mDataMatrix;
		mDataMatrix = 0;
	}
	mNumRows = 0;
	mNumCols = 0;
}

#endif //TABLE_H
