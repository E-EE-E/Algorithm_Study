#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>
#include <utility>
#include <array>
#include <limits>

using namespace std;

namespace bj {

	/*효빈이의 비밀 박스에는 조약돌이 N개 들어있다.
	조약돌의 색상은 1부터 M까지 중의 하나이다.
	비밀 박스에서 조약돌을 랜덤하게 K개 뽑았을 때,
	뽑은 조약돌이 모두 같은 색일 확률을 구하는 프로그램을 작성하시오.*/

	//chance =  sigma color_count Ck / nCk (count >= k 인 color에 대해)로 하려했으나,
	//=>unsigned long long range exceeded!
	int P13251()
	{
		unsigned long long M, K;
		cin >> M;

		unordered_map<unsigned long long, unsigned long long> map;
		long long totStoneCount = 0;
		for (size_t i = 0; i < M; i++)
		{
			cin >> map[i];
			totStoneCount += map[i];;
		}

		cin >> K;

		//for each color...
		long double chance = 0.0;
		for (auto& color : map)
		{
			if (color.second < K)
				continue;

			long double eachColorChance = 1.0L;
			for (size_t i = 0; i < K; i++) //200 100 100  = 100 * 99 ... / 200 * 199 ...
				eachColorChance *= static_cast<long double>(color.second - i) / (totStoneCount - i);
			chance += eachColorChance;
		}

		/*
		struct pair_hash {
			size_t operator () (const pair<long long, long long>& p) const {
				auto h1 = hash<long long>{}(p.first);
				auto h2 = hash<long long>{}(p.second);

				return h1 ^ h2;
			}
		};

		unordered_map<pair<long long, long long>, long long, pair_hash> memory;

		function<long long(long long, long long)> combination;
		combination = [&memory, &combination](long long n, long long r) -> long long
		{
			auto pair = make_pair(n, r);

			if (memory[pair] != 0)
				return memory[pair];

			if (r == 0 || r == n)
			{
				memory[pair] = 1;
				return memory[pair];
			}

			auto anotherPair = make_pair(n, n - r);
			memory[pair] = combination(n - 1, r - 1) + combination(n - 1, r);
			memory[anotherPair] = memory[pair];

			return memory[pair];
		};


		long long caseCount = 0;//각 color마다 가능한 경우
		long long N = 0;//tot count of stones
		for (auto& elem : map)
		{
			if (elem.second >= K)
				caseCount += combination(elem.second, K);
			N += elem.second;
		}
		*/


		cout << fixed;
		cout.precision(numeric_limits<double>::max_digits10);
		//cout << (long double)caseCount / combination(N, K);
		cout << chance;

		return 0;
	}

	//prev/next_permutation => time limit exceeded!
	int P1722()
	{
		long long N;
		cin >> N;	

		vector<long long> factorialMemory(N);//fac(0) ~ fac(N-1)
		factorialMemory[0] = 1;
		for (size_t i = 1; i < N; i++)
			factorialMemory[i] = factorialMemory[i - 1] * i;

		set<long long> set;
		for (size_t i = 0; i < N; i++)
			set.emplace(i + 1);// set : 1, 2, ..., N
		
		long long subProblem;
		cin >> subProblem;

		// 1 2 3 4 5 6
		// 1~5 x x x x를 재낌!
		// 6 x x x x x (5 * 5!)
		// 6 2 ...를 재낌!
		// 6 3 (1 * 4!)

		//1인 경우 k(1≤k≤N!)를 입력받고,
		if (subProblem == 1)
		{
			long long Kth;
			cin >> Kth;
			--Kth;//1번째 => 0번째.

			//set이 빌때까지.
			while (!set.empty())
			{
				auto factorial = factorialMemory[set.size() - 1];// (set.size() - 1)!

				//set : 1 2 3 4 ... N
				auto iter = set.begin();
				advance(iter, Kth / factorial);//Q
				Kth %= factorial;//mod

				cout << *iter << " ";

				set.erase(iter);
			}
		}
		else// 2인 경우 임의의 순열을 나타내는 N개의 수를 입력받는다.
		{
			long long answer = 1;//0번째 => 1번째
			for (size_t i = 0; i < N; ++i)
			{
				long long elem;
				cin >> elem;

				//set : 1 2 3 4 ... N
				// elem = 1
				auto dist = distance(set.begin(), set.find(elem));

				answer += dist * factorialMemory[set.size() - 1];

				set.erase(elem);
			}

			cout << answer;
		}

		return 0;
	}

