#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>

using namespace std;
const int MAXN=100001;
int N;
int nums[MAXN];
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    //sum
    sort(nums, nums+N);
    int sum1=0;
    for(int i=0; i<N/2; i++){
        sum1 += nums[i];
    }
    int sum2=0;
    for(int i=N/2; i<N; i++){
        sum2 += nums[i];
    }
    if(N%2 == 0){
        printf("0 ");
    }
    else{
        printf("1 ");
    }
    printf("%d", sum2-sum1);
    return 0;
}
