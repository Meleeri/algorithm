#include <iostream>
#include <cstdio>
#include <stack>

#define MIN_INF ~((unsigned)-1 >> 1)

int dp[21][21][21] = {0};
	
int solve_dp(int a, int b, int c){
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
	
    if (a > 20 || b > 20 || c > 20) {
        a = b = c = 20;
    }
	
	if (dp[a][b][c] != 0) {
		return dp[a][b][c];
	}

    for (int i = 0; i <= a; ++ i) {
        for (int j = 0; j <= b; ++ j) {
            for (int k = 0; k <= c; ++ k) {
				if (dp[i][j][k] == 0) {
					if (i == 0 || j == 0 || k == 0) {
						dp[i][j][k] = 1;
					}
					else if (i < j && j < k) {
						dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
					}
					else {
						dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] +  dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
					}
				}
            }
        }
    }
    return dp[a][b][c];
}

int main(){
    dp[0][0][0] = 1;
    int a, b, c;
    while (true) {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        else {
            printf("w(%d, %d, %d) = %d\n", a, b, c, solve_dp(a, b, c));
        }
    }
    return 0;
}
