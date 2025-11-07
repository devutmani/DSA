#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> &preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";  
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);  
    postOrder(root->right);
    cout << root->data << " ";
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int count(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + (count(root->left) + count(root->right));
}

int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sum(root->left)+sum(root->right);
}

bool subTree(Node* root, Node* subRoot) {
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL || root2 == NULL) {
        root1==root2;
    }

    return isIdentical(root1->left, root2->left) && 
           isIdentical(root1->right, root2->right) && 
           root1->data == root2->data;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postOrder(root);

    cout << "\nHeight of this tree is: " << height(root) << endl;
    cout << "Count of nodes: " << count(root) << endl;
    cout << "Sum of nodes' data: " << sum(root) << endl;
    return 0;
}