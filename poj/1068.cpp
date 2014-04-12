#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;


void solve(int p_seq[], int len){ 
    char S[1024];
    int w_seq[32];

    int idx = 0;
    int offset = 0;
    for (int i = 0; i < len; ++ i) {
        for (int j = 0; j < p_seq[i]-offset; ++ j) {
            S[idx++] = '(';
		}
        S[idx++] = ')';
        offset = p_seq[i];
	}
    S[idx] = '\0';

    int j = 0;
    stack<int> s;

    for (int i = 0; i < idx; ++ i) {
        if (S[i] == '(') {
            s.push(i);
		}
		else {
            w_seq[j++] = (i-s.top()+1) >> 1;
            s.pop();
		}
	}

    for (int i = 0; i < j; ++ i) {
        printf("%d ", w_seq[i]);
	}
    printf("\n");
}

int main(){
    int test_case;
    scanf("%d", &test_case);

    int len, p_seq[1024];
    for (int i = 0; i < test_case; ++ i) {
        scanf("%d", &len);
        for (int j = 0; j < len; ++ j) {
            scanf("%d", &p_seq[j]);
		}
        solve(p_seq, len);
	}
    return 0;
}