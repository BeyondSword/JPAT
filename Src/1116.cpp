#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

const int MAXN=10001;

int checked[MAXN];
int not_prime[MAXN];

int N,K;

void pre(){
    not_prime[1] = 1;
    for(int i=2; i<MAXN; i++){
        if(!not_prime[i]){
            for(int j=i*i; j<MAXN; j+=i){
                not_prime[j] = 1;
            }
        }
    }

}

int main(){
    pre();
    cin >> N;
    for(int i=1; i<=N; i++){
        int id;
        cin >> id;
        checked[id] = i;
    }
    cin >> K;
    for(int i=0; i<K; i++){
        int q;
        cin >> q;
        int rank = checked[q];

        printf("%04d: ", q);
        checked[q] = -1;
        if(rank == 0){
            cout << "Are you kidding?" << endl;
            checked[q] = 0;
        }
        else if(rank == -1){
            cout << "Checked" << endl;
        }
        else if(rank == 1){
            cout << "Mystery Award" << endl;
        }
        else if(!not_prime[rank]){
            cout << "Minion" << endl;
        }
        else{
            cout << "Chocolate" << endl;
        }

    }
    return 0;
}
