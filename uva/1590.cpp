#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bitrev(int num) {
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    result |= (((num >> i) & 0x1) << (31 - i));
  }
  return result;
}

int str2ip(const char *str) {
  int digits = 24;
  int num = 0;

  int cur = 0;
  for (const char *p = str; *p; ++p) {
    if (*p != '.') {
      num = num * 10 + (*p - '0');
    } else {
      cur |= (num << digits);
      digits -= 8;
      num = 0;
    }
  }
  return bitrev(cur);
}

void ip2str(int ip, char *str) {
  int j = 0;
  for (int i = 24; i >= 0; i -= 8) {
    int tmp = ip >> i;

    int k = 100;
    while (tmp < k)
      k /= 10;

    if (k == 0)
      k = 1;

    while (tmp) {
      char c = tmp / k + '0';
      str[j++] = c;
      tmp = tmp % k;
    }
    if (i > 0) {
        str[j++] = '.';
    }
  }
}

int main(int argc, char *argv[]) {
  int N;
  char ipstr[128];

  while (scanf("%d", &N) != EOF) {
    int result = 0;
    int mask = 0;

    for (int i = 0; i < N; ++i) {
      int ip = str2ip(ipstr);
      ip &= mask;

      int tmp = ip ^ result;
      tmp = (-tmp) & tmp;
      tmp = (~tmp) & (tmp >> 1);
      mask &= tmp;
    }
  }
}
