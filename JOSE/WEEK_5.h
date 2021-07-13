#pragma once

#include <iostream>
#include <queue>
#include <utility>//pair
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

namespace bj {

	int P11279()
	{
		unsigned int T;
		cin >> T;

		priority_queue<unsigned int> maxHeap;

		while (T--)
		{
			unsigned int x;
			cin >> x;
			if (x > 0)
			{
				maxHeap.push(x);
			}
			else
			{
				if (maxHeap.empty())
				{
					cout << 0 << "\n";
				}
				else
				{
					cout << maxHeap.top() << "\n";
					maxHeap.pop();
				}
			}
		}

		return 0;
	}

	int P1655()
	{
		int N;
		cin >> N;

		int caseCount = N;

		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		int num;
		while (caseCount--)
		{
			cin >> num;

			// 처음에는 맥스힙에 넣어줌.
			if (maxHeap.size() > minHeap.size())
				minHeap.push(num);
			else
				maxHeap.push(num);

			if (!minHeap.empty())
			{
				auto mtop = maxHeap.top();
				auto ntop = minHeap.top();

				//넣고나서 maxHeap의 탑이 minHeap의 탑이 더 크다면, 서로 바
				if (mtop > ntop)
				{
					maxHeap.pop(); minHeap.pop();
					maxHeap.push(ntop); minHeap.push(mtop);
				}
			}

			cout << maxHeap.top() << "\n";
		}

		return 0;
	}

	int P1927()
	{
		unsigned int T;
		cin >> T;

		priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> minHeap;

		while (T--)
		{
			unsigned int x;
			cin >> x;
			if (x > 0)
			{
				minHeap.push(x);
			}
			else
			{
				if (minHeap.empty())
				{
					cout << 0 << "\n";
				}
				else
				{
					cout << minHeap.top() << "\n";
					minHeap.pop();
				}
			}
		}

		return 0;
	}

	//!!!MEMORY EXCEEDED!!!
	int P5214()
	{
		unsigned int stationCount, connectionCount, hyperTubeCount;
		cin >> stationCount >> connectionCount >> hyperTubeCount;

		//둘다 메모리 초과
		vector<unordered_set<unsigned int>> tubeInformation(hyperTubeCount, unordered_set<unsigned int>());
		//vector<vector<unsigned int>> tubeInformation(hyperTubeCount, vector<unsigned int>(connectionCount));
		vector<unsigned int> memory(stationCount);

		for (auto& tube : tubeInformation)
		{
			for (size_t i = 0; i < connectionCount; ++i)
			{
				unsigned int passBy;
				cin >> passBy;
				tube.emplace(--passBy);
			}
		}

		//for (auto& tube : tubeInformation)
		//{
		//	for (int i = 0; i < connectionCount; ++i)
		//	{
		//		unsigned int passBy;
		//		cin >> passBy;
		//		tube.emplace_back(--passBy);
		//	}
		//}

		queue<pair<unsigned int, unsigned int>> queue; //station#
		queue.emplace(0, 0);

		while (!queue.empty())
		{
			const auto crntStation = queue.front().first;
			const auto answer = queue.front().second;
			if (crntStation == stationCount - 1)
				break;

			memory[crntStation] = true;
			queue.pop();

			for (auto& tube : tubeInformation)
			{
				if (tube.find(crntStation) == tube.end())
					//if (find(tube.begin(), tube.end(), crntStation) == tube.end())
					continue;

				for (const auto& station : tube)
				{
					if (!memory[station])
						queue.emplace(station, answer + 1);
				}
			}

		}

		cout << queue.front().second + 1;

		return 0;
	}

	//!!!TIME EXCEEDED!!!
	int P1202()
	{
		struct myGreater {
			constexpr bool operator()(const pair<unsigned int, unsigned int>& _Left, const pair<unsigned int, unsigned int>& _Right) const
			{
				return _Left.second < _Right.second;
			}
		};

		unsigned int jewelCount, bagCount;
		cin >> jewelCount >> bagCount;

		priority_queue <pair<unsigned int, unsigned int>, vector<pair<unsigned int, unsigned int>>, myGreater> maxHeap;
		for (size_t i = 0; i < jewelCount; ++i)
		{
			unsigned int weight, value;
			cin >> weight >> value;
			maxHeap.emplace(weight, value);
		}

		vector<unsigned int> bags(bagCount);
		for (auto& bag : bags)
			cin >> bag;

		sort(bags.begin(), bags.end());

		unsigned long long answer = 0;
		while (!maxHeap.empty() && !bags.empty())
		{
			const auto weight = maxHeap.top().first;
			const auto value = maxHeap.top().second;

			//let's try O(n*k) => Time_Exceeded
			for (auto iter = bags.begin(); iter != bags.end(); ++iter)
			{
				const auto capacity = *iter;
				if (capacity >= weight)
				{
					answer += value;
					iter = bags.erase(iter);
					break;
				}
			}

			maxHeap.pop();
		}

		cout << answer;
		return 0;
	}

