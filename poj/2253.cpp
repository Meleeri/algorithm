#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>

#define MAX 1024
#define INF (((unsigned)-1)>>1)

struct Coord{
  double x, y;
};

Coord coords[MAX];
double graph[MAX][MAX];
double dist[MAX];
bool visited[MAX];

inline
double min(double a, double b) {
  return a<b? a: b;
}

inline
double max(double a, double b) {
  return a>b? a: b;
}

double solve(int points){
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i < points; ++ i) {
      dist[i] = INF;
  }
  dist[0] = 0;
  
  int minn; double minn_val;
  for (int i = 0; i < points; ++ i) {
      minn = 0; minn_val = INF;
      for (int j = 0; j < points; ++ j) {
	  if (!visited[j] && dist[j] < minn_val) {
	      minn = j;
	      minn_val = dist[j];
	  }
	  visited[minn] = true;
      }
      for (int j = 0; j < points; ++ j) {
	dist[j] = min(dist[j], max(dist[minn], graph[minn][j]));
      }
  }
  return dist[points-1];
}

int main(){
    int scenario_count = 1, n;
    while (std::cin >> n) {
	if (n == 0)  {
	  break;
	}
	else {
	  std::cin >> coords[0].x >> coords[0].y;
	  std::cin >> coords[n-1].x >> coords[n-1].y;
	  for (int i = 1; i < n-1; ++ i) {
	    std::cin >> coords[i].x >> coords[i].y;
	  }
	  for (int i = 0; i < n; ++ i) {
	      for (int j = 0; j < n; ++ j) {
		 graph[i][j] = graph[j][i] = sqrt((coords[i].x-coords[j].x)*(coords[i].x-coords[j].x)
		    + (coords[i].y-coords[j].y)*(coords[i].y-coords[j].y));
	      }
	  }
	  std::cout << "Scenario #" << scenario_count << std::endl;
	  std::cout << "Frog Distance = ";
	  printf("%.3f\n\n", solve(n));
	}
	++ scenario_count;
    }
}