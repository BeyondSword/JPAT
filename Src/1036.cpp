#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

struct Stu{
    string name;
    char gender;
    string ID;
    int grade;
};

vector<struct Stu> boy;
vector<struct Stu> girl;

bool comparison(struct Stu &A, struct Stu &B){
    return A.grade < B.grade;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        struct Stu stu;
        cin >> stu.name >> stu.gender >> stu.ID >> stu.grade;
        if(stu.gender == 'M'){
            boy.push_back(stu);
        }
        else{
            girl.push_back(stu);
        }
    }
    //input end
    sort(boy.begin(), boy.end(), comparison);
    sort(girl.begin(), girl.end(), comparison);
    int ok=1;
    int g_grade, b_grade;
    if(girl.empty()){
        ok=0;
        printf("Absent\n");
    }
    else{
        g_grade = girl[girl.size()-1].grade;
        cout << girl[girl.size()-1].name << " " << girl[girl.size()-1].ID << endl;
    }

    if(boy.empty()){
        ok=0;
        printf("Absent\n");
    }
    else{
        b_grade = boy[0].grade;
        cout << boy[0].name << " " << boy[0].ID << endl;
    }

    if(ok==0){
        printf("NA");
    }
    else{
        printf("%d", g_grade-b_grade);
    }

    return 0;
}
