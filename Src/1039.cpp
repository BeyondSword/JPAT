#include<iostream>
#include<vector>
#include<set>

using namespace std;

//Èý´óÐ´+1×ÖÄ¸
set<int> st2co[26*26*26*10+1];
int N, K;

int cov(const string &name){
    int sum=0;
    for(int i=0; i<3; i++){
        sum = sum*26 + name[i]-'A';
    }
    sum = sum*10 + name[3] - '0';
    return sum;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<K; i++){
        int co, num;
        cin >> co >> num;
        for(int j=0; j<num; j++){
            string name;
            cin >> name;
            st2co[cov(name)].insert(co);
        }
    }
    //query
    for(int i=0; i<N; i++){
        string name;
        cin >> name;
        set<int> s = st2co[cov(name)];
        set<int>::iterator it;
        cout << name << " " << s.size();
        for(it=s.begin(); it!=s.end(); it++){
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}
