#include <stdio.h>
#include "array.c"

void main()
{
	Table table = table_create();

	table_insert(table, "a", "a", "TYPE_INDEX");
	table_insert(table, "aa", "aa", "TYPE_INDEX");
	table_insert(table, "b", "b", "TYPE_INDEX");
//	table_insert(table, "c", "c", "TYPE_INDEX");
//	table_insert(table, "d", "d", "TYPE_INDEX");
//	table_insert(table, "yes", "yes", "TYPE_INDEX");
//	table_insert(table, "man", "man", "TYPE_INDEX");
//	table_insert(table, "100", "hello", "TYPE_INDEX");
	table_insert(table, "100", "hello", "TYPE_RELATE");

	table_traverse(table);
}
