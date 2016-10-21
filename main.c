#include <stdio.h>
#include "array.c"

void main()
{
	Table table = table_create();

	table_insert(table, "a", "a");
	table_insert(table, "aa", "aa");
	table_insert(table, "b", "b");
	table_insert(table, "c", "c");

	table_traverse(table);
}
