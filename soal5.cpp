#include <iostream>
#include <string>
#include <vector>
#include "RedBlackTree.h"

using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
              vector<int>& result) {
    if (node == nil) return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
             vector<int>& result) {
    if (node == nil) return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
               vector<int>& result) {
    if (node == nil) return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printTraversal(const string& label, const vector<int>& result) {
    cout << label << " : ";
    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    RedBlackTree rbt;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        vector<int> pre, in, post;
        preorder(rbt.root(), rbt.nil(), pre);
        inorder(rbt.root(), rbt.nil(), in);
        postorder(rbt.root(), rbt.nil(), post);

        if (query == "PREORDER") {
            printTraversal("[Preorder]", pre);
        } else if (query == "INORDER") {
            printTraversal("[Inorder]", in);
        } else if (query == "POSTORDER") {
            printTraversal("[Postorder]", post);
        } else if (query == "ALL") {
            printTraversal("[Preorder]", pre);
            printTraversal("[Inorder]", in);
            printTraversal("[Postorder]", post);
        }
    

    return 0;
}