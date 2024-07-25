#include <stdio.h>
#include "headers/v3.h"
#include "headers/v3.c"

int main () {

    Matrix g1 = {
        {INF,10,INF,30,INF},
        {INF,INF,50,INF,INF},
        {20,INF,INF,INF,10},
        {INF,INF,20,INF,60},
        {INF,INF,INF,INF,INF},
    };

    dijkstraAlgo(g1, 0);
    /**Starting the Dijkstra with 0 as it's starting index**/

    return 0;
}