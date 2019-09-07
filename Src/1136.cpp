#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


string num;

vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    int ci=0,sum=0;
    int i;
    for(i=0; i<A.size()&&i<B.size(); i++){
        sum=A[i]+B[i]+ci;
        C.push_back(sum%10);
        ci = sum/10;
    }
    //考虑没加完的位
    for(;i<A.size();i++){
        sum = A[i]+ci;
        C.push_back(sum%10);
        ci = sum/10;
    }
    for(;i<B.size();i++){
        sum = B[i]+ci;
        C.push_back(sum%10);
        ci = sum/10;
    }
    if(ci>0){
        C.push_back(ci);
    }
    return C;
}

bool is_pal(vector<int> &A){
    for(int i=0; i<A.size(); i++){
        if(A[i] != *(A.end()-i-1)){
            return false;
        }
    }
    return true;
}

void out(vector<int> &A){
    for(int i=A.size()-1; i>=0; i--){
        cout << A[i];
    }
}
int main(){
    cin >> num;
    vector<int> A;
    for(int i=0; i<num.size(); i++){
        A.push_back(num[i] - '0');
    }
    if(is_pal(A)){
        cout << num << " is a palindromic number.";
        return 0;
    }
    reverse(A.begin(), A.end());
    vector<int> B;
    vector<int> C;
    for(int i=0; i<10; i++){
        B=A;
        reverse(B.begin(), B.end());
        C=add(A,B);
        out(A);
        cout << " + ";
        out(B);
        cout << " = ";
        out(C);
        cout << endl;
        if(is_pal(C)){
            out(C);
            cout << " is a palindromic number." << endl;
            return 0;
        }
        A = C;
    }
    printf("Not found in 10 iterations.");
    return 0;
}
