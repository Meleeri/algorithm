#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <math.h>

#define MAX 128

char digits[MAX][MAX];
int len[MAX];
char *p[MAX];

int main() {
  int n;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++ i) {
      scanf("%s", digits[i]);
      len[i] = strlen(digits[i]);
    }
    
    auto less_than = [&](int x, int y) {
      for (int i = 0; i < std::min(len[x], len[y]); ++ i) {
	if (digits[x][i] != digits[y][i]) {
	  return digits[x][i] > digits[y][i];
	}
      }
      return len[x] < len[y];
    };
    
    for (int i = 0; i < n; ++ i) {
      p[i] = digits[i];
    }
    
    for (int i = 0; i < n; ++ i) {
      for (int j = i+1; j < n; ++ j) {
	if (less_than(j, i)) {
	  std::swap(p[i], p[j]);
	}
      }
    }
    
    for (int i = 0; i < n; ++ i) {
      printf("%s", p[i]);
    }
    printf("\n");
  }
}