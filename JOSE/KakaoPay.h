#pragma once

#include <memory>
#include <vector>

using namespace std;

namespace kakao {

	vector<int> solution(vector<long long> ages, vector<vector<int>> wires);

	class Wire
	{
	public:
		explicit Wire(int length) : length_(length) {}
		~Wire() = default;

		bool isWorking() const;
		void imDying();

	private:
		int length_ = 0;
		int ages_ = 0;
		bool isWorking_ = true;
	};

	class Generator
	{
	public:
		explicit Generator(long long ages);
		~Generator() = default;

		void ADayAfter();
		bool isLive() const;
		int id() const;
		void addIncomingWire(const shared_ptr<Wire>& wire);
		void addOutgoingWire(shared_ptr<Wire> wire);

	private:
		int id_ = 0;
		long long ages_ = -1;
		vector<shared_ptr<Wire>> outgoing_ = {};
		vector<weak_ptr<Wire>> incoming_ = {};

		static int count_;
	};
}