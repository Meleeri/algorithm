#include <stdio.h>
#include <string.h>

#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

inline int min(int a, int b) { return a < b ? a : b; }

int KMP(char *p, int *next, int len) {
  int j, k;

  next[0] = -1;
  j = 0;
  k = next[j];
  while (j < len) {
    if (k == -1 || p[j] == p[k]) {
      next[++j] = ++k;
    } else {
      k = next[k];
    }
  }
  return next[len];
}

int main(int argc, char *argv[]) {
  int T;
  char buf[128];
  int next[128];

//  freopen("input.txt", "r", stdin);
  std::cin >> T;

  while (T--) {
    std::cin >> buf;
    int len = strlen(buf);
    int result = len - KMP(buf, next, len);
    if (len % result == 0) {
      std::cout << result;
    } else {
      std::cout << len;
    }
    if (T) {
      std::cout << std::endl;
    }
  }
  return 0;
}
