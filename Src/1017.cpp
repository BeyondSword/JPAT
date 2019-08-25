#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN=10001;
const int MAXK=101;
struct Customer{
    int a_time;
    int s_time;
    int e_time;
    int proc_time;
}cus[MAXN];
int wins[MAXK];

int N,K;
queue<int> wait_q;

bool comparison(struct Customer &A, struct Customer &B){
    return A.a_time < B.a_time;
}

int main(){
    cin >> N >> K;
    fill(wins, wins+K, -1);
    for(int i=0; i<N; i++){
        int h,m,s;
        int proc_time;
        scanf("%02d:%02d:%02d", &h, &m, &s);
        scanf("%d", &proc_time);
        if(proc_time > 60){
            proc_time = 60;
            //continue;
        }
        cus[i].a_time = h*3600+m*60+s;
        cus[i].proc_time = proc_time*60;
    }
    //input end
    sort(cus, cus+N, comparison);

    int cur_time = 8*3600;
    int close_time = 17*3600;

    int proc_cnt = 0;
    //在n个人结束之前

    for(int i=0; i<N; i++){
        wait_q.push(i);
    }

    while(proc_cnt <N){
        int indice=-1;//找窗口
        for(int i=0; i<K; i++){
            //有窗口空
            if(wins[i] == -1){
                indice = i;
                break;
            }
            if(indice == -1 || cus[wins[i]].e_time < cus[wins[indice]].e_time){
                indice = i;
            }
        }
        //wins[indice] = -1;
        //空窗口
        //清空
        if(wins[indice] != -1){
            //update time
            cur_time = cus[wins[indice]].e_time;
            wins[indice] = -1;
        }
        if(!wait_q.empty()){
            wins[indice] = wait_q.front();
            wait_q.pop();

            //窗口空出后还没有到达，更新时间
            if(cus[wins[indice]].a_time > cur_time){
                cur_time = cus[wins[indice]].a_time;
            }
            cus[wins[indice]].s_time = cur_time;
            cus[wins[indice]].e_time = cur_time + cus[wins[indice]].proc_time;
            proc_cnt++;
        }
    }

    //output
    float tot_time = 0.0;
    int cnt=0;
    for(int i=0; i<N; i++){
        if(cus[i].a_time > close_time){
            continue;
        }
        tot_time += cus[i].s_time-cus[i].a_time;
        cnt++;
    }
    printf("%.1f", (tot_time/(float)cnt)/60.0);
    return 0;
}
