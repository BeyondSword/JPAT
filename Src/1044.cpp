#include<iostream>
#include<vector>

using namespace std;

const int MAXN=100001;
int N, M;

int nums[MAXN];

const int INF=0x3fffffff;
vector<pair<int, int> > res;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    int i=0, j=0;
    int sum=0;
    int MIN = INF;
    while(i<N && i<=j){
        if(sum < M){
            if(j >= N){
                break;
            }
            sum += nums[j];
            if(sum-M>=0){
                //�ӳ����ģ���ǰjָ����
                if(sum-M<MIN){
                    MIN = sum-M;
                    res.clear();
                    res.push_back(make_pair(i, j));
                }
                else if(sum-M==MIN){
                    res.push_back(make_pair(i, j));
                }
            }
            j++;
        }
        else{
            //��i��������
            sum -= nums[i];
            i++;
            if(sum-M>=0){
                //�������ģ�j�Ѿ�ָ���׵���һԪ��
                if(sum-M<MIN){
                    MIN = sum-M;
                    res.clear();
                    res.push_back(make_pair(i, j-1));
                }
                else if(sum-M==MIN){
                    res.push_back(make_pair(i, j-1));
                }
            }
        }
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i].first+1 << '-' << res[i].second+1 << endl;
    }
    return 0;
}
