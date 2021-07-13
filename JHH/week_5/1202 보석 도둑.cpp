#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> bags;
vector<pair<int, int>> jewels;  
priority_queue<int> jewel_pq;



int main() {

	int N, K;
	scanf("%d %d", &N, &K);
	
	int M, V;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &M, &V);
		jewels.push_back(make_pair(M, V));
	}

	//보석들 : 무게 오름차순 정렬
	sort(jewels.begin(), jewels.end());
	
	int C;
	// 가방 : 크기 오름차순 정렬
	for (int i = 0; i < K; i++) {
		scanf("%d", &C);
		bags.push(-C);
	}



	long long jewel_sum = 0;
	int idx = 0;
	while (!bags.empty())
	{
		int bag_weight = - bags.top();
		bags.pop();

		// 가방 정렬 되어있으므로, 이전 가방이 담은 보석은 다음 가방도 담을 수 있다.
		// 그 다음 가방(idx)부터 검사
		for (int i = idx; i < jewels.size(); i++) {
			if (jewels[i].first <= bag_weight) { // 
				jewel_pq.push(jewels[i].second);
				idx = i+1;
			}
			else { //보석 무게 정렬되어 있음, 가방보다 크면 볼 필요 없음.
				break;
			}
		}
		if (!jewel_pq.empty()) { //담을 수 있는 것중 가장 큰 값 저장
			jewel_sum += jewel_pq.top();
			jewel_pq.pop(); //두 번 담을 수 없으므로 pop
		}
	}

	
	printf("%lld", jewel_sum);
	return 0;
}
