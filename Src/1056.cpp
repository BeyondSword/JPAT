#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int Np,Ng;
const int MAXNP=1001;


struct Mice{
    int id;
    int w;
    int rank;
}mic[MAXNP];
//int w[MAXNP];
int round[MAXNP];
//int order[MAXNP];
vector<int> order;
vector<int> res;

int tag;
bool comparison(struct Mice a, struct Mice b){
    if(tag==0){
        return round[a.id] > round[b.id];
    }
    else{
        return a.id < b.id;
    }
}

int main(){
    cin >> Np >> Ng;
    for(int i=0; i<Np; i++){
        cin >> mic[i].w;
        mic[i].id = i;
    }
    for(int i=0; i<Np; i++){
        int in;
        cin >> in;
        order.push_back(in);
    }

    while(order.size()>1){
        for(int i=0; i<order.size(); i+=Ng){
            int winner=-1;
            //找到每一组中最重的老鼠,进入下一轮
            for(int j=i; j<i+Ng&&j<order.size(); j++){
                if(winner == -1){
                    winner = order[j];
                    round[winner]++;
                    continue;
                }
                if(mic[winner].w < mic[order[j]].w){
                    round[winner]--;
                    winner = order[j];
                    round[winner]++;
                }
            }
            res.push_back(winner);
        }
        order = res;
        res.clear();
    }
    //确定每只老鼠倒下的轮数
    //round 表示每只老鼠第几轮淘汰
    //sort(round, round+Np, comparison);
    sort(mic, mic+Np, comparison);
    //按轮数排列
    int rank=1;
    mic[0].rank = rank;
    //排rank
    for(int i=1; i<Np; i++){
        rank++;
        if(round[mic[i-1].id] == round[mic[i].id]){
            mic[i].rank = mic[i-1].rank;
        }
        else{
            mic[i].rank = rank;
        }
    }

    tag=1;
    sort(mic, mic+Np, comparison);
    //output
    for(int i=0; i<Np; i++){
        if(i>0){
            cout << " ";
        }
        cout << mic[i].rank;
    }
    return 0;
}
