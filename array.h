typedef char * string;

typedef unsigned int unint;
typedef unsigned char unchar;

typedef struct node
{
	char *key;
	void *val;
	struct node *p_next;
	struct node *p_sub_next;
}NODE, *P_NODE;

typedef P_NODE Node;

/*
	可优化：
		增加一个结构体管理相同index生成的单链表。当前这样设计，添加相同index的元素需要寻找相同index的最后一个元素

		增加一个属性记录存在在nodes中的地址个数。当前这样设计会造成内存的浪费，因为扩容内存根据elem_num与size的差值。
*/
typedef struct table
{
	int size;
	int mask;
	int elem_num;
	P_NODE p_position;
	P_NODE p_top;
	P_NODE p_bottom;
	P_NODE *nodes;
}TABLE, *P_TABLE;

typedef P_TABLE Table;

Table table_create();

//插入元素
Node table_insert(Table, char *, void *);

//根据key查找元素
Node table_lookup(Table, char *);

/*
	遍历

	优化：
		增加一个形参，回调函数指针。这样在扩容的时候可用上
*/
void table_traverse(Table);

//检测是否需要扩容
char * resize_table_if_needed(Table);

//获取node个数
int table_count(Table);

//扩容
void resize_table(Table);

//创建node
Node node_create(char *key, void *val);

//下一个node
Node node_next(Node);

//当前node的key
char * node_key(Node);

//当前node的值
void * node_val(Node);

//是否为NULL
char * node_is_null(Node);
