#pragma once

#include <iostream>
#include <functional>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <stack>
#include <bitset>

using namespace std;

namespace bj {

	class TreeNode
	{
	public:
		TreeNode() : data_(0), leftChild_(nullptr), rightChild_(nullptr) {}
		TreeNode(int x) : data_(x), leftChild_(nullptr), rightChild_(nullptr) {}
		~TreeNode() = default;

		int data_;
		TreeNode* leftChild_;
		TreeNode* rightChild_;
	};

	class TreeNodeHelper
	{
	public:
		static TreeNode* mkNode(TreeNode* node)
		{
			if (node == nullptr)
				return node;

			char left, right;
			cin >> left >> right;
			if (left != '.')
			{
				auto leftChild = new TreeNode(left);
				node->leftChild_ = leftChild;
			}

			if (right != '.')
			{
				auto rightChild = new TreeNode(right);
				node->rightChild_ = rightChild;
			}

			return node;
		}

		static const TreeNode* findNode(const TreeNode* node, const char target)
		{
			if (node)
			{
				//전위탐색
				if (node->data_ == target)
				{
					return node;
				}

				if (node->leftChild_)
				{
					if (auto find = findNode(node->leftChild_, target))
						return find;
				}

				if (node->rightChild_)
				{
					if (auto find = findNode(node->rightChild_, target))
						return find;
				}
			}

			return nullptr;
		}

		static void preorderPrint(TreeNode* currentNode)
		{
			if (currentNode)
			{
				cout << currentNode->data_;
				preorderPrint(currentNode->leftChild_);
				preorderPrint(currentNode->rightChild_);
			}
		}
		static void inorderPrint(TreeNode* currentNode)
		{
			if (currentNode)
			{
				inorderPrint(currentNode->leftChild_);
				cout << currentNode->data_;
				inorderPrint(currentNode->rightChild_);
			}
		}
		static void postorderPrint(TreeNode* currentNode)
		{
			if (currentNode)
			{
				postorderPrint(currentNode->leftChild_);
				postorderPrint(currentNode->rightChild_);
				cout << currentNode->data_ << endl;
			}
		}

		static void preorderAdd(TreeNode* currentNode, const int newData)
		{
			if (currentNode)
			{
				if (currentNode->data_ > newData)
				{
					if (currentNode->leftChild_)
						preorderAdd(currentNode->leftChild_, newData);
					else
						currentNode->leftChild_ = new TreeNode(newData);
				}
				else
				{
					if (currentNode->rightChild_)
						preorderAdd(currentNode->rightChild_, newData);
					else
						currentNode->rightChild_ = new TreeNode(newData);
				}
			}
		}
	};

	/*트리 정보 받고 전위, 중위, 후위 순회 해보기*/
	int P1991()
	{
		//0ms	
		int nodeCount, rootData;
		cin >> nodeCount >> rootData;
		auto rootNode = TreeNodeHelper::mkNode(new TreeNode(rootData));

		while (nodeCount--)
		{
			char parent;
			cin >> parent;

			if (auto parentNode = const_cast<TreeNode*>(TreeNodeHelper::findNode(rootNode, parent)))
				TreeNodeHelper::mkNode(parentNode);
		}

		TreeNodeHelper::preorderPrint(rootNode);
		cout << endl;
		TreeNodeHelper::inorderPrint(rootNode);
		cout << endl;
		TreeNodeHelper::postorderPrint(rootNode);

		return 0;
	}

	/*preorder traverse 결과를 tree로 만들기*/
	int P5639()
	{
		//96ms
		int data;
		cin >> data;//<-첫 입력은 ROOT가 됨
		auto rootNode = new TreeNode(data);


		while (cin >> data)
			TreeNodeHelper::preorderAdd(rootNode, data);

		TreeNodeHelper::postorderPrint(rootNode);

		return 0;
	}

