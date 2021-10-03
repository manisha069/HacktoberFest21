#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;


class node {

public:
	int data;
	node* left, *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

//utility functions

//function buildtree
node* buildtree() {
	int d;
	cin >> d;

	if (d == -1)
		return NULL;
	node* n = new node(d);
	n->left = buildtree();
	n->right = buildtree();

	return n;
}

//function for inorder
node* inorder(node *root) {
	if (!root) return NULL;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
	return root;
}

//function levelorder
node* levelorder(node *root) {
	if (!root) return NULL;
	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			cout << "\n                                                                        ";
			if (!q.empty())
				q.push(NULL);
		}

		else {
			cout << temp->data;
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}

	}

	return root;
}

//function for itrinorder
node* itrinorder(node* root) {
	if (!root) return NULL;
	stack<node*> s;
	s.push(root);
	root = root->left;

	while (!s.empty() or root) {

		if (!root) {
			node *temp = s.top();
			s.pop();
			cout << temp->data;
			if (temp->right)
				root = temp->right;
		}
		else {
			s.push(root);
			root = root->left;
		}

	}
	return root;
}

//function itrpostorder
node* itrpostorder(node *root) {
	if (!root) return NULL;
	stack<pair<node*, int>> s;

	while (!s.empty() or root) {
		if (root) {
			s.push({root, 1});
			root = root->left;
		}
		else {
			auto temp = s.top(); s.pop();
			if (temp.second == 1) {
				s.push({temp.first, -1});
				root = temp.first->right;
			}
			else {
				cout << temp.first->data << " ";
				root = NULL;
			}
		}
	}

	return root;
}

//function treefrominorder
node* treefrominorder(vector<int> arr, node* &root) {

	int l = arr.size();
	queue<node*> q;

	root = new node(arr[0]);
	q.push(root);

	int i = 1;

	while (!q.empty()) {

		node *temp = q.front(); q.pop();

		temp->left = (arr[i] != -1) ? new node(arr[i]) : NULL;
		i++;

		if (temp->left)
			q.push(temp->left);

		temp->right = (arr[i] != -1) ? new node(arr[i]) : NULL;
		i++;

		if (temp->right)
			q.push(temp->right);

	}

	return root;
}

//function preorder
node* preorder(node *root) {
	if (!root)
		return NULL;

	cout << root->data;
	preorder(root->left);
	preorder(root->right);

	return root;
}



int main() {

	node *root = NULL;
	vector<int> arr{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};

	treefrominorder(arr, root);

	inorder(root);





	return 0;
}