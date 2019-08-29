#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

typedef struct BigNum{
    vector<int> digits;
    int flag;
    BigNum(){
        flag = 0;
    }
}bigNum;

int T;

void cov(const string &num, bigNum &A){
    int cnt=0;
    if(num[0] == '-'){
        cnt++;
        A.flag=1;
    }
    while(cnt<num.size()){
        A.digits.push_back(num[cnt]-'0');
        cnt++;
    }
    return;
}

//正数相加
void add(bigNum &A, bigNum &B, bigNum &C){
    int ci=0;
    int i;
    for(i=0; i<min(A.digits.size(), B.digits.size()); i++){
        int sum = A.digits[i]+B.digits[i]+ci;
        ci = sum/10;
        C.digits.push_back(sum%10);
    }
    while(i<A.digits.size()){
        int sum = A.digits[i]+ci;
        C.digits.push_back(sum%10);
        ci = sum/10;
        i++;
    }
    while(i<B.digits.size()){
        int sum = B.digits[i]+ci;
        C.digits.push_back(sum%10);
        ci = sum/10;
        i++;
    }
    if(ci){
        C.digits.push_back(ci);
    }
    return;
}

//比较,不出现全负数,实现小于
bool comparison(bigNum A, bigNum B){
    if(A.flag){
        return true;
    }
    if(B.flag){
        return false;
    }
    //全为非负
    if(A.digits.size()==B.digits.size()){
        for(int i=0; i<min(A.digits.size(), B.digits.size()); i++){
            if(A.digits[i] != B.digits[i]){
                return A.digits[i] < B.digits[i];
            }
        }
    }
    return A.digits.size() < B.digits.size();
}


int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        string s_a,s_b,s_c;
        bigNum A,B,C,SUM;
        int ok=0;
        cin >> s_a >> s_b >> s_c;
        cov(s_a, A);
        cov(s_b, B);
        cov(s_c, C);
        //A>=0 B>=0
        if(!A.flag && !B.flag){
            add(A,B,SUM);
            ok = comparison(C,SUM);
        }
        else if(A.flag && B.flag){
            A.flag = A.flag-1;
            B.flag = B.flag-1;
            C.flag = C.flag-1;
            add(A,B,SUM);
            ok = comparison(SUM, C);
        }
        else{
            //B < 0
            if(B.flag){
                swap(A,B);
            }
            //A < 0
            if(A.flag){
                //C < 0   (-C) + B > (-A)
                if(C.flag){
                    C.flag = 1-C.flag;
                    A.flag = 1-A.flag;
                    add(C, B, SUM);
                    ok = comparison(A, SUM);
                }
                //C >= 0   B > (-A) + C
                else{
                    A.flag = 1-A.flag;
                    add(A, C, SUM);
                    ok = comparison(SUM, B);
                }
            }
            /*
            //B < 0
            else{
                //C < 0
                if(C.flag){

                }
                else{

                }
            }*/
        }
        if(ok)
            printf("Case #%d: true\n", i+1);
        else
            printf("Case #%d: false\n", i+1);
    }
    return 0;
}
