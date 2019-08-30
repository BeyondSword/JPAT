#include<iostream>
#include<vector>

using namespace std;
vector<char> digits;

int main(){
    string S;
    cin >> S;
    int flag = (S[0]=='-');
    int index = 1;
    while(S[index] != 'E'){
        if(S[index] != '.')
            digits.push_back(S[index]);
        index++;
    }
    //跳过e
    index++;
    int exp_flag = (S[index]=='-');
    index++;
    int exp=0;
    while(index < S.size()){
        exp = exp*10 + S[index]-'0';
        index++;
    }

    //output
    if(flag == 1){
        cout << "-";
    }
    //负数
    if(exp_flag == 1){
        int ok=0;
        while(exp>0){
            cout << '0';
            if(!ok){
                cout << '.';
                ok=1;
            }
            exp--;
        }
        for(int i=0; i<digits.size(); i++){
            cout << digits[i];
        }
    }
    //正数
    else{
        int indi=0;
        //从第二个digit开始
        while(exp>0 && indi<digits.size()){
            cout << digits[indi];
            if(indi>0){
                exp--;
            }
            indi++;

        }
        //所有有效位输出完了，加后缀0
        if(indi >= digits.size()){
            while(exp>0){
                cout << '0';
                exp--;
            }
        }
        //没输出完,加'.'
        else{
            cout << '.';
            while(indi<digits.size()){
                cout << digits[indi];
                indi++;
            }
        }
    }

    return 0;
}
