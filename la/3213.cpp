#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>

char str1[128], str2[128];
int ocur1[26], ocur2[26];

void sort(int A[], int len) {
  int i = 1;
  while (i < len) {
    int temp = A[i], j = i-1;
    while (j && temp > A[j]) {
      A[j+1] = A[j--];
    } 
    A[j] = temp;
    ++ i;
  }
}

bool solve(void) {
  memset(ocur1, 0, sizeof(ocur1));
  memset(ocur2, 0, sizeof(ocur2));
  
  int len = strlen(str1); 
  for (int i = 0; i < len; ++ i) {
    ++ ocur1[str1[i]-'A'];
    ++ ocur2[str2[i]-'A'];
  }
  
  std::sort(ocur1, ocur1+26, std::greater<int>());
  std::sort(ocur2, ocur2+26, std::greater<int>());
  
  for (int i = 0; i < 26; ++ i) {
      if (ocur1[i] != ocur2[i]) {
	return false;
      }
      if ((ocur1[i] | ocur2[i]) == 0) {
	return true;
      }
  }
  return true;
}

int main(int argc, char *argv[]) {
  freopen("input.txt", "r", stdin);
  while (scanf("%s", str1) != EOF) {
      scanf("%s", str2);
      if (solve())  {
	printf("YES\n");
      }
      else {
	printf("NO\n");
      }
  }
}