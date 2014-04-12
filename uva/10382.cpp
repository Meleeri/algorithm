#include <cstdio>
#include <algorithm>
#include <math.h>

#define MAX 10000
#define EPS 1e-8

struct coord{
  double left, right;
  bool operator<(const coord& x) const {
    if (left < x.left) {
      return true;
    }
    else if (left > x.left) {
      return false;
    }
    else {
      return right > x.right;
    }
  }
};

coord points[MAX+1];

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    double length, width;
    while(scanf("%d%lf%lf", &n, &length, &width) != EOF) {
	double pos, radius;
	for (int i = 0; i < n; ++ i) {
	    scanf("%lf%lf", &pos, &radius);
	    double d = (radius*2 > width)? sqrt(radius*radius-width*width/4.0): 0.0;
	    points[i].left = pos-d;
	    points[i].right = pos+d;
	}
	
	std::sort(points, points+n);
	
	int ans = 0;
	bool success = true;
	
	double prev = 0.0;
	int j = 0;
	while (j < n && prev < length) {
	  double max_right = prev;
	  while (points[j].left <= prev && j < n) {
	      max_right = std::max(max_right, points[j].right);
	      ++ j;
	  }
	  if (max_right <= prev) {
	     success = false; 
	     break;
	  }
	  else {
	    prev = max_right;
	    ++ ans;
	  }
	}
	if (prev < length) {
	  success = false;
	}
	
	if (success) {
	  printf("%d\n", ans);
	}
	else {
	  printf("-1\n");
	}
    }
}