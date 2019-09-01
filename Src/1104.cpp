#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=111111;
double nums[MAXN];
double dp[MAXN];
int N;

int main(){
    //cin >> N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        //cin >> nums[i];
        scanf("%lf", &nums[i]);
    }
    double tot=0.0;
    dp[1] = nums[1];
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + i*nums[i];
    }
    for(int i=1; i<=N; i++){
        tot += dp[i];
    }
    printf("%.2lf", tot);
    return 0;
}
