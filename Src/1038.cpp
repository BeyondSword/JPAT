#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=10001;

string seg[MAXN];
int N;

bool comparison(const string &A, const string &B){
    string S1 = A+B;
    string S2 = B+A;
    for(int i=0; i<A.size()+B.size(); i++){
        if(S1[i]<S2[i]){
            return true;
        }
        else if(S1[i]>S2[i]){
            return false;
        }
    }
    //两种接法一样长
    return A.size()<B.size();
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> seg[i];
    }
    //input end
    sort(seg, seg+N, comparison);

    //output
    int ok=0;
    for(int i=0; i<N; i++){
        if(ok == 0){
            //去前置0
            int first=0;
            while(first<seg[i].size()&&seg[i][first]=='0'){
                first++;
            }
            //不全为0输出子串
            if(first < seg[i].size()){
                ok=1;
                cout << seg[i].substr(first, seg[i].size()-first);
            }
        }
        else{
            cout << seg[i];
        }
    }

    //全为0，什么都没输出
    if(ok == 0){
        cout << "0";
    }
    return 0;
}
