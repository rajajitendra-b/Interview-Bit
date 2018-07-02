/**************** QUESTION **************

Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array
*/


/*************** APPROACH *************
	If we keep adding elements, whenever we find a sum which is already exisiting, 
		it means the elements between the same sum add up to zero.
	In other words, we insert cumulative sum to hash map. 
	If we already had the same cumulative sum, it means, we get the range from current element to past element.
	We then check the maximum length and get the answer;
 */
	
/*************** SOLUTION *************/

 vector<int> Solution::lszero(vector<int> &A) 
{
    map<int, int>hm;
    int sum = 0, start = 0, prevLength = INT_MIN;
    hm[0] = -1;
    for(int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        //Find if we already got the same cumulative sum. 
        auto it = hm.find(sum);
        if(it != hm.end())
        {
        	//If we find, then, check if the length is more than we we already got.
            if(i - it->second > prevLength)
            {
            	//If we got longer one, we store start and the corresponding length;
                start = it->second + 1;
                prevLength = i - it->second;
            }
        }
        else
        {
            hm[sum] = i;
        }
    }
    
    vector<int> answer;
    if(prevLength >= 0)
        answer.insert(answer.end(), A.begin()+start, A.begin()+start+prevLength);
    return answer;
}