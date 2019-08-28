#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int N;
string A,B;
vector<char> numA;
vector<char> numB;

void cov(string A, vector<char> &num, int N, int &exp){
    int index=0;

    //跳过前置0
    while(A[index] == '0'){
        index++;
    }
    //停在'.'or数字上 0.000xxx
    if(index<A.size() && A[index] == '.'){
        //pass '.'
        index++;
        //统计exp
        while(index<A.size() && A[index] == '0'){
            exp--;
            index++;
        }
        //全是0
        if(index >= A.size()){
            exp=0;
            return;
        }
        while(index<A.size()){
            num.push_back(A[index]);
            index++;
        }
    }
    else{
        //整数部分，影响exp
        while(index<A.size()&&A[index] != '.'){
            num.push_back(A[index]);
            index++;
            exp++;
        }

        //跳过'.'
        index++;
        //处理小数部分
        while(num.size()<N&&index<A.size()){
            num.push_back(A[index]);
            index++;
        }
    }
    return;
}

void out(vector<char> &num, int exp){
    //if(num.size()==0){
        //printf("0");
    //}
    //else{
        cout << "0.";
    //}

    int i;
    for(i=0; i<num.size()&&i<N; i++){
        cout << num[i];
    }
    //补尾0
    while(i<N){
        i++;
        cout << "0";
    }

    //exp
    cout << "*10^" << exp;
    return;
}

int main(){
    cin >> N;
    cin >> A >> B;
    int exp_a=0,exp_b=0;
    cov(A, numA, N, exp_a);
    cov(B, numB, N, exp_b);
    //转换完毕,比较
    int ok=(exp_a == exp_b);
    //比较前n位
    int i;
    for(i=0; i<N&&i<min(numA.size(),numB.size()); i++){
        if(numA[i] != numB[i]){
            ok=0;
            break;
        }
    }
    //当n很大，可以比较所有位,在共同位上A、B两数相等 但多的位不等
    if(i<N&&numA.size()!=numB.size()){
        ok=0;
    }

    if(ok == 1){
        cout << "YES ";
        out(numA, exp_a);
    }
    else{
        cout << "NO ";
        out(numA, exp_a);
        cout << " ";
        out(numB, exp_b);
    }
    return 0;
}
