#include<iostream>

using namespace std;

const int MAXN=501;
const int INF=0x3fffffff;

int N,M;
int G[MAXN][MAXN];

int degree[MAXN];

int father[MAXN];

int find_father(int a){
    if(father[a] == -1){
        return a;
    }
    int fa = find_father(father[a]);
    father[a] = fa;
    return fa;
}

void Union(int a, int b){
    int fa = find_father(a);
    int fb = find_father(b);
    if(fa != fb)
        father[fa] = fb;
}


int main(){
    cin >> N >> M;
    for(int i=0; i<MAXN; i++){
        fill(G[i], G[i]+MAXN, INF);
    }
    fill(father, father+MAXN, -1);
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        degree[u]++;
        degree[v]++;
        Union(u,v);
    }
    int tree_cnt = 0;
    for(int i=1; i<=N; i++){
        if(father[i] == -1)
            tree_cnt++;
    }

    int odd=0, even=0;
    for(int i=1; i<=N; i++){
        if(i>1){
            cout << " ";
        }
        cout << degree[i];
        if(degree[i]%2 == 0){
            even ++;
        }
        else{
            odd++;
        }
    }
    cout << endl;

    //保证联通
    if(tree_cnt != 1){
        cout << "Non-Eulerian";
    }
    else{
        if(odd == 0){
            cout << "Eulerian";
        }
        else if(odd == 2){
            cout << "Semi-Eulerian";
        }
        else{
            cout << "Non-Eulerian";
        }
    }
    return 0;
}
