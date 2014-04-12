#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cfloat>
#include <cmath>

#include <queue>

#define MAX 32

float ratio[MAX][MAX];
std::map<std::string, int> currency;

float dist[MAX];
bool inqueue[MAX];
int inqueue_count[MAX];

bool solve_sfpa(int currency_count){
    for (int i = 1; i < currency_count; ++ i){
        dist[i] = ratio[0][i];
    }
    dist[0] = 0;
    memset(inqueue, 0, sizeof(inqueue));
    memset(inqueue_count, 0, sizeof(inqueue_count));

    std::queue<int> q;
    q.push(0);

    inqueue[0] = true;
    inqueue_count[0] = 1;

    while (!q.empty()){
        int p = q.front();
        q.pop();
        inqueue[p] = false;

        if (inqueue_count[p] >= currency_count){
            return true;
        }

        for (int i = 0; i < currency_count; ++ i) {
            if (dist[p] < FLT_MAX && ratio[p][i] < FLT_MAX && dist[p] + ratio[p][i] < dist[i]){
                dist[i] = dist[p] + ratio[p][i];
                if (!inqueue[i]){
                    q.push(i);
                    ++ inqueue_count[i];
                    inqueue[i] = true;
                }
            }
        }
    }
    return false;
}

bool solve(int currency_count) {
  for (int i = 0; i < currency_count; ++ i) {
      dist[i] = ratio[0][i];
  }

  for (int i = 0; i < currency_count; ++ i) {
      for (int j = 0; j < currency_count; ++ j) {
	  for (int k = 0; k < currency_count; ++ k) {
	      if (ratio[j][k] < FLT_MAX && dist[j] < FLT_MAX && dist[j] + ratio[j][k] < dist[k]) {
		  dist[k] = dist[j] + ratio[j][k];
	      }
      }
      }
  }

  for (int i = 0; i < currency_count; ++ i) {
      for (int j = 0; j < currency_count; ++ j) {
	  if (dist[i] + ratio[i][j] < dist[j]) {
	    return true;
    	}
      }
  }
  return false;
}

int main() {
  freopen("input.txt", "r", stdin);
  int currency_count, ratio_count;
  std::string cur1, cur2;
  float cur_ratio;

  int case_count = 0;
  while (std::cin >> currency_count) {
    if (currency_count == 0) {
      break;
    }
    for (int i = 0; i < currency_count; ++ i){
	for (int j = 0; j < currency_count; ++ j) {
	    ratio[i][j] = FLT_MAX;
	}
    }
    currency.clear();

    for (int i = 0; i < currency_count; ++ i) {
	std::cin >> cur1;
	currency.insert(std::make_pair(cur1, i));
    }

    std::cin >> ratio_count;
    for (int i = 0; i < ratio_count; ++ i) {
        std::cin >> cur1 >>  cur_ratio >> cur2;
	int idx1 = (*currency.find(cur1)).second, idx2 = (*currency.find(cur2)).second;
	ratio[idx1][idx2] = -log(cur_ratio);
    }
    std::cout << "Case " <<  ++case_count << ": ";
    if (solve_sfpa(currency_count)) {
	std::cout << "Yes" << std::endl;
    }
    else {
	std::cout << "No" << std::endl;
    }
  }
  return 0;
}
