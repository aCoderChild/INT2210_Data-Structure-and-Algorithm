#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        int level;

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
    	//Create a binary tree
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    void topView(Node * root) {
    	//Base case
    	if (root == NULL) return;

    	//Queue to Store the Nodes during level order tranversal
    	//for TRANVERSAL
    	queue<Node*> q;

    	//Map to take horizontal distance and node as key
    	//where the result is store
    	map<int, int> mp;

    	int level = 0;
    	root->level = 0;

    	q.push(root);

    	while(q.size()) {
    		level = root->level;
	
    		//if the map has no Visited node for that
    		//horizontal distance, push the node in the map

    		if (mp.count(level) == 0) {
    			mp[level] = root->data;
    		}

    		//continue the tranversal by pushing the left and right nodes into the queue, 
    		//with the updated value of their horizontal distance (aka. level)
    		if (root->left) {
    			root->left->level = level - 1;
    			q.push(root->left);
    		}

    		if (root->right) {
    			root->right->level = level + 1;
    			q.push(root->right);
    		}

    		q.pop();
    		root = q.front();
    	}

    	for (auto it = mp.begin(); it != mp.end(); it++) {
    		cout << it->second << " ";
    	}
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t--> 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
