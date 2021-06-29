#pragma once
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;

namespace bj {
	/*����
	N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��,
	�� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �ڿ��� N(1 �� N �� 100, 000)�� �־�����.
	���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
	���� �ٿ��� M(1 �� M �� 100, 000)�� �־�����.
	���� �ٿ��� M���� ������ �־����µ�,
	�� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�.
	��� ������ ������ - 231 ���� ũ�ų� ���� 231���� �۴�.

	���
	M���� �ٿ� ���� ����Ѵ�.�����ϸ� 1��,
	�������� ������ 0�� ����Ѵ�.

	5
	4 1 5 2 3
	5
	1 3 7 9 5

	*/
	int P1920()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int N, M;
		int n, m;
		cin >> N;
		//set<int> A;			search time :	O(log n)		(100ms)
		//unordered_set<int> A;					O(1) (Average)	(64ms)
		//unordered_map<int, int> A; //			O(log n)		(74ms)

		unordered_set<int> A;
		while (N--)
		{
			cin >> n;
			A.insert(n);
		}

		cin >> M;
		const auto end = A.end();
		while (M--)
		{
			cin >> m;
			cout << static_cast<int>(A.find(m) != end) << "\n";
		}

		return 0;
	}
	/*
	* �л����� ��õ�� �����ϱ� ���� ��� ����Ʋ�� ����ִ�.
	* � �л��� Ư�� �л��� ��õ�ϸ�, ��õ���� �л��� ������ �ݵ�� ����Ʋ�� �ԽõǾ�� �Ѵ�.
	* ����ִ� ����Ʋ�� ���� ��쿡�� ������� ��õ ���� Ƚ���� ���� ���� �л��� ������ �����ϰ�, �� �ڸ��� ���Ӱ� ��õ���� �л��� ������ �Խ��Ѵ�. �̶�, ������� ��õ ���� Ƚ���� ���� ���� �л��� �� �� �̻��� ��쿡�� �׷��� �л��� �� �Խõ� �� ���� ������ ������ �����Ѵ�.
	* ���� ������ �Խõ� �л��� �ٸ� �л��� ��õ�� ���� ��쿡�� ��õ���� Ƚ���� ������Ų��.
	* ����Ʋ�� �Խõ� ������ �����Ǵ� ��쿡�� �ش� �л��� ��õ���� Ƚ���� 0���� �ٲ��.
	* �Է�
	* ù° �ٿ��� ����Ʋ�� ���� N�� �־�����. (1��N��20) ��° �ٿ��� ��ü �л��� �� ��õ Ƚ���� �־�����, ��° �ٿ��� ��õ���� �л��� ��Ÿ���� ��ȣ�� �� ĭ�� ���̿� �ΰ� ��õ���� ������� �־�����. �� ��õ Ƚ���� 1,000�� �����̸� �л��� ��Ÿ���� ��ȣ�� 1���� 100������ �ڿ����̴�.
	*
	* ���
	* ����Ʋ�� ������ ����� ���� �ĺ��� �л� ��ȣ�� �����ϴ� ������� ����Ѵ�.
	*
	* 3
	* 9
	* 2 1 4 3 5 6 2 7 2
	*
	* 3
	* 14
	* 2 1 4 3 5 6 2 7 2 100 100 54 54 50
	*/
	int P1713()
	{
		int N, CandidateCount;
		cin >> N >> CandidateCount;

		vector<pair<int, int>> picFrame;

		while (CandidateCount--)
		{
			int recommand;
			cin >> recommand;
			auto findCandidate = find_if(picFrame.begin(), picFrame.end(), [&recommand](const auto& pic)
				{
					return recommand == pic.first;
				});

			if (findCandidate == picFrame.end())
			{
				if (picFrame.size() == N)
				{
					picFrame.erase(min_element(picFrame.begin(), picFrame.end(), [](const auto& one, const auto& theOther)
						{
							return one.second < theOther.second;
						}
					));
				}
				picFrame.emplace_back(recommand, 1);
			}
			else
			{
				(*findCandidate).second++;
			}
		}

		sort(picFrame.begin(), picFrame.end(), [](const auto& one, const auto& theOther)
			{
				return one.first < theOther.first;
			}
		);

		for (auto& candidate : picFrame)
			cout << candidate.first << " ";

		return 0;
	}

	int P15686()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		constexpr int HOUSE = 1;
		constexpr int CHIKIEN = 2;

		int N, M;
		cin >> N >> M;

		vector<vector<int>> City(N, vector<int>(N));
		vector<pair<int, int>> chikens;
		vector<pair<int, int>> houses;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int block;
				cin >> block;
				City[i][j] = block;
				if (block == HOUSE)
					houses.emplace_back(i, j);
				else if (block == CHIKIEN)
					chikens.emplace_back(i, j);
			}
		}

		vector<bool> visits(chikens.size());
		for (int i = 0; i < M; ++i)
			visits[i] = true;

		int answer = INT_MAX;

		auto _chikenLength = [&](pair<int, int> house)
		{
			int minDistance = INT_MAX;
			for (int k = 0; k < chikens.size(); ++k)
			{
				if (visits[k])
					minDistance = min(minDistance, abs(chikens[k].first - house.first) + abs(chikens[k].second - house.second));
			}

			//3�� for������ i, j �ֺ����� ã�� => Time Limit Exceeded
			/*
			const auto max_distance = 2 * (N - 1);
			for (int distance = 1; distance <= max_distance; ++distance)
			{
				for (int p = -distance; p <= distance; ++p)
				{
					if (i + p < 0 || N <= i + p)
						continue;

					for (int q = -distance; q <= distance; ++q)
					{
						if (j + q < 0 || N <= j + q)
							continue;

						if (abs(p) + abs(q) == distance && City[i + p][j + q] == 2)
						{
							return distance;
						}
					}
				}
			}
			return -1;
			*/

			return minDistance;
		};

		do
		{
			for (int i = 0; i < chikens.size(); ++i)
				City[chikens[i].first][chikens[i].second] = visits[i] ? 2 : 0;

			int cityDistance = 0;
			for (auto& house : houses)
			{
				if (cityDistance > answer)
					break;
				cityDistance += _chikenLength(house);
			}

			answer = min(answer, cityDistance);
		} while (prev_permutation(visits.begin(), visits.end()));


		cout << answer;
		return 0;
	}
}