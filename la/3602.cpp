#include <cstdio>
#include <cstring>

#define MAX 1024

char seq[MAX];
int cnt[MAX][4];

char dna[] = {'A', 'C', 'G', 'T'};

int main(int argc, char *argv[]) {
  freopen("input.txt", "r", stdin);
  
  int case_cnt;
  scanf("%d", &case_cnt);
  
  for (int i = 0; i < case_cnt; ++ i) {
    memset(cnt, 0, sizeof(cnt));
    int n, len;
    scanf("%d%d\n", &n, &len);
    for (int i = 0; i < n; ++ i) {
	scanf("%s", seq);
	for (int j = 0; j < len; ++ j) {
	  switch(seq[j]) {
	    case 'A': ++ cnt[j][0]; break;
	    case 'C': ++ cnt[j][1]; break;
	    case 'G': ++ cnt[j][2]; break;
	    case 'T': ++ cnt[j][3]; break;
	  }
	}
    }
    int ans = 0;
    for (int i = 0; i < len; ++ i) {
      int maxcnt = 0;
      int maxidx = 0;
      for (int j = 0; j < 4; ++ j) {
	if (maxcnt < cnt[i][j]) {
	  maxcnt = cnt[i][j];
	  maxidx = j;
	}
      }
      seq[i] = dna[maxidx];
      ans += n-cnt[i][maxidx];
    }
    printf("%s\n%d\n", seq, ans);
  }
  return 0;
}