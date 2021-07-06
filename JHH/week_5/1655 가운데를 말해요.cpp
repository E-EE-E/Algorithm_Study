#include <iostream>
#include <queue>
using namespace std;

int *heap;
int heap_size;
priority_queue<int> lower; // 중간 값 ~ 아랫 값 -> 내림차순 lower의 top 이 
priority_queue<int> upper; // 중간 값 윗 값 -> 오름차순
int main() {

	int N;
	scanf("%d", &N);
	heap = new int[N];
	int input;
	//1, 5, 2, 10, -99, 7, 5

	//1회차 (N>=1)
	scanf("%d", &input);
	lower.push(input);
	printf("%d \n", lower.top());

	for (int i = 1; i < N; i++) {
		scanf("%d", &input);

		
		if (lower.size() > upper.size()) { 
			/* CASE 1
				lower : 2 1 
				upper : 5 
				input = 1 -> 새 중간값 1, lower의 2를 이동.
			*/
			if (input < lower.top()) {
				upper.push(-lower.top());
				lower.pop();
				lower.push(input);
			}
			else {
				upper.push(-input);
			}
		}
		else {
			/* CASE 2
			lower : 2 1
			upper : 5 10
			input = 6 -> 새 중간값 5, upper의 5를 lower로 이동.
			*/
			if (input > -upper.top()) {
				lower.push(-upper.top());
				upper.pop();
				upper.push(-input);
			}
			else {
				lower.push(input);
			}
		}

		printf("%d \n", lower.top());
	}
	return 0;
}
