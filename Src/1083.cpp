#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct Rec{
    string name;
    string ID;
    int grade;
};

bool comparison(struct Rec &A, struct Rec &B){
    return A.grade > B.grade;
}



int N;
vector<struct Rec> res;
int main(){
    cin >> N;
    res.resize(N);
    for(int i=0; i<N; i++){
        struct Rec rec;
        cin >> rec.name >> rec.ID >> rec.grade;
        res.push_back(rec);
    }
    sort(res.begin(), res.end(), comparison);
    int low,hi;
    cin >> low >> hi;
    int ok=0;
    for(int i=0; i<res.size(); i++){
        if(res[i].grade > hi){
            continue;
        }
        if(res[i].grade < low){
            break;
        }
        ok=1;
        cout << res[i].name << " " << res[i].ID << endl;
    }
    if(ok == 0){
        cout << "NONE";
    }
    return 0;
}
