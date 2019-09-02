#include<iostream>
#include<vector>
#include<map>
using namespace std;

int k;
map<char, int> m_broken;
map<char, int> m;

int main(){
    string str;
    vector<char> res;
    vector<char> broken;
    cin >> k;
    cin >> str;
    string s = str;
    //sentry
    str+=' ';

    char cur = str[0];
    int cnt=1;
    for(int i=1; i<str.size(); i++){
        //字符切换,结算前一字符
        if(str[i] != str[i-1]){
            //可能坏掉的字符
            if(cnt >= k && cnt%k==0){
                if(!m.count(cur)){
                    m[cur] = 1;
                    broken.push_back(cur);
                }
            }
            //目前为止好的字符
            else{
                m[cur] = 0;
                res.push_back(cur);
            }
            cur = str[i];
            cnt = 0;
        }
        //连续的重复字符
        cnt++;
    }

    //先输出坏的字符
    for(int i=0; i<broken.size(); i++){
        if(m.count(broken[i]) && m[broken[i]]!=0){
            cout << broken[i];
        }
    }
    cout << endl;

    //输出好字符
    int index = 0;
    str = s;
    while(index<str.size()){
        //好字符
        if(m[str[index]] == 0){
            cout << str[index];
            index++;
        }
        //坏字符
        else{
            int cur = str[index];
            cout << str[index];
            for(int i=0; i<k; i++){
                index++;
            }
        }
    }
    return 0;
}
