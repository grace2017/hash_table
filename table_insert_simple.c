#include <stdio.h>
#include "array.c"

void main()
{
	Table table = table_create();

	table_insert_simple(table, "name", "zhangyu");
}
