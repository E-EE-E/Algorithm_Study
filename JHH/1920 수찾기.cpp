#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int M, N;
int *A_arr;

int findNum(int num) {
	int left, right, mid;
	
	left = 0;
	right = N-1;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (A_arr[mid] == num) {
			return 1;
		}
		if (A_arr[mid] > num) {
			right = mid - 1;
			
		}
		else {
			left = mid + 1;
		}
	}

	return 0;
}

int main() {
	scanf("%d", &N);
	A_arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A_arr[i]);
	}
	//cin >> M;
	scanf("%d", &M);

	sort(A_arr, A_arr+N);

	int num;
	//A_arr에 M_arr있는지 확인
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		printf("%d\n", findNum(num));
	}
	
	delete A_arr;

	return 0;
}