	int P6416()
	{
		//0ms

		int from, to;
		unsigned int caseCount = 0;

		while (++caseCount)
		{
			unordered_map<int, unordered_set<int>> map;
			unordered_set<int> starts;
			unordered_set<int> ends;

			bool flag = true;
			while (cin >> from >> to)
			{
				if (from < 0 && to < 0)
					return 0;

				if (from == 0 && to == 0)
					break;

				//끝이 이미 끝 목록에 있는가?(조건 2)
				auto findMultiEnds = ends.find(to);
				if (findMultiEnds != ends.end())
					flag = false;

				starts.emplace(from);
				ends.emplace(to);

				//끝에서 출발하는 간선중 시작으로 가는 부분이 있는가?(조건 2)
				auto findDoubleLinked = map[to].find(from);
				if (findDoubleLinked != map[to].end())
					flag = false;

				map[from].emplace(to);

			}

			//ROOT 가 둘 이상인가?(조건 1)
			for (auto end : ends)
			{
				auto findEndInStart = starts.find(end);
				if (findEndInStart != starts.end())
					starts.erase(findEndInStart);
			}

			if (starts.size() != 1)
			{
				if (!map.empty())
					flag = false;
				else//special case
				{
					cout << "Case " << caseCount << " is a tree.\n";
					continue;
				}
			}

			if (flag)
			{
				unordered_set<int> visits;
				queue<int> que;

				que.emplace(*starts.begin());

				while (!que.empty())
				{
					auto currentNode = que.front();
					visits.emplace(currentNode);
					que.pop();

					for (auto& next : map[currentNode])
					{
						auto findNext = visits.find(next);
						if (findNext == visits.end())
							que.push(next);
					}
				}

				if (visits.size() != ends.size() + 1)
					flag = false;
			}

			cout << "Case " << caseCount << " is ";
			if (!flag)
				cout << "not ";
			cout << "a tree.\n";
		}

		return -1;
	}

	int P4358()
	{
		//168ms

		map<string, unsigned int> map;
		string species;
		int tot = 0;
		while (getline(cin, species))
		{
			map[species]++;
			tot++;
		}

		if (tot == 0)
			return 0;

		cout << fixed << setprecision(4);

		for (auto orderedPair : map)
			cout << orderedPair.first << " " << 100 * (double)orderedPair.second / tot << "\n";

		return 0;
	}

	int P3425()
	{
		//8ms

		class GoStack
		{
		public:
			void push(const int x)
			{
				stack_.push(x);
			};

			void pop()
			{
				stack_.pop();
			};

			bool isPopable() //const
			{
				bool result = stack_.size() > 0;
				if (!result)
					printError();

				return result;
			}

			bool isOperatable() //const
			{
				bool result = stack_.size() > 1;
				if (!result)
					printError();

				return result;
			}

			void inverse()
			{
				auto top = stack_.top();
				stack_.pop();
				stack_.push(-top);
			};

			void duplicate()
			{
				stack_.push(stack_.top());
			}

			void swap()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();

				stack_.push(top);
				stack_.push(underTop);
			}

			bool add()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();

				if (abs(underTop + top) < 1000000001LL)
				{
					stack_.push(underTop + top);
					return true;
				}

				printError();
				return false;
			}

			bool sub()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();


				if (abs(underTop - top) < 1000000001LL)
				{
					stack_.push(underTop - top);
					return true;
				}

