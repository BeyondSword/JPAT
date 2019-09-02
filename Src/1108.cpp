#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;

int N;


bool is_num(char ch){
    return ch>='0'&&ch<='9';
}

//�ж��ַ����Ϸ���
bool is_legal(string buf){
    double sum=0;
    int sign=1;
    int i;
    int dot=0;
    for(i=0; i<buf.size(); i++){
        //��һλ�Ǹ����ŵĻ������⴦��
        if(i==0 && buf[i] == '-'){
            sign = -1;
            /*ֻ��һ������*/
            if(buf.size() == 1){
                return false;
            }
            continue;
        }
        //����'.'���������ִ�����
        if(buf[i] == '.'){
            dot = 1;
            break;
        }
        //��һλ�������֣���������
        if(!is_num(buf[i])){
            return false;
        }
        sum = sum*10 + buf[i] - '0';
    }

    if(sum>1000 || sum < -1000)
        return false;
    int cnt=0;
    //����С��
    i++;
    for(;i<buf.size(); i++){
        if(!is_num(buf[i])){
            return false;
        }
        cnt++;
        sum += (buf[i]-'0')*pow(10, -cnt);
    }
    //������λС����������С���㵫û��С��
    if(cnt > 2){
        return false;
    }
    //1000.xxx �� -1000.xx
    sum = sum * sign;
    if(sum > 1000.00 || sum < -1000.00){
        return false;
    }
    return true;
}

int main(){
    cin >> N;
    double sum = 0.0;
    int cnt=0;
    for(int i=0; i<N; i++){
        string buf;
        cin >> buf;
        if(is_legal(buf) == false){
            cout << "ERROR: " << buf << " is not a legal number" << endl;
        }
        //legal
        else{
            stringstream ss(buf);
            double in;
            ss >> in;
            sum += in;
            cnt++;
        }
    }
    if(cnt > 1){
        printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
    }
    else if(cnt == 1){
        printf("The average of 1 number is %.2lf\n", sum);
    }
    else{
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}
