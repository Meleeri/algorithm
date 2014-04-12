#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAXN = 101;
const int MAXF = 101;

bool likeF[MAXN][MAXN];
bool likeD[MAXN][MAXN];

const int MAXV = MAXN * 4+2;
int c[MAXV][MAXV], N, F, D;
bool visited[MAXV];
int pre[MAXV];

bool bfs(int s, int t) {
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(s);
    visited[s] = 1;
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int i = 0; i <= t; ++ i){
            if (!visited[i] && c[p][i] > 0) {
                que.push(i);
                visited[i]  = 1;
                pre[i] = p;
                if (i == t) return 1;
            }
        }
    }
    return 0;
}


int ek(int s, int t){
    int max_flow = 0;
    while (1) {
        if (!bfs(s, t)) {
            break;
        }
        int i = t;
        while (i != s) {
            c[pre[i]][i] -= 1;
            c[i][pre[i]] += 1;
            i = pre[i];
        }
        max_flow ++; 
    }
    return max_flow;
}


void solve() {
    int s = N*2+F+D, t=s+1;
    for (int i = 0; i < F; ++ i) {
        c[s][2*N+i] = 1;
    }

    for (int i = 0; i < D; ++ i) {
        c[2*N+F+i][t] = 1;
    }

    for (int i = 0; i < N; ++ i) {
        c[i][i+N] = 1;
        for (int j = 0; j < F; ++ j) {
            if (likeF[i][j]) {
                c[2*N+j][i] = 1;
            }
        }
        for (int j = 0; j < D; ++ j) {
            if (likeD[i][j]) {
                c[i+N][j+2*N+F] = 1;
            }
        }
    }
    cout << ek(s, t) << endl;
}

int main() {
    while (cin >> N >> F >> D) {
        memset(likeD, 0, sizeof(likeD));
        memset(likeF, 0, sizeof(likeF));

        for (int i = 0; i < N; ++ i) {
            int fn , dn;
            cin >> fn >> dn;
            for (int j = 0; j < fn; ++ j) {
                int f;
                cin >> f;
                likeF[i][f-1] = 1;
            }

            for (int j = 0; j < dn; ++ j) {
                int d;
                cin >> d;
                likeD[i][d-1] = 1;
            }
        }
        memset(c, 0, sizeof(c));
        solve();
    }
    return 0;
}

