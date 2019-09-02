#include<iostream>

using namespace std;

const int MAXN=21;
int N;

struct treeNode{
    int key;
    int left;
    int right;
}nodes[MAXN];
int not_root[MAXN];

int trees[MAXN*2+1];

// pos 1~MAXN+1
void create_tree(int root, int pos){
    if(pos > N+1 || root == -1){
        return;
    }
    trees[pos] = nodes[root].key;
    create_tree(nodes[root].left, pos*2);
    create_tree(nodes[root].right, pos*2+1);
    return;
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string s[2];
        for(int k=0; k<2; k++){
            cin >> s[k];
            int ch;
            if(s[k][0] == '-'){
                ch = -1;
            }
            else{
                int sum=0;
                for(int j=0; j<s[k].size(); j++){
                    sum = sum*10+s[k][j]-'0';
                }
                ch = sum;
                not_root[ch] = 1;
            }
            if(k==0){
                nodes[i].left = ch;
            }
            else{
                nodes[i].right = ch;
            }
            nodes[i].key = i;
        }
    }
    //input end
    int root = 0;
    //找根
    for(int i=0; i<N; i++){
        if(not_root[i] == 0){
            root = i;
        }
    }
    //根据完全二叉建树
    fill(trees, trees+N+1, -1);
    create_tree(root, 1);
    int ok=1;
    for(int i=1; i<=N; i++){
        if(trees[i] == -1){
            ok=0;
            break;
        }
    }
    //失败
    if(ok == 0){
        cout << "NO" << " " << root;
    }
    //成功
    else{
        cout << "YES" << " " << trees[N];
    }

    return 0;
}
