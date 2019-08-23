#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN=1001;

float A[MAXN];
float B[MAXN];

float res[MAXN];

int K1, K2;
int main(){
    cin >> K1;
    for(int i=0; i<K1; i++){
        int n;
        float a;
        cin >> n >> a;
        A[n] = a;
    }
    cin >> K2;
    for(int i=0; i<K2; i++){
        int n;
        float b;
        cin >> n >> b;
        B[n] = b;
    }

    int cnt = 0;
    for(int i=0; i<MAXN; i++){
        res[i] = A[i] + B[i];
        if(res[i] > 0 || res[i] < 0){
            cnt ++;
        }
    }
    cout << cnt;
    for(int i=MAXN-1; i>=0; i--){
        if(res[i] > 0 || res[i] < 0)
            printf(" %d %.1f", i, res[i]);
    }

    return 0;
}
