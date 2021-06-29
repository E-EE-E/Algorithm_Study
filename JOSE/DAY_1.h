#pragma once
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;

namespace bj {
	/*문제
	N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때,
	이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

	입력
	첫째 줄에 자연수 N(1 ≤ N ≤ 100, 000)이 주어진다.
	다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
	다음 줄에는 M(1 ≤ M ≤ 100, 000)이 주어진다.
	다음 줄에는 M개의 수들이 주어지는데,
	이 수들이 A안에 존재하는지 알아내면 된다.
	모든 정수의 범위는 - 231 보다 크거나 같고 231보다 작다.

	출력
	M개의 줄에 답을 출력한다.존재하면 1을,
	존재하지 않으면 0을 출력한다.

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
	* 학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
	* 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
	* 비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 그 자리에 새롭게 추천받은 학생의 사진을 게시한다. 이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
	* 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
	* 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
	* 입력
	* 첫째 줄에는 사진틀의 개수 N이 주어진다. (1≤N≤20) 둘째 줄에는 전체 학생의 총 추천 횟수가 주어지고, 셋째 줄에는 추천받은 학생을 나타내는 번호가 빈 칸을 사이에 두고 추천받은 순서대로 주어진다. 총 추천 횟수는 1,000번 이하이며 학생을 나타내는 번호는 1부터 100까지의 자연수이다.
	*
	* 출력
	* 사진틀에 사진이 게재된 최종 후보의 학생 번호를 증가하는 순서대로 출력한다.
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

			//3중 for문으로 i, j 주변으로 찾기 => Time Limit Exceeded
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