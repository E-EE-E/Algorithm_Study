#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

namespace bj {

	//N과 M (9)
	int P15663()
	{
		//nPr?
		int n, r;
		cin >> n >> r;
		vector<int> nums;

		int num;
		while (cin >> num)
			nums.emplace_back(num);

		sort(nums.begin(), nums.end());

		unordered_map<string, int> memory;
		do
		{
			string result;

			for (size_t i = 0; i < r; i++)
			{
				result.append(to_string(nums[i]));
				result.append(" ");
			}

			if (memory[result]++ != 0)
				continue;

			cout << result << "\n";

		} while (next_permutation(nums.begin(), nums.end()));

		return 0;
	}

	//N과 M (10)
	int P15664()
	{
		constexpr char yet = '0';
		constexpr char visited = '1';

		//nCr?
		int n, r;
		cin >> n >> r;
		vector<int> nums;

		int num;
		while (cin >> num)
			nums.emplace_back(num);

		sort(nums.begin(), nums.end());

		string visits(n, yet);//000....00

		for (size_t i = 0; i < r; i++)
			visits[i] = visited;

		unordered_map<string, int> memory;
		do
		{
			string comb;

			for (size_t i = 0; i < visits.length(); i++)
			{
				if (visits[i] == visited)
				{
					comb.append(to_string(nums[i]));
					comb.append(" ");
				}
			}

			if (memory[comb]++ != 0)
				continue;

			cout << comb << "\n";

		} while (prev_permutation(visits.begin(), visits.end()));

		return 0;
	}

	//로봇 청소기
	int P14503()
	{
		constexpr int SPACE = 0;
		constexpr int WALL = 1;
		constexpr int CLEANED = 2;

		int width, height;
		cin >> height >> width;

		int initialPosX, initialPosY, initialDirection;//0 1 2 3 : N E S W
		cin >> initialPosY >> initialPosX >> initialDirection;

		vector<vector<int>> room(height, vector<int>(width));
		for (auto& rows : room)
		{
			for (auto& space : rows)
				cin >> space;
		}

		enum class Direction
		{
			UNDEFINED = -1,
			NORTH = 0,
			EAST,//1
			SOUTH,//2
			WEST//3
		};


		pair<int, int> currentPos = { initialPosY , initialPosX };// (y, x)
		Direction currentDirection = static_cast<Direction>(initialDirection);
		int answer = 0;

		auto _applyCleanRule = [&]() -> bool
		{
			//현재 위치를 청소한다.
			if (room[currentPos.first][currentPos.second] == SPACE)
			{
				room[currentPos.first][currentPos.second] = CLEANED;
				++answer;
			}

			//DEBUG
			/*cout << "DIR : " << (int)currentDirection << "\n";

			for (size_t i = 0; i < room.size(); i++)
			{
				for (size_t j = 0; j < room[0].size(); j++)
				{
					if (i == currentPos.first && j == currentPos.second)
						cout << "@" << " ";
					else
						cout << room[i][j] << " ";
				}
				cout << "\n";
			}

			cout << "\n" << "\n";*/

			Direction faceDirection = currentDirection;
			while (true)
			{
				auto roi = currentPos;
				faceDirection = static_cast<Direction>(static_cast<int>(faceDirection) - 1);
				if (faceDirection == Direction::UNDEFINED)
					faceDirection = Direction::WEST;

				//check left direction
				switch (faceDirection)
				{
				case Direction::NORTH:
					roi.first -= 1;
					break;
				case Direction::EAST:
					roi.second += 1;
					break;
				case Direction::SOUTH:
					roi.first += 1;
					break;
				case Direction::WEST:
					roi.second -= 1;
					break;
				default:
					return -1;
				}

				if (room[roi.first][roi.second] == SPACE)
				{
					currentPos = roi;
					currentDirection = faceDirection;
					break;
				}

				if (currentDirection == faceDirection)
				{
					//후진할 곳
					roi = currentPos;

					switch (currentDirection)
					{
					case Direction::NORTH:
						roi.first += 1;
						break;
					case Direction::EAST:
						roi.second -= 1;
						break;
					case Direction::SOUTH:
						roi.first -= 1;
						break;
					case Direction::WEST:
						roi.second += 1;
						break;
					default:
						return -1;
					}

					if (room[roi.first][roi.second] == WALL)
						return false;

					currentPos = roi;
					break;
				}
			}

			return true;
		};

		while (true)
		{
			if (!_applyCleanRule())
			{
				cout << answer;
				break;
			}
		}

		return 0;
	}

