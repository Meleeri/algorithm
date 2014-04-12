#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 65536
#define MAX 512

struct G {
    bool operator <(const struct G& g) const {
        return w < g.w;
    }
    int u, v, w;
};

G graph[MAX*MAX];
int graph_len;

int parent[MAX];
int rank[MAX];

void make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int find_parent(int x) {
    if (parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

bool union_set(int x, int y) {
    int xroot = find_parent(x);
    int yroot = find_parent(y);
    
    if (xroot == yroot) {
	return false;
    }
    
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    }
    else if (rank[xroot] > rank[yroot]) {
      parent[yroot] = xroot;
    }
    else  {
        parent[yroot] = xroot;
	++ rank[xroot];
    }
    return true;
}

int solve(int vcount) {
    std::sort(graph, graph+graph_len);

    for (int i = 0; i < vcount; ++ i) {
	rank[i] = 0;
	parent[i] = i;
    }

    int result = graph[0].w;

    for (int i = 0; i < graph_len; ++ i) {
	if (union_set(graph[i].u, graph[i].v)){
	    result = graph[i].w;
	}
    }
    return result;
}


int main(){
    freopen("input.txt", "r", stdin);

    int case_num;
    scanf("%d", &case_num);

    int vcount, w;
    for (int i = 0; i < case_num; ++ i) {
        graph_len = 0;
	scanf("%d", &vcount);
        for (int j = 0; j < vcount; ++ j) {
            for (int k = 0; k < vcount; ++ k) {
	        scanf("%d", &w);
                if (j < k){
                    graph[graph_len].u = j;
                    graph[graph_len].v = k;
                    graph[graph_len].w = w;
                    ++ graph_len;
                }
            }
        }
        printf("%d\n", solve(vcount));
    }
}
