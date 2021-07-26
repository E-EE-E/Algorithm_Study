#include <iostream>

using namespace std;
int N, M;
long long comb[31][31];
void combination() {
	//nCr = comb[n][r]
	comb[1][0] = 1;
	comb[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= 30; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

}

int main() {
	int T;
	scanf("%d", &T);
	combination();
	while (T--)
	{
		scanf("%d %d", &N, &M);
		printf("%lld \n", comb[M][N]);

	}

	return 0;
}