	//개똥벌레
	int P3020()
	{
		int height, width;
		cin >> width >> height;

		vector<int> suksoon(width / 2);
		vector<int> jongyou(width / 2);

		for (size_t i = 0; i < width / 2; i++)
		{
			cin >> suksoon[i] >> jongyou[i];
		}

		sort(jongyou.begin(), jongyou.end());
		sort(suksoon.begin(), suksoon.end());

		int answer = INT_MAX;
		int count = 1;

		for (int i = 0; i < height; i++)
		{
			auto toBeDestroyed = suksoon.size() - distance(suksoon.begin(), upper_bound(suksoon.begin(), suksoon.end(), i));
			toBeDestroyed += jongyou.size() - distance(jongyou.begin(), lower_bound(jongyou.begin(), jongyou.end(), height - i));


			if (answer == toBeDestroyed)
				count++;
			else if (answer > toBeDestroyed)
			{
				answer = toBeDestroyed;
				count = 1;
			}
		}

		cout << answer << " " << count << "\n";

		return 0;
	}

	//1학년
	int P5557()
	{
		int numCount;
		cin >> numCount;

		vector<int> nums(numCount);
		for (auto& num : nums)
			cin >> num;

		vector<unordered_map<int, unsigned long long>> branches(numCount - 1);
		branches[0][nums[0]]++;

		for (size_t i = 1; i < nums.size() - 1; ++i)
		{
			for (auto& branch : branches[i - 1])
			{
				auto plus = branch.first + nums[i];
				auto minus = branch.first - nums[i];

				if (-1 < plus && plus < 21)
					branches[i][plus] += branch.second;

				if (-1 < minus && minus < 21)
					branches[i][minus] += branch.second;
			}
		}

		cout << branches.back()[nums.back()];

		return 0;
	}

	//	사전
	int P1256()
	{
		struct pair_hash {
			size_t operator () (const pair<int, int>& p) const
			{
				auto h1 = hash<int>{}(p.first);
				auto h2 = hash<int>{}(p.second);

				return h1 ^ h2;
			}
		};
		constexpr int MAX_ORDER = 1000000000;

		unordered_map<pair<int, int>, int, pair_hash> memory;

		function<int(int, int)> combination;
		combination = [&](int n, int r) -> int
		{
			r = r < (n - r) ? r : (n - r);
			auto pair = make_pair(n, r);

			if (memory[pair] != 0)
				return memory[pair];

			if (r == 0 || r == n)
			{
				memory[pair] = 1;
				return memory[pair];
			}
			memory[pair] = combination(n - 1, r - 1) + combination(n - 1, r);
			if (memory[pair] > MAX_ORDER)
				memory[pair] = MAX_ORDER + 1;//아무튼 MAX_ORDER보다 큼ㅋ

			return memory[pair];
		};

		int aCount, zCount, order;
		cin >> aCount >> zCount >> order;
		
		//"zzz ... aaa"의 order가 order에 못미침
		if (combination(aCount + zCount, zCount) < order)
		{
			cout << -1;
			return 0;
		}

		string answer;
		while (aCount + zCount)
		{
			if (aCount == 0)
			{
				answer.append(string(zCount, 'z'));
				break;
			}
			else if (zCount == 0)
			{

				answer.append(string(aCount, 'a'));
				break;
			}
			else
			{
				//현재 자리가 'a'라고 가정
				//남은 order수가 못 미치면 'z'
				auto comb = combination(aCount + zCount - 1, aCount - 1);
				if (comb >= order)
				{
					--aCount;
					answer += 'a';
				}
				else
				{
					--zCount;
					answer += 'z';
					order -= comb;
				}
			}
		}

		cout << answer;

		return 0;
	}
}
