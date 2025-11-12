#include "Table.h"

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

template<typename T>
void Table<T>::resize(int m, int n, const T& value)
{
	//destroy the previous data;
	destroy(); 

	// Save dimension
	mNumRows = m;
	mNumCols = n;

	// Allocate a row of pointers
	mDataMatrix = new T*[mNumRows];

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
T& Table<T>::operator()(int i, int j)
{
	return mDataMatrix[i][j];
}
