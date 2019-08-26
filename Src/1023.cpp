#include<iostream>
#include<vector>

using namespace std;

//¼Ó·¨or±¶³Ë

int A_digitCnt[10];
int B_digitCnt[10];

vector<int> double_A(vector<int> &A){
    int ci=0;
    vector<int> B;
    for(int i=0; i<A.size(); i++){
        int digit = ((2*A[i])+ci)%10;
        A_digitCnt[A[i]] ++;
        B_digitCnt[digit] ++;
        B.push_back(digit);
        ci = ((2*A[i])+ci)/10;
    }
    if(ci != 0){
        B.push_back(ci);
    }
    return B;
}

void output(vector<int> &B){
    for(int i=B.size()-1; i>=0; i--){
        cout << B[i];
    }
}


void comparison(vector<int> &A){
    vector<int> B=double_A(A);
    if(A.size() != B.size()){
        cout << "No" << endl;
        output(B);
        return;
    }
    else{
        for(int i=0; i<10; i++){
            if(A_digitCnt[i] != B_digitCnt[i]){
                cout << "No" << endl;
                output(B);
                return;
            }
        }
        cout << "Yes" << endl;
        output(B);
        return;
    }
}

int main(){
    string N;
    cin >> N;
    //reverse
    vector<int> A;
    for(int i=N.size()-1; i>=0; i--){
        A.push_back(N[i]-'0');
    }
    comparison(A);
    return 0;
}
