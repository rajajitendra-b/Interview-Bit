/**************** QUESTION **************

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/


/*************** APPROACH *************

	Fill initial row as 1. 
	For all next rows, fill 1 at start and end. 
	All the elements in between will be the sum of the corresponding adjacent indices.
 */
	
/*************** SOLUTION *************/

vector<vector<int> > Solution::generate(int A) 
{
    vector<vector<int>> answer;
    vector<int> curr, prev;
    if(A<1)
        return answer;
    //Fill the default first row.
    curr.push_back(1);
    answer.push_back(curr);
    for(int i = 1; i < A; i++)
    {
        prev = curr;
        curr.clear();
    	//For each next row, fill 1 as first element.
        curr.push_back(1);
        for(int j = 1; j < prev.size(); j++)
        {
        	//Add the two adjacent previous row indices of the corresponding currentindex
            curr.push_back(prev[j] + prev[j-1]);
        }
        curr.push_back(1);
        //Push the obtained row to answer for this row
        answer.push_back(curr);
    }
    return answer;
}