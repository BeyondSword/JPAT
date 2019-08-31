#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=100011;
double P,r;
int N;

struct treeNode{
    vector<int> childs;
}nodes[MAXN];


int g_depth;
int g_cnt;
double g_price;

void DFS(int root, int depth, double price){
    if(nodes[root].childs.empty()){
        if(depth > g_depth){
            g_price = price;
            g_cnt = 1;
            g_depth = depth;
        }
        else if(depth == g_depth){
            g_price = price;
            g_cnt ++;
        }
        return;
    }

    for(int i=0; i<nodes[root].childs.size(); i++){
        DFS(nodes[root].childs[i], depth+1, price*(1+r/100));
    }
    return;
}

int main(){
    cin >> N >> P >> r;
    int root=-1;
    for(int i=0; i<N; i++){
        int father;
        cin >> father;
        if(father != -1){
            nodes[father].childs.push_back(i);
        }
        else if(root == -1){
            root = i;
        }
    }
    //if(root == -1){
        //printf("%.2lf %d", P, 0);
    //}

    DFS(root, 0, P);
    printf("%.2lf %d", g_price, g_cnt);
    return 0;
}
