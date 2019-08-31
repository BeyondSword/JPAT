#include<iostream>
#include<map>
#include<sstream>
using namespace std;

string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string hi[13] = {" ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> m;
int main(){
    int N;
    string str;
    cin >> N;
    getline(cin, str);
    for(int i=0; i<N; i++){
        //转火星
        getline(cin, str);
        if(str[0]>='0'&&str[0]<='9'){
            int sum = 0;
            for(int i=0; i<str.size(); i++){
                sum = sum*10 + str[i] - '0';
            }
            //get num
            int l = sum%13;
            int h = sum/13%13;
            //两位
            if(h != 0){
                cout << hi[h];
                if(l != 0){
                    cout << " " << low[l];
                }
                cout << endl;
            }
            else{
                cout << low[l] << endl;
            }

        }
        //转地球
        else{
            stringstream ss(str);
            for(int i=0; i<13; i++){
                m[hi[i]] = (i)*13;
            }
            for(int i=0; i<13; i++){
                m[low[i]] = i;
            }

            string s[2];
            int cnt=0;
            while(ss >> s[cnt]){
                cnt++;
            }
            int sum=0;
            for(int i=0; i<cnt; i++){
                sum += m[s[i]];
            }


            cout << sum << endl;
        }
    }

    return 0;

}
