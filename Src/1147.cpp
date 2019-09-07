#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
const int MAXM=101;
const int MAXN=1001;


int M,N;
int tree[MAXN];

bool is_min;
bool is_Heap;

vector<int> post;

bool judge(int root){
    bool valid;
    //叶子
    if(2*root > N){
        post.push_back(tree[root]);
        return true;
    }
    //仅左子树，最后一个带叶节点
    if(2*root+1 > N){
        if(is_min){
            valid = tree[root] < tree[root*2];
        }
        else{
            valid = tree[root] > tree[root*2];
        }
        //递归左子树
        valid &= judge(2*root);
    }
    //双子树
    else{
        if(is_min){
            valid = tree[root] < min(tree[root*2], tree[root*2+1]);
        }
        else{
            valid = tree[root] > max(tree[root*2], tree[root*2+1]);
        }
        valid &= judge(2*root);
        valid &= judge(2*root+1);
    }
    post.push_back(tree[root]);
    return valid;
}

int main(){
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &tree[j]);
        }
        //输入完毕
        post.clear();
        //先预设大还是小
        if(tree[1] > tree[2]){
            is_min = false;
        }
        else{
            is_min = true;
        }
        if(judge(1)){
            if(is_min){
                printf("Min Heap\n");
            }
            else{
                printf("Max Heap\n");
            }
        }
        else{
            printf("Not Heap\n");
        }
        //output
        for(int j=0; j<post.size(); j++){
            if(j>0){
                printf(" ");
            }
            printf("%d", post[j]);
        }
        printf("\n");
    }
    return 0;
}
