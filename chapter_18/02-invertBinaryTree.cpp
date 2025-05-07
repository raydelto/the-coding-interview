#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void invert(TreeNode* node) {
  if (node != nullptr) {
    swap(node->left, node->right);
    invert(node->left);
    invert(node->right);
  }
}

// Helper function to compute the maximum depth of the tree
int maxDepth(TreeNode* root) {
  if (!root)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Helper function to fill the tree into a 2D grid
void fill(TreeNode* node,
          vector<string>& res,
          int row,
          int col,
          int depth,
          int offset) {
  if (!node)
    return;
  ostringstream ss;
  ss << node->value;
  string val = ss.str();

  int pos = col;
  for (size_t i = 0; i < val.size(); ++i) {
    if (pos + i < res[row].size()) {
      res[row][pos + i] = val[i];
    }
  }

  if (node->left)
    res[row + 1][col - offset] = '/';
  if (node->right)
    res[row + 1][col + offset] = '\\';

  fill(node->left, res, row + 2, col - offset * 2, depth, offset / 2);
  fill(node->right, res, row + 2, col + offset * 2, depth, offset / 2);
}

void print(TreeNode* root) {
  if (!root)
    return;

  int depth = maxDepth(root);
  int width = (1 << depth) * 2;
  int height = depth * 2 - 1;

  vector<string> res(height, string(width, ' '));
  fill(root, res, 0, width / 2, depth, width / 8);

  for (const string& line : res) {
    cout << line << '\n';
  }
}

int main() {
  /*
    Test case:
  Original Tree (Before Inversion):        Inverted Tree (After Inversion):

          1                                        1
        /   \                                    /   \
       2     5                                  5     2
      / \   / \                                / \   / \
     3   4 6   7                              7   6 4   3
    */

  vector<TreeNode> nodes;
  for (int i = 1; i <= 7; i++) {
    nodes.emplace_back(TreeNode(i));
  }

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[4];

  nodes[1].left = &nodes[2];
  nodes[1].right = &nodes[3];

  nodes[4].left = &nodes[5];
  nodes[4].right = &nodes[6];

  cout << "Original Tree:\n";
  print(&nodes[0]);
  invert(&nodes[0]);
  cout << "\nInverted Tree:\n";
  print(&nodes[0]);

  return 0;
}
