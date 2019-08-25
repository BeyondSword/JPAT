#include<iostream>
#include<vector>

using namespace std;

vector<long long> conv(long long N, long long ra){
    vector<long long> nums;
    while(N>0){
        nums.push_back(N%ra);
        N /= ra;
    }
    return nums;
}

bool comparison(vector<long long> &nums){
    int low = 0;
    int hi = nums.size()-1;
    while(low < hi){
        if(nums[low] != nums[hi]){
            return false;
        }
        low++;
        hi--;
    }
    return true;
}

long long N,b;
int main(){
    cin >> N >> b;
    vector<long long> nums = conv(N, b);
    if(comparison(nums)){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" << endl;
    }
    for(int i=nums.size()-1; i>=0; i--){
        if(i<nums.size()-1){
            cout << " ";
        }
        cout << nums[i];
    }
    return 0;
}


