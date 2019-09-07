#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;
const int MAXN=111111;
bool is_prime(int n){
    if(n == 1){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int hash_table[MAXN];

int S,N,M;
int main(){
    cin >> S >> N >> M;
    while(!is_prime(S)){
        S++;
    }
    for(int i=0; i<N; i++){
        int key;
        cin >> key;
        int ok=0;
        for(int i=0; i<=S; i++){
            int pos = (key+i*i)%S;
            if(!hash_table[pos]){
                hash_table[pos] = key;
                ok=1;
                break;
            }
        }
        if(ok == 0){
            printf("%d cannot be inserted.\n", key);
        }
    }

    double tot=0.0;
    for(int i=0; i<M; i++){
        int key;
        cin >> key;
        int j=0;
        for(;j<S;j++){
            int pos = (key+j*j)%S;
            if(hash_table[pos]==key || !hash_table[pos]){
                break;
            }
        }
        tot += j+1;
    }
    printf("%.1f", tot/M);
    return 0;
}
