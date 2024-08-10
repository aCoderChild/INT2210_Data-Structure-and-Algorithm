#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int Data) : data(Data), left(nullptr), right(nullptr) {}
};

// Insert data into the BST
Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        // Create and return a new node if the root is null
        return new Node(data);
    }

    // Recursively insert into the left or right subtree based on the data
    if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }

    return root;
}

// Build the binary tree from the array
Node* Build_Binary_Tree(int a[], int n) {
    if (n <= 0) return nullptr; // Handle empty array case

    Node* root = new Node(a[0]);
    for (int i = 1; i < n; i++) {
        Insert(root, a[i]);
    }

    return root;
}

// Print the tree in inorder (sorted order for BST)
//Use recursion
void Print(Node* root) {
    if (root == nullptr) return; // Base case for recursion

    Print(root->right);   // Print left subtree
    cout << root->data << " "; // Print current node
    Print(root->left);  // Print right subtree
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size should be positive." << endl;
        return 1;
    }

    int* a = new int[n]; // Dynamic array allocation
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* root = Build_Binary_Tree(a, n);
    Print(root);

    delete[] a; // Free the dynamically allocated array
    return 0;
}