#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=201;
const int INF=0x7fffffff;
int G[MAXN][MAXN];
int vis[MAXN];
int Nv,Ne;
int in[MAXN];
vector<int> v;

void judge(){
    int is_clique=1;
    int maximal=1;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(j==i)
                continue;
            if(G[v[i]][v[j]] == INF){
                is_clique=0;
                break;
            }
        }
        if(!is_clique){
            break;
        }
    }

    if(!is_clique){
        cout << "Not a Clique" << endl;
        return;
    }
    //≈–∂œ «∑Òmax
    for(int i=1; i<=Nv; i++){
        if(in[i]){
            continue;
        }
        int ok=1;
        for(int j=0; j<v.size(); j++){
            if(G[i][v[j]] == INF){
                ok=0;
                break;
            }
        }
        if(ok == 1){
            maximal=0;
            break;
        }
    }
    if(!maximal){
        printf("Not Maximal\n");
    }
    else{
        printf("Yes\n");
    }
    return;
}

int main(){
    cin >> Nv >> Ne;
    for(int i=0; i<MAXN; i++){
        fill(G[i], G[i]+MAXN, INF);
    }
    for(int i=0; i<Ne; i++){
        int u,v;
        cin >> u >> v;
        G[u][v]=G[v][u]=1;
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        int k=0;
        cin >> k;
        v.clear();
        fill(in, in+MAXN, 0);
        for(int j=0; j<k; j++){
            int n;
            cin >> n;
            v.push_back(n);
            in[n]=1;
        }
        // ‰»ÎΩ· ¯
        //œ»≈–∂œclique
        judge();
    }
    return 0;
}
