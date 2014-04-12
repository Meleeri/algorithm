#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>

#define MAX_HOUR 16
#define MAX_LAKE 26

#define DEBUG freopen("input.txt", "r", stdin);

int fish[MAX_LAKE];
int dec[MAX_LAKE];
int timecost[MAX_LAKE];

void solve(int lake, int hour) {
    hour *= 12;
    int result = 0;
    int times[MAX_LAKE];

    int tmptimes[MAX_LAKE];
    int tmpfish[MAX_LAKE];

    memset(times, 0, sizeof(times));

    for (int i = 1; i < lake-1; ++ i) {
        timecost[i] += timecost[i-1];
    }
    for (int i = 0; i < lake; ++ i) {
        int maxfish = 0;
        memset(tmptimes, 0, sizeof(tmptimes));
        memcpy(tmpfish, fish, sizeof(tmpfish));

        int cost = (i == 0? 0: timecost[i-1]);
        for (int j = 0; j < hour-cost; ++ j) {
            int tmpmax = 0, tmpidx = 0;
            for (int k = 0; k <= i; ++ k) {
               if (tmpfish[k] > tmpmax) {
                 tmpmax = tmpfish[k];
                 tmpidx = k;
               }
            }
            if (tmpmax <= 0) {
                tmptimes[0] += (hour-cost-j)*5;
                break;
            }
            tmptimes[tmpidx] += 5;
            maxfish += tmpfish[tmpidx];

            tmpfish[tmpidx] -= dec[tmpidx];
        }

        if (result < maxfish) {
             result = maxfish;
             memcpy(times, tmptimes, sizeof(times));
        }

        else if (result == maxfish) {
            int idx = 0;
            for (idx = 0; idx <= i; ++ idx) {
                if (tmptimes[idx] != times[idx]) {
                    break;
                }
            }

            if (tmptimes[idx] > times[idx]) {
                memcpy(times, tmptimes, sizeof(times));
            }
        }
    }

    int i = 0;
    for (i = 0; i < lake-1; ++ i) {
        printf("%d, ", times[i]);
    }
    printf("%d\n", times[i]);
    printf("Number of fish expected: %d\n\n", result);
}

int main() {
    int hour, lake;
    while (scanf("%d", &lake) != EOF, lake != 0) {
        scanf("%d", &hour);
        for (int i = 0; i < lake; ++ i) {
            scanf("%d", &fish[i]);
        }
        for (int i = 0; i < lake; ++ i) {
            scanf("%d", &dec[i]);
        }
        for (int i = 0; i < lake-1; ++ i) {
            scanf("%d", &timecost[i]);
        }
        solve(lake, hour);
    }
}
