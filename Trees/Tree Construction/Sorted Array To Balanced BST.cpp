/**************** QUESTION **************

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


*/


/*************** APPROACH *************
	As it is a sorted array, left and right elements are more or less equal when we choose middle element as root
	If we consider the same principle recursively, 
		we can construct a tree which is balanced by using binary allocation to tree.
 */
	
/*************** SOLUTION *************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode * sortedArrayToBSTUtil(const vector<int> &A, int start, int end)
{
    int mid = start + (end - start)/2;
    if(start <= end)
    {
        //Always, mid element is the current root of the subtree
        TreeNode * bst = new TreeNode(A[mid]);
        //Assign left half to left subtree and right half to right subtree
        bst->left = sortedArrayToBSTUtil(A, start, mid-1);
        bst->right = sortedArrayToBSTUtil(A, mid+1, end);
        return bst;
    }
    return NULL;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    return sortedArrayToBSTUtil(A, 0, A.size()-1);
}
