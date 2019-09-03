#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAXN=100000;

//int hash_table[100000];


int couple[MAXN];
int in_party[MAXN];

int N,M;
int main(){
    fill(couple, couple+MAXN, -1);
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int guest;
        cin >> guest;
        in_party[guest] = 1;
    }

    int lonely = 0;
    vector<int> res;
    for(int i=0; i<MAXN; i++){
        if(in_party[i] == 1){
            if(couple[i]==-1 || !in_party[couple[i]]){
                lonely++;
                res.push_back(i);
            }
        }
    }
    printf("%d\n", lonely);
    for(int i=0; i<res.size(); i++){
        if(i>0)
            printf(" ");
        printf("%05d", res[i]);
    }
    //printf("\n");
    return 0;
}
