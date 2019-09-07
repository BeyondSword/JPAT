#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=1001;


struct Edge{
    int in;
    int out;
    vector<int> v;
}edge[MAXN];

//int in[MAXN];
vector<int> e(MAXN, 0);
vector<int> res;
int N,M;
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int S,D;
        cin >> S >> D;
        edge[S].out++;
        edge[S].v.push_back(D);
        edge[D].in++;
        e[D]++;
    }
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        vector<int> in=e;
        int ok=1;
        for(int j=0; j<N; j++){
            int vertex;
            cin >> vertex;
            if(ok == 0){
                continue;
            }
            if(in[vertex] != 0){
                ok=0;
            }
            else{
                for(int k=0; k<edge[vertex].v.size(); k++){
                    in[edge[vertex].v[k]]--;
                }
            }
        }
        //judge
        if(ok == 0){
            res.push_back(i);
        }
    }
    for(int i=0; i<res.size(); i++){
        if(i>0){
            cout << " ";
        }
        cout << res[i];
    }
    return 0;
}
