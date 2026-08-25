#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lcs(const char* s1, const char* s2) {
    int m=strlen(s1), n=strlen(s2);
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=(dp[i-1][j]>dp[i][j-1])?dp[i-1][j]:dp[i][j-1];
    return dp[m][n];
}

void print_lcs(const char* s1, const char* s2) {
    int m=strlen(s1), n=strlen(s2);
    int dp[m+1][n+1], len;
    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=(dp[i-1][j]>dp[i][j-1])?dp[i-1][j]:dp[i][j-1];
    len=dp[m][n];
    char* r=(char*)malloc(len+1); r[len]='\0';
    int k=len,i=m,j=n;
    while(i>0&&j>0) {
        if(s1[i-1]==s2[j-1]) { r[--k]=s1[i-1]; i--; j--; }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    for(int x=0;x<len/2;x++) { char t=r[x]; r[x]=r[len-1-x]; r[len-1-x]=t; }
    printf("  LCS: \"%s\" (length %d)\n", r, len);
    free(r);
}

int main() {
    const char* s1="ABCBDAB", *s2="BDCAB";
    printf("=== Longest Common Subsequence ===\n\n");
    printf("  S1: \"%s\"\n  S2: \"%s\"\n", s1, s2);
    int len=lcs(s1,s2);
    printf("  LCS length: %d\n", len);
    print_lcs(s1,s2);
    return 0;
}
