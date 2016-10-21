#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "hash.c"
#include "array.h"

#define TABLE_DEFAULT_SIZE 8;

Table table_create()
{
	Table table = (Table)malloc(sizeof(TABLE));

	table->size = TABLE_DEFAULT_SIZE;
	table->mask = table->size - 1;
	table->all_elem_num = table->valid_elem_num = table->next_index = 0;
	table->p_top = table->p_bottom = table->p_position = NULL;
	
	table->nodes = (Node *)calloc(table->size, sizeof(Node));

	return table;
}

char * resize_table_if_needed(Table table)
{
	if(0 == (table->size - table->valid_elem_num)) {
		return "true";
	} else {
		return "false";
	}
}

void resize_table(Table table)
{
	int old_size = table->size;
	Node *old_nodes = table->nodes;
	Node old_node = table->p_top;

	table->size = table->size * 2;
	table->all_elem_num = table->valid_elem_num = 0;
	table->p_top = table->p_bottom = table->p_position = NULL;

	table->nodes = (Node *)calloc(table->size, sizeof(Node));

        while(NULL != old_node) {
		table_insert(table, old_node->key, old_node->val, old_node->type);

                Node sub_node = old_node->p_sub_next;
                while(NULL != sub_node) {
                       table_insert(table, sub_node->key, sub_node->val, sub_node->type); 

                        sub_node = sub_node->p_sub_next;
                }

                old_node = old_node->p_next;
        }
}

Node table_insert(Table table, string key, string val, string type)
{
	string allow_type[2] = {"TYPE_RELATE", "TYPE_INDEX"};
	if(FALSE == in_basic_string_array(allow_type, type, 2)) {
		printf("不允许的type：%s\n", type);
		
		exit(-1);
	}

	if("true" == resize_table_if_needed(table)) {
		resize_table(table);
	}

	int index = 0;

	if("TYPE_RELATE" == type) {
		if(0 == strlen(key)) {
			index = table->next_index;
		} else {
			index = atoi(key);
		}
	}

	if("TYPE_INDEX" == type) {
		index = time33(key, 1);
		index = table->mask & index;
	}

	Node new_node = node_create(key, val, type);
	
	Node tmp_node = table->nodes[index];
	if(NULL == tmp_node) {
		if(0 == table->all_elem_num) {		
			table->nodes[index] = new_node;

			table->p_top = table->p_bottom = table->p_position = new_node;	
		} else {
			table->nodes[index] = new_node;

			new_node->p_next = table->p_top;
			new_node->p_sub_next = NULL;			

			table->p_top = table->p_bottom = new_node;
		}

		table->all_elem_num++;
		table->valid_elem_num++;
	} else {
		for(;;) {
			if(NULL == tmp_node->p_sub_next) {
				tmp_node->p_sub_next = new_node;
			
				break;
			} else {
				tmp_node = tmp_node->p_sub_next;		
			}
		}

		table->all_elem_num++;
	}
	
	return new_node;
}

void table_traverse(Table table)
{
	Node current_node = table->p_top;
	while(NULL != current_node) {
		printf("父节点：key=%s, val=%s\n", current_node->key, current_node->val);

		//打印相同index的元素
		Node sub_node = current_node->p_sub_next;
		while(NULL != sub_node) {
			printf("子节点：key=%s, val=%s\n", sub_node->key, sub_node->val);

			sub_node = sub_node->p_sub_next;
		}
		
		current_node = current_node->p_next;
	}
}

int table_count(Table table)
{
	return table->all_elem_num;
}

Node node_create(string key, string val, string type)
{
	Node node = (Node)malloc(sizeof(NODE));

	node->key = key;
	node->val = val;
	node->type = type;

	node->p_next = node->p_sub_next = NULL;

	return node;
}

BOOL in_basic_string_array(string *array, string val, unint elem_num)
{
	if(elem_num > 0) {
		int key;

		for(key=0; key<=elem_num; key++) {
			if(key == elem_num) {
				return FALSE;
			} else {
				if(0 == strcmp(val, array[key])) {
                         	       return TRUE;
                        	}
			}
		}
	} else {
		return FALSE;
	}
}
