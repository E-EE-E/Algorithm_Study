#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;



vector<string> cmd_vec;

void calculator(int first_V) {
	stack<int> go_stack;
	string cmd;
	long long num, num2;
	long long temp_result;
	bool isError = false;

	go_stack.push(first_V);
	for (string cmd : cmd_vec)
	{
		if (cmd == "END" || isError==true) {
			if (isError == true || go_stack.size() != 1) {
				cout << "ERROR" << endl;
			}
			else {
				cout<< go_stack.top() <<endl;
			}	

			return;
		}

		
		if (cmd.substr(0,3) == "NUM") {
			num = stoi(cmd.substr(4, cmd.length()));
			go_stack.push(num);
		}
		else if (go_stack.size() < 1) { // 숫자가 부족해서 연산을 수행할 수 없음
			isError = true;
		}
		else if (cmd == "POP") {
			go_stack.pop();
		}
		else if (cmd == "INV") {
			num = go_stack.top();
			go_stack.pop();
			go_stack.push(-num);
		}
		else if (cmd == "DUP") {
			num = go_stack.top();
			go_stack.push(num);
		}
		else if (go_stack.size() < 2) { // 숫자가 부족해서 연산을 수행할 수 없음
			isError = true;
		}
		else if (cmd == "SWP") {
			if (go_stack.size() < 2) { // 숫자가 부족해서 연산을 수행할 수 없음
				isError = true;
			}
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			go_stack.push(num);
			go_stack.push(num2);
		}
		else if (cmd == "ADD") {
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			temp_result = num + num2;
			if (abs(temp_result) > 1000000000) {
				isError = true; continue;
			}
			go_stack.push(temp_result);
		}
		else if (cmd == "SUB") {
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			temp_result = num2 - num;
			if (abs(temp_result) > 1000000000) {
				isError = true; continue;
			}
			go_stack.push(temp_result);
		}
		else if (cmd == "MUL") {
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			temp_result = num * num2;
			if (abs(temp_result) > 1000000000) {
				isError = true; continue;
			}
			go_stack.push(temp_result);
		}
		else if (cmd == "DIV") {
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			if (num == 0) {
				isError = true; continue;
			}
			go_stack.push(num2 / num);			
		}
		else if (cmd == "MOD") {
			num = go_stack.top(); go_stack.pop();
			num2 = go_stack.top(); go_stack.pop();
			if (num == 0) {
				isError = true; continue;
			}
			go_stack.push(num2 % num);
		}
	}
}

int main() {
	
	string cmd;
	int N, first_val;
	while (getline(cin, cmd))
	{
		if (cmd == "QUIT") {
			break;
		}

		if (cmd == "")
			continue;
		if (cmd == "END") {
			cmd_vec.push_back(cmd);
			cin >> N;
			for (int i = 0; i < N; i++) {
				cin >> first_val;
				calculator(first_val);
			}
			cout << endl;
			cmd_vec.clear();
		}
		else {
			cmd_vec.push_back(cmd);
		}
	}

	
	

	return 0;
}