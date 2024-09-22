#include <iostream>
using namespace std;
#include <vector>

// 作业1： 实现二叉树的前序、中序、后序遍历：非递归实现
// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前序遍历：根 -> 左 -> 右
void preOrder(TreeNode* root,vector<int> &v_1) 
{
    //待补充

    if (root == NULL) return; 
    v_1.push_back(root->val);
    preOrder(root->left,v_1);
    preOrder(root->right,v_1);

}

// 中序遍历：左 -> 根 -> 右
void inOrder(TreeNode* root) 
{
    //待补充
    vector<int> v_2;
    if (root == NULL) return; 
    inOrder(root->right);
    v_2.push_back(root->val);
    inOrder(root->left);
}

// 后序遍历：左 -> 右 -> 根
void postOrder(TreeNode* root) 
{
    //待补充
    vector<int> v_3;
    if (root == NULL) return; 
    postOrder(root->left);
    postOrder(root->right);
    v_3.push_back(root->val);
      
}
void print_vector(vector<int> v_1)
{
    for(int i =0;i<v_1.size();i++)
    {
        cout<<v_1[i]<<"  ";
    }
    cout<<endl;
}

// 把遍历的结果存到一个数组vector里面
int main() {
    // 创建一个简单的二叉树
    vector<int> V_1 = {};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right ->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    cout << "前序遍历: ";
    preOrder(root,V_1);
    cout << endl;
    print_vector(V_1);

    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;

    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;

    return 0;
}
