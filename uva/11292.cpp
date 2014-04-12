#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAX 20000

int dragon[MAX+1];
int knight[MAX+1];

int main() {
    int n, m;
    
    while (std::cin >> n >> m, n != 0 || m != 0) {
	for (int i = 0; i < n; ++ i) {
	    std::cin >> dragon[i];
	}
	for (int i = 0; i < m; ++ i) {
	    std::cin >> knight[i];
	}
	
	std::sort(dragon, dragon+n);
	std::sort(knight, knight+m);
	
	
	int cost = 0;
	int i = 0;
	for (int j = 0; i < n && j < m; ++ j) {
	    if (dragon[i] <= knight[j]) {
	      cost += knight[j];
	      ++ i;
	    }
	}
	if (i < n) {
	    std::cout << "Loowater is doomed!" << std::endl;
	}
	else {
	    std::cout << cost << std::endl;
	}
    }
    return 0;
}