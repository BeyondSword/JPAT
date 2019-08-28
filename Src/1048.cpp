#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=100001;

int nums[MAXN];
int N,M;
//¾­µäË«Ö¸Õë
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    //input end
    sort(nums, nums+N);
    int i=0, j=N-1;
    int ok=0;
    while(i<j){
        if(nums[i]+nums[j] == M){
            ok=1;
            break;
        }
        else if(nums[i]+nums[j] > M){
            j--;
        }
        else{
            i++;
        }
    }

    if(!ok){
        cout << "No Solution";
    }
    else{
        cout << nums[i] << " " << nums[j];
    }

    return 0;
}
