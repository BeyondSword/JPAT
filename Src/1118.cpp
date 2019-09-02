#include<iostream>
#include<vector>
using namespace std;
const int MAX=11111;

int N;
int father[MAX];
int cnt[MAX];
int exist[MAX];

int find_father(int b){
    if(father[b] == -1){
        return b;
    }
    int f = find_father(father[b]);
    father[b] = f;
    return f;
}

void Union(int a, int b){
    int fa = find_father(a);
    int fb = find_father(b);
    father[fa] = fb;
    return;
}

int main(){
    cin >> N;
    fill(father, father+MAX, -1);
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        int b1;
        cin >> b1;
        exist[b1] = 1;
        for(int j=1; j<K; j++){
            int b2;
            cin >> b2;
            Union(b1, b2);
            exist[b2] = 1;
        }
    }
    int Q;
    cin >> Q;
    vector<string> res;
    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;

        int fa = find_father(a);
        int fb = find_father(b);
        if(fa == fb){
            res.push_back("Yes");
        }
        else{
            res.push_back("No");
        }
    }
    int trees=0;
    int bird_cnt=0;
    for(int i=1; i<MAX; i++){
        if(exist[i] == 1){
            bird_cnt++;
            if(father[i] == -1){
                trees++;
            }
        }
    }
    cout << trees << " " << bird_cnt << endl;
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
