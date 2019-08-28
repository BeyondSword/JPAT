#include<iostream>
using namespace std;

int N;


//pow自实现
int pow(int num, int digit_num){
    int res = 1;
    if(digit_num == 0){
        return 1;
    }
    else{
        for(int i=0; i<digit_num; i++){
            res *= num;
        }
    }
    return res;
}

int count_digit(int num){
    int cnt=0;
    if(num == 0){
        return 1;
    }
    while(num!=0){
        num/=10;
        cnt++;
    }
    return cnt;
}


int count_one(int num, int digit_num){
    //1位数
    if(digit_num == 1){
        if(num >= 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    //先计算最高位
    int a = pow(10, digit_num-1);
    int hi_digit = num/a;
    int hi_cnt=0;
    int low_cnt=0;

    //最高位
    if(hi_digit > 1){
        hi_cnt += a;
    }
    else{
        hi_cnt += num-a+1;
    }

    //其他位的1 0-X1000
    for(int i=0; i<digit_num-1; i++){
        low_cnt += pow(10, (digit_num-2));
    }
    low_cnt*=hi_digit;
    //X1 000-X1 X2X3X4
    low_cnt += count_one(num-hi_digit*a, count_digit(num-hi_digit*a));

    return hi_cnt+low_cnt;
}







int main(){
    int N;
    cin >> N;
    //统计位数
    int res = count_one(N, count_digit(N));
    cout << res;
    return 0;
}
