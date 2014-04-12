#include <cstdio>
#include <cstring>

#define MAX 512

int link[MAX];
bool graph[MAX][MAX];
int graph_len;

bool visited[MAX];
/*
 * 匈牙利算法
 */

bool crosspath(int k) {
  for (int i = 0; i < graph_len; ++ i) {
      if (!visited[i] && graph[k][i]) {
	  visited[i] = true;
	  if (link[i] == -1 || crosspath(link[i])) {
	    link[i] = k;
	    return true;
	  }
      }
  }
  return false;
}

int hungarian(void) {
  memset(link, -1, sizeof(link));
  int match = 0;
  for (int i = 0; i < graph_len; ++ i) {
      memset(visited, false, sizeof(visited));
      if (crosspath(i)) {
	  ++ match;
      }
  }
  return match;
}

int main() {
    int  K;
    while (scanf("%d%d", &graph_len, &K) != EOF) {
      int row, column;
      memset(graph, false, sizeof(graph));
      for (int i = 0; i < K; ++ i) {
	  scanf("%d%d", &row, &column);
	  graph[row-1][column-1] = true;
      }
      printf("%d\n", hungarian());
    }
    return 0;
}