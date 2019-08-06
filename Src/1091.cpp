#include<iostream>
#include<queue>
using namespace std;

const int MAXM=1287;
const int MAXN=1287;
const int MAXL=61;

int g_dirx[6] = {1,-1,0,0,0,0};
int g_diry[6] = {0,0,1,-1,0,0};
int g_dirz[6] = {0,0,0,0,1,-1};

int G[MAXL][MAXM][MAXN];
bool vis[MAXL][MAXM][MAXN];

int M,N,L,T;
//t4 t5 不过   1小时 25分
//已pass 注意：三个坐标的对应关系，for循环下标不要搞错
queue<int> q;
//BFS
int BFS(int i, int j,  int k){
    //node n()
    int index = i*M*N + j*N + k;
    q.push(index);
    vis[i][j][k] = true;
    int tot = 1;
    while(!q.empty()){
        index = q.front();
        i = index/(M*N);
        j = index%(M*N)/N;
        k = index%(M*N)%N;
        q.pop();
        //vis[i][j][k] = true;
        int next_i, next_j, next_k;
        for(int m=0; m<6; m++){
            next_i = i+g_dirx[m];
            next_j = j+g_diry[m];
            next_k = k+g_dirz[m];
            if(next_i>=0 && next_i<L && next_j>=0 && next_j < M && next_k>=0 && next_k < N \
               && G[next_i][next_j][next_k] == 1 && vis[next_i][next_j][next_k] == false){
                    vis[next_i][next_j][next_k] = true;
                    tot++;
                    q.push(next_i*M*N+next_j*N+next_k);
            }
        }
    }
    if(tot >= T){
        return tot;
    }
    else{
        return 0;
    }
}

int main(){
    cin >> M >> N >> L >> T;
    for(int i=0; i<L; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                int tmp = 0;
                cin >> tmp;
                G[i][j][k] = tmp;
                vis[i][j][k] = false;
            }
        }
    }
    //input end;
    int g_tot=0;
    for(int i=0; i<L; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                if(vis[i][j][k] == false && G[i][j][k] == 1){
                    g_tot += BFS(i, j, k);
                }
            }
        }
    }
    cout << g_tot;
    return 0;
}
