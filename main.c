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
	table_insert(table, "", "ont hundred and one", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and two", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and three", "TYPE_RELATE");

	table_resize_next_index(table);

	table_insert(table, "", "ont hundred and four", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and five", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");
	table_insert(table, "", "ont hundred and six", "TYPE_RELATE");

printf("size=%d, anum=%d, vnum=%d, next_index=%d\n", table->size, table->all_elem_num, table->valid_elem_num, table->next_index);
	table_traverse(table);
}
