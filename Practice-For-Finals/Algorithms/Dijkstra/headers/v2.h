#ifndef DIJKSTRA_V2
#define DIJKSTRA_V2

#define INF 0xFFFF
/**Sentinel value, an indication the vertex is not visited*/
#define SIZE 5

typedef enum {FALSE, TRUE} Boolean;
/**To determine if an index is visited**/

typedef int Matrix[SIZE][SIZE];
/** Matrix definition**/

void dijkstraAlgo(Matrix graph, int src);
/**Source is our origin vertex, where the path will come from**/

int minDistance(int retPath[], Boolean isVisit[]);
/**I don't know what is this lmao*/

void displayPath(int path[]);
/**displays the resulting shortest path**/

#endif