#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

namespace bj {

	/*���� �����̴� �������� ��� ���ӿ��� ���� �ʴ´�.������, �����̴� ���� ����� ���� �� �� ���� ������,
	�ڽ��� ���ϴ� ���� ����� ���� �ڽ��� ��û�� �Ƿ��� �������� ���Ѵٰ� �����ߴ�.

	���� ����� ������ ���� �����.

	���� Ƚ�� : X
	�̱� ���� : Y(Z%)
	Z�� �������� �·��̰�, �Ҽ����� ������.���� ���, X = 53, Y = 47�̶��, Z = 88�̴�.
	X�� Y�� �־����� ��, �����̰� ������ �ּ� �� �� �� �ؾ� Z�� ���ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	�� �ٿ� ���� X�� Y�� �־�����.

	���
	ù° �ٿ� �����̰� ������ �ּ� �� �� �� �ؾ��ϴ��� ����Ѵ�.���� Z�� ���� ������ �ʴ´ٸ� - 1�� ����Ѵ�.*/
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

	/*����̴� ���ܱ⿡ ���� H�� �����ؾ� �Ѵ�.
	���̸� �����ϸ� �鳯�� �����κ��� H���� ���� �ö󰣴�.
	�� ����, �� �ٿ� �������ִ� ������ ��� �����ع�����.
	����, ���̰� H���� ū ������ H ���� �κ��� �߸� ���̰�, ���� ������ �߸��� ���� ���̴�.
	���� ���, �� �ٿ� �������ִ� ������ ���̰� 20, 15, 10, 17�̶�� ����.
	����̰� ���̸� 15�� �����ߴٸ�, ������ �ڸ� ���� ���̴� 15, 15, 10, 15�� �� ���̰�,
	����̴� ���̰� 5�� ������ 2�� ������ ��� ���� �� ���̴�. (�� 7���͸� ���� ��� ����) ���ܱ⿡ ������ �� �ִ� ���̴� ���� ���� �Ǵ� 0�̴�.

	����̴� ȯ�濡 �ſ� ������ ���� ������, ������ �ʿ��� ��ŭ�� ������ ���������� �Ѵ�.
	�̶�, ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� ������ �� N�� ����̰� ������ ���������� �ϴ� ������ ���� M�� �־�����. (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)

	��° �ٿ��� ������ ���̰� �־�����.������ ������ ���� �׻� M���� ũ�ų� ���� ������, ����̴� ���� �ʿ��� ������ �׻� ������ �� �ִ�.
	���̴� 1,000,000,000���� �۰ų� ���� ���� ���� �Ǵ� 0�̴�.

	���
	��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ����Ѵ�.
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

		//H_saw == trees[0]�϶�
		//sum = 0;
		//H_saw == trees[1]�϶�
		//sum = trees[0] - trees[1]
		//H_saw == trees[2]�϶�
		//sum = trees[0] - trees[2] + trees[1] -trees[2]...
		//���� H_saw == trees[i]�϶�
		//sum = trees[0] - trees[i] + ... + trees[i-1] - trees[i]
		//=> SUM(trees j = 0; j < i) trees[j] - (i-1)trees[i]
		// � j�� ���ؼ�, sum(j) <= target <= sum(j+1)�� �����ϰ�( trees[j] > trees[j+1])
		// H_saw -- ���� sum += (j+1)
		// ���� H_saw = trees[j] - ceil({target - sum(j)} / j+1)
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

	/*����
	10, 000 ������ �ڿ����� �̷���� ���� N¥�� ������ �־�����.
	�� �������� ���ӵ� ������ �κ��� �߿� �� ���� S �̻��� �Ǵ� �� ��,
	���� ª�� ���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� N(10 �� N < 100, 000)�� S(0 < S �� 100, 000, 000)�� �־�����.��° �ٿ��� ������ �־�����.������ �� ���Ҵ� �������� ���еǾ��� ������, 10, 000������ �ڿ����̴�.

	���
	ù° �ٿ� ���ϰ��� �ϴ� �ּ��� ���̸� ����Ѵ�.���� �׷��� ���� ����� ���� �Ұ����ϴٸ� 0�� ����ϸ� �ȴ�.

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