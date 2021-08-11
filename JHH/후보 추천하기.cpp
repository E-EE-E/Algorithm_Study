#include <iostream>
#include<vector>
#include<tuple>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

bool **visit;
int N, recommend;
int cnt;
deque<int> dequ;
map<int, int> m_map;
tuple<int,int,int> *arr; //추천수, 입력시기, 번호
deque<tuple<int, int, int>>m_deque;
priority_queue<pair<int, int>> pq;



int main() {

	cin >> N >> recommend;

	//동적할당
	arr = new tuple<int,int,int>[N];

	//map 입력
	int num;
	cnt=0;
	bool check_exist = false;
	for (int i = 0; i < recommend; i++) {
		check_exist = false;
		cin >> num;

		//겹치는 번호 검색
		int count, old, number;
		for (int k = 0; k < cnt; k++) {
			//있으면 추천수 ++
			tie(count, old, number) = m_deque[k];
			if (number == num) {
				m_deque[k] = make_tuple(count + 1, old, number);
				check_exist = true;
				break;
			}
		}

		


		//없으면 추가 또는 교체.
		if (!check_exist) {
			if (cnt < N) { //비어있으면 추가.
				m_deque.push_back(make_tuple(1, i, num));
				cnt++;
			} 
			else { //꽉찼으면 교체
				sort(m_deque.begin(), m_deque.end());
				m_deque.pop_front();
				m_deque.push_back(make_tuple(1, i, num));
				//추천수 가장 적은 학생 삭제
				//

			}
		}
			
			
		
	}

	int count, old, number;
	deque<int> result_list;
	for (int i = 0; i < cnt; i++) {
		tie(count, old, number) = m_deque[i];
		result_list.push_back(number);
	}

	sort(result_list.begin(), result_list.end());
	for (int i : result_list) {
		cout << i<<" ";
	}
	
	delete arr;
}