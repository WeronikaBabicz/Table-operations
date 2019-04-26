#pragma once
#include "Table.h"
#include <vector>
const string MAX = " MAX : ";
const string ALL_OPERATIONS = "\n(1) Create table\n(2) Delete table\n(3) Delete all tables\n(4) Set length of a table\n(5) Set name of a table\n(6) Set value of a cell\n(7) Copy values and length of a table to a different table\n(8) Show info of table\n(9) Get max element of a table\n(10) Exit";
const string ADD_TABLES = "\n(1) Default\n(2) Custom\n(3) Copy";
const string INDEX_OF = "Index of added table: ";


const string ENTER_INTEGER = "Enter integer! ";
const string ENTER_TABLE_NAME = "Enter table name: ";
const string ENTER_TABLE_LENGTH = "Enter table length: ";
const string ENTER_INDEX_OF_TABLE = "Enter index of table: ";
const string ENTER_INDEX_OF_CELL = "Enter index of cell: ";
const string ENTER_CELL_VALUE = "Enter cell value: ";
const string ENTER_INDEX_OF_TABLE_TO_COPY = "Enter index of table to copy: ";
const string ENTER_INDEX_OF_TABLE_TO_REDEFINE = "Enter index of table to redefine: ";

const string ADDED_TABLE = "Table added!";
const string DELETED_TABLE = "Table deleted!";
const string DELETED_ALL_TABLES = "All table deleted!";
const string REDEFINED_TABLE = "Table redefined!";
const string SET_TABLE_LENGTH = "Table's length changed!";
const string SET_TABLE_NAME = "Table's name changed!";
const string CHANGED_CELL_VALUE = "Cell's value changed!";

const string OPERATION_NOT_FOUND_ERROR = "Operation not found!!! ";
const string TABLE_NOT_FOUND_ERROR = "Table not found!!! ";
const string TABLE_NOT_ADDED_ERROR = "Table not added!!! ";
const string TABLE_NOT_DELETED_ERROR = "Table not deleted!!! ";
const string REDEFINING_ERROR = "Table not redefined!!! ";
const string TABLE_LENGTH_NOT_CHANGED_ERROR = "Table's length not changed!!! ";
const string TABLE_NAME_NOT_CHANGED = "Table's name not changed!!! ";
const string VALUE_NOT_CHANGED_ERROR = "Cell's value not changed!!! ";

const int OPERATIONS_COUNT = 10;

class UserInterface
{
public:
	void runUserInterface();
	void loadOperationNumberFromUser();

	void addTable();
	void deleteTable();
	void deleteAllTables();
	void setTableLength();
	void setTableName();
	void setValueOfCell();
	void redefineTableValuesBasedOnOtherTable();
	void showInfoOfTable();
	void showMaxValueInTable();
	void getMaxValueInTable(Table *table);

private:
	int operationNumber;
	vector<Table*> tables;

	int getInt();
	string getString();

};
