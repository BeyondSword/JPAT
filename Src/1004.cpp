#include<iostream>
#include<queue>
#include<vector>

using namespace std;



int N,M;

struct{
    string ID;
    vector<int> childs;
}Node[100];

int toInt(string ID){
    int sum=0;
    for(int i=0; i<2; i++){
        sum = sum*10 + ID[i]-'0';
    }
    return sum;
}

int main(){
    int N,M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        string ID;
        int K;
        cin >> ID >> K;

        int indi = toInt(ID);
        Node[indi].ID = ID;
        for(int j=0; j<K; j++){
            string ch;
            cin >> ch;
            Node[indi].childs.push_back(toInt(ch));
        }
    }
    //input end;
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    int cnt=0;
    int last_depth = 0;
    //建一个存储深度的数组也可以处理
    while(!q.empty()){
        int indi = q.front().first;
        int depth = q.front().second;
        //leaf
        q.pop();

        //新层
        if(depth > last_depth){
            if(last_depth > 0){
                printf(" ");
            }
            printf("%d", cnt);
            cnt = 0;
            last_depth = depth;
        }

        if(Node[indi].childs.empty()){
            cnt++;
        }


        for(int i=0; i<Node[indi].childs.size(); i++){
            q.push(make_pair(Node[indi].childs[i], depth+1));
        }
    }

    if(last_depth > 0){
        printf(" ");
    }
    printf("%d", cnt);
    return 0;
}

