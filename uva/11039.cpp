#include <cstdio>
#include <algorithm>
#include <math.h>

#define MAX 500000+1
#define MASK (~((unsigned)-1>>1))

int dp[MAX];
int seq[MAX];

int solve(int len) {
  std::sort(seq, seq+len, [&](int x, int y) {
    return abs(x) < abs(y);
  });
  
  dp[0] = 1;
  for (int i = 1; i < len; ++ i) {
      if (((seq[i]^seq[i-1]) & MASK) == 0) {
	dp[i] = dp[i-1];
      }
      else {
	dp[i] = dp[i-1]+1;
      }
  }
  return dp[len-1];
}

int main() {
  printf("%x\n", MASK);
  freopen("input.txt", "r", stdin);
  int case_cnt;
  scanf("%d", &case_cnt);
  for (int i = 0; i < case_cnt; ++ i) {
    int len;
    scanf("%d", &len);
    for (int j = 0; j < len; ++ j) {
      scanf("%d", &seq[j]);
    }
    printf("%d\n", solve(len)); 
  }
  return 0;
}