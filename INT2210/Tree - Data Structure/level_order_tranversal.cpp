//Breadth First Search

#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
};

void levelOrder(Node* root) {
	if (root == NULL) return;

	//use for tranversal
	queue<Node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		//visit node
		Node* current = Q.front();
		cout << current->data << " ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop(); //remove the element at front
	}
}

Node* Insert(Node* root, char data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}

	else if (data <= root->data) root->left = Insert(root->left, data);
	else root->right = Insert(root->right, data);
	return root;
}

int main()
{
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Level Order. 
	levelOrder(root);
}

/*
Time - Complexity: O(n)
Space - Complexity: 
	+ O(1) - best
	+ O(n) - worst (perfect binary tree) / Avg