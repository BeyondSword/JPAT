#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M, K;
const int MAXN = 1001;
int G[MAXN][MAXN];
bool vis[MAXN];
//queue<int> q;
vector<int> res;

void BFS(int s, int d) {
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			//Á¬Í¨
			if (G[n][i] && G[i][n] && i!=d && vis[i]==false) {
				vis[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		G[c1][c2] = G[c2][c1] = 1;
	}

	for (int i = 0; i < K; i++) {
		int query_city;
		cin >> query_city;
		fill(vis, vis + MAXN, false);
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (j != query_city && vis[j] == false) {
				cnt++;
				BFS(j, query_city);
			}
		}
		res.push_back(cnt);
	}

	//output
	for (int i = 0; i < res.size(); i++) {
		cout << res[i]-1 << endl;
	}
	return 0;
}