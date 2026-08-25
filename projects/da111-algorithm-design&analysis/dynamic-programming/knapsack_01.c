#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int knapsack(int W, int n, int wt[], int val[]) {
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
            if (wt[i-1] <= w)
                dp[i][w] = ((val[i-1] + dp[i-1][w - wt[i-1]]) > dp[i-1][w]) ? val[i-1] + dp[i-1][w - wt[i-1]] : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
    printf("  Included items:");
    for (int w=W, i=n; i>0 && w>0; i--)
        if (dp[i][w] != dp[i-1][w]) { printf(" %d", i-1); w -= wt[i-1]; }
    printf("\n  Max value: %d\n", dp[n][W]);
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120, 80, 90};
    int wt[]  = {10, 20, 30, 40, 50};
    printf("=== 0/1 Knapsack Problem ===\n");
    knapsack(100, 5, wt, val);
    return 0;
}
