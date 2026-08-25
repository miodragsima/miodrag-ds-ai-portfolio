#include <stdio.h>
#include <stdlib.h>

int fib_bottomup(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int fib_memo(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
    return memo[n];
}

int main() {
    printf("=== Fibonacci - Dynamic Programming ===\n\n");
    int n;
    for (n = 5; n <= 30; n += 5)
        printf("fib(%d) = %d (bottom-up: %d)\n", n, fib_memo(n, NULL), fib_bottomup(n));
    int* memo = malloc(31 * sizeof(int));
    for(int i=0;i<31;i++) memo[i]=-1;
    printf("\nMemoized fib(25) = %d\n", fib_memo(25, memo));
    free(memo);
    return 0;
}
