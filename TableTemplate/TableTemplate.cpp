#include "Table.h"
#include <iostream>

int main()
{
	Table<int> table{ 10,10, 8 };
	Table<int> tableFloat(table);

	table.print();
	std::cout << "\n";
	tableFloat.print();
	std::cout << "\n";

	int numRows = table.getNumRows();
	int numCols = table.getNumCols();

	std::cout << "Num rows: " << numRows << "\n";
	std::cout << "Num cols: " << numCols << "\n";

	table(1, 2) = 15;

	int ind = table.linearSearch(15);

	std::cout << ind << "\n";

	table.print();
	return 0;
}