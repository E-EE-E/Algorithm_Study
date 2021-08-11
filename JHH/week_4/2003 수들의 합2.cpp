#include <iostream>

using namespace std;

int main() {
	int *arr;
	int N, M;
	cin >> N>>M;

	arr = new int[N];

	int start=0, end=0;
	int sum = 0, cnt=0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (start = 0; start < N; start++) {
		while (end<N && sum<M)
		{
			 sum += arr[end];
			 end++;
		}
		if (sum == M)
			cnt++;
		sum -= arr[start];
	}

	cout << cnt;

	delete[] arr;
}