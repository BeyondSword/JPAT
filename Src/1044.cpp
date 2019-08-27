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
                //加出来的，当前j指向串首
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
            //第i个数被切
            sum -= nums[i];
            i++;
            if(sum-M>=0){
                //剪出来的，j已经指向串首的下一元素
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
