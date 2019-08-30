#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAXN=40001;
const int MAXM=101;

struct App{
    int id;
    int Ge;
    int Gi;
    int Gt;
    int choice[5];
    int rank;
}app[MAXN];
int quota[MAXM];
vector<int> accept[MAXM];

bool comparison(struct App &A, struct App &B){
    if(A.Gt == B.Gt){
        return A.Ge > B.Ge;
    }
    return A.Gt > B.Gt;
}

bool same_rank(int school, int cur){
    int size = accept[school].size();
    if(!size){
        return false;
    }
    else{
        return app[accept[school][size-1]].rank == app[cur].rank;
    }

}

bool cmp2(int a, int b){
    return app[a].id < app[b].id;
}

int N,M,K;
int main(){
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        //cin >> quota[i];
        scanf("%d", &quota[i]);
    }
    for(int i=0; i<N; i++){
        scanf("%d%d", &app[i].Ge, &app[i].Gi);
        app[i].Gt = app[i].Ge + app[i].Gi;
        for(int j=0; j<K; j++){
            scanf("%d", &app[i].choice[j]);
        }
        app[i].id = i;
    }
    //input end
    sort(app, app+N, comparison);
    int rank=1;
    for(int i=0; i<N; i++){
        if(i==0){
            app[i].rank = 1;
        }
        else{
            //tie
            if(app[i].Gt==app[i-1].Gt && app[i].Ge == app[i-1].Ge){
                app[i].rank = app[i-1].rank;
            }
            else{
                app[i].rank = rank;
            }
        }

        //admission
        for(int j=0; j<K; j++){
            int school = app[i].choice[j];
            //有配额，接收学生
            if(quota[school] > 0){
                quota[school]--;
                accept[school].push_back(i);
                break;
            }
            //无配额，但上一个接受的学生和这个同rank，无条件接收
            else if(i>0 && same_rank(school, i)){
                quota[school]--;
                accept[school].push_back(i);
                break;
            }
        }
        rank++;
    }
    for(int i=0; i<M; i++){
        sort(accept[i].begin(), accept[i].end(), cmp2);
        for(int j=0; j<accept[i].size(); j++){
            if(j>0)
                printf(" ");
            printf("%d", app[accept[i][j]].id);
        }
        printf("\n");
    }

    return 0;
}
