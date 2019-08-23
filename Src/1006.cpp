#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int toInt(int hours, int mins, int seconds){
    return hours*3600 + mins*60 + seconds;
}

int tag;

class Stu{
public:
    string ID;
    int in;
    int out;
    Stu(string &_ID, int _in, int _out):ID(_ID), in(_in), out(_out){};
    /*bool operator<(Stu &a, Stu &b){
        if(!tag)
            return a.in < b.in;
        else
            return a.out > b.out;
    };*/
};

bool comparison(Stu* a, Stu* b){
    if(!tag)
        return a->in < b->in;
    else
        return a->out > b->out;
}

vector<Stu*> v;

int main(){
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        string ID;
        cin >> ID;
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d", &h1,&m1,&s1);
        scanf("%d:%d:%d", &h2,&m2,&s2);
        Stu* stu = new Stu(ID, toInt(h1,m1,s1), toInt(h2,m2,s2));
        v.push_back(stu);
    }
    sort(v.begin(), v.end(), comparison);
    cout << v[0]->ID << " ";
    tag = 1;
    sort(v.begin(), v.end(), comparison);
    cout << v[0]->ID;
    return 0;
}
