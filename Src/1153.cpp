#include<iostream>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int MAXN=10001;
const int MAXS=1001;
const int MAXT=1000000;

struct Site{
    int index;
    int cnt;
    int tot;
}sites[MAXS];

struct Testee{
    //string card;
    char level;
    int site;
    int utime;
    int id;
    int score;
}te[MAXN];
int g_cnt=0;
string card[MAXN];
vector<int> score;


int N,M;
int cov(string str){
    int sum=0;
    for(int i=0; i<str.size(); i++){
        sum = sum*10 + str[i] - '0';
    }
    return sum;
}

bool site_cmp(struct Site &A, struct Site &B){
    if(A.cnt == B.cnt){
        return A.index < B.index;
    }
    return A.cnt > B.cnt;
}

vector<int> B;
vector<int> A;
vector<int> T;
vector<pair<int,int> > Time[MAXT];
bool score_cmp(int a, int b){
    if(te[a].score == te[b].score){
        return card[a] < card[b];
    }
    return te[a].score > te[b].score;
}

bool cmp_time(pair<int,int> &A, pair<int,int> &B){
    if(A.second == B.second){
        return A.first < B.first;
    }
    return A.second > B.second;
}

void out(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << card[v[i]] << " " << te[v[i]].score << endl;
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        string buf;
        cin >> buf;
        card[i] = buf;
        te[i].level = buf[0];
        te[i].site = cov(buf.substr(1, 3));
        te[i].utime = cov(buf.substr(4,6));
        sites[te[i].site].index = te[i].site;
        sites[te[i].site].cnt++;
        cin >> te[i].score;
        sites[te[i].site].tot += te[i].score;
        int level = buf[0];
        if(level == 'B'){
            B.push_back(i);
        }
        else if(level == 'A'){
            A.push_back(i);
        }
        else{
            T.push_back(i);
        }

        //time
        int si = te[i].site;
        int t = te[i].utime;
        int ok=0;
        for(int i=0; i<Time[t].size(); i++){
            if(Time[t][i].first == si){
                Time[t][i].second ++;
                ok=1;
                break;
            }
        }
        if(ok == 0){
            pair<int, int> p(si, 1);
            Time[t].push_back(p);
        }
    }
    //sort(sites, sites+MAXS, site_cmp);
    sort(A.begin(), A.end(), score_cmp);
    sort(B.begin(), B.end(), score_cmp);
    sort(T.begin(), T.end(), score_cmp);


    for(int i=1; i<=M; i++){
        int type;
        scanf("%d", &type);

        printf("Case %d: %d ",i, type);
        if(type == 1){
            char term;
            cin >> term;
            printf("%c\n", term);
            if(term == 'B'){
                out(B);
            }
            else if(term == 'A'){
                out(A);
            }
            else{
                out(T);
            }
        }

        else if(type == 2){
            int indi;
            scanf("%d", &indi);
            printf("%d\n", indi);
            if(sites[indi].cnt == 0){
                printf("NA\n");
            }
            else{
                printf("%d %d\n", sites[indi].cnt, sites[indi].tot);
            }
        }
        else{
            int t;
            scanf("%d", &t);
            printf("%d\n", t);
            //output
            sort(Time[t].begin(), Time[t].end(), cmp_time);
            for(int j=0; j<Time[t].size(); j++){
                printf("%d %d\n", Time[t][j].first, Time[t][j].second);
            }
        }
    }
    return 0;
}
