#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

namespace bj {

	/*이제 형택이는 앞으로의 모든 게임에서 지지 않는다.하지만, 형택이는 게임 기록을 삭제 할 수 없기 때문에,
	자신의 못하던 예전 기록이 현재 자신의 엄청난 실력을 증명하지 못한다고 생각했다.

	게임 기록은 다음과 같이 생겼다.

	게임 횟수 : X
	이긴 게임 : Y(Z%)
	Z는 형택이의 승률이고, 소수점은 버린다.예를 들어, X = 53, Y = 47이라면, Z = 88이다.
	X와 Y가 주어졌을 때, 형택이가 게임을 최소 몇 번 더 해야 Z가 변하는지 구하는 프로그램을 작성하시오.

	입력
	각 줄에 정수 X와 Y가 주어진다.

	출력
	첫째 줄에 형택이가 게임을 최소 몇 판 더 해야하는지 출력한다.만약 Z가 절대 변하지 않는다면 - 1을 출력한다.*/
	int P1072()
	{
		long long X, Y;
		cin >> X >> Y;

		auto Z_ini = static_cast<const int>(floorl(100.0 * Y / X));
		if (Z_ini >= 99)
		{
			cout << -1;
			return 0;
		}
		else if (X == 0)
		{
			cout << 1;
			return 0;
		}

		const auto Z_target = static_cast<long double>(Z_ini + 1) / 100.0;
		cout << static_cast<long long>(ceill((Z_target * X - Y) / (1 - Z_target)));
		return 0;
	}

	/*상근이는 절단기에 높이 H를 지정해야 한다.
	높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다.
	그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다.
	따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다.
	예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자.
	상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고,
	상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다) 절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.

	상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다.
	이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

	둘째 줄에는 나무의 높이가 주어진다.나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다.
	높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

	출력
	적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
	5 20
	4 42 40 26 46

	4 7
	20 15 10 17
	*/
	int P2805()
	{
		int N, M;
		cin >> N >> M;
		vector<long long> trees(N);
		for (auto& tree : trees)
		{
			cin >> tree;
		}

		sort(trees.rbegin(), trees.rend());//O(n log n)

		//H_saw == trees[0]일때
		//sum = 0;
		//H_saw == trees[1]일때
		//sum = trees[0] - trees[1]
		//H_saw == trees[2]일때
		//sum = trees[0] - trees[2] + trees[1] -trees[2]...
		//따라서 H_saw == trees[i]일때
		//sum = trees[0] - trees[i] + ... + trees[i-1] - trees[i]
		//=> SUM(trees j = 0; j < i) trees[j] - (i-1)trees[i]
		// 어떤 j에 대해서, sum(j) <= target <= sum(j+1)가 존재하고( trees[j] > trees[j+1])
		// H_saw -- 마다 sum += (j+1)
		// 따라서 H_saw = trees[j] - ceil({target - sum(j)} / j+1)
		//TODO 1 FIND j

		int j = 0;
		bool flag = true;
		int sum = 0;
		for (int i = 1; i < trees.size() && flag; ++i) //O(n^2)
		{
			sum = 0;
			for (j = 0; j < i; ++j)
			{
				sum += (trees[j] - trees[i]);
			}

			if (sum == M)
			{
				//lucky case
				cout << trees[i];
				return 0;
			}
			else if (sum > M)
			{
				flag = false;
				break;
			}
		}

		cout << ceill(trees[j] + (long double)(sum - M) / j);

		return 0;
	}

	/*문제
	10, 000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
	이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중,
	가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N(10 ≤ N < 100, 000)과 S(0 < S ≤ 100, 000, 000)가 주어진다.둘째 줄에는 수열이 주어진다.수열의 각 원소는 공백으로 구분되어져 있으며, 10, 000이하의 자연수이다.

	출력
	첫째 줄에 구하고자 하는 최소의 길이를 출력한다.만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

	10 15
	5 1 3 5 10 7 4 9 2 8*/
	int P1806()
	{
		int N, S;
		cin >> N >> S;
		vector<int> inputs(N);
		int tot = 0;
		for (auto& element : inputs)
		{
			cin >> element;
			tot += element;
		}

		if (tot < S)
		{
			cout << 0;
			return 0;
		}
		else if (S == 0)
		{
			cout << 1;
			return 0;
		}

		int left = 0, right = 0;
		int min_len = INT_MAX;
		int subSum = 0;
		while (left <= right)
		{
			if (subSum >= S)
			{
				min_len = min(min_len, right - left);
				subSum -= inputs[left++];
			}
			else if (right == N)
			{
				break;
			}
			else
				subSum += inputs[right++];
		}

		cout << min_len;
		return 0;
	}
}