#include <stdio.h>

#define Max(a,b) (a>b?a:b)

#define nmax (int)(3e4 + 5)
#define inf (int)(2e9 + 5)

int dp[nmax];

/*
dp[i] -> the maximum profit till day i
dp[i] -> max(dp[i - 1], dp[j - 1] + (a[i] - a[j]))
finalAns = dp[pricesSize - 1]
*/

int call(int i, int *prices, int n) {
    if (i <= 0) return 0;

    if (dp[i] != -1) return dp[i];

    int dont_buy = call(i - 1, prices, n);

    int res = 0;
    for (int j = 0; j < i; j++) {
        int buyJ_sellI = 0;
        if (prices[j] < prices[i]) {
            buyJ_sellI = call(j - 1, prices, n) + (prices[i] - prices[j]);
        }
        res = Max(res, Max(dont_buy, buyJ_sellI));
    }
    return dp[i] = res;
}

int maxProfit(int* prices, int pricesSize) {
    for (int i = 0; i < pricesSize; i++) {
        dp[i] = -1;
    }
    call(pricesSize - 1, prices, pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        printf("%d ", dp[i]);
    }
    puts("");
    return dp[pricesSize-1];
}

int main() {
    int a[] = {3, 2, 6, 5, 0, 3};
    int b[] = {7, 1, 5, 3, 6, 4};
    int c[] = {1, 2, 3, 4, 5};

    printf("%d", maxProfit(c, 5));
    return 0;
}