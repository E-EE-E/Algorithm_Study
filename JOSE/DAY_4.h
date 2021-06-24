#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
//#include <unordered_set>
#include <iterator>
#include <climits>
#include <numeric>//std::accumulate
#include <unordered_map>
using namespace std;

namespace bj {

	int P2748()
	{
		int n;
		cin >> n;

		auto fibo = new long long[max(2, n + 1)];
		fibo[0] = 0;
		fibo[1] = 1;

		for (int i = 2; i <= n; ++i)
			fibo[i] = fibo[i - 2] + fibo[i - 1];

		cout << fibo[n];

		delete[] fibo;
		return 0;
	}

	int P2003()
	{
		int N, M;
		cin >> N >> M;

		vector<long long> A(N, 0);

		long long accumulation = 0;
		int answer = 0;
		int startIndex = 0;
		for (auto& a : A)
		{
			cin >> a;
			accumulation += a;

			while (accumulation > M)
				accumulation -= A[startIndex++];

			if (accumulation == M)
				answer++;
		}

		cout << answer;
		return 0;
	}

	int P2143()
	{
		int T, sizeA, sizeB;
		cin >> T >> sizeA;

		vector<long long> A(sizeA);
		unordered_map<long long, long long> subA;
		/*
		* ★★★ unodered_set => Time Exceeded ★★★
		*/

		for (auto& a : A)
			cin >> a;

		auto subArrLen = sizeA;
		auto begin = A.begin();
		do
		{
			for (auto start = begin; start != A.end(); ++start)
			{
				if (distance(begin, start) + subArrLen > A.size())
					break;

				auto end = start; advance(end, subArrLen);
				//auto debug = accumulate(start, end, 0);
				subA[accumulate(start, end, 0)]++;
			}
		} while (subArrLen-- != 1);

		cin >> sizeB;
		vector<long long> B(sizeB);
		for (auto& b : B)
			cin >> b;

		subArrLen = sizeB;
		begin = B.begin();
		long long answer = 0;
		do
		{
			for (auto start = begin; start != B.end(); ++start)
			{
				if (distance(begin, start) + subArrLen > B.size())
					break;

				auto end = start; advance(end, subArrLen);
				//auto debug = accumulate(start, end, 0);

				//FIND PAIR
				answer += subA[T - accumulate(start, end, 0)];
			}
		} while (subArrLen-- != 1);

		cout << answer;
		return 0;
	}

	/*
	3
	1 2 3
	4 5 6
	4 9 0
	*/
	int P2096()//내려가기
	{
		constexpr unsigned int THREE = 3;

		int rowCount;
		cin >> rowCount;
		if (rowCount == 0)
		{
			cout << 0 << " " << 0;
			return 0;
		}
		vector<long long> floor(THREE);
		vector<pair<long long, long long>> memory(THREE);
		//first => min, second => max

		for (long long row = 0; row < rowCount; ++row)
		{
			for (auto& val : floor)
				cin >> val;

			if (row != 0)
			{
				const auto one_min = memory[0].first, one_max = memory[0].second;
				const auto two_min = memory[1].first, two_max = memory[1].second;
				const auto thr_min = memory[2].first, thr_max = memory[2].second;

				memory[0].first = floor[0] + min(one_min, two_min);
				memory[0].second = floor[0] + max(one_max, two_max);

				memory[1].first = floor[1] + min(min(one_min, two_min), thr_min);
				memory[1].second = floor[1] + max(max(one_max, two_max), thr_max);

				memory[2].first = floor[2] + min(two_min, thr_min);
				memory[2].second = floor[2] + max(two_max, thr_max);
			}
			else
			{
				memory[0].first = memory[0].second = floor[0];
				memory[1].first = memory[1].second = floor[1];
				memory[2].first = memory[2].second = floor[2];
			}

		}

		cout << max(max(memory[0].second, memory[1].second), memory[2].second);
		cout << " ";
		cout << min(min(memory[0].first, memory[1].first), memory[2].first);

		return 0;
	}
}