#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

//* 后序遍历
class PostorderTraversal {
public:
    vector<int> postorderTraversal_0(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }

            dfs(node->left);
            dfs(node->right);
            ans.emplace_back(node->val);
        };

        dfs(root);

        return ans;
    }

public:
    vector<int> postorderTraversal_1(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;

        TreeNode* pre = nullptr;
        while (!stk.empty() || root) {
            // 找到最左边的节点
            while (root) {
                stk.emplace(root);
                root = root->left;
            }

            // 进行回退
            root = stk.top();

            if (root->right == nullptr || root->right == pre) { // 当前节点没有右孩子或者右孩子已经访问过了
                stk.pop();
                ans.emplace_back(root->val);

                pre = root; // 记录 root 历史访问
                root = nullptr; // 便于回退
            } else {
                root = root->right;
            }
        }

        return ans;
    }

    /**
        Morris:
            >> x 无左孩子：
                访问 x 的右孩子

            >> x 有左孩子
                找到 pre
                    （左子树上最右的节点、左子树遍历的最后一个节点、中序遍历 x 的前驱节点）
                    （PS：pre 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止）

                > pre 无右孩子：
                    将右孩子指向 x
                    访问 x 的左孩子

                > pre 有右孩子（此时右孩子已经指向 x，表明已经遍历完左子树）
                    将 pre 的右孩子置空

    //              * 记录（倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点）

                    访问 x 的右孩子
    */
    vector<int> postorderTraversal_2(TreeNode* root) {
        vector<int> ans;
        TreeNode* pre = nullptr;
        TreeNode* node = root;

        function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
            int cnt = 0;
            while (node) {
                cnt++;
                ans.emplace_back(node->val);
                node = node->right;
            }
            reverse(ans.end() - cnt, ans.end());
        };

        while (node) {
            if (node->left) {
                pre = node->left;
                while (pre->right && pre->right != node) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    pre->right = node;
                    node = node->left;
                    continue;
                } else {
                    pre->right = nullptr;
                    f(node->left);
                }
            }
            node = node->right;
        }

        f(root);

        return ans;
    }
};