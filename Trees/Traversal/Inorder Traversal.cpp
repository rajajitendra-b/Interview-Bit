/**************** QUESTION **************

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

*/


/*************** APPROACH *************
Like recursive approach, keep pushing current node to stack and move to left.
If no more lefts, take the top of stack and move right, if any, then continue from above step
 */
	
/*************** SOLUTION *************/
 vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    stack<TreeNode*> stk;
    vector<int> inorder;
    while(!stk.empty() || A)
    {
        while(A)
        {
            //Push current to the stack and move to left most element
            stk.push(A);
            A = A->left;
        }
        //Get the latest element to inorder and move to right, if any
        A = stk.top();
        stk.pop();
        inorder.push_back(A->val);
        A = A->right;
    }
    return inorder;
}