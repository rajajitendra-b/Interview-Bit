/**************** QUESTION **************

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

*/


/*************** APPROACH *************
	Fill initial row as 1. 
	For all next rows, fill 1 at start and end. 
	All the elements in between will be the sum of the corresponding adjacent indices.
 */
	
/*************** SOLUTION *************/
vector<int> Solution::getRow(int A) 
{
    vector<int> prev, curr;
    if(A<0)
        return curr;
    //Fill the default first row.
    curr.push_back(1);
    for(int i = 1; i <= A; i++)
    {
        prev = curr;
        curr.clear();
    	//For each next row, fill 1 as first element.
        curr.push_back(1);
        for(int j = 1; j < prev.size(); j++)
        {
        	//Add the two adjacent previous row indices of the corresponding currentindex
            curr.push_back(prev[j-1] + prev[j]);
        }
        curr.push_back(1);
    }
    //When we hit the required row, we quit the loop and return the correspoding row.
    return curr;
}