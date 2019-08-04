#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>

using namespace std;


//�ڽӾ��� + ���ȶ���
int team[501];
int max_team[501];
int routes[501];
int dp[501];
int G[501][501];

const int INF = 0x3fffffff;

class comparison{
public:
    bool operator ()(const int &a, const int &b){
        return dp[a] > dp[b];
    }
};

int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++) {
		cin >> team[i];
	}
	for (int i = 0; i < M; i++) {
		int u,v,len;
		scanf("%d%d%d", &u, &v, &len);
		G[u][v] = G[v][u] = len;
	}
	//input end;
	//memset(dp, -2, 501 * sizeof(int));
	for(int i=0; i<501; i++){
        dp[i] = INF;
	}
	dp[C1] = 0;
	max_team[C1] = team[C1];
	routes[C1] = 1;
	priority_queue<int, vector<int>, comparison> pq;
	pq.push(C1);
    bool vis[501];
    fill(vis, vis+501, false);
	//initialize end
	for (int i = 0; i < N; i++) {
		//find min len

        int indice = pq.top();
        pq.pop();
		if (dp[indice] == INF) {
			break;
		}
		//update ��������
		vis[indice] = true;
		for (int j = 0; j<N; j++) {
			if(vis[j]==true || !G[indice][j]){
                continue;
			}
			if (dp[j] > dp[indice] + G[indice][j]) {
				//�������·��
				dp[j] = dp[indice] + G[indice][j];
				//����·����
				routes[j] = routes[indice];
				//��������Ȩ
				max_team[j] = max_team[indice] + team[j];
				//�������ȶ���
				pq.push(j);
			}
			//���·������
			else if (dp[j] == dp[indice] + G[indice][j]) {
				//����·��
				routes[j] += routes[indice];
				//�Ƚ�����Ȩ,ȡ�ϴ���
				if (max_team[j] < max_team[indice] + team[j]) {
					max_team[j] = max_team[indice] + team[j];
				}
			}
		}
	}

	cout << routes[C2] << " " << max_team[C2];
	return 0;
}
