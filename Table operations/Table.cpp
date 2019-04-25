#include "Table.h"

Table::Table()
{
	name = DEFAULT_NAME;
	length = DEFAULT_LENGTH;
	values = new int[length];
	cout << DEFAULT_CONSTRUCTOR_TEXT << OPENING_BRACKET << name << CLOSING_BRACKET << endl;
}

Table::Table(string name, int length)
{
	this->name = name;
	this->length = length;
	values = new int[length];
	cout << PARAMETER_CONSTRUCTOR_TEXT << OPENING_BRACKET << name << CLOSING_BRACKET << endl;
}

Table::Table(Table & otherTable)
{
	name = otherTable.name + COPY_STATEMENT;
	length = otherTable.length;
	values = new int[length];
	cout << COPY_CONSTRUCTOR_TEXT << OPENING_BRACKET << name << CLOSING_BRACKET << endl;
	for (int i = 0; i < length; i++)
	{
		values[i] = otherTable.values[i];
	}
}


Table::~Table()
{
	cout << DESTRUCTOR_TEXT << OPENING_BRACKET << name << CLOSING_BRACKET << endl;
	delete[] values;
}


void Table::setSize(int newSize)
{
	if (newSize > 0)
	{
		int * pi_new_table = new int[newSize];
		for (int i = 0; i < newSize && i < length; i++)
		{
			pi_new_table[i] = values[i];
		}
		length = newSize;

		delete[] values;
		values = pi_new_table;

	}
	else
	{
		cout << WRONG_SIZE_ERROR << endl;
	}
}

void Table::setValueOfCell(int indexOfCell, int newValue)
{
	if (indexOfCell >= 0 && indexOfCell < length)
	{
		values[indexOfCell] = newValue;
	}
	else
	{
		cout << NO_SUCH_CELL_ERROR << endl;
	}
}

int Table::getValueOfCell(int indexOfCell)
{
	if (indexOfCell >= 0 && indexOfCell < length)
	{
		return values[indexOfCell];
	}
	else
	{
		cout << NO_SUCH_CELL_ERROR << endl;
	}
}


void Table::redefineTableValuesBasedOnOtherTable(Table & baseTable)
{
	length = baseTable.length;
	for (int i = 0; i < length; i++)
	{
		values[i] = baseTable.values[i];
	}

}

string Table::getInfoOfTable()
{
	string infoOfTable = string(OPENING_BRACKET + name + CLOSING_BRACKET + LEN_STATEMENT + OPENING_BRACKET + to_string(length) + CLOSING_BRACKET + VALUES_STATEMENT + OPENING_BRACKET);
	for (int i = 0; i < length; i++)
	{
		if (i == length - 1)
		{
			infoOfTable += string(to_string(values[i]) + CLOSING_BRACKET);
		}
		else
		{
			infoOfTable += string(to_string(values[i]) + COMMA);
		}
	}
	return infoOfTable;
}

void Table::setName(string name)
{
	this->name = name;
}

int Table::getMaxValueInTable()
{
	int maxValueInTable = values[0];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (values[i] > values[j])
			{
				maxValueInTable = values[i];
			}
		}
	}
	maxValue = maxValueInTable;
	return maxValue;
}