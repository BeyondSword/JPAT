#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=40001;
struct Stu{
    string id;
    int Gp;
    int Gm;
    int Gf;
    int G;
    int qua;
}stu[MAXN];
int g_cnt;

map<string, int> id2indi;

bool cmp(struct Stu &A, struct Stu &B){
    if(A.qua == B.qua){
        if(A.G == B.G){
            return A.id < B.id;
        }
        return A.G > B.G;
    }
    return A.qua > B.qua;
}

int P,M,N;

int Round(double num){
    int low = floor(num);
    int hi = ceil(num);
    //取下
    if(hi-num > num-low){
        return low;
    }
    else{
        return hi;
    }
}

int main(){
    scanf("%d%d%d", &P, &M, &N);
    //平时
    for(int i=0; i<P; i++){
        string id;
        int Gp;
        cin >> id >> Gp;
        //平时合格
        if(Gp>=200){
            int indi=g_cnt;
            g_cnt++;
            id2indi[id] = indi;
            stu[indi].id = id;
            stu[indi].Gp = Gp;
            //init Gm
            stu[indi].Gm = stu[indi].Gf = -1;
        }
    }
    for(int i=0; i<M; i++){
        string id;
        int Gm;
        cin >> id >> Gm;
        if(id2indi.count(id)){
            int indi = id2indi[id];
            stu[indi].Gm = Gm;
        }
    }
    for(int i=0; i<N; i++){
        string id;
        int Gf,indi;
        cin >> id >> Gf;
        if(id2indi.count(id)){
            indi = id2indi[id];
            stu[indi].Gf = Gf;
            //计算G,没有期末成绩肯定通不过
            stu[indi].G = (stu[indi].Gm > stu[indi].Gf? (int)round(Gf*0.6+stu[indi].Gm*0.4):Gf);
            if(stu[indi].G>=60){
                stu[indi].qua = 1;
            }
            else{
                stu[indi].qua = 0;
            }

        }
    }
    sort(stu, stu+g_cnt, cmp);
    for(int i=0; i<g_cnt; i++){
        //输出合格学生
        if(stu[i].qua){
            cout << stu[i].id <<" "<< stu[i].Gp << " " << stu[i].Gm<<" "<< stu[i].Gf << " " << stu[i].G <<endl;
        }
    }

    return 0;
}
