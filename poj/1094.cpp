#include <cstdio>
#include <stack>
#include <cstring>

#define MAX 32

bool visited[MAX];
bool graph[MAX][MAX];
int graph_len;

int ind[MAX];
int outd[MAX];

bool hasCircle(void) {
  for (int k = 0; k < graph_len; ++ k) {
      for (int i = 0; i < graph_len; ++ i) {
	if (graph[i][k]) {
	  for (int j = 0; j < graph_len; ++ j) {
	    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
	  }
	}
      }
  }
  
  for (int i = 0; i < graph_len; ++ i) {
      if (graph[i][i]) {
	return true;
      }
  }
  return false;
}

bool topologiable(void){
  memset(ind, 0, sizeof(ind));
  memset(outd, 0, sizeof(outd));
  
  for (int i = 0; i < graph_len; ++ i) {
    for (int j = 0; j < graph_len; ++ j) {
      if (graph[i][j]) {
	++ ind[j];
	++ outd[i];
      }
    }
  } 
  
  for (int i = 0; i < graph_len; ++ i) {
      if (ind[i] + outd[i] != graph_len-1) {
	  return false;
      }
  }
  return true;
}

void topo(void) {
  memset(visited, 0, sizeof(visited));
  
  std::stack<int> s;

  for (int i = 0; i < graph_len; ++ i) {
    if (ind[i] == 0) {
      s.push(i);
    }
  }
  
  while (!s.empty()) {
      int p = s.top();
      s.pop();
      printf("%c", p+'A');
      visited[p] = true;
      
      for (int i = 0; i < graph_len; ++ i) {
	if (!visited[i] && graph[p][i]) {
	    -- ind[i];
	}
      }
      
      for (int i = 0; i < graph_len; ++ i) {
	if (!visited[i] && ind[i] == 0) {
	    s.push(i);
	}
      }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  int stat_num;
  char buf[4];
  
  bool flag;
  while (scanf("%d%d", &graph_len, &stat_num)) {
    if (graph_len == 0 && stat_num == 0) {
      break;
    }
    flag = false;
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < stat_num; ++ i) {
      scanf("%s", buf);
      graph[buf[0]-'A'][buf[2]-'A'] = true;
      
      if (flag) {
	  continue;
      }
      if (hasCircle()) {
	printf("Inconsistency found after %d relations.\n", i+1);
	flag = true;
	continue;
      }
      if (topologiable()) {
	printf("Sorted sequence determined after %d relations: ", i+1);
	topo();
	printf(".\n");
	flag = true;
	continue;
      }
    }
    if (flag == false) {
	printf("Sorted sequence cannot be determined.\n");
    }
  }
  return 0;
}