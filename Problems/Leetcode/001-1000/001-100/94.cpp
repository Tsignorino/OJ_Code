#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

//* 中序遍历
class Solution {
public:
    vector<int> inorderTraversal_0(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }

            dfs(node->left);
            // if (node->left != nullptr) {
            //     dfs(node->left);
            // }

            ans.emplace_back(node->val);

            dfs(node->right);
            // if (node->right != nullptr) {
            //     dfs(node->right);
            // }
        };

        dfs(root);

        return ans;
    }

public:
    vector<int> inorderTraversal_1(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;

        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            ans.emplace_back(root->val);

            root = root->right;
        }

        return ans;
    }

public:
    /**
        Morris:
            >> x 无左孩子：
                记录 x，
                访问右孩子

            >> x 有左孩子
                找到 pre
                    （左子树上最右的节点、左子树遍历的最后一个节点、中序遍历 x 的前驱节点）
                    （PS：pre 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止）

                > pre 无右孩子：
                    将右孩子指向 x
                    然后访问 x 的左孩子
                > pre 有右孩子（此时右孩子已经指向 x，表明已经遍历完左子树）
                    将 pre 的右孩子置空
                    记录 x
                    访问右孩子
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* pre = nullptr;

        while (root) {
            if (root->left) {
                pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) { // 让 predecessor 的右指针指向 root，继续遍历左子树
                    pre->right = root;
                    root = root->left;
                } else { // 说明左子树已经访问完了，我们需要断开链接
                    ans.emplace_back(root->val);

                    pre->right = nullptr;
                    root = root->right;
                }
            } else { // 如果没有左孩子，则直接访问右孩子
                ans.emplace_back(root->val);

                root = root->right;
            }
        }

        return ans;
    }
};