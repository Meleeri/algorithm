#include <cstdio>
#include <algorithm>
#include <numeric>

#define MAX (1000000+1)

long long C[MAX];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
	long long tot = 0;
	for (int i = 0; i < n; ++ i) {
	  scanf("%lld", &C[i]);
	  tot += C[i];
	}
	
	long long mean = tot / n;
	
	C[0] = 0;
	for (int i = 1; i < n; ++ i) {
	    C[i] += C[i-1]-mean;
	}
	std::sort(C, C+n);
	long long mid = C[n>>1];
	
	long long ans = 0;
	for (int i = 0; i < n; ++ i) {
	  ans += abs(C[i]-mid);
	}
	printf("%lld\n", ans);
    }
    return 0;
}