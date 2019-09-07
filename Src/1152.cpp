#include<cmath>
#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int L,K;
long long num;
string s_num;

bool is_prime(long long num){
    if(num == 1 || num == 0){
        return false;
    }
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &L, &K);
    cin >> s_num;
    if(L < K){
        printf("404");
        return 0;
    }
    //init
    for(int i=0; i<K; i++){
        num = num*10 + s_num[i] - '0';
    }
    int exp=1;
    for(int i=1; i<K; i++){
        exp*=10;
    }

    int i=0, j=K-1;
    int ok=0;
    while(j < s_num.size()){
        if(is_prime(num)){
            ok=1;
            break;
        }
        num -= exp*(s_num[i]-'0');
        i++;
        j++;
        if(j < s_num.size()){
            num = num*10 + (s_num[j]-'0');
        }
    }
    if(!ok){
        printf("404");
    }
    else{
        //printf("%ld", num);
        //cout << num;
        cout << s_num.substr(i, K);
    }
    return 0;
}
