#include<iostream>
#include<vector>

using namespace std;
const int MAXN=1000001;

int p_hash[MAXN];
void pre(){
    for(int i=2; i<MAXN; i++){
        //prime
        if(p_hash[i] == 0){
            for(int j=i*2; j<MAXN; j+=i){
                p_hash[j] = 1;
            }
        }
    }
}

vector<int> convert(int N, int radix){
    vector<int> nums;
    while(N>0){
        nums.push_back(N%radix);
        N/=radix;
    }
    return nums;
}

bool comparison(vector<int> nums, int radix, int N){
    int sum1=0;
    int indi=0;
    //reverse »•«∞÷√0
    /*
    while(indi<nums.size() && nums[indi]==0){
        indi++;
    }*/
    for(int i=indi; i<nums.size(); i++){
        sum1 = sum1*radix + nums[i];
    }
    if(N==1 || sum1==1){
        return false;
    }
    return p_hash[N]==0 && p_hash[sum1]==0;
}


int main(){
    pre();
    while(1){
        int N;
        int radix;
        cin >> N;
        if(N<0){
            break;
        }
        cin >> radix;
        vector<int> nums = convert(N, radix);
        if(comparison(nums, radix, N)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
