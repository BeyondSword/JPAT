#include<iostream>
#include<vector>
using namespace std;

const int MAXN=100001;
int num_hash[100];

int N;

int digit_sum(string &s){
    int sum=0;
    for(int i=0; i<s.size(); i++){
        sum += s[i] - '0';
    }
    return sum;
}

int g_cnt;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        int sum = digit_sum(str);
        num_hash[sum]++;
        if(num_hash[sum] == 1){
            g_cnt++;
        }
    }
    //output
    cout << g_cnt << endl;
    int first = 1;
    for(int i=0; i<100; i++){
        if(num_hash[i]>=1){
            if(!first){
                cout << " ";
            }
            cout << i;
            first = 0;
        }
    }

    return 0;
}
