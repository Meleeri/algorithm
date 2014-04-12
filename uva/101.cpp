#include <cstdio>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

#define MAXN 32

std::vector<int> pile[MAXN];
int pile_cnt[MAXN];
int locate[MAXN];

inline
void remove_upper(int a) {
    while (true) {
	int p = pile[locate[a]].back();
	if (p == a) {
	  break;
	}
	pile[locate[a]].pop_back();
	pile[p].push_back(p);
	locate[p] = p;
    }
}

inline
void move_to(int a, int b) {
    pile[locate[a]].pop_back();
    pile[locate[b]].push_back(a);
    locate[a] = locate[b];
}

inline
void pile_to(int a, int b) {
   std::stack<int> tmp;
   while (true) {
      int p = pile[locate[a]].back();
      pile[locate[a]].pop_back();
      tmp.push(p);
      
      if (p == a) {
	break;
      }
   }
   while (!tmp.empty()) {
      int p = tmp.top();
      tmp.pop();
      pile[locate[b]].push_back(p);
      locate[p] = locate[b];
   }
   locate[a] = locate[b];
}

void print(int n) {
  for (int i = 0; i <  n; ++ i) {
    std::cout << i << ":";
    if (!pile[i].empty()) {
      for (auto x = pile[i].cbegin(); x != pile[i].cend(); ++ x) {
	std::cout << " " << *x;
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  std::string instruction;
  std::string str1, str2;
  int a, b;
  
  for (int i = 0; i < MAXN; ++ i) {
    pile[i].push_back(i);
    locate[i] = i;
  }
  
  std::cin >> n;
  while (getchar() != '\n'); 
  while (getline(std::cin, instruction)) {
    if (instruction.compare("quit") == 0) {
      break;
    }
    std::istringstream f(instruction);
    f >> str1 >> a >> str2 >> b;
    if (a == b || locate[a] == locate[b]) {
      continue;
    }
    else {
      bool move = false, onto = false;
      move = (str1.compare("move")==0);
      onto = (str2.compare("onto")==0);
      
      if (move == true && onto == true) {
	remove_upper(a);
	remove_upper(b);
	move_to(a, b);
      }
      else if (move == true && onto == false) {
	remove_upper(a);
	move_to(a, b);
      }
      else if (move == false && onto == true) {
	remove_upper(b);
	pile_to(a, b);
      }
      else {
	pile_to(a, b);
      }
    }
  }
  print(n);
  return 0;
}