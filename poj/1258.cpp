#include <cstdio>

#define INF 100001
#define MAX 128

int graph[MAX][MAX];
int graph_len;

int lowcost[MAX];
int closest[MAX];

int solve() {
  for (int i = 1; i < graph_len; ++ i) {
      lowcost[i] = graph[0][i];
      closest[i] = 0;
  }
  lowcost[0] = 0;
  closest[0] = 0;
  
  int result = 0;
  for (int i = 1; i < graph_len; ++ i) {
      int mincost = INF, minone = 0;
      for (int j = 0; j < graph_len; ++ j) {
	if (lowcost[j] &&  lowcost[j] < mincost) {
	  mincost = lowcost[j];
	  minone = j;
	}
      }
      result += mincost;
      lowcost[minone] = 0;
      
      for (int j = 0; j < graph_len; ++ j) {
	if (lowcost[j] && lowcost[j] > graph[minone][j]) {
	  lowcost[j] = graph[minone][j];
	  closest[j] = minone;
	}
      }
  }
  return result;
}

int main() {
    while (scanf("%d", &graph_len) != EOF) {
	for (int i = 0; i < graph_len; ++ i) {
	    for (int j = 0; j < graph_len; ++ j) {
	      scanf("%d", &graph[i][j]);
	    }
	}
	printf("%d\n", solve());
    }
    return 0;
}