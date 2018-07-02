/**************** QUESTION **************

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

*/


/*************** APPROACH *************
Do a tree traversal. pushing the elements to current path while traversing.
In case you find a leaf, check if the current path makes up to sum given.
	If so, add it to our answer
After the current path, backtrack.
 */
	
/*************** SOLUTION *************/
void pathSumUtil(TreeNode * A, int sumLeft, vector<int> & curr, vector<vector<int>> & answer)
{
    if(A)
    {
        curr.push_back(A->val); // On all valid elements, push the element to current path
        //If any of the children exist, go through that path
        if(A->left)
        {
            pathSumUtil(A->left, sumLeft - A->val, curr, answer);
			curr.pop_back();//Backtrack
        }
        if(A->right)
        {
            pathSumUtil(A->right, sumLeft - A->val, curr, answer);
			curr.pop_back();//Backtrack
        }
        // If this element is the leaf, check if sum left is this element 
        // In other words, will this path makes up to sum? If so, push this path to our answer
        if(!A->left && !A->right && sumLeft == A->val)
            answer.push_back(curr);
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
	//Curr for one path, answer to track all paths with given sum
    vector<int>curr;
    vector<vector<int>>answer;
    pathSumUtil(A, B, curr, answer);
    return answer;
}