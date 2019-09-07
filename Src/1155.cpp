#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAXN=1001;

int tree[MAXN];


int N;

bool is_Heap;
bool is_min;

vector<vector<int> > res;
void check(int root, vector<int> &path){
    if(root > N){
        return;
    }
    path.push_back(tree[root]);
    if(is_min){
        if(path.size()>1 && path[path.size()-1] < path[path.size()-2]){
            is_Heap = false;
        }
    }
    else{
        if(path.size()>1 && path[path.size()-1] > path[path.size()-2]){
            is_Heap = false;
        }
    }
    //р╤вс
    if(2*root > N){
        res.push_back(path);
        path.pop_back();
        return;
    }
    check(2*root+1, path);
    check(2*root, path);

    path.pop_back();
    return;
}

void out(){
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            if(j>0){
                cout << " ";
            }
            cout << res[i][j];
        }
        cout << endl;
    }

}

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &tree[i]);
    }
    //input end
    if(tree[1] > tree[2]){
        is_min = false;
    }
    else{
        is_min = true;
    }
    is_Heap = true;
    //output
    vector<int> path;
    check(1, path);
    out();
    if(!is_Heap){
        cout << "Not Heap";
    }
    else{
        if(is_min){
            cout << "Min Heap";
        }
        else{
            cout << "Max Heap";
        }
    }
    return 0;
}
