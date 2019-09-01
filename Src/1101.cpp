#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int nums[MAXN];
int Left[MAXN];
int Right[MAXN];
int N;


int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> nums[i];
    }
    //index=0 sentry
    Left[0] = 0;
    Right[N+1] = 0x7fffffff;

    for(int i=1; i<=N; i++){
        Left[i] = max(Left[i-1], nums[i]);
    }
    for(int i=N; i>=1; i--){
        Right[i] = min(Right[i+1], nums[i]);
    }
    vector<int> res;
    for(int i=1; i<=N; i++){
        if(Left[i] == Right[i] && Left[i] == nums[i]){
            res.push_back(nums[i]);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++){
        if(i>0){
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
    return 0;
}
