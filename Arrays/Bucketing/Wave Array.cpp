/**************** QUESTION **************

Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
  NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 
So, in example case, you will return [2, 1, 4, 3] 


*/

/*************** APPROACH *************
	Sort the array for easier rearrangement. 
	Keep swapping the current element with the next element to obtain the wave fashion
 */
	
/*************** SOLUTION *************/

vector<int> Solution::wave(vector<int> &A) 
{
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i+=2)
    {
    	//To make the array like a wave
        if(i+1<A.size())
        {
            swap(A[i], A[i+1]);
        }
    }
    return A;
}