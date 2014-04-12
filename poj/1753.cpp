#include <cstdio>
#include <iostream>
#include <queue>

#define IM (~((unsigned)-1 >> 1))

typedef unsigned short _state;

struct node{
	node(_state _s, int _step):
		s(_s), step(_step){};
	_state s;
	unsigned int step;
};

int solve(_state init_state) {
	std::queue<node> q;
	q.push(node(init_state, 0));
	
	while (!q.empty()) {
		node nd = q.front();
		q.pop();
		
		if (nd.s == 0x0 || nd.s == (unsigned)-1) {
			return nd.step;
		}
		for (int row = 0; row < 4; ++ row) {
			for (int column = 0; column < 4; ++ column) {
				_state mask = 0x0;
				short pos = row*4+column;
				if (row != 0) {
					mask = mask | (0x1 << 15-(pos-4));
				}
				if (column != 0) {
					mask = mask | (0x1 << 15-(pos-1));
				}
				mask = mask | (0x1 << 15-pos);
				if (column != 3) {
					mask = mask | (0x1 << 15-(pos+1));
				}
				if (row != 3) {
					mask = mask | (0x1 << 15-(pos+4));
				}

				q.push(node((~(nd.s & mask)) & (nd.s | mask), nd.step+1));
			}
		}
	}
	return -1;
}

int main(){
	_state init_state = 0x0;
	int ans;
	
	char c[16];
	for (int i = 0; i < 4; ++ i) {
		std::cin >> c;
		for (int j = 0; j < 4; ++ j) {
			if (c[j] == 'b') {
				init_state = init_state | 0x1;
			}
			if (!(i == 3 && j ==3)) {
				init_state = init_state << 1;
			}
		}
	}
		
	if ((ans = solve(init_state)) == -1) {
		std::cout << "Impossible" << std::endl;
	}
	else {
		std::cout << ans << std::endl;
	}
}