#include<iostream>
#include<stdio.h>
using namespace std;
string s1, s2, s3, s4;

string week_str[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int find_week;
int find_hour;

bool capLet(char ch){
    return ch>='A'&&ch<='G';
}

bool numLet(char ch){
    return (ch>='A'&&ch<='N')||(ch>='0'&&ch<='9');
}

bool Let(char ch){
    return (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z');
}

int covHour(char ch){
    if(ch>='0'&&ch<='9'){
        return ch-'0';
    }
    if(ch>='A'&&ch<='N'){
        return ch-'A'+10;
    }
}

int main(){
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    getline(cin, s4);
    int week;
    int hour;
    int minute;
    for(int i=0; i<min(s1.size(),s2.size());i++){
        if(!find_week&&capLet(s1[i])&&capLet(s2[i])&&s1[i]==s2[i]){
            week = s1[i]-'A';
            find_week++;
            continue;
        }
        if(find_week&&numLet(s1[i])&&numLet(s2[i])&&s1[i]==s2[i]){
            hour = covHour(s1[i]);
        }
    }

    for(int i=0; i<min(s3.size(), s4.size()); i++){
        if(Let(s3[i])&&Let(s4[i])&&s3[i]==s4[i]){
            minute = i;
        }
    }

    //output
    cout << week_str[week];
    printf(" %02d:%02d",hour, minute);
    return 0;
}
