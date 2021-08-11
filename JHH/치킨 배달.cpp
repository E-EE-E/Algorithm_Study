#include <iostream>
#include<algorithm>
#include <vector>
#include<tuple>
#include<cmath>
#include <climits>
#include <cstring>

using namespace std;
int N, M;
int **arr;
bool visit[13];
vector<pair<int,int>> house_list;
vector<pair<int,int>> chicken_list;

vector<pair<int, int>> minimum_list;

int max_store;
int min_dist;
int find_distance() {
	int result = 0;
	int house_x, house_y;
	int x, y;
	
	for (int i = 0; i < house_list.size(); i++) {//모든 집에 대하여
		int dist = 99999;
		tie(house_x, house_y) = house_list[i];
		for (int j = 0; j < minimum_list.size(); j++) { //현재 선택된 집들돌면서 거리 측정
			tie(x, y) = minimum_list[j];
			int d = abs(house_x - x) + abs(house_y - y);
			dist = min(dist, d);
		}

		result += dist;
	}

	return result;
}

void DFS(int cnt, int idx) { //선택한 치킨집 개수, 현재 선택한 치킨집 번호

	

	
	if (cnt>0 && cnt <= M) { //최대 M개 선택가능.
		//거리 합 구하기.
		int neighbor_distance = find_distance();
		if (neighbor_distance <= min_dist) {
			max_store = cnt;
			min_dist = neighbor_distance;
		}
	}
	
	if (cnt == M)
		return;

	for (int i = idx; i < chicken_list.size(); i++) {
	
		if (visit[i] == true) continue;
		minimum_list.push_back(chicken_list[i]);
		visit[i] = true;
		DFS(cnt + 1, i);
		visit[i]=false;
		minimum_list.pop_back();
		//DFS(cnt, idx + 1);
	}
}


int main() {
	cin >> N>>M;

	int num = 0;
	//집, 치킨집 위치 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> num;

			if (num == 1) {
				house_list.push_back(make_pair(i, j));
			}
			else if(num == 2) {
				chicken_list.push_back(make_pair(i, j));
			}
		}
	}
	
	
	//백트래킹 시작
	max_store = 0;
	min_dist = 99999;

	DFS(0,0);

	cout <<  min_dist;


}