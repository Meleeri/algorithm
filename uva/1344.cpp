#include <cstdio>
#include <algorithm>

using namespace std;

long long tian[1024], king[1024];

int main() {
  freopen("input.txt", "r", stdin);
  int N;
  while (scanf("%d", &N), N) {
    for (int i = 0; i < N; ++ i) {
      scanf("%lld", &tian[i]);  
    }
    for (int i = 0; i < N; ++ i) {
      scanf("%lld", &king[i]);  
    }
    
    sort(tian, tian+N);
    sort(king, king+N);
    
    int ans = 0;
    int j = 0, r = N-1;
    
    for (int i = 0; i < N && j < N; ++ i) {
      if (tian[i] < king[j]) {
	ans -= 200;
	-- r;
      }
      else if (tian[i] > king[j]){
	ans += 200;
	++ j;
      }
      else {
      }
    }
    printf("%d\n", ans);
  }
}