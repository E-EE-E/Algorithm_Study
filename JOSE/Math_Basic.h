#pragma once
//https://www.acmicpc.net/step/8

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

namespace bj {

	//0  : 0
	//1  : 1
	//2  : 1 1
	//4  : 1 2 1
	//6  : 1 2 2 1 
	//9  : 1 2 3 2 1
	//12 : 1 2 3 3 2 1
	//16 : 1 2 3 4 3 2 1  

	int P1011()
	{
		int T;
		cin >> T;
		while (T--)
		{
			unsigned int from, to;
			cin >> from >> to;
			const unsigned int distance = to - from;

			unsigned int accumulation = 0;
			int vi = 1;
			unsigned int count = 0;
			while (accumulation < distance)
			{
				accumulation += vi;
				count++;
				if (accumulation >= distance)
					break;

				accumulation += vi++;
				count++;
			}

			cout << count << endl;
		}

		return 0;
	}

	int P3053()
	{
		long double radius;
		cin >> radius;

		long double taxiS;
		long double ClassicS;

		const auto pi = 2 * acosl(0.0L); //cos(0) == pi/2

		cout.precision(17);
		cout << radius * radius * pi;
		cout << endl;
		cout.precision(17);
		cout << radius * radius * 2.00000L;

		return 0;
	}

	int P4153()
	{
		unsigned int A, B, C;
		while (cin >> A >> B >> C)
		{
			if (A == 0 && B == 0 && C == 0)
				break;

			set<unsigned int> filter;
			filter.insert(A);
			filter.insert(B);
			filter.insert(C);

			auto longgest = max(A, max(B, C));
			auto shortest = min(A, min(B, C));

			filter.erase(longgest);
			filter.erase(shortest);
			auto mid = *filter.begin();


			if (longgest * longgest == mid * mid + shortest * shortest)
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
		}

		return 0;
	}

	int P3009()
	{
		unordered_map<int, int> X;
		unordered_map<int, int> Y;

		int x, y;
		while (cin >> x >> y)
		{
			X[x]++; Y[y]++;
		}

		for (auto find : X)
			if (find.second == 1)
				cout << find.first << " ";

		for (auto find : Y)
			if (find.second == 1)
				cout << find.first;


		return 0;
	}

	int P1085()
	{
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		cout << min(min(x, w - x), min(y, h - y));

		return 0;
	}

	int P1929()
	{
		ios::sync_with_stdio(false);
		cout.tie(nullptr);
		cin.tie(nullptr);

		int M, N;
		cin >> M >> N;

		vector<int> primes;
		primes.reserve(1000000);

		for (int i = 2; i <= N; ++i)
		{
			bool isPrime = true;
			for (auto prime : primes)
			{
				if (prime * prime > i)
					break;

				if (i % prime == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				if (M <= i && i <= N)
					cout << i << "\n";
				primes.push_back(i);
			}
		}

		return 0;
	}

	int P4948()
	{
		while (true)
		{
			int M, N;
			cin >> M;

			if (M == 0)
				break;

			N = 2 * M;

			vector<int> primes;
			primes.reserve(123456 * 2);
			int count = 0;

			for (int i = 2; i <= N; ++i)
			{
				bool isPrime = true;
				for (auto prime : primes)
				{
					if (prime * prime > i)
						break;

					if (i % prime == 0)
					{
						isPrime = false;
						break;
					}
				}

				if (isPrime)
				{
					if (M < i && i <= N)
						count++;
					primes.push_back(i);
				}
			}

			cout << count << "\n";
		}

		return 0;
	}

	int P9020()
	{
		int T;
		cin >> T;
		while (T--)
		{
			int target;
			cin >> target;

			set<int> primeSet;

			int count = 0;

			for (int i = 2; i < target; ++i)
			{
				bool isPrime = true;
				for (auto prime : primeSet)
				{
					if (prime * prime > i)
						break;

					if (i % prime == 0)
					{
						isPrime = false;
						break;
					}
				}

				if (isPrime)
					primeSet.insert(i);
			}

			vector<int> keys;
			for (auto prime : primeSet)
			{
				if (prime > target - prime)
					break;

				if (primeSet.find(target - prime) != primeSet.end())
					keys.push_back(prime);
			}

			cout << *keys.rbegin() << " " << target - *keys.rbegin() << endl;
		}

		return 0;
	}
}