#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX (10000+5)

struct Job {
  int b, j;
  bool operator <(const Job& x) const {
      return j > x.j;
  }
};

Job j[MAX];

int main() {
    int case_cnt = 1, n;
    while (std::cin >> n, n) {
	for (int i = 0; i < n; ++ i) {
	    std::cin >> j[i].b >> j[i].j;
	}
	std::sort(j, j+n); 
	int alltime = 0, btime = 0;
	
	for (int i = 0; i < n; ++ i) {
	   btime += j[i].b; 
	   if (btime + j[i].j > alltime) {
	      alltime = btime + j[i].j;
	   }
	}
	std::cout << "Case " << case_cnt << ": " << alltime << std::endl;
	++ case_cnt;
    }
    return 0;
}