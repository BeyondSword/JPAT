#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<set>
using namespace std;

const int MAXN=50001;

int N,K;
vector<int> v;
//priority_queue<int, less, vector<int> > q;
int g_cnt[MAXN];
int g_index[MAXN];

//间接排
//用插排是否会快

bool larger(int a, int b){
    if(g_cnt[a] == g_cnt[b]){
        return a<b;
    }
    return g_cnt[a]>g_cnt[b];
}

void insert_sort(int pos){
    int indi = pos;
    for(int i=min(K-1, pos-1); i>=0; i--){
        if(larger(v[indi], v[i])){
            g_index[v[indi]] = i;
            g_index[v[i]] = indi;
            swap(v[indi], v[i]);
            indi = i;
        }
        else{
            break;
        }
    }
}


struct Node{
    int val;
    bool operator < (struct Node &A){
        //return g_cnt[A.val] == g_cnt[B.val]?A.val<B.val:g_cnt[A.val]<g_cnt[B.val];
        if(g_cnt[A.val] == g_cnt[val]){
            return val < A.val;
        }
        return g_cnt[A.val] > g_cnt[val];
    }
};
set<Node> s;


int main(){
    scanf("%d%d", &N, &K);
    int num;
    //int cnt=0;
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        /*
        //先输出
        if(v.size()>0){
            //sort(v.begin(), v.end(), cmp);
            //cout << num << ":";
            printf("%d:",num);
            for(int i=0; i<K&&i<v.size(); i++){
                //cout << " " << v[i];
                printf(" %d", v[i]);
            }
            //cout << endl;
            printf("\n");
        }
        */

        iterator::set<node> it = s.find(node{num});
        //再入

        if(g_cnt[num] == 0){
            v.push_back(num);
            g_index[num] = v.size()-1;
        }
        g_cnt[num]++;
        insert_sort(g_index[num]);*/
    }

    return 0;
}
