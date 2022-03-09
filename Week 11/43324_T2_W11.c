#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void kruskal(int V, int cost[V][V])
{
    int parent[V];

    int find(int i)
    {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    void union1(int i, int j)
    {
        int a = find(i);
        int b = find(j);
        parent[a] = b;
    }

    void KruskalMST(int cost[V][V])
    {
        int mincost = 0;

        for (int i = 0; i < V; i++)
            parent[i] = i;

        int E = 0;
        printf("\nFollowing are the edges in the constructed MST\n");
        while (E < V - 1)
        {
            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (find(i) != find(j) && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            union1(a, b);
            printf("%d -- %d == %d \n",
                   a, b, min);
            E++;
            mincost += min;
        }
        printf("\nMinimum cost : %d", mincost);
    }

    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    KruskalMST(cost);

    getchar();
}

void prim(int V, int graph[V][V])
{
    int minKey(int key[], bool mstSet[])
    {

        int min = INT_MAX, min_index;

        int v;
        for (v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;

        return min_index;
    }

    int printMST(int parent[], int graph[V][V])
    {
        printf("\nFollowing are the edges in the constructed  MST\n");
        int i;
        for (i = 1; i < V; i++)
            printf("%d -- %d == %d \n", parent[i], i, graph[i][parent[i]]);
    }

    int parent[V];

    int key[V];

    bool mstSet[V];

    int i;
    for (i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    int count;
    for (count = 0; count < V - 1; count++)
    {

        int u = minKey(key, mstSet);

        mstSet[u] = true;

        int v;
        for (v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);

    getchar();
}

int main()
{
    int msize, baris, kolom;
    printf("Matrix size: ");
    scanf("%d", &msize);
    printf("Adjacency matrix: \n");
    baris = kolom = msize;
    int matrix[baris][kolom];
    for (baris = 0; baris < msize; baris++)
    {
        for (kolom = 0; kolom < msize; kolom++)
        {
            scanf("%d", &matrix[baris][kolom]);
        }
    }

    int input;
    do
    {
        system("cls");
        printf("1. Algoritma Kruskal\n");
        printf("2. Algoritma Prim\n");
        printf("3. Exit\n");
        printf("Input: ");
        scanf("%d", &input);
        fflush(stdin);

        if (input == 3)
            break;
        switch (input)
        {
        case 1:
            kruskal(msize, matrix);
            break;
        case 2:
            prim(msize, matrix);
            break;
        case 3:
            break;
        default:
            printf("\nInput salah!");
            getchar();
        }
    } while (input != 3);

    return 0;
}