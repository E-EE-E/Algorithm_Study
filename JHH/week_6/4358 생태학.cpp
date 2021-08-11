#include <iostream>
#include <vector>
#include <map>
#include<unordered_map>
#include<string>
#include <iterator>
using namespace std;




int main() {
	
	string s;

	map<string, int> map_tree;
	map<string, int>::iterator it;
	int total = 0;
	while (getline(cin, s))
	{
		total += 1;
		it = map_tree.find(s);
		if (it != map_tree.end()) {
			map_tree[s] += 1;
		}
		else {
			map_tree.insert(make_pair(s, 1));
		}
	}

	
	double percent = 0.0000;
	double cnt = (double)total;
	cout << fixed;
	cout.precision(4);
	for (pair<string, int> val : map_tree) {
		percent = ((double)val.second / cnt) * 100;
		cout << val.first << " " << percent<<endl;
	}

	return 0;
}