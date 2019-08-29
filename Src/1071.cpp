#include<map>
#include<vector>
#include<iostream>
using namespace std;

bool is_alphanum(char &ch){
    if(ch>='A' && ch<='Z'){
        ch = ch - 'A' + 'a';
        return true;
    }
    if(ch>='a' && ch<='z'){
        return true;
    }
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}

map<string, int> m;

int main(){
    string S;
    getline(cin,S);

    //加个哨兵，非字母数字字符的时候才会存
    S+='*';
    string str;
    for(int i=0; i<S.size(); i++){
        if(S[i] == '\n'){
            break;
        }
        if(is_alphanum(S[i])){
            str+=S[i];
        }
        else{
            if(str.size()){
                if(!m.count(str)){
                    m[str] = 1;
                }
                else{
                    m[str] ++;
                }
            }
            str.clear();
        }
    }

    map<string, int>::iterator it;
    int most_freq=0;
    string res;
    for(it=m.begin(); it!=m.end(); it++){
        string s = it->first;
        int cnt = it->second;
        if(cnt > most_freq){
            most_freq = cnt;
            res = s;
        }
        else if(cnt == most_freq){
            res = s<res?s:res;
        }
    }
    cout << res << " " << most_freq;
    return 0;
}
