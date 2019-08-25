#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXN=2001;
const int MAXK=2001;
int N,K;

map<int, string> indi2name;
map<string, int> name2indi;

bool vis[MAXN];
int weight[MAXN];
int G[MAXN][MAXN];
int index;

int tot_cnt;
//int gang_size[MAXN];

vector<pair<int, int> > gang;

queue<int> q;

//BFS 求解 return cnt record head pair怎么用？？
void BFS(int s){
    int cnt=1;
    int tot_weight=weight[s];
    int head=s;

    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<index; i++){
            if(G[i][node] && G[node][i] && !vis[i]){
                vis[i] = true;
                q.push(i);
                cnt++;
                //cal tot_weight
                tot_weight += weight[i];
                //find head
                if(weight[i] > weight[head]){
                    head = i;
                }
            }
        }
    }
    //a gang
    if(cnt>2 && tot_weight >K*2){
        tot_cnt++;
        pair<int, int> p(head, cnt);
        gang.push_back(p);
    }
}

bool comparison(const pair<int, int> &p1, const pair<int, int> &p2){
    string s1 = indi2name[p1.first];
    string s2 = indi2name[p2.first];
    return s1 < s2;
}


int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        string s1,s2;
        int w;
        int u,v;
        cin >> s1 >> s2 >> w;
        if(!name2indi.count(s1)){
            u = index;
            index ++;
            name2indi[s1] = u;
            indi2name[u] = s1;
        }
        else{
            u = name2indi[s1];
        }
        if(!name2indi.count(s2)){
            v = index;
            index ++;
            name2indi[s2] = v;
            indi2name[v] = s2;
        }
        else{
            v = name2indi[s2];
        }
        //
        weight[u] += w;
        weight[v] += w;
        G[u][v] += w;
        G[v][u] += w;
    }
    //input end
    for(int i=0; i<index; i++){
        if(vis[i] == false){
            BFS(i);
        }
    }
    //output
    sort(gang.begin(), gang.end(), comparison);
    cout << tot_cnt << endl;
    for(int i=0; i<tot_cnt; i++){
        pair<int, int> p = gang[i];
        cout << indi2name[p.first] << " " << p.second << endl;
    }
    return 0;
}
