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
}