	/*N×N의 표에 수 N2개 채워져 있다.채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다.N = 5일 때의 예를 보자.

		12	7	9	15	5
		13	8	11	19	6
		21	10	26	31	16
		48	14	28	35	25
		52	20	32	41	49

	이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오.표에 채워진 수는 모두 다르다.*/

	int P2075()
	{
		unsigned int N;// (1 <= N <= 1500)
		cin >> N;

		priority_queue<int, vector<int>, greater<int>> minHeap;
		const unsigned int HEAP_SIZE = N;

		int input;
		while (cin >> input)
		{
			minHeap.emplace(input);

			if (minHeap.size() > HEAP_SIZE)
				minHeap.pop();
		}

		cout << minHeap.top();

		return 0;
	}

	/*어떤 수열을 읽고, 홀수번째 수를 읽을 때 마다,
	지금까지 입력받은 값의 중앙값을 출력하는 프로그램을 작성하시오.

	예를 들어, 수열이 1, 5, 4, 3, 2 이면,
	홀수번째 수는 1번째 수, 3번째 수, 5번째 수이고,
	1번째 수를 읽었을 때 중앙값은 1,
	3번째 수를 읽었을 때는 4,
	5번째 수를 읽었을 때는 3이다.

	입력
	첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.
	각 테스트 케이스의 첫째 줄에는 수열의 크기 M(1 ≤ M ≤ 9999, M은 홀수)이 주어지고,
	그 다음 줄부터 이 수열의 원소가 차례대로 주어진다. 원소는 한 줄에 10개씩 나누어져있고,
	32비트 부호있는 정수이다.

	출력
	각 테스트 케이스에 대해 첫째 줄에 출력하는 중앙값의 개수를 출력하고,
	둘째 줄에는 홀수 번째 수를 읽을 때 마다 구한 중앙값을 차례대로 공백으로 구분하여 출력한다.
	이때, 한 줄에 10개씩 출력해야 한다.
	*/

	int P2696()
	{
		unsigned int caseSize;
		cin >> caseSize;

		while (caseSize--)
		{
			priority_queue<int, vector<int>, less<int>> maxHeap;
			priority_queue<int, vector<int>, greater<int>> minHeap;

			int sampleSize;
			cin >> sampleSize;
			vector<int> centres;

			while (sampleSize)
			{
				int input;
				cin >> input;

				if (maxHeap.size() > minHeap.size())
					minHeap.push(input);
				else
					maxHeap.push(input);

				if (!minHeap.empty())
				{
					const auto minTop = minHeap.top();
					const auto maxTop = maxHeap.top();
					if (minTop < maxTop)
					{
						minHeap.pop(); maxHeap.pop();
						minHeap.push(maxTop); maxHeap.push(minTop);
					}
				}

				if (sampleSize-- & 1)
					centres.emplace_back(maxHeap.top());
			}

			cout << centres.size() << "\n";
			for (size_t index = 0; index < centres.size(); ++index)
			{
				cout << centres[index] << " ";
				if ((index + 1) % 10 == 0)
					cout << "\n";
			}
			cout << "\n";

		}


		return 0;
	}

	/*문제
	정렬된 두 묶음의 숫자 카드가 있다고 하자.
	각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는
	A + B 번의 비교를 해야 한다.이를테면,
	20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.

	매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다.
	이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다.
	예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면
	(10 + 20) + (30 + 40) = 100번의 비교가 필요하다.
	그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면
	(10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.

	N개의 숫자 카드 묶음의 각각의 크기가 주어질 때,
	최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100, 000) 이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다.
	숫자 카드 묶음의 크기는 1, 000보다 작거나 같은 양의 정수이다.

	출력
	첫째 줄에 최소 비교 횟수를 출력한다.*/
	int P1715()
	{
		unsigned int bundleCount;
		cin >> bundleCount;

		priority_queue<int, vector<int>, greater<int>> minHeap;
		while (bundleCount--)
		{
			unsigned int bundleSize;
			cin >> bundleSize;

			minHeap.emplace(bundleSize);
		}
		
		int answer = 0;
		while (minHeap.size() >= 2)
		{
			const auto theLeast = minHeap.top(); 
			minHeap.pop();
			
			const auto lessLeast = minHeap.top();
			minHeap.pop();

			minHeap.emplace(theLeast + lessLeast);
			answer += theLeast + lessLeast;
		}

		cout << answer;
		return 0;
	}


