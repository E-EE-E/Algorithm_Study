#pragma once

#include <iostream>
#include <queue>
#include <utility>//pair
#include <algorithm>
#include <set>

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
			for (int i = 0; i < connectionCount; ++i)
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
		for (int i = 0; i < jewelCount; ++i)
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
}