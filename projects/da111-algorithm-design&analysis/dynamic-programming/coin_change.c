#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 999999

int minCoins(int coins[], int n, int target) {
    int dp[target+1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=target;i++)
        for(int j=0;j<n;j++)
            if(coins[j]<=i && dp[i-coins[j]]!=INF)
                dp[i]=(dp[i-coins[j]]+1<dp[i])?dp[i-coins[j]]+1:dp[i];
    return (dp[target]>=INF)?-1:dp[target];
}

void print_change(int coins[], int n, int target) {
    int dp[target+1], parent[target+1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=target;i++)
        for(int j=0;j<n;j++)
            if(coins[j]<=i && dp[i-coins[j]]!=INF)
                if(dp[i-coins[j]]+1<dp[i]) { dp[i]=dp[i-coins[j]]+1; parent[i]=coins[j]; }
    printf("  Minimum %d coin(s):", target);
    int amt=target;
    while(amt>0) { printf(" %d", parent[amt]); amt-=parent[amt]; }
    printf("\n");
}

int main() {
    printf("=== Coin Change Problem ===\n\n");
    int coins[] = {1, 3, 4};
    int n = sizeof(coins)/sizeof(coins[0]);
    int ts[] = {6,7,10,15,25};
    for(int i=0;i<5;i++) {
        int c=minCoins(coins,n,ts[i]);
        if(c<0) printf("  Amount %d: cannot make change\n", ts[i]);
        else { printf("  Amount %d: min %d coin(s)\n", ts[i],c); print_change(coins,n,ts[i]); }
    }
    return 0;
}
