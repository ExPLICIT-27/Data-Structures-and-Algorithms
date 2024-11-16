
/*In a unique team-building exercise, a company has decided to distribute a certain number of resources among its departments based on mathematical powers. The company has x resources that need to be distributed such that each department receives a different power of an integer. Specifically, each department i receives n resources, where n is a given power.



George, the resource manager, needs to find all possible ways to distribute exactly x resources using the powers of integers starting from 1. Each integer's power can only be used once.



Write a program to help George determine the number of ways to distribute x resources in this manner using a recursive manner.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int countWays(int, int, int, int);
int main(){
    int x, n;
    printf("\nEnter the number and power: ");
    scanf(" %d %d", &x, &n);
    printf("Total ways: %d", countWays(x, n, 1, 0));
    return 0;
}
int countWays(int number, int power, int curr_num, int curr_sum){
    int result = 0;
    int p = pow(curr_num, power);
    while((p + curr_sum) < number){
        result += countWays(number, power, curr_num+1, curr_sum+p);
        curr_num++;
        p = pow(curr_num, power);
    }
    if((p + curr_sum) == number){
        result++;
    }
    return result;
}