#include "UserInterface.h"


void UserInterface::runUserInterface()
{
	loadInterfaceOperationNumberFromUser();
	while (operationNumber != 10)
	{
		switch (operationNumber)
		{
		case 1:
			addTable();
			break;
		case 2:
			deleteTable();
			break;
		case 3:
			deleteAllTables();
			break;
		case 4:
			setTableLength();
			break;
		case 5:
			setTableName();
			break;
		case 6:
			setValueOfCell();
			break;
		case 7:
			redefineTableValuesBasedOnOtherTable();
			break;
		case 8:
			showInfoOfTable();
			break;
		case 9:
			showMaxValueInTable();
			break;
		}
		loadInterfaceOperationNumberFromUser();
	}
	deleteAllTables();
}

void UserInterface::addTable()
{
	loadAddingOperationFromUser();
	if (operationNumber == 1)
	{
		Table *table = new Table();
		tables.push_back(table);
		int tableIndex;
		for (int i = 0; i < tables.size(); i++)
		{
			if (tables.at(i) == table) tableIndex = i;
		}
		cout << ADDED_TABLE << endl;
		cout << INDEX_OF << tableIndex << endl;
	}
	if (operationNumber == 2)
	{
		int newTableLength;
		string newTableName;

		cout << ENTER_TABLE_NAME << endl;
		newTableName = getString();

		cout << ENTER_TABLE_LENGTH << endl;
		newTableLength = getInt();

		Table * table = new Table(newTableName, newTableLength);
		tables.push_back(table);
		cout << ADDED_TABLE << endl;
	}
	if (operationNumber == 3)
	{
		int tableIndex;
		cout << ENTER_INDEX_OF_TABLE << endl;
		tableIndex = getInt();

		if ((tableIndex > 0) && (tableIndex < tables.size()))
		{
			Table *table = new Table(*tables.at(tableIndex));
			tables.push_back(table);
			cout << ADDED_TABLE << endl;
		}
		else
		{
			cout << TABLE_NOT_ADDED_ERROR << endl;
		}
	}
}


void UserInterface::deleteTable()
{
	int tableIndex;
	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	if ((tableIndex > 0) && (tableIndex < tables.size()))
	{
		delete tables[tableIndex];
		tables.erase(tables.begin() + tableIndex);
		cout << DELETED_TABLE << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << TABLE_NOT_DELETED_ERROR << endl;
	}
}

void UserInterface::deleteAllTables()
{
	for (size_t i = 0; i < tables.size(); i++)
	{
		delete tables[i];
	}
	tables.clear();
	cout << DELETED_ALL_TABLES << endl;
}

void UserInterface::setTableLength()
{
	int tableIndex;
	int tableLength;
	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_TABLE_LENGTH << endl;
	tableLength = getInt();

	if ((tableIndex >= 0) && (tableIndex < tables.size()))
	{
		Table * table = tables.at(tableIndex);
		(*table).setSize(tableLength);
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << TABLE_LENGTH_NOT_CHANGED_ERROR << endl;
	}
}

void UserInterface::setTableName()
{
	int tableIndex;
	string newTableName;

	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_TABLE_NAME << endl;
	newTableName = getString();

	if ((tableIndex >= 0) && (tableIndex < tables.size()))
	{
		Table * table = tables.at(tableIndex);
		(*table).setName(newTableName);
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << TABLE_LENGTH_NOT_CHANGED_ERROR << endl;
	}
}

void UserInterface::setValueOfCell()
{
	int tableIndex;
	int indexOfCell;
	int newCellValue;

	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_INDEX_OF_CELL << endl;
	indexOfCell = getInt();

	cout << ENTER_CELL_VALUE << endl;
	newCellValue = getInt();

	if ((tableIndex >= 0) && (tableIndex < tables.size()))
	{
		Table *table = tables.at(tableIndex);
		(*table).setValueOfCell(indexOfCell, newCellValue);
		cout << CHANGED_CELL_VALUE << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << VALUE_NOT_CHANGED_ERROR << endl;
	}
}

void UserInterface::redefineTableValuesBasedOnOtherTable()
{
	int indexOfCopyFromTable;
	int indexOfCopyToTable;

	cout << ENTER_INDEX_OF_TABLE_TO_COPY << endl;
	indexOfCopyFromTable = getInt();

	cout << ENTER_INDEX_OF_TABLE_TO_REDEFINE << endl;
	indexOfCopyToTable = getInt();

	if ((indexOfCopyFromTable >= 0) && (indexOfCopyFromTable < tables.size()) && (indexOfCopyToTable > 0) && (indexOfCopyToTable < tables.size()))
	{
		Table *tableToCopyFrom = tables.at(indexOfCopyFromTable);
		Table *tableToCopyTo = tables.at(indexOfCopyToTable);
		(*tableToCopyTo).redefineTableValuesBasedOnOtherTable(*tableToCopyFrom);

	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << REDEFINING_ERROR << endl;
	}
}

void UserInterface::showInfoOfTable()
{
	cout << ENTER_INDEX_OF_TABLE << endl;
	int tableIndex = getInt();
	if ((tableIndex >= 0) && (tableIndex < tables.size()))
	{
		Table *table = tables.at(tableIndex);
		cout << (*table).getInfoOfTable() << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << endl;
	}
}

void UserInterface::showMaxValueInTable()
{
	int tableIndex;
	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();
	if ((tableIndex >= 0) && (tableIndex < tables.size()))
	{
		Table *table = tables.at(tableIndex);
		table = tables.at(tableIndex);
		getMaxValueInTable(table);
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << endl;
	}
}


void UserInterface::getMaxValueInTable(Table * table)
{
	cout << MAX << table->getMaxValueInTable();
}


void UserInterface::loadInterfaceOperationNumberFromUser()
{
	cout << ENTER_OPERATION_NUMBER << endl;
	cout << ALL_OPERATIONS << endl;
	operationNumber = getInt();
	while ((operationNumber > OPERATIONS_COUNT) || (operationNumber < 0))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << OPERATION_NOT_FOUND_ERROR << endl;
		cout << ALL_OPERATIONS << endl;
		operationNumber = getInt();
	}
	cin.clear();
	cin.ignore();
}

void UserInterface::loadAddingOperationFromUser()
{
	cout << ENTER_OPERATION_NUMBER << endl;
	cout << ADD_TABLES << endl;
	operationNumber = getInt();
	while ((operationNumber > ADDING_OPERATIONS_COUNT) || (operationNumber < 0))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << OPERATION_NOT_FOUND_ERROR << endl;
		cout << ADD_TABLES << endl;
		operationNumber = getInt();
	}
	cin.clear();
	cin.ignore();
}

int UserInterface::getInt()
{
	int integer;
	cin >> integer;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << ENTER_INTEGER << endl;
	}

	return integer;
}

string UserInterface::getString()
{
	string string;
	cin >> string;
	return string;
}