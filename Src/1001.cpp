#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
const int INF=0x7fffffff;

char buf[20];




string right_ans(int sum)
{
    int c;
    //sum = 0;

    //scanf("%d %d", &a,&b);
    //sum = a + b;

    if(sum < 1000 && sum > -1000)
        sprintf(buf, "%d",sum);
    else if(sum < 1000000 && sum > -1000000){
        int tmp = abs(sum % 1000);
        sprintf(buf, "%d,%03d", sum/1000, tmp);
    }
    else {
        c = sum % 1000000;
        int tmp1 = abs(c/1000);
        int tmp2 = abs(c%1000);
        sprintf(buf, "%d,%03d,%03d", sum / 1000000, tmp1, tmp2);
    }

    string res;
    int i=0;
    while(buf[i] != '\0'){
        res += buf[i];
        i++;
    }
    return res;
}
/*
int right_ans(int c){
    if(c<0) cout<<'-';
    c=abs(c);
    char s[20];
    sprintf(s,"%d",c);
    int len=strlen(s);
    //if(len<=3) {cout<<s;return 0;}
    int m=len/3,n=len%3,start=0;
    //cout<<"m="<<m<<' '<<"n="<<n<<endl;
    if(n==0) {cout<<s[0]<<s[1]<<s[2];start=3;m--;}
    else if(n==1) {cout<<s[0];start=1;}
    else if(n==2) {cout<<s[0]<<s[1];start=2;}
    while(m!=0){
        cout<<',';
        cout<<s[start]<<s[start+1]<<s[start+2];
        start+=3;
        m--;
    }
    return 0;
}*/



string my_ans(int sum){
    //int a,b;
    //cin >> a >> b;

    //int sum = a+b;
    char sign;
    if(sum < 0){
        sign = '-';
        sum = -sum;
    }
    sprintf(buf, "%d", sum);
    //get str
    int len = strlen(buf);


    string res;
    for(int i=0; i<len; i++){
        if(i%3 == 0 && i!=0){
            res += ',';
        }
        res += buf[len-i-1];
    }
    if(sign == '-'){
        res += sign;
    }
    //reverse
    string res2;
    for(int i=0; i<res.size(); i++){
        res2 += res[res.size()-1-i];
    }
    //cout << res2 << endl;
    return res2;
}

int main(){


    int a,b;
    cin >> a >> b;
    //string s1 = right_ans(a+b);
    //cout << s1;
    string s2 = my_ans(a+b);
    cout << s2;

        /*
    for(int i=-2000000; i<2000000 ;i++){
        fill(buf, buf+20, 0);
        string s1 = right_ans(i);
        fill(buf, buf+20, 0);
        string s2 = my_ans(i);
        if(s2 != s1){

            cout << "error:" << i << endl;
            cout << s1 << endl;
            cout << "===" << endl;
            cout << s2 << endl;
            //break;
        }
    }*/
    //int a, b;
    //cin >> a >> b;
    return 0;
}



/*
#include <iostream>
#include <cstdio>
#include <cstdlib>

 using namespace std;

int main()
{
    int a, b, sum, c;
    sum = 0;

    scanf("%d %d", &a,&b);
    sum = a + b;

    if(sum < 1000 && sum > -1000)
        printf("%d\n",sum);
    else if(sum < 1000000 && sum > -1000000)
        printf("%d,%03d\n", sum/1000, abs(sum % 1000));
    else {
        c = sum % 1000000;
        printf("%d,%03d,%03d\n", sum / 1000000, abs(c/1000), abs(c%1000));
    }

    return 0;
}*/
