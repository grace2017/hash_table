#include <stdio.h>
#include "array.c"

void main()
{
	Table table = table_create();

	table_insert(table, "a", "a");
	table_insert(table, "aa", "aa");
	table_insert(table, "b", "b");
	table_insert(table, "c", "c");
	table_insert(table, "d", "d");
	table_insert(table, "yes", "yes");
	table_insert(table, "man", "man");
	table_insert(table, "100", "hello");

	table_traverse(table);
}
