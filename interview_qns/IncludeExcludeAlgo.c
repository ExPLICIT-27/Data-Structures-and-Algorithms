/*
Given a set of coins, find how many ways can they be used to 
reach a certain target sum.
*/
#include <stdio.h>
#include <stdlib.h>
int countWays(int *coins, int n, int sum){
    if(sum == 0){
        return 1;
    }
    if(sum < 0 || n == 0){
        return 0;
    }
    return countWays(coins, n, sum - coins[n-1]) + countWays(coins, n-1, sum);
}
int main(){
    int n;
    printf("\nEnter the number of coins: ");
    scanf(" %d", &n);
    int coins[n];
    printf("\nEnter the coin values separated by a space: ");
    for(int i = 0; i < n; i++){
        scanf(" %d", &coins[i]);
    }
    int sum;
    printf("\nEnter the target sum: ");
    scanf(" %d", &sum);
    printf("\nTotal number of ways: %d", countWays(coins, n, sum));
    return 0;
}