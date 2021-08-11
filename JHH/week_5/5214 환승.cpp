#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
int min_val;

queue <pair<int,int>> qu; //tubenum, cnt
int main() {
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);

	vector<vector<int>>  v(N+1); //N개 역
	vector<vector<int>> tubes; //M개 하이퍼 튜브들
	bool tube_visit[1001] = { false, };
	bool station_visit[100001] = { false, };
	int tube_num=0;
	int input;

	for (int i = 0; i < M; i++) {
		vector<int> hyperTube;
		for (int j = 0; j < K; j++) {
			scanf("%d", &input);
			v[input].push_back(tube_num); //N번 역에 연결된 튜브 번호 저장
			hyperTube.push_back(input); //하이퍼 튜브에 푸시
		}
		tubes.push_back(hyperTube); tube_num++;
	}
	

	/* 1번째 역에 연결된 튜브번호, cnt, 현재 역 번호 큐에 푸시*/
	for (int i = 0; i < v[1].size(); i++) {
		qu.push(make_pair(v[1][i], 1));
		tube_visit[v[1][i]] = true;
	}
	station_visit[1] = true;
	
	min_val = INT_MAX;

	while (!qu.empty())
	{
		int tube_num, cnt;
		tie(tube_num,cnt) = qu.front();
		qu.pop();
		

		vector<int> t = tubes[tube_num];
		//한 튜브에서 갈 수 있는 모든 역에 연결된 튜브들 큐에 푸시
		for (int i = 0; i < t.size(); i++) { //K번 수행
			int station = t[i];
			if (station == N) {			
				/* if (N == 1) -> 이동안하고 도착
					1 1 1
					1 
					ans : 1
				*/
				if(N!=1){
					cnt = cnt + 1;
				}
					
				
				if (cnt < min_val) {
					min_val = cnt;
				}
				break;
			}


			if (station_visit[station]) //방문한 역 pass
				continue;

			for (int j = 0; j < v[station].size(); j++) { //역에 연결된 튜브로 이동
				int tube = v[station][j]; 
				if (tube_visit[tube]) //방문한 튜브 pass
					continue;

				qu.push(make_pair(tube, cnt + 1));
				tube_visit[tube_num] = true;
			}
			station_visit[station] = true;
		}

	}

	if (min_val == INT_MAX)
		cout << -1;
	else
		cout << min_val;
	return 0;
}