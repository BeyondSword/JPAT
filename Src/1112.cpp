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
        //�ַ��л�,����ǰһ�ַ�
        if(str[i] != str[i-1]){
            //���ܻ������ַ�
            if(cnt >= k && cnt%k==0){
                if(!m.count(cur)){
                    m[cur] = 1;
                    broken.push_back(cur);
                }
            }
            //ĿǰΪֹ�õ��ַ�
            else{
                m[cur] = 0;
                res.push_back(cur);
            }
            cur = str[i];
            cnt = 0;
        }
        //�������ظ��ַ�
        cnt++;
    }

    //����������ַ�
    for(int i=0; i<broken.size(); i++){
        if(m.count(broken[i]) && m[broken[i]]!=0){
            cout << broken[i];
        }
    }
    cout << endl;

    //������ַ�
    int index = 0;
    str = s;
    while(index<str.size()){
        //���ַ�
        if(m[str[index]] == 0){
            cout << str[index];
            index++;
        }
        //���ַ�
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
