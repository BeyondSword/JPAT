#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

const int MAXM=1001;
string name[MAXM];
map<string, int> win;
int M,N,S;
int main(){
    cin >> M >> N >> S;
    //vector<string> name;
    for(int i=1; i<=M; i++){
        cin >> name[i];
    }
    // ‰»ÎΩ· ¯
    vector<string> res;
    int index = S;
    int cnt = N;
    while(index<=M){
        if(cnt>=N&&!win.count(name[index])){
            win[name[index]]=1;
            cnt=1;
            res.push_back(name[index]);
        }
        else{
            cnt++;
        }
        index++;
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    if(!res.size())
        cout << "Keep going...";
    return 0;
}
