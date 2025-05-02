#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
  if (root == nullptr)
    return;
  // Visit the current node
  cout << root->value << " ";

  // Traverse left subtree
  preOrderTraversal(root->left);

  // Traverse right subtree
  preOrderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
  if (root == nullptr)
    return;

  inorderTraversal(root->left);
  cout << root->value << " ";
  inorderTraversal(root->right);
}

void postOrder(TreeNode* root) {
  if (root == nullptr)
    return;

  // Traverse left subtree
  postOrder(root->left);

  // Traverse right subtree
  postOrder(root->right);

  // Visit the current node
  cout << root->value << " ";
}

void levelOrder(TreeNode* root) {
  if (root == nullptr)
    return;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();

    cout << current->value << " ";

    if (current->left)
      q.push(current->left);
    if (current->right)
      q.push(current->right);
  }
}

bool search(TreeNode* root, int key) {
  if (root == nullptr)
    return false;
  if (key == root->value)
    return true;
  if (key < root->value)
    return search(root->left, key);
  else
    return search(root->right, key);
}

int main() {
/*/
Example Tree Structure;
    4
  /   \
 2     6
/ \   / \
1   3 5   7
*/

  // Create a simple binary tree
  TreeNode one(1);
  TreeNode two(2);
  TreeNode three(3);
  TreeNode four(4);
  TreeNode five(5);
  TreeNode six(6);
  TreeNode seven(7);

  four.left = &two;
  four.right = &six;
  
  two.left = &one;
  two.right = &three;
  
  six.left = &five;
  six.right = &seven;

  TreeNode* root = &four;

  cout << "Pre-order traversal: ";
  preOrderTraversal(root);
  cout << endl;

  cout << "In-order traversal: ";
  inorderTraversal(root);
  cout << endl;

  cout << "Post-order traversal: ";
  postOrder(root);
  cout << endl;

  cout << "Level-order traversal: ";
  levelOrder(root);
  cout << endl;

  int key = 6;
  if (search(root, key)) {
    cout << "Key " << key << " found in the tree." << endl;
  } else {
    cout << "Key " << key << " not found in the tree." << endl;
  }

  return 0;
}
