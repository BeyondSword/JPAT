#include<iostream>
#include<stdio.h>
#include<cmath>
#include<map>
using namespace std;

const int MAXN=3000;
int K;

int R[MAXN];
int D1[MAXN];
//int D2[MAXN];
map<int, int> D2;

int main(){
    cin >> K;
    for(int i=0; i<K; i++){
        int N;
        cin >> N;
        fill(R, R+MAXN, 0);
        fill(D1, D1+MAXN, 0);
        //fill(D2, D2+MAXN, 0);
        D2.clear();
        int ok=1;
        for(int col=1; col<=N; col++){
            int row;
            cin >> row;
            R[row] ++;
            D1[col+row]++;

            int x = col-row;
            if(!D2.count(x)){
                D2[x] = 1;
            }
            else{
                D2[x] ++;
            }
            if(R[row]>1 || D1[col+row]>1 || D2[x]>1){
                ok=0;
                //break;
            }
        }
        if(ok == 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
