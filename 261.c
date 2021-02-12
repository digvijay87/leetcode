/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/

struct node{
	int vert;
	struct node* next;
};

struct garph{
	int n;
	struct node** adjlist;
	int *visited;
	int count;
};

struct graph* creategraph(int n)
{
	struct graph* g = (struct graph*)malloc(sizeof(sruct graph);

	g->n = n;
	
	g->visited = (int*)malloc(sizeof(int));

	g->count = n;

	g->adjlist = (struct node**)malloc(sizeof(struct node*)*n);

	for(int i = 0; i < n; i++)
	{
		g->visited[i] = 0;
		g->adjlist[i] = NULL;
	}
	
	return g;
}

struct node* addedge(int d)
{
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	
	nn->vert = d;
	nn->next = NULL;
	
	return nn;
}

void addedge(struct graph *g, int s, int d)
{
	struct node *nn = createnode(d);
	
	nn->next = g->adjlist[s];
	
	g->adjlist[s] = nn;

}

bool istree(struct graph *g, int src)
{
	struct node* connectedNode;
	struct node* temp;

	temp = g->adjlist[src];
	int dest;

	if(g->visited[src] == 1)
        {
            return false;
        }
        else{
            g->visited[src] = 1;
            count--;
	}

	while(temp != NULL)
	{
		dst = temp->vert;
		
		istree(g,dst);
		temp = temp->next; 
	}
	return true;
}

bool validTree(int n, int** edges, int edgesRow, int* edgesColSize){
    
	if(edgesRow != n-1) return false;
    
	//Create adjecency list//
	
	struct graph* g;
	g = creategraph(n);

	for(int i = 0; i < edgesRow; i++)
	{
		addedge(g,edges[i][0],edges[i][1]);
	}

	return istree(g,edges[0][0]) && g->count == 0;
}
		
