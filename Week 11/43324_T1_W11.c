#include <stdio.h>
#include <string.h>
#include <malloc.h>

void dijkstra(int V, int graph[V][V], int src)
{
    int minDistance(int dist[], int sptSet[])
    {

        int min = INT_MAX, min_index;

        int v;
        for (v = 0; v < V; v++)
            if (sptSet[v] == 0 && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    void printSolution(int dist[], int source)
    {
        int i;
        for (i = 0; i < V; i++)
            printf("Untuk mencapai kota %c dari kota %c membutuhkan jarak terpendek %d\n", i + 97, source + 97, dist[i]);
    }

    int dist[V];

    int sptSet[V];

    int i;
    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    int count;
    for (count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        int v;
        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, src);
}

int charToint(char ichar)
{
    ichar -= 97;
    return ichar;
}

int main()
{
    int matrix[26][26];
    int baris, kolom;
    for (baris = 0; baris < 26; baris++)
    {
        for (kolom = 0; kolom < 26; kolom++)
        {
            matrix[baris][kolom] = 0;
        }
    }

    printf("[source]#[destination]#[weight]: \n");
    char source, destination;
    int weight;

    int isource, idestination;
    int size = INT_MIN;
    do
    {
        scanf("%c#%c#%d", &source, &destination, &weight);
        fflush(stdin);

        if (source == '-' || destination == '-')
            break;

        isource = charToint(source);
        idestination = charToint(destination);
        matrix[isource][idestination] = weight;
        if (isource > size)
            size = isource;
        if (idestination > size)
            size = idestination;
    } while (1);

    char source0;
    printf("\nSource: ");
    scanf("%c", &source0);
    int isource0 = charToint(source0);

    size += 1;
    int graph[size][size];
    for (baris = 0; baris < size; baris++)
    {
        for (kolom = 0; kolom < size; kolom++)
        {
            graph[baris][kolom] = matrix[baris][kolom];
        }
    }
    dijkstra(size, graph, isource0);

    return 0;
}
