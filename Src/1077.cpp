#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=101;
string S[MAXN];

int main(){
    int N;
    //¶ÁÈë
    cin >> N;
    string buf;
    getline(cin, buf);
    //¼ÇÂ¼×î¶Ì×Ö´®
    int min_size=0x7fffffff;
    for(int i=0; i<N; i++){
        //cin >> S[i];
        getline(cin, S[i]);
        reverse(S[i].begin(), S[i].begin()+S[i].size());
        //S[i].reverse();
        if(min_size > S[i].size()){
            min_size = S[i].size();
        }
    }
    string res;
    for(int i=0; i<min_size; i++){
        char Ch=S[0][i];
        int ok=1;
        for(int j=0; j<N; j++){
            if(Ch != S[j][i]){
                ok=0;
                break;
            }
        }
        if(!ok){
            break;
        }
        else{
            res += Ch;
        }
    }
    if(!res.size()){
        cout << "nai";
    }
    else{
        reverse(res.begin(), res.end());
        cout << res;
    }

    return 0;
}
