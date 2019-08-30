#include<iostream>
#include<vector>

using namespace std;

string num_ch[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string unit[9] = {" Yi", " Qian", " Bai", " Shi", " Wan", " Qian", " Bai", " Shi", ""};


int main(){
    string str;
    cin >> str;
    int flag = 0;
    int first = 0;
    string number=str;
    if(str[0] == '-'){
        flag = 1;
        number = str.substr(1, str.size()-1);
    }
    //output
    int index = 0;
    int offset = 9-number.size();
    bool last_input=true;
    int tot_size = number.size();

    if(flag == 1){
        cout << "Fu";
        first = 1;
    }
    //亿


    //千万 百万 十万 个万


    //裸串 千 百 十 个
    while(index < number.size() && number[index] != 0){
        if(number[index] == '0'){
            last_input = false;
            //刚好是万且位数多于5
            if(offset == 4 && tot_size > 5){
                cout << unit[offset];
                last_input = true;
                first = 1;
            }
            first = 1;
        }
        else{
            if(first != 0){
                cout << " ";
            }
            if(last_input == false){
                cout << "ling ";
            }
            cout << num_ch[number[index]-'0'];
            cout << unit[offset];
            last_input = true;
            first = 1;
        }
        offset++;
        index ++;
    }

    if(number == "0"){
        cout << "ling";
    }
    return 0;
}
