#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 100001;

int N,M;
vector<int> couple[MAXN];
vector<int> goods;
int in[MAXN];

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        couple[a].push_back(b);
        couple[b].push_back(a);
    }
    int K;
    while(cin >> K){
        goods.clear();
        fill(in, in+MAXN, 0);
        for(int i=0; i<K; i++){
            int g;
            cin >> g;
            goods.push_back(g);
            in[g] = 1;
        }
        //客人输入完
        int ok=1;
        for(int i=0; i<goods.size(); i++){
            int g = goods[i];
            for(int j=0; j<couple[g].size(); j++){
                //另一半在船上,爆炸
                if(in[couple[g][j]]){
                    ok = 0;
                    break;
                }
            }
            if(ok == 0){
                break;
            }
        }
        if(ok == 0){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
