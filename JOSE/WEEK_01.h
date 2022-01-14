#pragma once
#include <map>
#include <memory>
#include <string>
#include <queue>
#include <iostream>

namespace bj
{
	class Room
	{
	public:
		explicit Room(std::string name) : name_(name) {};

		void addChild(std::queue<std::string>& nameSeq)
		{
			if (nameSeq.empty())
				return;

			const auto currentName = nameSeq.front();
			nameSeq.pop();

			auto findRoom = children_.find(currentName);
			if (findRoom == children_.cend())
			{
				auto child = std::make_shared<Room>(currentName);
				children_.emplace(currentName, child);

				child->addChild(nameSeq);
			}
			else
			{
				(*findRoom).second->addChild(nameSeq);
			}
		}

		void traverse() const
		{
			if (level_ != 0)
			{
				std::string dashdash(2 * (level_ - 1), '-');
				std::cout << dashdash << name_ << std::endl;
			}
			level_++;

			for (const auto& eachPair : children_)
			{
				const auto& child = eachPair.second;
				child->traverse();
			}

			level_--;
		}

	private:
		std::map<std::string, std::shared_ptr<Room>> children_;
		std::weak_ptr<Room> parent_;
		std::string name_;

	private:
		static int level_;
	};

	int Room::level_ = 0;

	int P14725()
	{
		Room enterance("root");
		int roomCount = 0;
		std::cin >> roomCount;

		std::vector<std::queue<std::string>> inputs(roomCount);
		auto iter = inputs.begin();

		while (roomCount--)
		{
			int elemCount = 0;
			std::cin >> elemCount;

			auto& queue = (*iter++);
			while (elemCount--)
			{
				std::string elem;
				std::cin >> elem;

				queue.emplace(elem);
			}
		}

		for (auto& line : inputs)
			enterance.addChild(line);

		enterance.traverse();
		return 0;
	}

	int P()
	{
		size_t N, M, K;
		cin >> N >> M >> K;

		std::vector<long long> num(N);
		std::vector<long long> acc(N);

		long long acc = 0;

		auto jter = acc.begin();
		for(auto iter = num.begin(); iter != num.end(); ++iter, ++jter)
		{
			auto& elem = *iter;
			std::cin >> elem;
			*jter = acc += elem;
		}

		enum class Command
		{
			UNDEFINED = 0,
			SWITCH,
			PRINT
		};

		std::vector<std::pair<int, long long>> record(M);
		Command command;
		int from, to;
		
		for(size_t i = M + K; i != 0; --i)
		{
			cin >> command >> from >> to;
			switch (command)
			{
			case Command::SWITCH:
				record.emplace_back(from, to);
				break;
			case Command::PRINT:

				auto rerult = acc[to] - acc[from];
				for (const auto& rec : record)
				{
					int where = rec.first;
					if (where > to)
						continue;
					else
					{
						result += (to - from + 1) * rec.second;
						result -= (to - i) * rec.second;
					}
				}
				std::cout << result << std::endl;
				break;
			default:
				return -1;
			}
		}

		return 0;
	}



}
