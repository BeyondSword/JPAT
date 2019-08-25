#include<iostream>

using namespace std;

const int MAXK = 10001;
int dp[MAXK];
int nums[MAXK];
int s[MAXK];
int e[MAXK];

int main(){
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> nums[i];
    }
    //input end
    //check if all neg
    bool all_neg = true;
    dp[0] = nums[0];
    s[0] = 0;
    if(nums[0]>=0)
        all_neg = false;

    for(int i=1; i<K; i++){
        if(nums[i] >= 0){
            all_neg = false;
        }
        if(dp[i-1] + nums[i] >= nums[i]){
            dp[i] = dp[i-1] + nums[i];
            s[i] = s[i-1];
        }
        else{
            dp[i] = nums[i];
            s[i] = i;
        }
    }
    if(all_neg){
        printf("0 %d %d", nums[0], nums[K-1]);
    }
    else{
        int MAX=dp[0];
        int start=0, end=0;
        for(int i=1; i<K; i++){
            if(dp[i] > MAX){
                MAX = dp[i];
                start = s[i];
                end = i;
            }

            /*
            else if(dp[i] == MAX && s[i]+e[i]<=start+end){
                start = s[i];
                end = e[i];
            }*/
        }
        printf("%d %d %d", MAX, nums[start], nums[end]);
    }
    return 0;
}
