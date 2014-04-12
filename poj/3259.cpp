#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

#define MAX 1024
#define INF 1000000000  

int path[MAX][MAX];
int dist[MAX];

bool inQueue[MAX];
int inQueueCount[MAX];

void sfpa(int fields){
    memset(inQueue, 0, sizeof(bool)*MAX);
    memset(inQueueCount, 0, sizeof(int)*MAX);
    
    for (int i = 1; i < fields; ++ i) {
	dist[i] = INF;
    }
    dist[0] = 0;
    
    std::queue<int> q;
    q.push(0);
    inQueue[0] = true;
    ++ inQueueCount[0];
    
    while (!q.empty()) {
	int p = q.front();
	q.pop();
	inQueue[p] = false;
	
	for (int i = 0; i < fields; ++ i) {
	    if (path[p][i] != INF && i != p && dist[p]+path[p][i] < dist[i]) {
		dist[i] = dist[p] + path[p][i];
	        if (!inQueue[i]) {
		    q.push(i);
		    inQueue[i] = true;
		    ++ inQueueCount[i];
		    if (inQueueCount[i] >= fields) {
		      std::cout << "YES" << std::endl;
		      return;
		    }
		}
	    }
	}
    }
    std::cout << "NO" << std::endl;
}


int main() {
    int farms;
    std::cin >> farms;
    
    int n, m, w;
    int u, v, weight;
    
    for (int i = 0; i < farms; ++ i) {
	for (int j = 0; j < MAX; ++ j) {
	   for (int k = 0; k < MAX; ++ k) {
	      path[j][k] = INF;
	   }
	}
	
	std::cin >> n >> m >> w;
	for (int j = 0; j < m; ++ j) {
	    std::cin >> u >> v >> weight;
	    --u; --v;
	    path[u][v] = path[v][u] = weight;
	}
	
	for (int j = 0; j < w; ++ j) {
	    std::cin >> u >> v >> weight;
	    --u; --v;
	    path[u][v] = -weight;
	}
	sfpa(n);
    }
    return 0;
}