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

			// ó������ �ƽ����� �־���.
			if (maxHeap.size() > minHeap.size())
				minHeap.push(num);
			else
				maxHeap.push(num);

			if (!minHeap.empty())
			{
				auto mtop = maxHeap.top();
				auto ntop = minHeap.top();

				//�ְ��� maxHeap�� ž�� minHeap�� ž�� �� ũ�ٸ�, ���� ��
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

		//�Ѵ� �޸� �ʰ�
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

	/*N��N�� ǥ�� �� N2�� ä���� �ִ�.ä���� ������ �� ���� Ư¡�� �ִµ�, ��� ���� �ڽ��� �� ĭ ���� �ִ� ������ ũ�ٴ� ���̴�.N = 5�� ���� ���� ����.

		12	7	9	15	5
		13	8	11	19	6
		21	10	26	31	16
		48	14	28	35	25
		52	20	32	41	49

	�̷��� ǥ�� �־����� ��, N��° ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.ǥ�� ä���� ���� ��� �ٸ���.*/

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

	/*� ������ �а�, Ȧ����° ���� ���� �� ����,
	���ݱ��� �Է¹��� ���� �߾Ӱ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	���� ���, ������ 1, 5, 4, 3, 2 �̸�,
	Ȧ����° ���� 1��° ��, 3��° ��, 5��° ���̰�,
	1��° ���� �о��� �� �߾Ӱ��� 1,
	3��° ���� �о��� ���� 4,
	5��° ���� �о��� ���� 3�̴�.

	�Է�
	ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����.
	�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� M(1 �� M �� 9999, M�� Ȧ��)�� �־�����,
	�� ���� �ٺ��� �� ������ ���Ұ� ���ʴ�� �־�����. ���Ҵ� �� �ٿ� 10���� ���������ְ�,
	32��Ʈ ��ȣ�ִ� �����̴�.

	���
	�� �׽�Ʈ ���̽��� ���� ù° �ٿ� ����ϴ� �߾Ӱ��� ������ ����ϰ�,
	��° �ٿ��� Ȧ�� ��° ���� ���� �� ���� ���� �߾Ӱ��� ���ʴ�� �������� �����Ͽ� ����Ѵ�.
	�̶�, �� �ٿ� 10���� ����ؾ� �Ѵ�.
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

	/*����
	���ĵ� �� ������ ���� ī�尡 �ִٰ� ����.
	�� ������ ī���� ���� A, B�� �ϸ� ���� �� ������ ���ļ� �ϳ��� ����� ������
	A + B ���� �񱳸� �ؾ� �Ѵ�.�̸��׸�,
	20���� ���� ī�� ������ 30���� ���� ī�� ������ ��ġ���� 50���� �񱳰� �ʿ��ϴ�.

	�ſ� ���� ���� ī�� ������ å�� ���� ���� �ִ�.
	�̵��� �� ������ ��� ���� ���ĳ����ٸ�, ���� ������ ���� �� Ƚ���� �ſ� �޶�����.
	���� ��� 10��, 20��, 40���� ������ �ִٸ� 10��� 20���� ��ģ ��, ��ģ 30�� ������ 40���� ��ģ�ٸ�
	(10 + 20) + (30 + 40) = 100���� �񱳰� �ʿ��ϴ�.
	�׷��� 10��� 40���� ��ģ ��, ��ģ 50�� ������ 20���� ��ģ�ٸ�
	(10 + 40) + (50 + 20) = 120 ���� �񱳰� �ʿ��ϹǷ� �� ȿ������ ����̴�.

	N���� ���� ī�� ������ ������ ũ�Ⱑ �־��� ��,
	�ּ��� �� ���� �񱳰� �ʿ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� N�� �־�����. (1 �� N �� 100, 000) �̾ N���� �ٿ� ���� ���� ī�� ������ ������ ũ�Ⱑ �־�����.
	���� ī�� ������ ũ��� 1, 000���� �۰ų� ���� ���� �����̴�.

	���
	ù° �ٿ� �ּ� �� Ƚ���� ����Ѵ�.*/
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

				//������ �߰��� ��Ҹ� ������. algorithm��� ����
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

				//������ Ǯ���ٸ�, �� ������ ��ȣ�� ���Ϳ��� ã�´�.
				//auto findInMax = find_if(maxHeap.begin(), maxHeap.end(), _findIf);
				//auto findInMin = find_if(minHeap.begin(), minHeap.end(), _findIf);
				
				maxHeap.erase(subCommand);
				minHeap.erase(subCommand);

				//if (findInMax != maxHeap.end())
				//{
				//	//ã�Ҵٸ�, �����ش�. ���� �ٽ� heapify
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