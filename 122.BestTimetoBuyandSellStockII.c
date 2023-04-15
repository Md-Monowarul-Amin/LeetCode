#include<stdio.h>

int Max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int max_return(int* array, int array_len){
    int out = 0;
    for(int i=0; i< array_len; i++){
        if(array[i] > out){
            out = array[i];
        }
    }
    return out;
}

int out_func(int* prices, int pricesSize, int buy_day, int* dp){
    //printf("%d\n", buy_day);
    //printf("buy_day in first%d\n", buy_day);
    if(buy_day >= pricesSize -1){
        //printf("pricesSize %d\n", pricesSize);
        return dp[pricesSize-1]=0;
    }
    if (dp[buy_day] >= 0){
        printf("dp[%d] %d\n", buy_day, dp[buy_day]);
        return dp[buy_day];
    }
    
    //printf("dp[%d] = %d prices[%d]-prices[%d]=%d\n",buy_day, dp[buy_day], buy_day, buy_day, prices[] - prices[buy_day]);
    for(int i=buy_day; i<pricesSize; i++){
        //printf("Buy_day = %d, i=%d\n", buy_day, i);
        dp[buy_day] = Max(dp[buy_day], Max(out_func(prices, pricesSize, i+1, dp), out_func(prices, pricesSize, i+1, dp)+ prices[i] - prices[buy_day]));
        //printf("buy_day in ret %d, dp[%d] = %d\n", buy_day, buy_day, dp[buy_day]);        
    }
    return dp[buy_day];
}// 3 2 6 5 0 3

int maxProfit(int* prices, int pricesSize){
    int dp[pricesSize +100];
    for(int i=0; i<pricesSize; i++){
        dp[i] = -1;
    }

    int max = 0;
    max =  out_func(prices, pricesSize, 0, dp);
    //for(int i=0; i<6; i++){
    //    printf("%d\n", dp[i]);
    //}
    return max;
}

int main(){
    int prices[] = {3, 2, 6, 5, 0, 3};
    printf("%d\n", maxProfit(prices, 6));
    return 0;
}