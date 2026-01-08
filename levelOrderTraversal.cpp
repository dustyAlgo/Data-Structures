#include <iostream>
#include <queue>
using namespace std;

// Tree Node definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Level Order Traversal (Each level in new line)
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();   // number of nodes at current level

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;   // new line after each level
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order Traversal (Each level in new line):\n";
    levelOrderTraversal(root);

    return 0;
}
