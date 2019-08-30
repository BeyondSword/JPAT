#include<iostream>
#include<stdio.h>
#include<math.h>
#include<sstream>
using namespace std;

struct Frac{
    long long a;
    long long b;
    int sign;
    int num;
    Frac(){
        sign=0;
        num=0;
        a=0;
        b=0;
    }
};

void add(struct Frac &A, struct Frac &B){
    //�����B
    if(A.sign){
        A.a = -A.a;
    }
    if(B.sign){
        B.a = -B.a;
    }
    if(B.a == 0){
        swap(A,B);
    }
    else if(A.a == 0){
        return;
    }
    else{
        A.a*=B.b;
        B.a*=A.b;
        B.a = A.a+B.a;
        B.b = A.b*B.b;
    }
    if(B.a < 0){
        B.a = -B.a;
        B.sign = 1;
    }
    else{
        B.sign = 0;
    }
    return;
}

//��Ϊ������
void cov(struct Frac &A){
    while(A.a >= A.b){
        A.a -= A.b;
        A.num++;
    }
    //��Ϊ�����ʽ
    //��a�ܴ�ʱ�����
    int i=2;
    while(i <= A.a){
        while(A.a%i==0 && A.b%i==0){
            A.a/=i;
            A.b/=i;
        }
        i++;
    }
    return;
}

void out(struct Frac &A){
    //ȫ0
    if(A.num == 0 && A.a == 0){
        cout << "0";
        return;
    }

    //�д���������
    if(A.num != 0){
        if(A.sign){
            cout << "-";
        }
        cout << A.num;
    }

    //�з�������
    if(A.a != 0){
        //������
        if(A.num){
            cout << " ";
        }
        //��������Ҫ�������
        else{
            if(A.sign){
                cout << "-";
            }
        }
        cout << A.a << "/" << A.b;
    }
    return;
}

int N;
int main(){
    cin >> N;
    struct Frac Sum;
    for(int i=0; i<N; i++){
        struct Frac A;
        string in;
        cin >> in;
        int index=0;
        if(in[index] == '-'){
            A.sign = 1;
            index ++;
        }
        int sum=0;
        while(in[index] != '/'){
            sum = sum*10 + in[index]-'0';
            index++;
        }
        A.a = sum;
        sum = 0;
        index++;
        while(index < in.size()){
            sum = sum*10 + in[index]-'0';
            index++;
        }
        A.b = sum;
        //�����������,��
        add(A, Sum);
        cov(Sum);
    }
    out(Sum);
    return 0;
}
