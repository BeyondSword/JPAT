#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=1001;

int nums[MAXN];
int nodes[MAXN];
int N;

//ÖÐÐò
void DFS(int root, int &cur){
    //³¬¹ý·¶Î§
    if(root > N){
        return;
    }
    DFS(2*root, cur);
    nodes[root] = nums[cur];
    cur++;
    DFS(2*root+1, cur);
    return;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    sort(nums, nums+N);
    int cur=0;
    DFS(1, cur);
    for(int i=1; i<N+1; i++){
        if(i>1){
            cout << " ";
        }
        cout << nodes[i];
    }
    return 0;
}
