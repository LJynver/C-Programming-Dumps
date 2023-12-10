#include <stdio.h>
#include <stdlib.h>
#include "v2.h"

void dijkstraAlgo(Matrix graph, int src)
{
    int resultPath[SIZE];
    Boolean isVisited[SIZE];

    int i, count, minV, v;
    
    for (i = 0; i < SIZE; ++i) {
        resultPath[i] = INF;
        isVisited[i] = FALSE;
    }

    resultPath[src] = 0;

    for (count = 0; count < SIZE - 1; count++) {

        minV = minDistance(resultPath, isVisited);
        isVisited[minV] = TRUE;

        for (v = 0; v < SIZE; ++v) {
            if (isVisited[v] == FALSE &&
                graph[minV][v] != INF &&
                resultPath[minV] != INF &&
                resultPath[minV] + graph[minV][v] < resultPath[v]) {
                    resultPath[v] = resultPath[minV] + graph[minV][v];
            }
        }

    }

    displayPath(resultPath);

}

int minDistance(int retPath[], Boolean isVisit[])
{
    int min, mindx, v;
    min = INF;

    for (v = 0; v < SIZE; v++) {
        if (isVisit[v] == FALSE && retPath[v] <= min) {
            min = retPath[v];
            mindx = v;
        }
    }

    return mindx;
}

void displayPath(int path[])
{
    printf("Vertex   Distance from Source\n");
    int i;
    for (i = 0; i < SIZE; i++) {
      printf("%d \t\t %d\n", i, path[i]);
    }
}