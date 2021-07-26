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

	int P3020()
	{
		int height, width;
		cin >> width >> height;

		vector<int> suksoon(width / 2); //석순
		vector<int> jong(width / 2); //종유석

		for (size_t i = 0; i < width / 2; i++)
			cin >> suksoon[i] >> jong[i];

		sort(jong.begin(), jong.end());
		sort(suksoon.begin(), suksoon.end());

		int answer = INT_MAX;
		int count = 1;

		for (int i = 0; i < height; i++) {


			auto toBeDestroyed = distance(lower_bound(suksoon.begin(), suksoon.end(), suksoon[i]), suksoon.begin());
			toBeDestroyed -= distance(jong.end(), upper_bound(jong.begin(), jong.end(), height - jong[i]));

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

	//int akakopay()
	//{
	//	string line1("abbbcbbb");
	//	string lint2("bbb");

	//	//contain..
	//	//for (size_t i = 0; i < length; i++)
	//	{
	//		//lint2의 변형



	//		for (auto iter = line1.begin(); iter !=line1.end(); iter++)
	//		{
	//			//
	//			auto size = line1.find(lint2, distance(line1.begin(), line1.begin()));
	//			if (size != std::string::npos)
	//			{
	//				iter += size;
	//				advance(iter, size);
	//				count++;
	//			}
	//		}
	//	}

	//}
}
