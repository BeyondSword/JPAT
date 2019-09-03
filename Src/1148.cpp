#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAXN = 101;

int stat[MAXN];
int is_wolf[MAXN];

int N;
vector<pair<int,int> > res;

bool cmp(pair<int, int> &A, pair<int, int> &B){
    if(A.first == B.first){
        return A.second < B.second;
    }
    return A.first<B.first;
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> stat[i];
    }
    //input end
    fill(is_wolf, is_wolf+MAXN, -1);
    //����һ��˵�ѵ���Ϊi
    int ok=1;
    for(int i=1; i<=N; i++){
        //˵���ˣ���ָ����ת
        stat[i] = -stat[i];
        //����ڶ���˵�ѵ���Ϊj,������
        int j;
        for(j=1; j<=N; j++){
            fill(is_wolf, is_wolf+MAXN, -1);
            if(j == i){
                continue;
            }
            stat[j] = -stat[j];
            int human_cnt=1;
            int wolf_cnt=1;
            is_wolf[j] = 1;
            is_wolf[i] = 0;
            ok=1;
            for(int k=1; k<=N; k++){
                int indi = abs(stat[k]);

                if(is_wolf[indi] != -1){
                    //֤�����ˣ���ʾ����
                    if((stat[k] > 0 && is_wolf[indi] == 1)||
                       (stat[k] < 0 && is_wolf[indi] == 0)){
                        ok=0;
                        break;
                    }
                }
                //֤�ʲ�ì��,��¼
                stat[k] > 0? is_wolf[indi]=0:is_wolf[indi]=1;
                if(stat[k] > 0){
                    human_cnt ++;
                }
                else{
                    wolf_cnt ++;
                }
            }
            //��ԭ
            stat[j] = -stat[j];
            //��ì��
            if(ok == 1){
                //�Ƿ�ǡ������
                wolf_cnt = 0;
                int hum_cnt = 0;
                int fir = -1;
                int sec = -1;
                for(int k=1; k<=N; k++){
                    if(is_wolf[k] == 1){
                        wolf_cnt ++;
                        if(fir == -1){
                            fir = k;
                        }
                        else{
                            sec = k;
                        }
                    }
                    else{
                        hum_cnt ++;
                    }
                }
                if(wolf_cnt==2 && hum_cnt==N-2 && (fir == j || sec == j)){
                    pair<int, int> p;
                    if(fir > sec){
                        swap(fir, sec);
                    }
                    p.first = fir;
                    p.second = sec;
                    res.push_back(p);
                }
            }
        }

        //��ԭ
        stat[i] = -stat[i];
    }
    sort(res.begin(), res.end(), cmp);
    if(res.size() == 0){
        cout << "No Solution";
    }
    else{
        cout << res[0].first << " " << res[0].second;
    }
    return 0;
}
