#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, prob;
bool num[21];
long long arr[21];
long long input_list[21];

void makeFactorial(int n) {
	long long result = 1;
	for (int i = 1; i < n; i++) {
		result *= i;
		arr[N - 1 - i] = result;
	}
	//arr = N-1! -> N-2! -> N-3! -> ,,,, ->1
}


void whatIsArr(long long k) {
	k = k - 1; //0~k-1
	long long locate, cnt, temp = 0;

	//
	for (int i = 0; i <N-2; i++) {
			
		locate = (k / arr[i]); //이번에 몇번째 자리?
		cnt = -1;
		for (int t = 0; t < N; t++) {
			if (num[t] == false) { 
				cnt++; //사용 안한 숫자 몇개

				if (cnt == locate) { 
					cout << t + 1 << " ";
					num[t] = true;
					break;
				}				
			}
		}
		k %= arr[i];
	}

	cnt = -1;

	//마지막 남은 두개 정하기
	for (int t = 0; t < N; t++) {
		if (num[t] == false) {
			cnt++;
			if (cnt == k) {
				cout << t + 1<<" ";
				num[t] = true;
			}
			else 
				temp = t + 1;
		}
	}
	cout << temp <<endl;
}

void wharIsK() {
	long long cnt = 0, sum = 1, locate, number;

	for (int i = 0; i < N - 1;i++) {
		number = input_list[i]; 
		cnt = 0;

		for (int j = 0; j < N; j++) {
			if (num[j] == false) {
				cnt++;
				if (j+1 == number) {
					locate = cnt;  num[j] = true;
					break;
				}
			}
		}

		sum += (locate -1) * arr[i]; //몇번째 구간 인지 더해주기
	}
	cout << sum << endl;
}

int main() {
	
	cin >> N;
	cin >> prob;
	if (prob == 1) {
		long long k;
		cin >> k;
		makeFactorial(N);
		whatIsArr(k);
	}
	else {
		long long input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			input_list[i] = input;
		}
		makeFactorial(N);
		wharIsK();

	}

	return 0;
}