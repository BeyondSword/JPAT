#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=100001;


struct Person{
    int type;
    int ID;
    int v_grade;
    int t_grade;
    int tot;
}per[MAXN];

bool comparison(struct Person &A, struct Person &B){
    if(A.type == B.type){
        if(A.tot == B.tot){
            if(A.v_grade == B.v_grade){
                return A.ID < B.ID;
            }
            return A.v_grade > B.v_grade;
        }
        return A.tot>B.tot;
    }
    return A.type < B.type;
}

int cnt;
int N,L,H;
int main(){
    cin >> N >> L >> H;
    for(int i=0; i<N; i++){
        int v,t,id,type;
        scanf("%d%d%d", &id, &v, &t);
        if(v<L || t <L){
            continue;
        }
        int tot=v+t;
        if(v>=H&&t>=H){
            type=0;
        }
        else if(v>=H&&t<H){
            type=1;
        }
        else if(v<H&&t<H&&v>=t){
            type=2;
        }
        else{
            type=3;
        }
        per[cnt].type = type;
        per[cnt].ID=id;
        per[cnt].v_grade=v;
        per[cnt].t_grade=t;
        per[cnt].tot = tot;
        cnt++;
    }
    //input end
    sort(per, per+cnt, comparison);
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
        printf("%08d %d %d\n", per[i].ID, per[i].v_grade, per[i].t_grade);
    }
    return 0;
}
