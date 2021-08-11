#include <iostream>

using namespace std;

int main() {
	long long F[92];
	int N;

	cin >> N;
	F[0] = 1; F[1] = 1;
	for (int i = 2; i <= N; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}

	cout << F[N - 1] << endl;

}