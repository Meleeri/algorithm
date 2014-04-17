#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAXD 1000000
#define MAXN 10000

using namespace std;

int box[MAXN];
vector<int> ans[MAXN];
unordered_map<int, int> cnt;

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &box[i]); 
    }
    sort(box, box+n);
    
    
    cnt.clear(); 
    for (int i = 0; i < n; ++ i) {
      auto x = cnt.find(box[i]);
      if (x == cnt.end()) {
	cnt.insert(make_pair(box[i], 1));
      }
      else {
	++ x->second;
      }
    }
    
    int N = 0;
    for (int i = 0; i < n; ++ i) {
      N = max(N, cnt.find(box[i])->second);
    }
    
    for (int i = 0; i < N; ++ i) {
      ans[i].clear();
    }
    
    for (int i = 0; i < n; ++ i) {
	ans[i%N].push_back(box[i]);
    }
    
    printf("%d\n", N);
    for (int i = 0; i < N; ++ i) {
      printf("%d", *(ans[i].cbegin()));
      for (auto x = ans[i].cbegin()+1; x != ans[i].cend(); ++ x) {
	printf(" %d", *x);
      }
      printf("\n");
    }
  }
  return 0;
}