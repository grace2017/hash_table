#include <stdio.h>
#include <string.h>
#include "type.h"
#include "string.c"

void main()
{
	printf("111是不是整型：%d\n", is_int("111"));
	printf("a111是不是整型：%d\n", is_int("a111"));
	printf("111a是不是整型：%d\n", is_int("111a"));
}
