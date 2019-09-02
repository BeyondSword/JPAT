#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN=11111;
int N;

struct Family{
    int small_id;
    int size;
    double tot_sets;
    double tot_area;
}fam[MAXN];
int cnt;

struct Node{
    int id;
    double area;
    int sets;
    int exist;
    vector<int> P;
}nodes[MAXN];

int vis[MAXN];

int BFS(int root, double &tot_assets, double &tot_area, int &small_id){
    queue<int> q;
    int tot_num=0;
    q.push(root);
    vis[root] = true;

    small_id = 0x3ffff;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        tot_assets += nodes[n].sets;
        tot_area += nodes[n].area;
        tot_num ++;
        if(n < small_id){
            small_id = n;
        }
        for(int i=0; i<nodes[n].P.size(); i++){
            int v = nodes[n].P[i];
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return tot_num;
}

bool comp(struct Family &A, struct Family &B){
    if(A.tot_area/A.size == B.tot_area/B.size){
        return A.small_id < B.small_id;
    }
    return A.tot_area/A.size > B.tot_area/B.size;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int id, father, mother,k;
        scanf("%d%d%d%d",&id, &father, &mother, &k);
        if(father != -1){
            nodes[id].P.push_back(father);
            nodes[father].P.push_back(id);
        }
        if(mother != -1){
            nodes[id].P.push_back(mother);
            nodes[mother].P.push_back(id);
        }
        nodes[father].exist = nodes[mother].exist = 1;
        for(int j=0; j<k; j++){
            int son;
            scanf("%d", &son);
            nodes[son].P.push_back(id);
            nodes[id].P.push_back(son);
            nodes[son].exist = 1;
        }
        double area;
        int sets;
        cin >> sets >> area;
        nodes[id].sets = sets;
        nodes[id].area = area;
        nodes[id].exist = 1;
    }
    for(int i=0; i<MAXN; i++){
        if(nodes[i].exist && !vis[i]){
            fam[cnt].size = BFS(i, fam[cnt].tot_sets, fam[cnt].tot_area, fam[cnt].small_id);
            cnt ++;
        }
    }
    sort(fam, fam+cnt, comp);
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
        int size = fam[i].size;
        printf("%04d %d %.3lf %.3lf\n", fam[i].small_id, size, fam[i].tot_sets/size, fam[i].tot_area/size);
    }

    return 0;
}