	int P21939()
	{
		using pii = pair<unsigned int, unsigned int>;//Problem#, Level

		unsigned int problemCount;
		cin >> problemCount;

		auto compLess = [](const pii& lhs, const pii& rhs)
		{
			if (lhs.second == rhs.second)
				return lhs.first > rhs.first;

			return lhs.second > rhs.second;
		};

		auto compGreater = [](const pii& lhs, const pii& rhs)
		{
			if (lhs.second == rhs.second)
				return lhs.first < rhs.first;

			return lhs.second < rhs.second;
		};

		map<unsigned int, unsigned int, less<unsigned int>> maxHeap;
		map<unsigned int, unsigned int, greater<unsigned int>> minHeap;
		//vector<pii> maxHeap;
		//vector<pii> minHeap;

		auto _addProblem = [&maxHeap, &minHeap, &compLess, &compGreater]()
		{
			unsigned int problemNumber, level;
			cin >> problemNumber >> level;
			
			//maxHeap.emplace_back(problemNumber, level);
			//minHeap.emplace_back(problemNumber, level);
			maxHeap.emplace(problemNumber, level);
			minHeap.emplace(problemNumber, level);
		};

		while (problemCount--)
		{
			_addProblem();
		}

		//make_heap(maxHeap.begin(), maxHeap.end(), compLess);
		//make_heap(minHeap.begin(), minHeap.end(), compGreater);

		////DEBUG
		//while (!maxHeap.empty())
		//{
		//	cout << maxHeap.top().first << " " << maxHeap.top().second << "\n";
		//	maxHeap.pop();
		//}

		unsigned int commandCount;
		cin >> commandCount;

		const string ADD = "add";
		const string RECOMMNAD = "recommend";
		const string SOLVED = "solved";
		constexpr int DIFFICULT = 1;
		constexpr int EASY = -1;

		while (commandCount--)
		{
			string command;
			int subCommand;

			cin >> command;

			if (command == ADD)
			{
				_addProblem();

				//마지막 추가된 요소를 정렬함. algorithm헤더 참고
				// push *(_Last - 1) onto heap at [_First, _Last - 1)
				//push_heap(maxHeap.begin(), maxHeap.end(), compLess);
				//push_heap(minHeap.begin(), minHeap.end(), compGreater);
			}
			else if (command == RECOMMNAD)
			{
				cin >> subCommand;

				if (subCommand == DIFFICULT)
				{
					cout << (*maxHeap.begin()).first << "\n";
					//cout << maxHeap.back().first << "\n";
				}
				else if (subCommand == EASY)
				{
					cout << (*minHeap.begin()).first << "\n";
					//cout << minHeap.back().first << "\n";
				}
				else
					return -1;
			}
			else if (command == SOLVED)
			{
				cin >> subCommand;

				auto _findIf = [subCommand](const pii& pair)
				{
					return pair.first == subCommand;
				};

				//문제를 풀었다면, 그 문제의 번호로 벡터에서 찾는다.
				//auto findInMax = find_if(maxHeap.begin(), maxHeap.end(), _findIf);
				//auto findInMin = find_if(minHeap.begin(), minHeap.end(), _findIf);
				
				maxHeap.erase(subCommand);
				minHeap.erase(subCommand);

				//if (findInMax != maxHeap.end())
				//{
				//	//찾았다면, 지워준다. 이후 다시 heapify
				//	maxHeap.erase(findInMax);
				//	make_heap(maxHeap.begin(), maxHeap.end(), compLess);
				//}

				//if (findInMin != minHeap.end())
				//{
				//	minHeap.erase(findInMin);
				//	make_heap(minHeap.begin(), minHeap.end(), compGreater);
				//}
			}
			else
				return -1;

		}

		return 0;
	}
}