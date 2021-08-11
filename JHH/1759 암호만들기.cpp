#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<pair<char,bool>> Consonant;
vector<pair<char,bool>> Vowels;
vector<string> key_words;
string result;
int N, L_minus_N;
void chooseConsnant(int cnt, int idx) {
	
	if (cnt == L_minus_N) {
		//결과 완성, 오름 차순 정렬해서 배열에 푸시.
		string sorted;
		sorted = result; //깊은 복사 
		
		sort(sorted.begin(), sorted.end());
		key_words.push_back(sorted);
		return;
	}

	for (int i = idx; i < Consonant.size(); i++) {
		if (Consonant[i].second == true)
			continue;
		result.push_back(Consonant[i].first);
		Consonant[i].second = true;
		chooseConsnant(cnt + 1, i);
		result.pop_back();
		Consonant[i].second = false;
	}


}

void chooseVowel(int cnt, int idx) {
	if (cnt == N) {
		//이제 자음 골라야 함 ;;;
		chooseConsnant(0, 0);
		return;
	}
	for (int i = idx; i < Vowels.size(); i++) {
		if (Vowels[i].second == true)
			continue;
		result.push_back(Vowels[i].first);
		Vowels[i].second = true;
		chooseVowel(cnt + 1, i);
		result.pop_back();
		Vowels[i].second = false;
	}
}
int main() {
	cin >> L >> C;
	char input;
	for (int i = 0; i < C; i++) {
		cin >> input;
		if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') {
			Vowels.push_back(make_pair(input,false)); //모음끼리 푸시 
		}
		else {
			Consonant.push_back(make_pair(input, false)); //자음끼리 푸시
		}
	}
	//정렬 1회
	sort(Vowels.begin(), Vowels.end());
	sort(Consonant.begin(), Consonant.end());


	//
	N = 1;
	L_minus_N = L - N;
	while (L_minus_N >= 2) {
		chooseVowel(0, 0);
		N++;
		L_minus_N = L - N;
	}

	sort(key_words.begin(), key_words.end());

	for (int i = 0; i < key_words.size(); i++) {
		cout << key_words[i] << endl;
	}
	//Vowel에서 N개 뽑기

	//Consonant에서  L-N개 뽑기

	//

}