#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

const int MAXN=31;

struct treeNode{
    int val;
    int left;
    int right;
    int height;
    bool is_blanc;
    bool is_red;
}nodes[MAXN];
int g_cnt;

int H(int root){
    return root==-1?1:nodes[root].height;
}

int Insert(int root, int val, bool &valid){
    //插入
    if(root == -1){
        root = g_cnt;
        g_cnt++;
        nodes[root].val = abs(val);
        nodes[root].is_red = (val<0);
        nodes[root].left = nodes[root].right = -1;
        nodes[root].is_blanc = true;
        //nodes[root].height = 1;
        if(nodes[root].is_red == true){
            nodes[root].height = 1;
        }
        else{
            nodes[root].height = 2;
        }
        return root;
    }

    if(abs(val) < nodes[root].val){
        nodes[root].left = Insert(nodes[root].left, val, valid);
    }
    else{
        nodes[root].right = Insert(nodes[root].right, val, valid);
    }
    //插入结束
    //先判断是否有连续的红节点
    int L = nodes[root].left;
    int R = nodes[root].right;

    if(valid == false){
        return root;
    }
    if(nodes[root].is_red == true){
        //有连续红
        if((L!=-1&&nodes[L].is_red == true)||(R!=-1&&nodes[R].is_red == true)){
            valid = false;
        }
        else{
            valid = true;
        }
    }
    //判断平衡性
    if(nodes[root].is_red == true){
        nodes[root].height = max(H(L),H(R));
    }
    else{
        nodes[root].height = max(H(L),H(R)) + 1;
    }
    if(H(L) == H(R)){
        nodes[root].is_blanc = true;
    }
    else{
        nodes[root].is_blanc = false;
    }
    return root;
}

int K,N;
int main(){
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        scanf("%d", &N);
        int root = -1;
        g_cnt = 0;
        bool valid = true;
        for(int j=0; j<N; j++){
            int val;
            scanf("%d", &val);
            if(valid == false){
                continue;
            }
            root = Insert(root, val, valid);
        }
        if(valid == false || nodes[root].is_red == true){
            printf("No\n");
            continue;
        }
        //每个点都平衡
        int ok=1;
        for(int j=0; j<g_cnt; j++){
            if(nodes[j].is_blanc == false){
                ok = 0;
                printf("No\n");
                break;
            }
        }
        if(1 == ok){
            printf("Yes\n");
        }
    }
    return 0;
}
