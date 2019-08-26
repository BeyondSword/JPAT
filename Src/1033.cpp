#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

const int MAXN=501;
struct station{
    float price;
    int dist;
}st[MAXN];

bool comparison(struct station &A, struct station &B){
    return A.dist < B.dist;
}

//增加一个油站表示终点
int Cmax, D, Davg, N;
int INF = 10000000.0;
int main(){
    cin >> Cmax >> D >> Davg >> N;
    int start_st=0;
    for(int i=0; i<N; i++){
        cin >> st[i].price >> st[i].dist;
        //起始位置必须有油站
        if(st[i].dist == 0){
            start_st=1;
        }
    }
    st[N].dist = D;

    if(start_st==0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    sort(st, st+N+1, comparison);
    float max_dist = Cmax*Davg;

    float cap=0;
    int loc=0;
    float tot_amount=0.0;
    int ok=1;
    //loc==N时已经到达终点了
    while(loc<N){
        //遍历所有可达节点
        int cheaper_loc = -1;
        int st_exist = 0;
        int i;
        for(i=loc+1; st[loc].dist+max_dist>=st[i].dist&&i<=N; i++){
            //距离内有油站
            st_exist=1;
            //找到更便宜的油站，先开到该油站
            if(st[i].price <= st[loc].price){
                cheaper_loc = i;
                //计算开到目标油站需要的油
                float need_fuel = (float)(st[i].dist-st[loc].dist)/(float)Davg;
                //油箱里的油足够，不需要再加
                if(cap >= need_fuel){
                    cap -= need_fuel;
                }
                //需要加油
                else{
                    tot_amount += (need_fuel-cap)*st[loc].price;
                    cap = 0;
                }
                loc = i;
                break;
            }
        }
        //找不到更便宜的油站,但有油站可达,则开到最远油站,并在当前油站加满油
        if(cheaper_loc == -1 && st_exist){
            tot_amount += (Cmax-cap)*st[loc].price;
            cap = Cmax-((float)(st[i-1].dist-st[loc].dist)/(float)Davg);
            loc = i-1;
        }
        //找不到油站加油了
        if(cheaper_loc == -1 && !st_exist){
            printf("The maximum travel distance = %.2f", st[loc].dist + max_dist);
            ok=0;
            break;
        }
    }
    if(ok==1){
        printf("%.2f", tot_amount);
    }

    return 0;
}
