#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAXN=10001;
const int MAXK=8*10000+1;

struct Rec{
    string p_num;
    int u_time;
    int st;
}rec[MAXN];

vector<int> p_rec;

struct Car{
    string p_num;
    int time;
}car[MAXN];
int car_index;

vector<int> res;
int g_longest;

bool cmp1(struct Rec &A, struct Rec &B){
    if(A.p_num == B.p_num){
        return A.u_time < B.u_time;
    }
    return A.p_num < B.p_num;
}

bool cmp2(int a, int b){
    return rec[a].u_time < rec[b].u_time;
}

bool cmp3(int a, int b){
    return car[a].p_num < car[b].p_num;
}

int longest_car;
int car_indi;

int N,K;
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> rec[i].p_num;
        int hh,mm,ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        string status;
        cin >> status;
        if("out" == status){
            rec[i].st = 1;
        }
        rec[i].u_time = hh*3600 + mm*60 + ss;
    }

    sort(rec+1, rec+N+1, cmp1);
    //i==0 哨兵 i==N+1 哨兵
    int in=-1, out=-1;
    for(int i=1; i<=N+1; i++){
        //牌照不同，结算前一辆车
        if(rec[i].p_num != rec[i-1].p_num){
            //更新时间最长车
            if(car[car_index].time > g_longest){
                res.clear();
                res.push_back(car_index);
                g_longest = car[car_index].time;
            }
            //增加同时长车
            else if(car[car_index].time == g_longest){
                res.push_back(car_index);
            }
            //更新车
            car_index++;
            //更新车牌
            car[car_index].p_num = rec[i].p_num;
            in = -1; out = -1;
        }

        //sentry
        if(i == N+1){
            break;
        }
        // in
        if(rec[i].st==0){
            in = i;
        }
        // out
        else{
            if(in != -1){
                out = i;
            }
        }
        //结算
        if(in!=-1 && out!=-1){
            //记录有效数据
            p_rec.push_back(in);
            p_rec.push_back(out);
            //记录时间
            car[car_index].time += rec[out].u_time-rec[in].u_time;
            in = -1;
            out = -1;
        }

    }

    int indi = 0;
    int g_carnum=0;
    sort(p_rec.begin(), p_rec.end(), cmp2);
    for(int i=0; i<K; i++){
        int hh,mm,ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh*3600 + mm*60 + ss;
        while(indi<p_rec.size() && rec[p_rec[indi]].u_time <= time){
            // in
            if(rec[p_rec[indi]].st == 0){
                g_carnum++;
            }
            //out
            else{
                g_carnum--;
            }
            indi++;
        }
        cout << g_carnum << endl;
    }

    sort(res.begin(), res.end(), cmp3);
    for(int i=0; i<res.size(); i++){
        if(i>0){
            cout << " ";
        }
        cout << car[res[i]].p_num;
    }
    printf(" %02d:%02d:%02d", car[res[0]].time/3600, car[res[0]].time%3600/60, car[res[0]].time%3600%60);
    return 0;
}


