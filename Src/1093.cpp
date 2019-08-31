#include<iostream>

using namespace std;

const int mod=1000000007;


long long pat_cnt;
long long at_cnt;
long long t_cnt;
int main(){
    string s;
    cin >> s;
    //´ÓºóÍùÇ°
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == 'T'){
            t_cnt++;
        }
        else if(s[i] == 'A'){
            at_cnt += t_cnt;
            at_cnt %= mod;
        }
        else if(s[i] == 'P'){
            pat_cnt += at_cnt;
            pat_cnt %= mod;
        }
    }
    cout << pat_cnt;
    return 0;
}
