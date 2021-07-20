#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

int N, H;
deque<int> top, bottom;
int main() {
	scanf("%d %d", &N, &H);

	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (i % 2 == 0) {
			bottom.push_back(input); //석순 따로
		}
		else {
			top.push_back(input); //종유석 따로
		}
		
	}
	sort(top.begin(), top.end(),greater<int>()); // 내림차순 정렬, 큰것부터
	sort(bottom.begin(), bottom.end(), greater<int>());


	int min_val = INT_MAX;
	int min_cnt = 0;

	//종유석
	vector<int> ans(H);
	int before_cnt = 0;
	for (int h = H-1; h >=0; h--) { //각 칸 순회하기(H)
		
		
		if (!top.empty()) {
			int cnt = 0;
			while (!top.empty() && top.front() == h+1) //높이가 h인 것 -> h번째 칸
			{
				top.pop_front();
				cnt++;
			}
			//이번 칸에 뚫어야 되는것 : 이번 칸에 높이 h 인것 개수 + 나보다 높이 컸던 것(이전 칸에서 뚫은 것 개수)
			ans[h] = before_cnt + cnt;
			before_cnt = ans[h];
		}
		else {
			ans[h] = before_cnt;
		}
		
	}

	//석순
	vector<int> ans2(H);
	before_cnt = 0;
	for (int h = H - 1; h >= 0; h--) {

		if (!bottom.empty()) {
			int cnt = 0;
			while (!bottom.empty() && bottom.front() == h + 1)
			{
				bottom.pop_front();
				cnt++;
			}
			//이전 칸  + 이번 칸에 높이 h 인
			ans2[H - 1 - h] = before_cnt + cnt;
			before_cnt = ans2[H - 1 - h];
		}
		else {
			ans2[H - 1 - h] = before_cnt;
		}
		
	}

	
	for (int h = 0; h <H; h++) {
		if (ans[h]+ans2[h] < min_val) {
			min_val = ans[h] + ans2[h]; min_cnt = 1;
		}
		else if(ans[h] + ans2[h] == min_val){
			min_cnt++;
		}
	}

	printf("%d %d", min_val, min_cnt);
	return 0;

}