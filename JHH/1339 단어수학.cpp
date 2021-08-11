#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <functional>
using namespace std;


int N;

int total_alpahbet_cnt;
vector<pair<string,int>> list;

//후보군 -> 단어, 현재 단어의 몇번째 위치 점검중인지, 몇 번째 단어인지
vector<tuple<string, int,int>> candidate; 
vector<tuple<string, int, int>> sorted; //많은 순으로 정렬된 버전


bool compare(int a, int b) {
	return a > b;
}


int current_num;




int main() {
	cin >> N;
	total_alpahbet_cnt = 0;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		list.push_back(make_pair(input,input.length()));
		total_alpahbet_cnt += input.length();
	}

	//sort(list.begin(), list.end(), compare);
	current_num = 9;
	int alphabet_list[26] = { 0, };

	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list[i].first.length(); j++) {
			char word = list[i].first[j];
			int idx = list[i].first.length() - (j+1);
			alphabet_list[word - 65] += pow(10, idx);
		}

	}
	sort(alphabet_list, alphabet_list + 26, greater<>());

	int result = 0;
	for (int i=0; i < 26; i++) {
		if (alphabet_list[i] == 0)
			break;
		//cout << alphabet_list[i] << endl;
		result += alphabet_list[i] * current_num; 
		current_num--;
	}
	cout << result;
	
	
	
}