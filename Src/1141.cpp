#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int MAXN=100001;

void str_cov(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

struct School{
    int rank;
    string name;
    double B;
    double A;
    double T;
    int Ns;
    int TWS;
}sch[MAXN];
int g_cnt=1;

map<string, int> m;

bool cmp(int a, int b){
    int TWS_a = (int)sch[a].B/1.5 + sch[a].A + sch[a].T*1.5;
    int TWS_b = (int)sch[b].B/1.5 + sch[b].A + sch[b].T*1.5;
    sch[a].TWS = TWS_a;
    sch[b].TWS = TWS_b;
    if(TWS_a == TWS_b){
        if(sch[a].Ns == sch[b].Ns){
            return sch[a].name < sch[b].name;
        }
        return sch[a].Ns < sch[b].Ns;
    }
    return TWS_a > TWS_b;
}

int N;
vector<int> sch_v;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string id,school;
        int score;
        cin >> id >> score >> school;
        str_cov(school);
        int indi;
        if(!m.count(school)){
            indi = g_cnt;
            g_cnt++;
            m[school] = indi;
            sch_v.push_back(indi);
        }
        else{
            indi = m[school];
        }
        sch[indi].name = school;
        sch[indi].Ns++;
        if(id[0] == 'B'){
            sch[indi].B += score;
        }
        else if(id[0] == 'A'){
            sch[indi].A += score;
        }
        else{
            sch[indi].T += score;
        }
    }
    sort(sch_v.begin(), sch_v.end(), cmp);
    int rank=1;
    cout << m.size() << endl;
    for(int i=0; i<sch_v.size(); i++){
        if(i==0){
            sch[sch_v[i]].rank = rank;
        }
        else if(sch[sch_v[i]].TWS == sch[sch_v[i-1]].TWS){
            sch[sch_v[i]].rank = sch[sch_v[i-1]].rank;
        }
        else{
            sch[sch_v[i]].rank = rank;
        }
        rank ++;
        int index = sch_v[i];
        //output
        cout << sch[index].rank << " " << sch[index].name << " " << sch[index].TWS << " " << sch[index].Ns << endl;
        //cout << sch[index].A << sch[index].B << sch[index].T << endl;
    }
    return 0;
}
