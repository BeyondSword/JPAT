#include<iostream>
#include<set>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAXN=40001;
const int MAXK=2501;

vector<int> co[MAXK];

int N,K;

int cov(const string &name){
    int sum=0;
    for(int i=0; i<3; i++){
        sum = sum*26 + name[i]-'A';
    }
    sum = sum*10 + name[3] - '0';
    return sum;
}

void cov2name(int num){
    vector<char> res;
    res.push_back(num%10+'0');
    num/=10;
    for(int i=0; i<3; i++){
        res.push_back(num%26+'A');
        num/=26;
    }

    for(int i=res.size()-1; i>=0; i--){
        printf("%c", res[i]);
    }
    printf("\n");
}

//�ӿ��ٶ� 1.��������� 2.����ת��Ϊ���ֹ�ϣ 3.����vector��

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        string stu;
        cin >> stu;
        int C;
        cin >> C;
        int course;
        for(int j=0; j<C; j++){
            cin >> course;
            co[course].push_back(cov(stu));
        }
    }

    for(int i=1; i<=K; i++){
        printf("%d %d\n", i, co[i].size());
        sort(co[i].begin(), co[i].end());
        for(int j=0; j<co[i].size(); j++){
            cov2name(co[i][j]);
        }
    }

    return 0;
}
