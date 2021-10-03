#include<iostream>
#include<utility>
#include <bits/stdc++.h>
using namespace std;

struct node {
	node *lchild;
	node *mchild;
	node *rchild;
	int *key;
};

class tree23 {
public:
	tree23() {
		root = NULL;
	}
	node *root;
	node* display(node *);
	pair<node*, int> recInsert( node *p, int );
	node *nodeSplitter(node*, node*);

};

int main() {

	tree23 t;
	t.recInsert(t.root, 20);
	t.recInsert(t.root, 30);
	t.recInsert(t.root, 40);
	t.recInsert(t.root, 50);
	t.recInsert(t.root, 60);
	t.recInsert(t.root, 25);
	t.display(t.root);

	return 0;
}


/* function for making a new node with
left element having value and other having -1..
and all pointers pointing to NULL   */



node* nodeMaker(int val) {
	node *temp = new node;
	temp->lchild = NULL;
	temp->mchild = NULL;
	temp->rchild = NULL;
	temp->key = new int[2];
	temp->key[0] = val;
	temp->key[1] = -1;
	return temp;
}

/*

Function for splitting nodes..
takes two nodes and then splits the nodes and returns the middle
 node having l and r childs as other two nodes

*/
node* tree23::nodeSplitter(node *p, node *val) {

	if (val->key[0] < p->key[0]) {
		node *t1 = nodeMaker(p->key[1]);		//new node from right most value
		p->key[1] = -1;						//making rigthspace empty for node to be pushed up
		p->lchild = val;						//boththe nodes made children of pushed node
		t1->lchild = p->mchild;
		p->mchild = t1;
		p->rchild = NULL;
		return p;
	}
	else if (val->key[0] > p->key[0] && val->key[0] < p->key[1]) {
		node *t1 = nodeMaker(p->key[1]); //new node for right value
		p->key[1] = -1;					//emptying the space occupied by the value which made the node
		p->mchild = val->lchild;			//middle child of left node is left child of middle node
		t1->lchild = val->mchild;			//left child of right node is middle child of middle node
		t1->mchild = t1->lchild;			//make lchild the middle child
		val->lchild = p;					//left and right nodes made children of pushed nodes
		val->mchild = t1;
		if (p == root)
			root = val;
		return val;

	}
	else {
		node *t1 = nodeMaker(p->key[1]);	//making new node for middle value
		p->key[1] = -1;					//emptying the space middle node's value took
		p->rchild = NULL;
		t1->lchild = p;
		t1->mchild = val;
		if (p == root)
			root = t1;
		return t1;
	}

}


/*Function to recursively insert elements.
 returns a pair of <node*,int>
	. If node *=NULL and int=-1; then the tree has ended and the current node is leaf node
	. If node * !=NULL and int =1; then the node needs to be handeled
	. If node *!=NULL and int =-1; then node needs not be handeled.
 */

pair<node*, int> tree23::recInsert(node *p, int val) {

	pair <node*, int> temp;

	if (root == NULL) {
		root = nodeMaker( val);
		temp.first = root;
		temp.second = -1;
		return temp;
	}

	if (p == NULL) {
		temp.first = NULL;
		temp.second = -1;
		return temp;
	}

	if (val < p->key[0]) {
		temp = recInsert(p->lchild, val);
	}
	else if ((val > p->key[0] && p->key[1] == -1) || (val > p->key[0] && p->key[1] != -1 && val < p->key[1]))
		temp = recInsert(p->mchild, val);
	else
		temp = recInsert(p->rchild, val);


	if (temp.first == NULL && temp.second == -1) {					//-1 and NULL are for indicating end is reached
		if (val < p->key[0] && p->key[1] == -1) {              // shift to right and place the value
			p->key[1] = p->key[0];
			p->key[0] = val;
		}
		else if (val > p->key[0] && p->key[1] == -1) {
			p->key[1] = val;
		}
		else {
			node *temp2 = nodeMaker(val);
			temp2 = nodeSplitter(p, temp2);
			temp.first = temp2;
			temp.second = 1;
			return temp;
		}

	}
	else if (temp.first != NULL &&  temp.second == 1) {			//not NULL and 1 are indicators that the returning node needs to be handeled
		if (p->key[1] == -1) {
			if (temp.first->key[0] > p->key[0]) {
				p->key[1] = temp.first->key[0];
				p->mchild = temp.first->lchild;
				p->rchild = temp.first->mchild;
			}
			else {
				p->key[1] = p->key[0];
				p->key[0] = temp.first->key[0];
				p->rchild = p->mchild;
				p->mchild = temp.first->mchild;
				p->lchild = temp.first->lchild;
			}
		}
		else {
			node *temp2 = temp.first;
			temp2 = nodeSplitter(p, temp2);
			temp.first = temp2;
			temp.second = 1;
			return temp;
		}

	}
	else {

	}

	temp.first = p;		//not NULL and -1 are indicators that returning node doesn.t need any handling
	temp.second = -1;
	return temp;


}
node* tree23::display(node *p) {
	if (p == NULL) {
		return NULL;
	}
	display(p->lchild);

	if (p->key[0] != -1)
		cout << p->key[0];

	display(p->mchild);

	if (p->key[1] != -1)
		cout << p->key[1];

	display(p->rchild);
	return p;

}
