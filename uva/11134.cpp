#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 5000

using namespace std;

struct Rect{
  int x1, y1;
  int x2, y2;
  
  int x, y;
};

Rect rect[MAX];
int N;

bool solve() {
  Rect *p[MAX];
  for (int i = 0; i < N; ++ i) {
    p[i] = &rect[i];
  }
  sort(p, p+N, [&](const Rect* x, const Rect* y) {
      return x->x1 < y->x1;
  });
  
  if (p[0]->x1 != 1) {
      return false;
  }
  
  for (int i = 0; i < N; ++ i) {
    if (p[i]->x1 > i+1 || p[i]->x2 < i+1) return false;
    p[i]->x = i+1;
  }
  
  sort(p, p+N, [&](const Rect* x, const Rect* y) {
      return x->y1 < y->y1;
  });
  if (p[0]->y1 != 1) {
    return false;
  }
  p[0]->y = 1;
  for (int i = 0; i < N; ++ i) {
    if (p[i]->y1 > i+1 || p[i]->y2 < i+1) return false;
    p[i]->y = i+1;
  }
  
  return true;
}

int main() {
  while (scanf("%d", &N), N) {
    for (int i = 0; i < N; ++ i) {
	scanf("%d%d%d%d", &(rect[i].x1), &(rect[i].y1), &(rect[i].x2), &(rect[i].y2));
	rect[i].x = rect[i].y = 0;
    }
    
    if (solve()) {
       for (int i = 0; i < N; ++ i) {
	  printf("%d %d\n", rect[i].x, rect[i].y);
       }
    }
    else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}