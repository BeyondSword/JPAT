#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN=2001;

struct Student{
    string ID;
    int score[4];
    int rank[4];//sort

}Stu[MAXN];

int tag = 0;
int N,M;

char course[4] = {'C', 'M', 'E', 'A'};

bool comparison(struct Student &A, struct Student &B){
    return A.score[tag] > B.score[tag];
}

map<string, int> m;
int index = 0;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string ID;
        int c,m,e;
        cin >> ID >> c >> m >> e;
        Stu[index].ID = ID;
        Stu[index].score[0] = c;
        Stu[index].score[1] = m;
        Stu[index].score[2] = e;
        Stu[index].score[3] = (c+m+e)/3;
        index++;
    }
    //sort11
    //∂‡¥Œ≈≈–Ú
    for(int i=0; i<4; i++){
        tag = i;
        sort(Stu, Stu+N, comparison);
        //update rank
        int rank = 1;
        Stu[0].rank[i] = rank;
        for(int j=1; j<N; j++){
            rank ++;
            if(Stu[j].score[i] == Stu[j-1].score[i]){
                Stu[j].rank[i] = Stu[j-1].rank[i];
            }
            else{
                Stu[j].rank[i] = rank;
            }
        }
    }
    for(int i=0; i<N; i++){
        m[Stu[i].ID] = i;
    }
    for(int i=0; i<M; i++){
        string ID;
        cin >> ID;
        int indi;
        if(m.count(ID)){
            indi = m[ID];
        }
        //stu not exist
        else{
            cout << "N/A" << endl;
            continue;
        }
        //find best rank;

        int best_indi=3;
        //int Min = 0x3fffffff;
        for(int j=0; j<3; j++){
            if(Stu[indi].rank[j] < Stu[indi].rank[best_indi]){
                //Min = Stu[indi].rank[j];
                best_indi = j;
            }
        }
        cout << Stu[indi].rank[best_indi] << " " << course[best_indi] << endl;
    }
    return 0;
}
