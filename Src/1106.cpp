#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
using namespace std;

const int INF=0x7fffffff;
int g_deep=INF;
int g_cnt;
double g_price;
const int MAXN=100001;

struct treeNode{
    int val;
    vector<int> childs;
}nodes[MAXN];
int N;
double P,r;
void DFS(int root, int depth, double price){
    //р╤вс
    if(nodes[root].childs.empty()){
        if(depth < g_deep){
            g_deep = depth;
            g_price = price;
            g_cnt = 1;
        }
        else if(depth == g_deep){
            g_cnt ++;
        }
    }
    else{
        for(int i=0; i<nodes[root].childs.size(); i++){
            DFS(nodes[root].childs[i], depth+1, price*(1+r/100));
        }
    }
}

int main(){
    cin >> N >> P >> r;
    int root = 0;
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        for(int j=0; j<K; j++){
            int ch;
            cin >> ch;
            nodes[i].childs.push_back(ch);
        }
    }
    DFS(root, 0, P);
    printf("%.4lf %d", g_price, g_cnt);
    return 0;
}
