#include <cstdio>
#include <iostream>

#define INF (((unsigned)-1)>>1)
#define MAX 128

int graph[MAX][MAX];
int graph_len;

int min_start;
int min_cost;

bool solve(){
  for (int k = 0; k < graph_len; ++ k) {
      for (int i = 0; i < graph_len; ++ i) {
	for (int j = 0; j < graph_len; ++ j) {
	    if (graph[i][k] < INF && graph[k][j] < INF && graph[i][k] + graph[k][j] < graph[i][j]) {
		graph[i][j] = graph[i][k] + graph[k][j];
	    }
	}
      }
  }
  
  min_start = 0;
  min_cost = INF;
  
  bool flag = false;
  for (int i = 0; i < graph_len; ++ i) {
      int tmpcost = 0;
      for (int j = 0; j < graph_len ;++ j) {
	  if (i != j && tmpcost < graph[i][j]) {
	     tmpcost = graph[i][j];
	  }
      }
      flag = flag || (tmpcost < INF);
      
      if (min_cost > tmpcost) {
	 min_start = i;
	 min_cost = tmpcost; 
      }
  }
  return flag;
}

int main(){
    while (std::cin >> graph_len) {
	if (graph_len == 0) {
	  break;
	}
	for (int i = 0; i < graph_len; ++ i) {
	    for (int j = 0; j < graph_len; ++ j) {
		graph[i][j] = INF;
	    }
	}
	
	int trusted;
	for (int i = 0; i < graph_len; ++ i) {
	    int v, w;
	    std::cin >> trusted;
	    for (int j = 0; j < trusted; ++ j) {
		std::cin >> v >> w;
		graph[i][v-1] = w;
	    }
	}
	if (solve()) {
	    std::cout << min_start+1 << " " << min_cost << std::endl;
	}
	else {
	    std::cout << "disjoint" << std::endl;
	}
    }
}