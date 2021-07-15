#pragma once

#include <iostream>

using namespace std;

namespace bj {

	int P7568()
	{
		int peopleCount;
		cin >> peopleCount;

		vector<pair<int, int>> bulks;
		while (peopleCount--)
		{
			int w, h;
			cin >> w >> h;
			bulks.emplace_back( w, h );
		}

		auto isBigger = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.first > rhs.first && lhs.second > rhs.second;
		};

		//아래 루프에서
		//index로 할떄보다 손해보긴 함 ㅋㅋ
		//N^2이나 N(N-1)이나... 거기서 거기니까 그냥 함.
		for (const auto& bulk : bulks)
		{
			int rank = 1;
			for (const auto& other : bulks)
			{
				if (isBigger(other, bulk))
					++rank;
			}
			cout << rank << " ";
		}

		return 0;
	}

	int P1018()
	{
		constexpr auto UNIT_SIZE = 8;
		constexpr auto WHITE = 'W';
		constexpr auto BLACK = 'B';

		int N, M;
		cin >> N >> M;
		//M * N 크기의 보드

		int h = N;
		vector<string> raw;
		while (h--)
		{
			string row;
			cin >> row;
			raw.push_back(row);
		}

		int answer = INT_MAX;

		for (int j = 0; j <= M - UNIT_SIZE; ++j)
		{
			//1. 만들 수 있는 88사이즈 마다,
			for (int k = 0; k <= N - UNIT_SIZE; ++k)
			{
				vector<string> truncated;
				int count = 0;

				for (int i = 0; i < UNIT_SIZE; ++i)
				{
					truncated.emplace_back(raw[k + i], j, UNIT_SIZE);
				}

				//2. 수정해야하는 cell 개수 파악.
				int blackCaseCount = 0;
				int whiteCaseCount = 0;

				for (size_t i = 0; i < UNIT_SIZE; i++)
				{
					for (size_t j = 0; j < UNIT_SIZE; j++)
					{
						const auto isOdd = (i + j) & 1;
						if (isOdd && truncated[i][j] == BLACK || !isOdd && truncated[i][j] == WHITE)
							blackCaseCount++;

						if (isOdd && truncated[i][j] == WHITE || !isOdd && truncated[i][j] == BLACK)
							whiteCaseCount++;
					}
				}

				answer = min(answer, min(blackCaseCount, whiteCaseCount));
			}

		}
		cout << answer;

		return 0;
	}

	int P1436()
	{
		int Nth;
		cin >> Nth;

		int count = 0;
		for (long long i = 666;; ++i)
		{
			if (to_string(i).find("666") != string::npos)
			{
				++count;
			}
			else continue;

			if (Nth == count)
			{
				cout << i;
				return 0;
			}
		}

		return 0;
	}
}