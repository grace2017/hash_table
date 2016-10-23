#define BOOL int
#define TRUE 1
#define FALSE 0

typedef char * string;

typedef unsigned int unint;
typedef unsigned char unchar;

typedef struct node
{
	void * key;
	string val;
	string type;
	struct node *p_next;
	struct node *p_sub_next;
}NODE, *P_NODE;

typedef P_NODE Node;

/*
	可优化：
		增加一个结构体管理相同index生成的单链表。当前这样设计，添加相同index的元素需要寻找相同index的最后一个元素
*/
typedef struct table
{
	int size;
	int mask;
	int all_elem_num;
	int valid_elem_num;
	int next_index; //类似mysql的自增字段
	P_NODE p_position;
	P_NODE p_top;
	P_NODE p_bottom;
	P_NODE *nodes;
}TABLE, *P_TABLE;

typedef P_TABLE Table;

Table table_create();

//插入元素
Node table_insert(Table, void *, string, string);

//根据key查找元素
Node table_lookup(Table, string);

/*
	遍历

	优化：
		增加一个形参，回调函数指针。这样在扩容的时候可用上
*/
void table_traverse(Table);

//检测是否需要扩容
BOOL resize_table_if_needed(Table);

//获取node个数
int table_count(Table);

//重置
void table_resize_next_index(Table);

//扩容
void resize_table(Table);

//创建node
Node node_create(void *, string, string);

//下一个node
Node node_next(Node);

//当前node的key
char * node_key(Node);

//当前node的值
void * node_val(Node);

//是否为NULL
char * node_is_null(Node);

BOOL in_basic_string_array(string *, string, unint);

//获取整数的长度
int get_int_length(unint);

//整型转为字符串
string int_to_string(int);
