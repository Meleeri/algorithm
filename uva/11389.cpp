#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>

#define MAX 1024

int day[MAX], night[MAX];

int main() {
    freopen("input.txt", "r", stdin);
    int n, d, r;
    while (scanf("%d%d%d", &n, &d, &r), n|d|r) {
      for (int i = 0; i < n; ++ i) {
	scanf("%d", &day[i]);
      }
      for (int i = 0; i < n; ++ i) {
	scanf("%d", &night[i]);
      }
      std::sort(day, day+n);
      std::sort(night, night+n, std::greater<int>()); 
      
      int ans = 0;
      for (int i = 0; i < n; ++ i) {
	day[i] += night[i];
	if (day[i] > d) {
	  ans += (day[i]-d)*r;
	} 
      }
      printf("%d\n", ans);
    }
}