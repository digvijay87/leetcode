#include<stdio.h>


struct edges{
	int src;
	int dst;
};

struct graph{
	int v;
	int e;
	struct edges *edg;
};

int main()
{
	struct graph *g = initGraph(
