#include<iostream>
using namespace std;
struct node{
	char data;
	node* left;
	node* right;
	node( char c)
	:data(c)
	{
		left=NULL;
		right=NULL;
	}
};
class AVL{
public:
	node* root;
	AVL(){
		root=NULL;
	}
	node* insert(node*p, char c);	
	node* remove(node*p,char c);
	void inorder(node* p);
	node* ll_rotate(node *p);
	node* rr_rotate(node *p);
	node* lr_rotate(node *p);
	node* rl_rotate(node *p);
	int  heightfromnode(node*p);
	int  h_difference(node* p);
	node* inorder_successor(node *p);
};
node* AVL::inorder_successor(node *p){
	p=p->right;
	while(p->left) p=p->left;

	return p;
}
int AVL::heightfromnode(node* p){
	if(!p) return 0;
	return 1+ max(heightfromnode(p->left),heightfromnode(p->right));
}
int AVL::h_difference(node *p){
	int left_height=(p->left)?heightfromnode(p->left):0;
	int right_height=(p->right)?heightfromnode(p->right):0;
	return  right_height-left_height;
}
node* AVL::insert(node*p ,char c){
	if(!root){
		root=new node(c);
		return root;
	}
	if(!p){
		p=new node(c);
		return p;
	}
	if(p->data > c)
		p->left=insert(p->left,c);
	else
		p->right=insert(p->right,c);

	int diff=h_difference(p);
	if(diff>1 || diff<-1){
		//right rotations
		if(diff>1){
			//right-right rotations
			if(h_difference(p->right)>0){
				p=rr_rotate(p);
			}
			//right-left rotations
			else{
				p=rl_rotate(p);
			}
		}
		//left rotations
		else{
			//left-left rotations
			if(h_difference(p->left)<0){
				p=ll_rotate(p);
			}
			//left-right rotations
			else{
				p=lr_rotate(p);
			}
		}
	}



	return p;

}

node* AVL::remove(node*p,char c){
	if(!p) return NULL;  //for no root

	if(!p->left && !p->right){
		if(p==root) root=NULL;
		delete(p);
		return NULL;
	}

	if(p->data>c)
		p->left=remove(p->left,c);
	else if(p->data<c)
		p->right=remove(p->right,c);

	else{
		p->data=inorder_successor(p)->data;
		p->right=remove(p->right,p->data);
	}

	int diff=h_difference(p);
	if(diff>1 || diff<-1){
		//right rotations
		if(diff>1){
			//right-right rotations
			if(h_difference(p->right)>0){
				p=rr_rotate(p);
			}
			//right-left rotations
			else{
				p=rl_rotate(p);
			}
		}
		//left rotations
		else{
			//left-left rotations
			if(h_difference(p->left)<0){
				p=ll_rotate(p);
			}
			//left-right rotations
			else{
				p=lr_rotate(p);
			}
		}
	}

	return p;
}
void AVL::inorder(node *p){
	if(!p) return ;
	inorder(p->left);
	cout<<" "<<p->data;
	inorder(p->right);
}
node* AVL::ll_rotate(node* p){
	int flag=0;
	if(p==root) flag=1; 
	node* left_node=p->left;
	node* left_left_node=p->left->left;

	p->left=left_node->right;
	left_node->right=p;

	p=left_node;
	if(flag) root=p;
	return p;
}
node* AVL::lr_rotate(node* p){
	int flag=0;
	if(p==root) flag=1;

	node* left_node=p->left;
	node* left_right_node=p->left->right;

	left_node->right=left_right_node->left;
	p->left=left_right_node->right;

	left_right_node->left=left_node;
	left_right_node->right=p;

	p=left_right_node;
	if(flag) root=p;
	return NULL;
}
node* AVL::rr_rotate(node* p){
	int flag=0;
	if(p==root) flag=1;
	node* right_node=p->right;
	node* rigth_right_node=p->right->right;

	p->right=right_node->left;
	right_node->left=p;

	p=right_node;
	if(flag) root=p;
	return p;
}
node* AVL::rl_rotate(node* p){
	int flag=0;
	if(p==root) flag=1;

	node* right_node=p->right;
	node* right_left_node=p->right->left;

	right_node->left=right_left_node->right;
	p->right=right_left_node->left;

	right_left_node->left=p;
	right_left_node->right=right_node;

	p=right_left_node;
	if(flag) root=p;
	return p;
}

int main(){
	AVL tree;

	tree.insert(tree.root,'H');
	tree.insert(tree.root,'I');
	tree.insert(tree.root,'J');
	tree.insert(tree.root,'B');
	tree.insert(tree.root,'A');
	tree.insert(tree.root,'E');
	tree.insert(tree.root,'C');
	tree.insert(tree.root,'F');
	tree.insert(tree.root,'D');
	tree.insert(tree.root,'G');
	tree.insert(tree.root,'K');
	tree.insert(tree.root,'L');


	tree.inorder(tree.root);
	return 0;	
}