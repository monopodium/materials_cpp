#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前序遍历：根 -> 左 -> 右
void preOrder(TreeNode* root) {
//待补充
}

// 中序遍历：左 -> 根 -> 右
void inOrder(TreeNode* root) {
//待补充
}

// 后序遍历：左 -> 右 -> 根
void postOrder(TreeNode* root) {
    //待补充
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;

    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;

    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;

    return 0;
}
