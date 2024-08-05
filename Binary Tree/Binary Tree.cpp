#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

#define PREORDER_TRAVERSAL 1
#define INORDER_TRAVERSAL 1
#define POSTORDER_TRAVERSAL 1
#define LEVELORDER_TRAVERSAL 1

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
} Node;

#if PREORDER_TRAVERSAL
/**
 * @brief       Get the preorder traversal sequence of the binary tree recursively.
 * 
 * @param cur   Pointer to the current node.
 * @param seq   Reference to a vector that stores the values of nodes visited during
 *              the preorder traversal. The function appends node values to this vector.
 */
void RecurPreTraversal(const Node* cur, vector<int>& seq)
{
    if (cur == nullptr) return;
    seq.push_back(cur->val);
    RecurPreTraversal(cur->left, seq);
    RecurPreTraversal(cur->right, seq);
}

/**
 * @brief       Get the preorder traversal sequence of the binary tree iteratively.
 * 
 * @param root  Pointer to the root node of the binary tree. If null, an empty
 *              vector is returned.
 * @return      A vector to store the values of nodes visited during the preorder
 *              traversal.
 */
vector<int> IteraPreTraversal(Node* root)
{
    if (root == nullptr) return vector<int>();
    stack<Node*> st;
    vector<int> res;
    st.push(root);
    while (!st.empty())
    {
        Node* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    return res;
}
#endif

#if INORDER_TRAVERSAL
/**
 * @brief       Get the preorder traversal sequence of the binary tree recursively.
 * 
 * @param cur   Pointer to the current node.
 * @param seq   Reference to a vector that stores the values of nodes visited during
 *              the inorder traversal. The function appends node values to this vector.
 */
void RecurInTraversal(const Node* cur, vector<int>& seq)
{
    if (cur == nullptr) return;
    RecurInTraversal(cur->left, seq);
    seq.push_back(cur->val);
    RecurInTraversal(cur->right, seq);
}

/**
 * @brief       Get the inorder traversal sequence of the binary tree iteratively.
 * @param root  Pointer to the root node of the binary tree. If null, an empty
 *              vector is returned.
 * @return      A vector to store the values of nodes visited during the inorder
 *              traversal.
 */
vector<int> IteraInTraversal(Node* root)
{
    if (root == nullptr) return vector<int>();
    Node* cur = root;
    stack<Node*> st;
    vector<int> res;
    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr) // Traversal the binary tree along the left child.
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }

    return res;
}
#endif

#if POSTORDER_TRAVERSAL
/**
 * @brief       Get the postorder traversal sequence of the binary tree recursively.
 * @param cur   Pointer to the current node.
 * @param seq   Reference to a vector that stores the values of nodes visited during
 *              the postorder traversal. The function appends node values to this vector.
 */
void RecurPostTraversal(const Node* cur, vector<int>& seq)
{
    if (cur == nullptr) return;
    RecurPostTraversal(cur->left, seq);
    RecurPostTraversal(cur->right, seq);
    seq.push_back(cur->val);
}

/**
 * @brief       Get the inorder traversal sequence of the binary tree iteratively.
 * @param root  Pointer to the root node of the binary tree. If null, an empty
 *              vector is returned.
 * @return      A vector to store the values of nodes visited during the postorder
 *              traversal.
 * @note        Change the stacking order of the left node and right nodes, we can get
 *              a sequence that is opposite of the preorder traversal.
 */
vector<int> IteraPostTraversal(Node* root)
{
    if (root == nullptr) return vector<int>();
    stack<Node*> st;
    vector<int> res;
    st.push(root);
    while (!st.empty())
    {
        Node* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(res.begin(), res.end());

    return res;
}
#endif

#if LEVELORDER_TRAVERSAL
/**
 * @brief       Recursive helper function for level order traversal. The function traverses
 *              the tree recursively and appends node values to an inner vector correspond
 *              to a certain level.
 * 
 * @param cur   Pointer to the current node.  
 * @param seq   A reference to a 2D vector where each inner vector represents the node 
 *              values at a particular depth in the tree. This vector is populated during
 *              the traversal.
 * @param depth The current depth in the tree. Start from 0 for the root node.
 */

void RecurLevelHelper(const TreeNode* cur, vector<vector<int>>& vvec, int depth)
{
    if (cur == nullptr) return;
    if (vvec.size() == depth) vvec.push_back(vector<int>());
    vvec[depth].push_back(cur->val);
    RecurLevelHelper(cur->left, vvec, depth + 1);
    RecurLevelHelper(cur->right, vvec, depth + 1);
}

/**
 * @brief       Get the level order traversal sequence of the binary tree recursively.
 * @param root  Pointer to the root node of the binary tree. If null, an empty
 *              vector is returned.
 * @param seq   A vector to store the values of nodes visited during the level order
 *              traversal. The function appends node values to this vector from
 *              the 2D vector seq filled by the function RecurLevelHelper().
 */
void RecurLevelTraversal(const TreeNode* root, vector<int>& seq)
{
    if (root == nullptr) return;
    vector<vector<int>> vvec;
    RecurLevelHelper(root, vvec, 0);
    for (const auto& v : vvec)
        for (const auto& i : v) seq.push_back(i);
}

/**
 * @brief       Get the levelorder traversal sequence of the binary tree iteratively.
 * @param root  Pointer to the root node of the binary tree. If null, an empty
 *              vector is returned.
 * @return      A vector to store the values of nodes visited during the level order
 *              traversal.
 */
vector<int> IteraLevelTraversal(Node* root)
{
    if (root == nullptr) return vector<int>();
    queue<Node*> qu;
    vector<int> res;
    qu.push(root);
    while (!qu.empty())
    {
        Node* node = qu.front();
        res.push_back(node->val);
        qu.pop();
        if (node->left) qu.push(node->left);
        if (node->right) qu.push(node->right);
    }

    return res;
}
#endif
