#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 128

int currency_count;
int point_count;
int currency_nick;
float volume_nick;

float ratio[MAX][MAX];
float comission[MAX][MAX];

float dist[MAX];

void solve() {
    for (int i = 0; i < MAX; ++ i) {
	dist[i] = 0.0f;
    }
    
    for (int i = 0; i < currency_count; ++ i) {
	if (i != currency_nick && ratio[currency_nick][i] != 0) {
	    dist[i] = -((volume_nick - comission[currency_nick][i])*ratio[currency_nick][i]);
	}
    }
    
    int source = currency_nick;
    for (int i = 1; i < currency_count; ++ i){
	for (int j = 0; j < currency_count; ++ j) {
	    for (int k = 0; k < currency_count; ++ k) {
		if (ratio[k][j] != 0 && (dist[k]+comission[k][j])*ratio[k][j] < dist[j]) {
		    dist[j] = (dist[k]+comission[k][j])*ratio[k][j];
		}
	    }
	}
    }
    
    for (int i = 0; i < currency_count; ++ i) {
	for (int j = 0; j < currency_count; ++ j) {
	    if ((dist[j]+comission[j][i])*ratio[j][i] < dist[i]) {
		std::cout << "YES" << std::endl;
		return;
	    }
	}
    }
    
    std::cout << "NO" << std::endl;
}


int main(){
    for (int i = 0; i < MAX; ++ i) {
	for (int j = 0; j < MAX; ++ j) {
	  ratio[i][j] = 0.0f;
	  comission[i][j] = 0.0f;
	}
    }
    std::cin >> currency_count >> point_count >> currency_nick >> volume_nick;
    
    -- currency_nick;
    int u, v;
    for (int i = 0; i < point_count; ++ i) {
	std::cin >> u >> v;
	--u; --v;
	std::cin >> ratio[u][v] >> comission[u][v] >> ratio[v][u] >> comission[v][u];
    }
    solve();
}
