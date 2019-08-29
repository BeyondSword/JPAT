#include<iostream>

using namespace std;

const int MAXN=21;
struct treeNode{
    int v;
    int left;
    int right;
    int h;
}nodes[MAXN];

int cnt=0;

int Height(int n){
    return n==-1?0:nodes[n].h;
}

void upH(int n){
    nodes[n].h=max(Height(nodes[n].left), Height(nodes[n].right))+1;
}

int right_rotation(int root){
    int A = root;
    int B = nodes[root].left;
    nodes[A].left = nodes[B].right;
    nodes[B].right = A;
    upH(A);
    upH(B);
    return B;
}

int left_rotation(int root){
    int A = root;
    int B = nodes[root].right;
    nodes[A].right = nodes[B].left;
    nodes[B].left = A;
    upH(A);
    upH(B);
    return B;
}

int left_right_rotation(int root){
    nodes[root].left = left_rotation(nodes[root].left);
    return right_rotation(root);
}

int right_left_rotation(int root){
    nodes[root].right = right_rotation(nodes[root].right);
    return left_rotation(root);
}


int create_tree(int root, int target){
    //insert
    if(root == -1){
        root = cnt;
        cnt++;
        nodes[root].v = target;
        nodes[root].h = 1;
        nodes[root].left = nodes[root].right = -1;
        return root;
    }
    if(target < nodes[root].v){
        nodes[root].left = create_tree(nodes[root].left, target);
    }
    else{
        nodes[root].right = create_tree(nodes[root].right, target);
    }
    //插入完毕
    //左边子树高
    if(Height(nodes[root].left) > Height(nodes[root].right)+1){
        int LL = nodes[nodes[root].left].left;
        int LR = nodes[nodes[root].left].right;
        if(Height(LL) > Height(LR)){
            root = right_rotation(root);
        }
        else{
            root = left_right_rotation(root);
        }
    }
    //右边子树高
    else if(Height(nodes[root].right) > Height(nodes[root].left)+1){
        int RR = nodes[nodes[root].right].right;
        int RL = nodes[nodes[root].right].left;
        if(Height(RR) > Height(RL)){
            root = left_rotation(root);
        }
        else{
            root = right_left_rotation(root);
        }
    }

    //更新树高
    upH(root);
    return root;
}

int N;
int main(){
    cin >> N;
    int root=-1;
    for(int i=0; i<N; i++){
        int target;
        cin >> target;
        root = create_tree(root, target);
    }
    cout << nodes[root].v;
    return 0;
}
