/**************** QUESTION **************
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]

Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.

*/


/*************** APPROACH *************

1) We can do a level order traversal along with map based vertical order tracking -- Correct and order as per expectatoin
2) Do an inorder traversal and push to the map, both depth and node value, with key being vertical level. 
	Later sort the pair(depth, tree node value) based on depth -- Correct, but order not as per the expectation.

 */
	
/*************** SOLUTION - 1 *************/

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) 
{
    map<int, vector<int>> mymap;
    queue<pair<int, TreeNode*>> q;
    vector<vector<int> > answer;
    if(!A)  
    return answer;
	//Do a level order traversal using a queue
    q.push(make_pair(0, A));
    while(!q.empty())
    {
        pair<int, TreeNode*> levelWiseNode = q.front();
        TreeNode * currentNode = levelWiseNode.second;
        q.pop();
        //Push each element to the hash map based on the vertical level
        mymap[levelWiseNode.first].push_back(currentNode->val);
        //Reduce the level when you move left, increase the level when you move right, to keep track of vertical order
        if(currentNode->left)
            q.push(make_pair(levelWiseNode.first-1, currentNode->left));
        if(currentNode->right)
            q.push(make_pair(levelWiseNode.first+1, currentNode->right));
    }
    //Once level order traversal is done, push each level from hashmap to the answer
    for(auto level : mymap)
    {
        answer.push_back(level.second);
    }
    return answer;
}

/*************** SOLUTION - 2 *************/
void verticalOrderTraversalUtil(int level, int depth, TreeNode * A, map<int, vector<pair<int, int>>> &hashMap)
{
    if(A)
    {
        //Insert all nodes to the corresponding vertical level of the hashmap
        hashMap[level].push_back(make_pair(depth, A->val));
        //Traverse the tree, every children is 1 depth more.
        verticalOrderTraversalUtil(level+1, depth+1, A->right, hashMap);
        verticalOrderTraversalUtil(level-1, depth+1, A->left, hashMap);
    }
    return;
}

vector<vector<int> > /*Solution::*/verticalOrderTraversal(TreeNode* A) 
{
    map<int, vector<pair<int, int>>> hashMap;
    vector<vector<int> > answer;
    verticalOrderTraversalUtil(0, 0, A, hashMap);
    for(auto unsortedLevel : hashMap)
    {
    	//Sort the unsorted level elements by depth (since it is a pair, it is sorted by first, i.e., depth)
        sort(unsortedLevel.second.begin(), unsortedLevel.second.end());
        vector<int> sortedLevel;
        //Push sorted values to the level
        for(auto nodeVal : unsortedLevel.second)
            sortedLevel.push_back(nodeVal.second);
        answer.push_back(sortedLevel);
    }
    return answer;
}