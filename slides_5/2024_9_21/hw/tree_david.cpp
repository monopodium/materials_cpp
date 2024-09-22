#include <iostream>
#include<vector>
using namespace std;


// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前序遍历：根 -> 左 -> 右
void preOrder(TreeNode* root,vector<int> &result) 
{
    //待补充
    
    if (root == NULL) return; 

    result.push_back(root->val);
    preOrder(root->left,result);
    preOrder(root->right,result);

}

// 中序遍历：左 -> 根 -> 右
void inOrder(TreeNode* root) 
{
    //待补充
    if (root == NULL) return; 
    inOrder(root->left);
    cout<<root->val<<"   ";
    inOrder(root->right);
}

// 后序遍历：左 -> 右 -> 根
void postOrder(TreeNode* root) 
{
    //待补充
    if (root == NULL) return; 
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<"    ";    
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int>result;
    preOrder(root,result);

    for (int val:result){
        cout<<val<<"";
    }
    cout<<endl;

    return 0;
}
