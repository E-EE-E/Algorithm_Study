#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
vector<vector<int>> ans;
map<int, int> dup;
int select_num[8];
bool chk[8];

void DFS(int cnt) {
	if (cnt == M) {
		vector<int> newV;
		int num = 0;
		for (int i = 0; i < M; i++) {
			num = num * 10 + select_num[i]; //겹치는 것 찾는 용도
			newV.push_back(select_num[i]);
		}
		if (dup.find(num) == dup.end()) { // 안 겹칠때만 푸시
			ans.push_back(newV);
			dup.emplace(num, 0);
		}
		
		return;
	}
	
	for (int i = 0; i < N;i++) {
		if (chk[i] != true) {
			select_num[cnt] = nums[i];
			chk[i] = true;
			DFS(cnt + 1);
			chk[i] = false;
		}		
	}
}

int main() {

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums[i] = num;
	}
	DFS(0);
	
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		for (int i : ans[i]) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}