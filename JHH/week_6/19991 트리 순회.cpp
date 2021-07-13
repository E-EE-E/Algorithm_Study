#include <iostream>
#include <vector>

using namespace std;



vector<vector<char>> tree;

void preorder(int nodeNum) {
	vector<char> v = tree[nodeNum];
	char node = nodeNum + 65;
	cout << node; //나 방문

	if (v[0] != '.') { //왼쪽 있으면 방문
		preorder(v[0] - 65);
	}
	if (v[1] != '.') { //오른쪽 있으면 방문
		preorder(v[1] - 65);
	}
}


void inorder(int nodeNum) {
	vector<char> v = tree[nodeNum];
	char node = nodeNum + 65;
	
	if (v[0] != '.') {
		inorder(v[0] - 65);
	}
	cout << node;
	if (v[1] != '.') {
		inorder(v[1] - 65);
	}
}

void postorder(int nodeNum) {
	vector<char> v = tree[nodeNum];
	char node = nodeNum + 65;

	if (v[0] != '.') { 
		postorder(v[0] - 65);
	}
	if (v[1] != '.') {
		postorder(v[1] - 65);
	}
	cout << node;
	
}

int main() {
	int N;
	cin >> N;
	
	tree = vector<vector<char>>(N); //N개 노드 가진 트리

	char me, left, right;
	for (int i = 0; i < N; i++) {
		cin >> me >> left >> right;
		tree[me-65].push_back(left); 
		tree[me - 65].push_back(right);
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);

	return 0;
}