#include<iostream>
#include<queue>
#include<vector>

using namespace std;
//邻接矩阵+优先队列+DFS    未通过样例点4

int Cmax,N,Sp,M;
const int INF = 0x3fffffff;
const int MAXN = 501;
int dp[MAXN];
bool vis[MAXN];
int C[MAXN];
int G[MAXN][MAXN];
int send_num = INF;
int col_num = INF;
vector<int> res;

class comparison{
public:
    bool operator()(int &a, int &b){
        return dp[a]>dp[b];
    }
};
priority_queue<int, vector<int>, comparison> pq;




vector<vector<int> > before;

int djikstra(void){

    //PBMC
    dp[0] = 0;
    pq.push(0);
    for(int i=0; i<N+1; i++){
        int indice = pq.top();
        pq.pop();
        if(dp[indice] == INF){
            break;
        }
        vis[indice] = true;
        for(int j=0; j<N+1; j++){
            //已访问或路径不可达
            if(vis[j]==true || G[indice][j]==INF){
                continue;
            }
            //更新最短路径
            if(dp[j] > dp[indice]+G[indice][j]){
                dp[j] = dp[indice]+G[indice][j];
                //重置路径
                before[j].clear();
                before[j].push_back(indice);
                pq.push(j);
            }
            //更新路径
            else if(dp[j] == dp[indice]+G[indice][j]){
                before[j].push_back(indice);
            }
        }
    }
    return 0;
}



void DFS(int root, int tot, vector<int> &path, int depth){
    //到达起点
    if(root == 0){
        //沿路径遍历
        int col=0;
        int sen=0;
        int perfect = Cmax/2;
        for(int i=path.size()-1; i>=0; i--){
            //少
            int a = C[path[i]]-perfect;
            if(a<0){
                col = col + a;
                if(col < 0){
                    sen = sen - col;
                    col = 0;
                }
            }
            //多
            else{
                col += a;
            }
        }

        path.push_back(0);
        if(sen < send_num){
            send_num = sen;
            col_num = col;
            res = path;
        }
        else if(sen == send_num){
            if(col < col_num){
                col_num = col;
                res = path;
            }
        }
        path.pop_back();
        return;
    }
    //遍历所有路径
    tot += C[root];
    path.push_back(root);
    for(int i=0; i<before[root].size(); i++){
        DFS(before[root][i], tot, path, depth+1);
    }
    path.pop_back();
    return;
}

int main(){

    fill(vis, vis+MAXN, false);
    fill(dp, dp+MAXN, INF);
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            G[i][j] = INF;
        }
    }

    cin >> Cmax >> N >> Sp >> M;
    for(int i=1; i<N+1; i++){
        cin >> C[i];
    }
    for(int i=0; i<M; i++){
        int u,v,len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    //input end
    vector<int> tmp;
    before.resize(N+1, tmp);

    djikstra();

    vector<int> path;
    DFS(Sp, 0, path, 0);

    cout << send_num << " ";
    for(int i=res.size()-1; i>0; i--){
        cout << res[i] << "->";
    }
    cout << res[0] << " " << col_num;

    return 0;
}
