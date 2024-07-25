#include <stdio.h>
#include <stdlib.h>
#include "v1.h"

void dijkstraAlgo(Matrix graph, int src)
{
    int resultPath[SIZE];
    Boolean isVisited[SIZE];

    int i, count, minV, v;
    for (i = 0; i < SIZE; ++i) {
        resultPath[i] = (i == src) ? 0 : INF ;
        /**Path to node itself is 0, the rest is infinite. Assume the path is unknonwn**/

        isVisited[i] = (i == src) ? TRUE : FALSE;
        /**Contains Boolean set wherein each index indicates we have already visited the node. It is TRUE if visited, otherwise, mark it FALSE**/
    }

    for (count = 0; count < SIZE - 1; count++) {
        /**This refers to the remaining index to be visited**/
        /**Since the source vertex is no longer needed to be visited, you have SIZE-1 vertices to visit**/

        minV = minDistance(resultPath, isVisited);
        isVisited[minV] = TRUE;

        for (v = 0; v < SIZE; ++v) {
            if (!isVisited[v] &&
                graph[minV][v] != INF &&
                resultPath[minV] + graph[minV][v] < resultPath[minV]) {
                    resultPath[minV] = resultPath[minV] + graph[minV][v];
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