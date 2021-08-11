#include <iostream>
#include<algorithm>
#include<vector>
#include <cmath>

using namespace std;

int main() {
	int N;
	double M;
	vector<int> trees;

	int tree;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree;
		trees.push_back(tree);
	}

	sort(trees.begin(), trees.end());
	
	int left = 0;
	int right = trees.back();
	int mid = (left+right) / 2;

	int max_height = 0;
	int temp_block = 0;
	while (left < right) {
		double block=0; //잘려진 목재 길이
		for (int i = 0; i < N; i++) {
			temp_block = (trees[i] - mid);
			if (temp_block < 0)
				temp_block = 0;
			block += temp_block;
		}
		if (block >= M) { //
			if (mid <= max_height) {
				break; // 이미 최대를 찾았으면 갈 필요 없지
			}
			else {
				max_height = mid;
			}
			left = mid;
			mid = (mid + right) / 2;
		}
		else {
			right = mid;
			mid = (mid + left) / 2;
		}
	}

	cout << max_height;
	



	return 0; 
}