				printError();
				return false;
			}

			bool mul()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();

				if (abs(underTop * top) < 1000000001LL)
				{
					stack_.push(underTop * top);
					return true;
				}

				printError();
				return false;
			}

			void div()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();

				if (underTop < 0 && top > 0 || underTop > 0 && top < 0)
					stack_.push(-(abs(underTop) / abs(top)));
				else
					stack_.push((abs(underTop) / abs(top)));
			}

			void mod()
			{
				auto top = stack_.top();
				stack_.pop();
				auto underTop = stack_.top();
				stack_.pop();

				if (underTop < 0)
				{
					stack_.push(-abs(underTop) % abs(top));
				}
				else
				{
					stack_.push(abs(underTop) % abs(top));
				}

			}

			bool isSafeDivideByZero()// const
			{
				bool result = isPopable();
				if (!result)
					return result;

				result = stack_.top() != 0;
				if (!result)
					printError();

				return result;
			}

			bool topValidCheck()//const
			{
				bool result = isPopable();
				if (!result)
					return result;

				result = abs(stack_.top()) < 1000000001LL;
				if (!result)
					printError();

				return result;
			}

			void checkEndCondition()// const
			{
				if (!topValidCheck())
					return;
				else if (stack_.size() != 1)
				{
					printError();
				}
				else
				{
					cout << stack_.top() << "\n";
				}
			}

			void printError()//const
			{
				cout << "ERROR" << "\n";
			}

		private:
			stack<long long> stack_;
		};

		/*고스택*/

		const string NUM = "NUM";
		const string POP = "POP";
		const string INV = "INV";
		const string DUP = "DUP";
		const string SWP = "SWP";
		const string ADD = "ADD";
		const string SUB = "SUB";
		const string MUL = "MUL";
		const string DIV = "DIV";
		const string MOD = "MOD";
		const string END = "END";
		const string QUIT = "QUIT";

		while (true)
		{
			string COMMAND;
			vector<string> commandList;
			while (COMMAND != END)
			{
				cin >> COMMAND;

				if (COMMAND == QUIT)
					return 0;

				commandList.emplace_back(COMMAND);
			}

			unsigned int caseCount;
			cin >> caseCount;
			while (caseCount--)
			{
				GoStack goStack;

				long long initialValue;
				cin >> initialValue;

				goStack.push(initialValue);

				for (const auto& command : commandList)
				{
					if (command == NUM) {}
					else if (command == POP)
					{
						if (goStack.isPopable())
							goStack.pop();
						else
							break;
					}
					else if (command == INV)
					{
						if (goStack.isPopable())
							goStack.inverse();
						else
							break;
					}
					else if (command == DUP)
					{
						if (goStack.isPopable())
							goStack.duplicate();
						else
							break;
					}
					else if (command == SWP)
					{
						if (goStack.isOperatable())
							goStack.swap();
						else
							break;
					}
					else if (command == ADD)
					{
						if (goStack.isOperatable() && goStack.add())
							continue;
						break;
					}
					else if (command == SUB)
					{
						if (goStack.isOperatable() && goStack.sub())
							continue;
						break;
					}
					else if (command == MUL)
					{
						if (goStack.isOperatable() && goStack.mul())
							continue;
						break;
					}
					else if (command == DIV)
					{
						if (goStack.isSafeDivideByZero() && goStack.isOperatable())
							goStack.div();
						else
							break;
					}
					else if (command == MOD)
					{
						if (goStack.isSafeDivideByZero() && goStack.isOperatable())
							goStack.mod();
						else
							break;
					}
					else if (command == END)
					{
						goStack.checkEndCondition();
						break;
					}
					else//NUM X의 X
					{
						goStack.push(atoi(command.c_str()));
					}
				}
			}

			cout << "\n";

		}

		return -1;
	}

	/*교환*/
	int P1039()
	{
		//4ms

		string N;
		int swapCount;

		cin >> N >> swapCount;

		if (N.length() < 2)
		{
			//교환불가
			cout << -1;
			return 0;
		}

		set<string> candiates;
		candiates.emplace(N);

		while (swapCount--)
		{
			//string candidate(N);
			string visits(N.length(), '0');
			visits[0] = '1';
			visits[1] = '1';

			set<string> nextGeneration;

			do
			{
				bool flag = true;

				for (size_t i = 0; i < visits.size() && flag; ++i)
				{
					if (visits[i] != '1')
						continue;

					for (size_t j = i + 1; i < visits.size(); ++j)
					{
						if (visits[i] == '1' && visits[j] == '1')
						{

							for (auto& candidate : candiates)
							{
								string toBeSwaped(candidate);
								swap(toBeSwaped[i], toBeSwaped[j]);

								if (toBeSwaped[0] != '0')
									nextGeneration.emplace(toBeSwaped);
							}

							flag = false;
							break;
						}
					}
				}

			} while (prev_permutation(visits.begin(), visits.end()));

			candiates = nextGeneration;
		}

		if (candiates.empty())
			cout << -1;
		else
			cout << *prev(candiates.cend());

		return 0;
	}

}