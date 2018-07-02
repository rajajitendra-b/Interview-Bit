/**************** QUESTION **************

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

*/


/*************** APPROACH *************
Insert the element one by one to hasmap. 
While inserting, we will check if we already got an element that sums with current one to get target. 
	In other words, check if target - current is already in the hash.
	If so, check for the given conditions and mark the answer
 */
	
/*************** SOLUTION *************/

vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    int start = INT_MAX, end = INT_MAX;
    map<int, int> hm;
    for(int i = 0; i < A.size(); i++)
    {
        auto it = hm.find(B-A[i]);
        if(it != hm.end())
        {
        	/* If multiple solutions exist, output the one where index2 is minimum.
        	 * If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.
        	 */
            if((end > i) || (end == i && start > it->second))
            {
                start = it->second;
                end = i;
            }
        }
        else
        {
            hm.insert(make_pair(A[i], i));
        }
    }
    vector<int> answer;
    //Append answer only when we have filled end (Note that, if no pair exists, return empty list.)
    if(end < A.size())
    {
    	//+1 as we have the condition "Please note that your returned answers are not zero-based. "
        answer.push_back(start+1);
        answer.push_back(end+1);
    }
    return answer;
}