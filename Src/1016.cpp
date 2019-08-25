#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


int rates[25];
const int MAXN=1001;

struct Rec{
    string name;
    int time;
    int MM;
    int dd;
    int hh;
    int mm;
    int status; //0 on 1 off
}rec[MAXN];

int N;

bool comparison(struct Rec &A, struct Rec &B){
    if(A.name != B.name){
        return A.name<B.name;
    }
    else{
        return A.time<B.time;
    }
}

float day_amount=0.0;
float fee(struct Rec &start, struct Rec &end){
    //从分钟开始计算
    float amount=0.0;
    //minute
    amount += (60-start.mm)*rates[start.hh] + end.mm*rates[end.hh];
    //hour
    for(int i=start.hh+1; i<24; i++){
        amount += rates[i]*60;
    }
    for(int i=0; i<end.hh; i++){
        amount += rates[i]*60;
    }
    //day
    if(start.dd < end.dd){
        amount += day_amount*(end.dd-start.dd-1);
    }
    else{
        amount -= day_amount;
    }
    return amount/100;
}

int main(){
    int tot_rate = 0;
    for(int i=0; i<24; i++){
        cin >> rates[i];
        tot_rate += rates[i];
    }
    rates[24] = tot_rate;

    for(int i=0; i<24; i++){
        day_amount += 60*rates[i];
    }

    cin >> N;
    for(int i=1; i<=N; i++){
        string name;
        string status;
        cin >> rec[i].name;
        scanf("%02d:%02d:%02d:%02d", &rec[i].MM, &rec[i].dd, &rec[i].hh, &rec[i].mm);
        cin >> status;
        rec[i].status = (status!="on-line");
        rec[i].time = rec[i].dd*60*24 + rec[i].hh*60 + rec[i].mm;
    }
    //input end
    sort(rec+1, rec+N+1, comparison);
    //排序从1-N


    float tot_amount = 0.0;
    vector<pair<int, int> > res;
    int start_indi=-1;
    int end_indi=-1;
    for(int i=1; i<=N+1; i++){
        //一人账单统计完,输出
        if(rec[i-1].name != rec[i].name){
            //output
            if(i != 1){
                if(res.size()>0){
                    cout << rec[res[0].first].name;
                    printf(" %02d\n", rec[res[0].first].MM);
                    for(int i=0; i<res.size(); i++){
                        float amount = fee(rec[res[i].first], rec[res[i].second]);
                        tot_amount += amount;
                        printf("%02d:%02d:%02d",rec[res[i].first].dd, rec[res[i].first].hh, rec[res[i].first].mm);
                        printf(" %02d:%02d:%02d",rec[res[i].second].dd, rec[res[i].second].hh, rec[res[i].second].mm);
                        printf(" %d $%.2f\n", rec[res[i].second].time-rec[res[i].first].time, amount);
                    }
                    printf("Total amount: $%.2f\n", tot_amount);
                }
            }
            tot_amount=0.0;
            res.clear();
        }
        if(rec[i].status == 0){
            start_indi = i;
        }
        else{
            if(start_indi != -1){
                end_indi = i;
            }
        }
        //一条完整记录
        if(start_indi != -1 && end_indi != -1){
            res.push_back(make_pair(start_indi, end_indi));
            start_indi = end_indi = -1;
        }
    }
    return 0;
}
