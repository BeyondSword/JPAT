#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<stdio.h>

using namespace std;

//test 2 fail => priority_queue has problem

const int MAXN=202;
const int INF=0x3fffffff;
int string_hash(string &s){
    int num=0;
    for(int i=0; i<s.size(); i++){
        num = num*26+s[i]-'A';
    }
    return num;
}
int str2indi[26*26*26+1];

string indi2city[MAXN];
int dp[MAXN];
int Hap[MAXN];
int G[MAXN][MAXN];
int vis[MAXN];

int max_hap[MAXN];
int city_num[MAXN];
int routes[MAXN];

int before[MAXN];

class comparison{
public:
    bool operator()(int &a, int &b){
        return dp[a] > dp[b];
    };
};

priority_queue<int, vector<int>, comparison> pq;

int index=0;

int N,K;
string start_city;

void dijkstra(int s){
    dp[s] = 0;
    pq.push(s);
    routes[s] = 1;

    for(int i=0;i<N;i++){
        //int indice = pq.top();
        //pq.pop();
        //if(dp[indice] == INF){
            //break;
        //}

        //do not use priority queue
        int indice = -1;
        int Min  = INF;
        for(int j=0; j<N; j++){
            if(vis[j]==false&&dp[j] < Min){
                Min = dp[j];
                indice = j;
            }
        }

        if(indice == -1){
            break;
        }
        vis[indice] = true;
        for(int j=0; j<N; j++){
            if(vis[j]==true||G[indice][j]==INF){
                continue;
            }
            if(dp[j] > dp[indice]+G[indice][j]){
                //pq.push(j);
                dp[j] = dp[indice] + G[indice][j];

                routes[j] = routes[indice];
                max_hap[j] = max_hap[indice] + Hap[j];
                city_num[j] = city_num[indice] + 1;
                before[j]=indice;
            }
            else if(dp[j] == dp[indice] + G[indice][j]){
                routes[j] += routes[indice];
                if(max_hap[j] < max_hap[indice]+Hap[j]){
                    max_hap[j] = max_hap[indice]+Hap[j];
                    before[j] = indice;
                    city_num[j] = city_num[indice] + 1;
                }
                else if(max_hap[j] == max_hap[indice]+Hap[j]&&city_num[j]>city_num[indice]+1){
                    city_num[j] = city_num[indice] + 1;
                    before[j] = indice;
                }
            }
        }
    }
}


int main(){
    fill(dp, dp+MAXN, INF);
    fill(G[0], G[0]+MAXN*MAXN, INF);
    fill(vis, vis+MAXN, false);
    //fill(Hap, Hap+MAXN, 0);
    fill(before, before+MAXN, -1);

    cin >> N >> K;
    cin >> start_city;
    indi2city[index] = start_city;
    str2indi[string_hash(start_city)] = index;
    index++;

    for(int i=0; i<N-1; i++){
        string city;
        int happy;
        cin >> city >> happy;
        indi2city[index] = city;
        str2indi[string_hash(city)] = index;
        Hap[index] = happy;
        index++;
    }
    for(int i=0; i<K; i++){
        string c1, c2;
        int dist;
        cin >> c1 >> c2 >> dist;
        int u = str2indi[string_hash(c1)];
        int v = str2indi[string_hash(c2)];
        G[u][v] = G[v][u] = dist;
    }
    //input end;
    dijkstra(0);

    vector<int> res;
    string tmp = "ROM";
    int dst = str2indi[string_hash(tmp)];
    int node = dst;
    while(node != -1){
        res.push_back(node);
        node = before[node];
    }
    printf("%d %d %d %d\n", routes[dst], dp[dst], max_hap[dst], max_hap[dst]/city_num[dst]);
    for(int i=res.size()-1; i>=0; i--){
        cout << indi2city[res[i]];
        if(i>0){
            cout << "->";
        }
    }
    return 0;
}
