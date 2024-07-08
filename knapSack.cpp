#include<iostream>
using namespace std;
int weight[5] = {3, 4, 5};
int value[5] = {30, 50, 60};
int wt = 8;
int dp[10][10];

int knapSack(int index, int weightLeft) {
    if(weightLeft == 0) return 0;
    if(index < 0) return 0;
    if(dp[index][weightLeft] != -1) return dp[index][weightLeft];
    int ans = knapSack(index-1, weightLeft);
    if(weightLeft - weight[index] >= 0) {
        ans = max(ans, knapSack(index-1, weightLeft - weight[index]) + value[index]);
    }
    return dp[index][weightLeft] = ans;
}
int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
        dp[i][j] = -1;
    }
}
    int index = sizeof(weight) / sizeof(int);
    int profit = knapSack(index-1, wt);
    cout<<"maximum profit is : "<<profit;   //90
}