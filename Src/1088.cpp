#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

typedef struct Frac{
    int a;
    int b;
    int N;
    Frac():a(0),b(1),N(0){};
}frac;

//a+b 结果存b
void add(frac A, frac B, frac &C){
    A.a*=B.b;
    B.a*=A.b;

    C.a = A.a+B.a;
    C.b = A.b*B.b;

    return;
}

void sub(frac A, frac B, frac &C){
    A.a*=B.b;
    B.a*=A.b;

    C.a = A.a-B.a;
    C.b = A.b*B.b;

    return;
}

void multi(frac A, frac B, frac &C){
    C.a = A.a*B.a;
    C.b = A.b*B.b;
}

bool quo(frac A, frac B, frac &C){
    if(B.a == 0){
        return false;
    }
    swap(B.a, B.b);
    if(B.b < 0){
        B.b = -B.b;
        B.a = -B.a;
    }
    multi(A, B, C);
    return true;
}

void out(frac &A){
    if(A.a == 0){
        cout << "0";
        return;
    }

    //约分
    int i=2;
    while(i<=abs(A.a)){
        while(A.a%i==0 && A.b%i==0){
            A.a/=i;
            A.b/=i;
        }
        i++;
    }
    int sign = A.a<0;
    A.a = abs(A.a);
    //转换假分数，负数处理
    while(A.a >= A.b){
        A.N++;
        A.a -= A.b;
    }

    if(sign){
        cout << "(-";
    }
    if(A.N != 0){
        cout << A.N;
    }
    if(A.a != 0){
        if(A.N!=0){
            cout << " ";
        }
        cout << A.a << "/" << A.b;
    }
    if(sign){
        cout << ")";
    }
    return;
}

void output(char oper, frac A, frac B, frac C, bool quo){
    out(A);
    cout << " " << oper << " ";
    out(B);
    cout << " = ";
    if(quo){
        out(C);
    }
    else{
        cout << "Inf";
    }
    cout << endl;
    return;
}

int main(){
    frac A,B,C;
    bool quo_res=true;
    scanf("%d/%d", &A.a, &A.b);
    scanf("%d/%d", &B.a, &B.b);
    add(A, B, C);
    output('+', A, B, C, quo_res);
    sub(A, B, C);
    output('-', A, B, C, quo_res);
    multi(A, B, C);
    output('*', A, B, C, quo_res);
    quo_res = quo(A, B, C);
    output('/', A, B, C, quo_res);
    return 0;
}
