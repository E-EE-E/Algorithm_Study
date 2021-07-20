#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

namespace bj {

	int P15663()
	{

		//nPr
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
			string comb;

			for (size_t i = 0; i < r; i++)
			{
				{
					comb.append(to_string(nums[i]));
					comb.append(" ");
				}
			}

			if (memory[comb]++ != 0)
				continue;

			cout << comb << "\n";

		} while (next_permutation(nums.begin(), nums.end()));

		return 0;
	}

	int P15664()
	{

		//nCr
		int n, r;
		cin >> n >> r;
		vector<int> nums;

		int num;
		while (cin >> num)
			nums.emplace_back(num);

		sort(nums.begin(), nums.end());

		string visits(n, '0');
		for (size_t i = 0; i < r; i++)
		{
			visits[i] = '1';
		}

		unordered_map<string, int> memory;
		do
		{
			string comb;

			for (size_t i = 0; i < visits.length(); i++)
			{
				if (visits[i] == '1')
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
			{
				cin >> space;
			}
		}

		enum class Direction
		{
			UNDEFINED = -1,
			NORTH = 0,
			EAST,
			SOUTH,
			WEST
		};


		pair<int, int> currentPos = { initialPosY , initialPosX };// (y, x)
		Direction currentDirection = static_cast<Direction>(initialDirection);
		int answer = 0;

		auto _cleanRule = [&]() -> bool
		{
			//현재 위치를 청소한다.
			if (room[currentPos.first][currentPos.second] == SPACE)
			{
				room[currentPos.first][currentPos.second] = CLEANED;
				++answer;
			}
			cout << "DIR : " << (int)currentDirection << "\n";

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

			cout << "\n" << "\n";

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
					//후진할곳
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
					{
						return true;
					}

					currentPos = roi;
					break;
				}
				//currentDirection = faceDirection;
			}
			return false;
		};

		while (true)
		{
			if (_cleanRule())
			{
				cout << answer;
				break;
			}
		}

		return 0;
	}

	int P3020()
	{
		int height, width;
		cin >> width >> height;

		vector<int> stalagmite(width / 2); //석순
		vector<int> stalactite(width / 2); //종유석

		for (size_t i = 0; i < width / 2; i++)
			cin >> stalagmite[i] >> stalactite[i];

		sort(stalactite.begin(), stalactite.end());
		sort(stalagmite.begin(), stalagmite.end());

		int answer = INT_MAX;
		int count = 1;
		for (int i = 0; i < height; i++) {

			auto toBeDestroyed = -distance(stalagmite.end(), lower_bound(stalagmite.begin(), stalagmite.end(), stalagmite[i])) - 1;
			toBeDestroyed -= distance(stalactite.end(), upper_bound(stalactite.begin(), stalactite.end(), height - stalactite[i])) - 1;

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
}