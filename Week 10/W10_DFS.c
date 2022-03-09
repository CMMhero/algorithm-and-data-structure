#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Edge {
	int dest;
	struct Edge *next;
} Edge;

void addEdge (Edge *adjlist[], int src, int dest) {
	Edge *temp;
	
	temp = (Edge*) malloc(sizeof(Edge)); 
	temp->dest = dest; 
	temp->next = NULL;
	
	if(adjlist[src] == NULL) {
		adjlist[src] = temp; 
	} else {
		Edge *ptr = adjlist[src]; 
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void DFS(int v, int visited[], Edge *adjlist[]) {
	int i, j;
	
	visited[v] = 1; 
	printf("%d ", v);
	
	Edge *it; 
	for(it = adjlist[v]; it!=NULL; it-it->next) { 
		if (!visited[it->dest])
			DFS(it->dest, visited, adjlist);
	}
}

int main() {
	int i; 
	int src, dest; 
	int start;
	
	int V; // Jumlah vertex dalam graph 
	// Inisialisasi graph 
	printf("Jumlah vertex = "); scanf("%d", &V); 
	Edge *adjList[V]; // Representasi Graph dengan Adjacency List
	
	for(i=0; i<V; i++) {
		adjList[i] = NULL;
	}
	
	i = 0;
	while(1) {
		printf("Adjacency List ke-%d\n", ++i); 
		printf("Source: "); scanf("%d", &src); 
		printf("Destination: "); scanf("%d", &dest); 
		printf("\n");
	
		if(src <= -1 || dest <= -1) break; 
		else {
			addEdge (adjList, src, dest); 
			addEdge (adjList, dest, src);
		}
	}
	
	// Inisialisasi nilai visited 
	int visited[V+2]; 
	for(i=0; i<V+2; i++) {
		visited[i] = 0;
	}
	
	//Mulai DFS
	printf("Starting node: "); scanf("%d", &start);
	DFS(start, visited, adjList);
	
	return 0;
}
