/**************** QUESTION **************
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

*/


/*************** APPROACH *************
	Check max depth by traversing through the tree, adding one at each level.
	While traversring, keep track of maximum,  which is passed by reference. 
 */
	
/*************** SOLUTION *************/
void maxDepthUtil(TreeNode * A, int depth, int &maxDepth)
{
    if(A)
    {
    	//Add 1 when we traverse each level
        maxDepthUtil(A->left, depth+1, maxDepth);
        maxDepthUtil(A->right, depth+1, maxDepth);
        //Keep track of maximum depth every time
        if(depth > maxDepth)
            maxDepth = depth;
    }
}

int Solution::maxDepth(TreeNode* A) 
{
    int maxDepth = INT_MIN;
    maxDepthUtil(A, 1, maxDepth);
    return maxDepth;
}