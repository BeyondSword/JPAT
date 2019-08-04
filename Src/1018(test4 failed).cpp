#include<iostream>
#include<queue>
#include<vector>

using namespace std;
//�ڽӾ���+���ȶ���+DFS    δͨ��������4

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
            //�ѷ��ʻ�·�����ɴ�
            if(vis[j]==true || G[indice][j]==INF){
                continue;
            }
            //�������·��
            if(dp[j] > dp[indice]+G[indice][j]){
                dp[j] = dp[indice]+G[indice][j];
                //����·��
                before[j].clear();
                before[j].push_back(indice);
                pq.push(j);
            }
            //����·��
            else if(dp[j] == dp[indice]+G[indice][j]){
                before[j].push_back(indice);
            }
        }
    }
    return 0;
}



void DFS(int root, int tot, vector<int> &path, int depth){
    //�������
    if(root == 0){
        //��·������
        int col=0;
        int sen=0;
        int perfect = Cmax/2;
        for(int i=path.size()-1; i>=0; i--){
            //��
            int a = C[path[i]]-perfect;
            if(a<0){
                col = col + a;
                if(col < 0){
                    sen = sen - col;
                    col = 0;
                }
            }
            //��
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
    //��������·��
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
