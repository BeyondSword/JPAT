#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAXN=100001;

struct treeNode{
    double amount;
    vector<int> childs;
}nodes[MAXN];


int N;
double P,r;
double tot;

void DFS(int root, double rate){
    //Ò¶×Ó
    if(nodes[root].childs.empty()){
        //rate = rate*(1+r/100);
        tot += rate*nodes[root].amount*P;
        return;
    }
    //·ÇÒ¶
    for(int i=0; i<nodes[root].childs.size(); i++){
        DFS(nodes[root].childs[i], rate*(1+r/100));
    }
    return;
}

int main(){
    cin >> N >> P >> r;
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        if(K == 0){
            cin >> nodes[i].amount;
        }
        else{
            for(int j=0; j<K; j++){
                int child;
                cin >> child;
                nodes[i].childs.push_back(child);
            }
        }
    }
    DFS(0, 1.0);
    printf("%.1lf", tot);
    return 0;
}
