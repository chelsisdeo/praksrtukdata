#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


void tambahChild(TreeNode* parent, string childData) {
    if (parent->left == NULL)
        parent->left = new TreeNode(childData);
    else if (parent->right == NULL)
        parent->right = new TreeNode(childData);
    else
        cout << "Node ini sudah memiliki dua child." << endl;
}

void tampilkanDescendant(TreeNode* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";
    tampilkanDescendant(node->left);
    tampilkanDescendant(node->right);
}

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    
    string rootData;
    cout << "Masukkan data simpul root: ";
    cin >> rootData;
    TreeNode* root = new TreeNode(rootData);
    
    
    for (int i = 0; i < jumlahSimpul - 1; ++i) {
        string parentData, childData;
        cout << "Masukkan data simpul parent: ";
        cin >> parentData;
        cout << "Masukkan data simpul child: ";
        cin >> childData;

        
        TreeNode* parent = NULL;
        
        tambahChild(parent, childData);
    }

    
    cout << "Descendant dari setiap simpul:" << endl;
    

    return 0;
}
