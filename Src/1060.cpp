#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int N;
string A,B;
vector<char> numA;
vector<char> numB;

void cov(string A, vector<char> &num, int N, int &exp){
    int index=0;

    //����ǰ��0
    while(A[index] == '0'){
        index++;
    }
    //ͣ��'.'or������ 0.000xxx
    if(index<A.size() && A[index] == '.'){
        //pass '.'
        index++;
        //ͳ��exp
        while(index<A.size() && A[index] == '0'){
            exp--;
            index++;
        }
        //ȫ��0
        if(index >= A.size()){
            exp=0;
            return;
        }
        while(index<A.size()){
            num.push_back(A[index]);
            index++;
        }
    }
    else{
        //�������֣�Ӱ��exp
        while(index<A.size()&&A[index] != '.'){
            num.push_back(A[index]);
            index++;
            exp++;
        }

        //����'.'
        index++;
        //����С������
        while(num.size()<N&&index<A.size()){
            num.push_back(A[index]);
            index++;
        }
    }
    return;
}

void out(vector<char> &num, int exp){
    //if(num.size()==0){
        //printf("0");
    //}
    //else{
        cout << "0.";
    //}

    int i;
    for(i=0; i<num.size()&&i<N; i++){
        cout << num[i];
    }
    //��β0
    while(i<N){
        i++;
        cout << "0";
    }

    //exp
    cout << "*10^" << exp;
    return;
}

int main(){
    cin >> N;
    cin >> A >> B;
    int exp_a=0,exp_b=0;
    cov(A, numA, N, exp_a);
    cov(B, numB, N, exp_b);
    //ת�����,�Ƚ�
    int ok=(exp_a == exp_b);
    //�Ƚ�ǰnλ
    int i;
    for(i=0; i<N&&i<min(numA.size(),numB.size()); i++){
        if(numA[i] != numB[i]){
            ok=0;
            break;
        }
    }
    //��n�ܴ󣬿��ԱȽ�����λ,�ڹ�ͬλ��A��B������� �����λ����
    if(i<N&&numA.size()!=numB.size()){
        ok=0;
    }

    if(ok == 1){
        cout << "YES ";
        out(numA, exp_a);
    }
    else{
        cout << "NO ";
        out(numA, exp_a);
        cout << " ";
        out(numB, exp_b);
    }
    return 0;
}
