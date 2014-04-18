#include <cstdio>
#include <algorithm>

using namespace std;

long long tian[1024], king[1024];

int main() {
  int N;
  while (scanf("%d", &N), N) {
    for (int i = 0; i < N; ++ i) {
      scanf("%lld", &tian[i]);  
    }
    for (int i = 0; i < N; ++ i) {
      scanf("%lld", &king[i]);  
    }
    
    auto cmp = [&](int x, int y) {return x > y;};
    
    sort(tian, tian+N, cmp);
    sort(king, king+N, cmp);
    
    int ans = 0;
    int fin_k = N-1, fin_t = N-1; 
    for (int i = 0, j = 0; i <= fin_t && j < N; ++ j) {
      if (tian[i] < king[j]) {
	ans -= 200;
	-- fin_t;
      }
      else if (tian[i] > king[j]){
	ans += 200;
	++ i;
      }
      else {
	for (int m = fin_t, k = fin_k; m >=i; --m, -- k) {
	    if (tian[m] > king[k]) {
	      ans += 200;
	      -- fin_k, -- fin_t;
	    }
	    else {
	      if (tian[m] < king[j]) {
		ans -= 200;
	      }
	      fin_t = m-1; fin_k = k;
	      break;
	    }
	}
      }
    }
    printf("%d\n", ans);
  }
}