#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

#define MAX 1000000

int cycle[MAX+1];

int find(long long n) {
    if (n == 1) {
        return 1;
    }
    else {
        if (n & 1) {
            n += n<<1+1;
        }
        else {
            n >>= 1;
        }
        if (n < MAX) {
            if (!cycle[n])
                cycle[n] = find(n);
            return 1+cycle[n];
        }
        else {
            return 1+find(n);
        }
    }
}

int counter(long long n) {
    if (n == 1) {
        return 1;
    }
    if (n & 1)
        n += (n<<1) + 1;
    else
        n >>= 1;

    if (n < MAX) {
        if (!cycle[n])
            cycle[n] = counter(n);
        return 1 + cycle[n];
    }
    return 1 + counter(n);
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(cycle, 0, sizeof(cycle));
    int s, e;
    while (scanf("%d%d", &s, &e) != EOF) {
        if (s > e){
            int tmp = s;
            s = e;
            e = tmp;
        }
        int max = 0;
        for (int i = s; i <= e; ++ i) {
            int r = counter(i);
            if (max < r) {
                max = r;
            }
        }
        printf("%d %d %d\n", s, e, max);
    }
    return 0;
}
