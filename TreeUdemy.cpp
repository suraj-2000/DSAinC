#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
struct Node {
	int data;
	Node* lchild;
	Node* rchild;
	Node(int val) {
		data = val;
		lchild = rchild = NULL;
	}
};

Node* create() {
	int x;
	Node *root = NULL;
	cout<<"Enter the root value::";
	cin>>x;
	root = new Node(x);
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node* p = q.front(), *t;
		q.pop();
		cout<<"Enter the Lchild of "<<p->data<<endl;
		cin>>x;
		if(x != -1) {
			t = new Node(x);
			p->lchild = t;
			q.push(t);
		}
		cout<<"Enter the Rchild of "<<p->data<<endl;
		cin>>x;
		if(x != -1) {
			t = new Node(x);
			p->rchild = t;
			q.push(t);
		}  
	}
	return root;	
}

void Preorder(Node *p) {
	if(p) {
		cout<<p->data<<" ";
		Preorder(p->lchild);
		Preorder(p->rchild);	
	}
}

void Inorder(Node *p) {
	if(p) {
		Inorder(p->lchild);
		cout<<p->data<<" ";
		Inorder(p->rchild);	
	}
}

void Postorder(Node *p) {
	if(p) {
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout<<p->data<<" ";	
	}
}

//Iterative preorder////////

void I_Preorder(Node* root) {
	stack<Node*>st;
	while(root || !st.empty()) {
		if(root != NULL) {
			cout<<root->data<<" ";
			st.push(root);
			root = root->lchild;
		}
		else {
			Node* temp = st.top();
			st.pop();
			root = temp;
			root = root->rchild;
		}
	}
}

void Levelorder(Node* root) {
	queue<Node*>q;
	cout<<root->data<<" ";
	q.push(root);
	Node* p;
	while(!q.empty()) {
		p = q.front();
		q.pop();
		if(p->lchild) {
			cout<<p->lchild->data<<" ";
			q.push(p->lchild);	
		}
		if(p->rchild) {
			cout<<p->rchild->data<<" ";
			q.push(p->rchild);	
		}
	}
}
//Iterative Inorder////////

void I_Inorder(Node* root) {
	stack<Node*>st;
	while(root || !st.empty()) {
		if(root != NULL) {
			st.push(root);
			root = root->lchild;
		}
		else {
			Node* temp = st.top();
			cout<<temp->data<<" ";
			st.pop();
			root = temp;
			root = root->rchild;
		}
	}
}

int Height(Node* root) {
	int x, y;
	if(root) {
	    x = Height(root->lchild);
		y = Height(root->rchild);
		if(x > y) {
			return x + 1;
		}
		else {
			return y + 1;
		}
	}
	return 0;
}

int main() {
	Node* root = create();
	cout<<Height(root)<<" ";
	return 0; 
}
