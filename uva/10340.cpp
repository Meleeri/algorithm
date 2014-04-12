#include <iostream>
#include <cstring>
#include <string>

int main() {
  freopen("input.txt", "r", stdin);
  std::string sub, s;
  while (std::cin >> sub >> s) {
    int i = 0;
    for (int j = 0; i < sub.size() && j < s.size(); ++ j) {
      if (sub.at(i) == s.at(j)) {
	  ++ i;
      }
    }
    if (i < sub.size()) {
      printf("No\n");
    }
    else {
      printf("Yes\n");
    }
  }
}