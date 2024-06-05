#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constuctor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder (TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder (TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder (TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode*zero = new TNode(0);
    TNode*one = new TNode(1);
    TNode*five = new TNode(5);
    TNode*seven = new TNode(7);
    TNode*eight = new TNode(8);
    TNode*nine = new TNode(9);

    seven->left = one;

    seven->right = nine;

    one->left = zero;

    one->right = five;

    nine->left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
