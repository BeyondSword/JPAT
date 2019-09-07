#include<iostream>

using namespace std;


int N;
string s;
int main(){
    cin >> N;
    for(int step=0; step<N; step++){
        cin >> s;
        int sum1=0;
        int sum2=0;
        long long sum=0;
        int i=0;
        for(;i<s.size()/2;i++){
            sum1 = sum1*10 + s[i] - '0';
            sum = sum*10 + s[i] - '0';
        }
        for(;i<s.size(); i++){
            sum2 = sum2*10 + s[i] - '0';
            sum = sum*10 + s[i] - '0';
        }
        if(sum1*sum2!=0 && sum % (sum1*sum2) == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
