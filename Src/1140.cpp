#include<iostream>
#include<vector>

using namespace std;

int D,N;
int main(){
    cin >> D >> N;
    vector<int> v(1,D);
    vector<int> res;
    int cur;
    int cnt=0;
    for(int step=1; step<N; step++){
        //sentry
        v.push_back(-1);
        for(int i=0; i<v.size()-1;i++){
            cur = v[i];
            cnt++;
            if(v[i+1] != v[i]){
                res.push_back(cur);
                res.push_back(cnt);
                cnt=0;
            }
        }
        v = res;
        res.clear();
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    return 0;
}
