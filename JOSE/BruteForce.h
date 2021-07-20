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

		//�Ʒ� ��������
		//index�� �ҋ����� ���غ��� �� ����
		//N^2�̳� N(N-1)�̳�... �ű⼭ �ű�ϱ� �׳� ��.
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
		//M * N ũ���� ����

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
			//1. ���� �� �ִ� 88������ ����,
			for (int k = 0; k <= N - UNIT_SIZE; ++k)
			{
				vector<string> truncated;
				int count = 0;

				for (int i = 0; i < UNIT_SIZE; ++i)
				{
					truncated.emplace_back(raw[k + i], j, UNIT_SIZE);
				}

				//2. �����ؾ��ϴ� cell ���� �ľ�.
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