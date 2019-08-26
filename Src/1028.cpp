#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAXN=100001;
int N,C;

int tag=1;

struct Stu{
    string ID;
    string name;
    int grade;
}stu[MAXN];

bool comparison(struct Stu &A, struct Stu &B){
    if(1 == tag){
        return A.ID<B.ID;
    }
    else if(2 == tag){
        if(A.name == B.name){
            return A.ID<B.ID;
        }
        return A.name<B.name;
    }
    else{
        if(A.grade == B.grade){
            return A.ID<B.ID;
        }
        return A.grade<B.grade;
    }
}

int main(){
    cin >> N >> C;
    tag = C;
    for(int i=0; i<N; i++){
        cin >> stu[i].ID >> stu[i].name >> stu[i].grade;
    }
    sort(stu, stu+N, comparison);
    //output
    for(int i=0; i<N; i++){
        cout << stu[i].ID << " " << stu[i].name << " " << stu[i].grade << endl;
    }
    return 0;
}
