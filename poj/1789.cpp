#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>


#define INF (((unsigned)-1)>>1)
#define MAX 10000000
#define MAX_LEN 2048


struct G{
    int v, w;
    int next;
};

G graph[MAX];
int graph_len;
int first[MAX_LEN];

int lowcost[MAX_LEN];
int closest[MAX_LEN];

std::string types[MAX_LEN];
int types_count;

void addEdge(int u, int v, int w){
    graph[graph_len].v = v;
    graph[graph_len].w = w;
    graph[graph_len].next = first[u];
    first[u] = graph_len++;
}

int solve(){
    // Prim
    //
    memset(lowcost, 0, sizeof(lowcost));
    memset(closest, -1, sizeof(closest));

    for (int i = first[0]; i != -1; i = graph[i].next){
        lowcost[graph[i].v] = graph[i].w;
        closest[graph[i].v] = 0;
    }

    int minone = 0, mindis = INF, ans = 0;

    for (int i = 0; i < types_count-1; ++ i){
        mindis = INF;
        for (int j = 0; j < types_count; ++ j){
            if (lowcost[j] && mindis > lowcost[j]){
                mindis = lowcost[j];
                minone = j;
            }
        }
        ans += lowcost[minone];
        lowcost[minone] = 0;

        for (int j = first[minone]; j != -1; j = graph[j].next) {
            if (graph[j].w < lowcost[graph[j].v]){
                lowcost[graph[j].v] = graph[j].w;
                closest[graph[j].v] = minone;
            }
        }
    }
    return ans;
}

int delta(const std::string& s1, const std::string& s2){
    int result = 0;
    for (int i = 0; i < 7; ++ i){
        if (s1.at(i) != s2.at(i)){
            ++ result;
        }
    }
    return result;
}

int main(){
//    freopen("input.txt", "r", stdin);
    while (std::cin >> types_count) {
        if (types_count == 0) {
            break;
        }

        memset(first, -1, sizeof(first));
        graph_len = 0;

        int len = 0;
        for (int i = 0; i < types_count; ++ i) {
            std::cin >> types[len++];
        }

        for (int i = 0; i < types_count; ++ i) {
            for (int j = 0; j < types_count; ++ j) {
                if (i != j) {
                    addEdge(i, j, delta(types[i], types[j]));
                }
            }
        }
        std::cout << "The highest possible quality is 1/" << solve() << "." << std::endl;
    }
    return 0;
}
