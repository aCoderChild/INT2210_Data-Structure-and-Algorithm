#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

int calculateHeight(TreeNode* node) {
    if (node == NULL) return 0;
    int maxHeight = 0;
    for (TreeNode* child : node->children) {
        maxHeight = max(maxHeight, calculateHeight(child));
    }
    return maxHeight + 1;
}

//preorder Tranversal
void preorderTranversal(TreeNode* node, vector<int>& result) {
    if (node) {
        result.push_back(node->value);
        for (TreeNode* child : node->children) {
            preorderTranversal(child, result);
        }
    }
}

//postorder Tranversal
void postorderTranversal(TreeNode* node, vector<int>& result) {
    if (node) {
        for (TreeNode* child : node->children) {
            postorderTranversal(child, result);
        }
        result.push_back(node->value);
    }
}

//check if is binary or not
bool isBinaryTree(TreeNode* node) {
    if (node == NULL) return true;
    if (node->children.size() > 2) return false;
    for (TreeNode* child : node->children) {
        if (!isBinaryTree(child)) return false;
    }
    return true;
}

void inorderTranversal(TreeNode* node, vector<int>& result) {
    if (node) {
        if (node->children.size() >= 1) {
            inorderTranversal(node->children[0], result);
        }
        result.push_back(node->value);
        if (node->children.size() >= 2) {
            inorderTranversal(node->children[1], result);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of Nodes (n) and edges (m): ";
    cin >> n >> m;

    //Create the Nodes
    map<int, TreeNode*> nodes;
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }

    cout << "Enter the edges (u v) indicating u is the parent of v: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u]->children.push_back(nodes[v]);
    }

    TreeNode* root = nodes[1]; // Assuming node 1 is always the root

    cout << "Height of tree: " << calculateHeight(root) << endl;

    //Preorder Tranversal
    vector<int> preorderResult;
    preorderTranversal(root, preorderResult);
    cout << "Preorder tranversal: ";
    for (int i : preorderResult) cout << i << " ";
    cout << endl;
    
    //Postorder Tranversal
    vector<int> postorderResult;
    postorderTranversal(root, postorderResult);
    cout << "Postorder tranversal: ";
    for (int i : postorderResult) cout << i << " ";
    cout << endl;

    bool isBinary = isBinaryTree(root);
    cout << "Is Binary Tree: " << (isBinary ? "YES" : "NO") << endl;

    //inorder Tranversal
    vector<int> inorderResult;
    inorderTranversal(root, inorderResult);
    cout << "Inorder tranversal: ";
    for (int i : inorderResult) cout << i << " ";
    cout << endl;

    //Clean up
    for (auto& pair : nodes) {
        delete pair.second;
    }

    return 0;
}

//with the help of chat GPT