	//출근 경로
	int P5569()
	{
		int width, height;
		cin >> width >> height;

		//현재 교차로에서 '들어오는' 경로에 대한 정보
		struct Intersection
		{
			int northNonFixedCount_ = 0; //북쪽에서 왔고, 방향을 바꿀 수 있는 경우
			int westNonFixedCount_ = 0; //서쪽에서 왔고, 방향을 바꿀 수 있는 경우
			int northFixedCount_ = 0;//북쪽에서 왔고, 방향을 바꿀 수 없는 경우
			int westFixedCount_ = 0;//서쪽에서 왔고, 방향을 바꿀 수 없는 경우
		};

		vector<vector<Intersection>> city(height, vector<Intersection>(width));

		for (size_t i = 1; i < height; ++i)
			city[i][0].northNonFixedCount_ = 1;

		for (size_t i = 1; i < width; ++i)
			city[0][i].westNonFixedCount_ = 1;

		for (size_t i = 1; i < height; ++i)
		{
			for (size_t j = 1; j < width; ++j)
			{
				city[i][j].northNonFixedCount_ = (city[i - 1][j].northFixedCount_ + city[i - 1][j].northNonFixedCount_) % 100000;
				city[i][j].westNonFixedCount_ = (city[i][j - 1].westFixedCount_ + city[i][j - 1].westNonFixedCount_) % 100000;
				city[i][j].northFixedCount_ = city[i - 1][j].westNonFixedCount_;
				city[i][j].westFixedCount_ = city[i][j - 1].northNonFixedCount_;
			}
		}

		//DEBUG
		/*for (auto& row : city)
		{
			for (auto& elem : row)
			{
				cout << fixed;
				cout.precision(5);
				cout <<
					elem.northNonFixedCount +
					elem.westNonFixedCount +
					elem.northFixedCount +
					elem.westFixedCount << " ";
			}
			cout << endl;
		}*/

		cout <<
			(city[height - 1][width - 1].northNonFixedCount_ +
				city[height - 1][width - 1].westNonFixedCount_ +
				city[height - 1][width - 1].northFixedCount_ +
				city[height - 1][width - 1].westFixedCount_) % 100000;

		return 0;
	}

	int P1010()
	{
		struct pair_hash {
			size_t operator () (const pair<int, int>& p) const 
			{
				auto h1 = hash<int>{}(p.first);
				auto h2 = hash<int>{}(p.second);

				return h1 ^ h2;
			}
		};

		unordered_map<pair<int, int>, int, pair_hash> memory;

		int caseSize = 0;
		cin >> caseSize;

		function<int(int, int)> combination;
		combination = [&memory, &combination](int n, int r) -> int
		{
			auto pair = make_pair(n, r);

			if (memory[pair] != 0)
				return memory[pair];

			if (r == 0 || r == n)
			{
				memory[pair] = 1;
				return memory[pair];
			}

			auto anotherPair = make_pair(n, n - r);
			memory[pair] = combination(n - 1, r - 1) + combination(n - 1, r);
			memory[anotherPair] = memory[pair];

			return memory[pair];
		};

		while (caseSize--)
		{
			int W, E;
			cin >> W >> E;

			cout << combination(E, W) << "\n";
		}

		return 0;
	}

	int P1240() 
	{

		int N, M;
		cin >> N >> M;

		vector<vector<int>> graph(N + 1, vector<int>(N + 1, numeric_limits<int>::max()));
		while (--N)
		{
			int from, to, cost;
			cin >> from >> to >> cost;

			graph[from][to] = cost;
			graph[to][from] = cost;
		}

		//다익스트라
		//나무위키 보고만듦
		//https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
		while (M--)
		{
			int from, to;
			cin >> from >> to;

			//1.출발점으로부터의 최단거리를 저장할 배열 d[v]를 만들고,
			//  출발 노드에는 0을,
			//  출발점을 제외한 다른 노드들에는 매우 큰 값 INF를 채워 넣는다.
			vector<int> distance = vector<int>(graph.size(), numeric_limits<int>::max());
			distance[from] = 0;

			array<bool, 1000/*문제에서 제한*/> visits = { false, };
			using pii = pair<int, int>;//Cost, Node
			priority_queue<pii, vector<pii>, greater<pii>> minHeap;

			//2.현재 노드를 나타내는 변수 A에 출발 노드의 번호를 저장한다.
			minHeap.emplace(distance[from], from);

			while (!minHeap.empty())
			{
				auto currentNode = minHeap.top().second;
				minHeap.pop();
				 
				//3. A로부터 갈 수 있는 임의의 노드 B에 대해,
				//d[A] + P[A][B]와 d[B]의 값을 비교한다.
				for (size_t i = 1; i < graph.size(); ++i)
				{
					auto costCurrentToNext = graph[currentNode][i];

					if (costCurrentToNext == numeric_limits<int>::max())
						continue;
					
					//4.만약 d[A] + P[A][B]의 값이 더 작다면, 즉 더 짧은 경로라면,
					//  d[B]의 값을 이 값으로 갱신시킨다.
					if (distance[currentNode] + costCurrentToNext < distance[i])
					{
						distance[i] = distance[currentNode] + costCurrentToNext;

						if(!visits[i])
							minHeap.emplace(graph[currentNode][i], i);
					}
				}
				//5. A의 상태를 "방문 완료"로 바꾼다. 그러면 이제 더 이상 A는 사용하지 않는다.
				visits[currentNode] = true;
			}

			//from => i번째 까지의 최단 경로의 비용을 다 저장
			cout << distance[to] << "\n";
		}

		return 0;
	}

	int P5573()
	{
		int width, height, n;
		cin >> width >> height >> n;
		auto village = new bool*[height+1];
		for (size_t i = 0; i < height; i++)
			village[i] = new bool[width+1];
		
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j)
			{
				int input;
				cin >> input;
				village[i][j] = static_cast<bool>(input);
			}
		}

		//if(false -> i++)
		//else(j++)

		for (size_t i = 0; i < height; i++)
			delete[] village[i];
		delete village;

		return 0; 
	}

}
