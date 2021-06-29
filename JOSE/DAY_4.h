#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
//#include <unordered_set>
#include <iterator>
#include <climits>
#include <numeric>//std::accumulate
#include <unordered_map>
#include <queue>
#include <functional>
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
		* unodered_set => Time Exceeded!
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
	int P2096()//³»·Á°¡±â
	{
		constexpr unsigned int THREE = 3;

		int rowCount;
		cin >> rowCount;

		vector<long long> floor(THREE);
		vector<pair<long long, long long>> memory(THREE);
		//first => min, second => max

		for (int row = 0; row < rowCount; ++row)
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

	/*
	5 5
	#####
	#..B#
	#.#.#
	#RO.#
	#####
	*/
	int P13460()
	{
		constexpr char SPACE = '.';
		constexpr char WALL = '#';
		constexpr char HOLE = 'O';
		constexpr char RED = 'R';
		constexpr char BLUE = 'B';
		constexpr int MAX_COUNT = 10;

		enum class Gravity_Direction
		{
			DOWN = 0,
			RIGHT,
			LEFT,
			UP
		};

		int N, M;
		cin >> N >> M;

		//초기 red, blue, hole위치 저장을 위함.
		pair<int, int> red, blue, hole;// (Y, X)
		
		//map받기
		vector<vector<char>> map(N, vector<char>(M));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == RED)
				{
					red = make_pair(i, j);
					map[i][j] = '.';
				}
				else if (map[i][j] == BLUE)
				{
					blue = make_pair(i, j);
					map[i][j] = '.';
				}
				else if (map[i][j] == HOLE)
				{
					hole = make_pair(i, j);
				}
			}
		}


		auto _isFailCondition = [&](pair<int, int> blue)
		{
			return blue == hole;
		};

		auto _isEscapeCondition = [&](pair<int, int> red)
		{
			return red == hole;
		};

		//해당 방향으로 이동시키기
		auto _applyGravity = [&](Gravity_Direction direction, const pair<int, int>& red, const pair<int, int>& blue)
		{
			//TODO MOVE BOTH WITH SUITABLE DIRECTION
			//debug
			int xRedInitial = red.second;
			int yRedInitial = red.first;
			int xBlueInitial = blue.second;
			int yBlueInitial = blue.first;

			int yRedSpaceCount = 0;
			int xRedSpaceCount = 0;
			int yBlueSpaceCount = 0;
			int xBlueSpaceCount = 0;

			switch (direction)
			{
			case Gravity_Direction::DOWN:
			{
				//TODO COUNT NUMBER OF SPACES UNTIL REACH THE NEAREST WALL
				for (int i = yRedInitial + 1; i < N; ++i)
				{
					auto search = map[i][red.second];
					if (i == blue.first && red.second == blue.second)
						continue;
					else if (search == SPACE)
						yRedSpaceCount++;
					else if (search == HOLE)
					{
						yRedSpaceCount = i - yRedInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				for (int i = yBlueInitial + 1; i < N; ++i)
				{
					auto search = map[i][blue.second];
					if (red.first == i && red.second == blue.second)
						continue;
					else if (search == SPACE)
						yBlueSpaceCount++;
					else if (search == HOLE)
					{
						yBlueSpaceCount = i - yBlueInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				break;
			}
			case Gravity_Direction::RIGHT:
			{
				for (int i = xRedInitial + 1; i < M; ++i)
				{
					auto search = map[red.first][i];
					if (red.first == blue.first && i == blue.second)
						continue;
					else if (search == SPACE)
						xRedSpaceCount++;
					else if (search == HOLE)
					{
						xRedSpaceCount = i - xRedInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				for (int i = xBlueInitial + 1; i < M; ++i)
				{
					auto search = map[blue.first][i];
					if (red.first == blue.first && red.second == i)
						continue;
					else if (search == SPACE)
						xBlueSpaceCount++;
					else if (search == HOLE)
					{
						xBlueSpaceCount = i - xBlueInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				break;
			}
			case Gravity_Direction::LEFT:
			{
				for (int i = xRedInitial - 1; i > 0; --i)
				{
					auto search = map[red.first][i];
					if (red.first == blue.first && i == blue.second)
						continue;
					else if (search == SPACE)
						xRedSpaceCount--;
					else if (search == HOLE)
					{
						xRedSpaceCount = i - xRedInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				for (int i = xBlueInitial - 1; i > 0; --i)
				{
					auto search = map[blue.first][i];
					if (red.first == blue.first && red.second == i)
						continue;
					if (search == SPACE)
						xBlueSpaceCount--;
					else if (search == HOLE)
					{
						xBlueSpaceCount = i - xBlueInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				break;
			}
			case Gravity_Direction::UP:
			{
				for (int i = yRedInitial - 1; i > 0; --i)
				{
					auto search = map[i][red.second];
					if (i == blue.first && red.second == blue.second)
						continue;
					else if (search == SPACE)
						yRedSpaceCount--;
					else if (search == HOLE)
					{
						yRedSpaceCount = i - yRedInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				for (int i = yBlueInitial - 1; i > 0; --i)
				{
					auto search = map[i][blue.second];
					if (red.first == i && red.second == blue.second)
						continue;
					if (search == SPACE)
						yBlueSpaceCount--;
					else if (search == HOLE)
					{
						yBlueSpaceCount = i - yBlueInitial;
						break;
					}
					else if (search == WALL)
						break;
				}

				break;
			}

			default:
				break;
			}

			return make_pair(make_pair(yRedInitial + yRedSpaceCount, xRedInitial + xRedSpaceCount), make_pair(yBlueInitial + yBlueSpaceCount, xBlueInitial + xBlueSpaceCount));
		};

		/*
		auto _findPossibleDirection = [&](pair<int, int> currentRedPos, pair<int, int> currentBluePos)
		{
			vector<Gravity_Direction> directions = { Gravity_Direction::DOWN, Gravity_Direction::LEFT, Gravity_Direction::RIGHT, Gravity_Direction::UP };
			if (map[currentRedPos.first + 1][currentRedPos.second] == WALL && map[currentBluePos.first + 1][currentBluePos.second] == WALL)
				directions.erase(find(directions.begin(), directions.end(), Gravity_Direction::DOWN));
			if (map[currentRedPos.first][currentRedPos.second + 1] == WALL && map[currentBluePos.first + 1][currentBluePos.second] == WALL)
				directions.erase(find(directions.begin(), directions.end(), Gravity_Direction::RIGHT));
			if (map[currentRedPos.first - 1][currentRedPos.second] == WALL && map[currentBluePos.first + 1][currentBluePos.second] == WALL)
				directions.erase(find(directions.begin(), directions.end(), Gravity_Direction::UP));
			if (map[currentRedPos.first][currentRedPos.second - 1] == WALL && map[currentBluePos.first + 1][currentBluePos.second] == WALL)
				directions.erase(find(directions.begin(), directions.end(), Gravity_Direction::LEFT));

			return directions;
		};
		*/

		//탐색을 위한 큐
		queue<pair<pair<pair<int, int>, pair<int, int>>, int>> myQ;

		//방문기록하기
		set<pair<pair<int, int>, pair<int, int>>> seen_;

		function<void(pair<int, int>, pair<int, int>)> _findWayOut;
		_findWayOut = [&](pair<int, int> initialRedPos, pair<int, int> initialBluePos) -> void
		{
			myQ.push(make_pair(make_pair(initialRedPos, initialBluePos), 1));//1->첫 시도니까.
			while (!myQ.empty())
			{
				const auto currentRedBluePos = myQ.front().first; //현재위치&count pop
				const auto count = myQ.front().second;			  
				if (count > MAX_COUNT)
				{
					cout << -1;
					return;
				}

				seen_.insert(make_pair(currentRedBluePos.first, currentRedBluePos.second));//방문 기록하기
				myQ.pop();
				auto possibleDirection = vector<Gravity_Direction>{ Gravity_Direction::DOWN,
																		Gravity_Direction::LEFT,
																		Gravity_Direction::RIGHT,
																		Gravity_Direction::UP };//그냥 다 탐색하기

				//auto possibleDirection = _findPossibleDirection(front.first, front.second);

				//현재 위치들에서 가능한 모든 방향에 대해,
				for (auto direction : possibleDirection)
				{
					//한번 가보기
					auto appliedPosPair = _applyGravity(direction, currentRedBluePos.first, currentRedBluePos.second);
					
					if (_isFailCondition(appliedPosPair.second))
					{
						//파란구슬이 빠지면 continue
						continue;
					}

					if (_isEscapeCondition(appliedPosPair.first))
					{
						//빨간구슬만 빠지면 escape
						cout << count;
						return;
					}

					if (seen_.find(appliedPosPair) == seen_.end())
					{
						//만약 안가본 경우라면, 가보기
						myQ.push(make_pair(appliedPosPair, count + 1));
					}
					
					//가본경우면 continue;

				}
			}

			cout << -1;
			// count <= MAX_COUNT일때 모든 경우를 가봤는데 Loop를 나옴 -> 탈출이 불가능
		};

		_findWayOut(red, blue);
		return 0;
	}
}
