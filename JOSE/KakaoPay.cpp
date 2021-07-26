#pragma once

#include "KakaoPay.h"

#include <algorithm>

using namespace std;

int kakao::Generator::count_ = 0;

namespace kakao {

	vector<int> solution(vector<long long> ages, vector<vector<int>> wires)
	{
		vector<Generator> generators;
		for (auto& age : ages)
			generators.emplace_back(age);

		for (auto& wire : wires)
		{
			auto newWire = make_shared<Wire>(wire[2]);

			generators[wire[0] - 1].addOutgoingWire(newWire);
			generators[wire[1] - 1].addIncomingWire(newWire);
		}

		vector<int> answer;

		auto isAllGenDead = [&generators, &answer]() ->bool
		{
			bool isAllDead = true;
			for (auto& generator : generators)
			{
				bool isLive = generator.isLive();
				if (!isLive)
				{
					if (find(answer.begin(), answer.end(), generator.id()) == answer.end())
						answer.emplace_back(generator.id());
				}
				isAllDead &= !isLive;
			}

			return isAllDead;
		};

		auto aDayAfter = [&generators]()
		{
			for (auto& generator : generators)
				generator.ADayAfter();
		};

		//어느 하나 살아있는동안, 하루 하루 지나기
		while (!isAllGenDead())
			aDayAfter();

		return answer;
	}

	bool Wire::isWorking() const
	{
		return isWorking_;
	}

	void Wire::imDying()
	{
		--ages_;
		if (ages_ <= 0)
			isWorking_ = false;
	}

	Generator::Generator(long long ages) : ages_(ages)
	{
		id_ = ++count_;
	}

	void Generator::ADayAfter()
	{
		//수명은 하루에 1씩 감소합니다.
		--ages_;
		if (ages_ <= 0)
		{
			for (auto& wire : outgoing_)
			{
				wire->imDying();
			}
		}
	}

	bool Generator::isLive() const
	{
		//발전기의 남은 수명이 0보다 커야 합니다. 
		auto ageCondition = ages_ > 0;
		//해당 발전기로 들어오는 전선 중,
		//적어도 1개 이상의 전선에서 전력이 공급되어야 합니다.

		bool powerSupplyCondition = false;
		for (auto& wire : incoming_)
			powerSupplyCondition |= wire.lock()->isWorking();

		return ageCondition && powerSupplyCondition;
	}

	int Generator::id() const
	{
		return id_;
	}

	void Generator::addIncomingWire(const shared_ptr<Wire> wire)
	{
		incoming_.emplace_back(wire);
	}

	void Generator::addOutgoingWire(const shared_ptr<Wire> wire)
	{
		outgoing_.emplace_back(wire);
	}
}
