#include <iostream>
#include <vector>

using namespace std;


class Node
{
public:

	int val;
	Node * left;
	Node * right;

	Node(int val) { this->val = val; this->left = NULL; this->right = NULL; }
	Node() {};
	~Node() {};
};

class Tree
{
public:
	Node* root;
	void Insert(Node *newNode);
	void postorder(Node *newNode);
	Tree();
	~Tree();

private:

};

void Tree::Insert(Node *newNode)
{
	if (root == NULL) {
		root = newNode;
	}
	else {
		Node * parent = NULL;
		Node *current = root;
		while (current!=NULL)
		{
			parent = current;
			if (newNode->val < parent->val) {
				current = parent->left;
			}
			else {
				current = parent->right;
			}
		}
		
		//정해진 부모 밑에 insert
		if (newNode->val < parent->val) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
}

void Tree::postorder(Node * newNode)
{
	if (newNode != NULL) {
		postorder(newNode->left);
		postorder(newNode->right);
		cout << newNode->val << endl;
	}
}

Tree::Tree()
{
	root = NULL;

}

Tree::~Tree()
{
}




int main() {
	
	int input;
	Tree t;
	while (cin>>input) {
		Node *n = new Node(input);
		t.Insert(n);
	}

	t.postorder(t.root);
	

	return 0;
}