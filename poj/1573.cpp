#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <deque>

using namespace std;

#define MAX 1024

char rmap[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};

void solve(int row, int column, int start) {
    memset(visited, 0, sizeof(bool)*MAX*MAX);

    deque<int> q;
    int x = start, y = 0;
    while (!visited[y][x] && (x >= 0 && x < column && y >= 0 && y < row)) {
        visited[y][x] = true;
        q.push_back(y*column+x);
        switch(rmap[y][x]) {
		case 'W':
            -- x;
            break;
		case 'S':
            ++ y;
            break;
		case 'E':
            ++ x;
            break;
		case 'N':
            -- y;
            break;
		}
	}
    if (visited[y][x]) {
        int count = 0;
        while (q.front() != y*column+x) {
            q.pop_front();
            ++ count;
		}
        cout << count << " step(s) before a loop of " << q.size() << " step(s)" << endl;
	}
	else {
        cout << q.size() << " step(s) to exit" << endl;
	}
}

int main() {
    int row, column, start;
    while (true) {
        cin >> row >> column >> start;
        if (row || column || start) {
            for (int i = 0; i < row; ++ i) {
                for (int j = 0; j < column; ++ j) {
                    cin >> rmap[i][j];
				}
			}
            solve(row, column, start-1);
		}
		else {
            break;
		}
	}
    return 0;
}