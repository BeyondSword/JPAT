#include<iostream>
#include<vector>

using namespace std;

string C[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    string N;
    cin >> N;
    if(N == "0"){
        cout << C[0];
        return 0;
    }

    int sum=0;
    for(int i=0; i<N.size(); i++){
        sum += N[i]-'0';
    }
    //get a sum
    vector<int> digits;
    while(sum!=0){
        digits.push_back(sum%10);
        sum/=10;
    }

    //reverse
    for(int i=digits.size()-1; i>=0; i--){
        if(i < digits.size()-1){
            cout << " ";
        }
        cout << C[digits[i]];
    }
    return 0;
}
