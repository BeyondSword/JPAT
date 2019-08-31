#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
long long nums[MAXN];
long long p;
int N;
int main(){
    cin >> N >> p;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    sort(nums, nums+N);
    int max_len=0;
    //同向出发
    int lo=0,hi=0;
    while(hi<N&&lo<N&&lo<=hi){
        if(nums[lo]*p >= nums[hi]){
            max_len = max(max_len, hi-lo+1);
            hi++;
        }
        else{
            lo++;
        }
    }
    cout << max_len;
    return 0;
}
