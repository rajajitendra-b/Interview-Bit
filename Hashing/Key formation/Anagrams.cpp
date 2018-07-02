/**************** QUESTION **************

Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.

/*************** APPROACH *************
The expectation is to return the indexes of the string in groups of anagrams. 
Anagrams result in same string if they are sorted. 
So, if we maintain a hashmap with sorted string as key and their index as value, our job is done.

 */
	
/*************** SOLUTION *************/
vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    vector<vector<int> > answer;
    map<string, vector<int>>m;
    for(int i = 0; i < A.size(); i++)
    {
    	//Sort the string so that anagrams get the same string
        string str = A[i];
        sort(str.begin(), str.end());
        //Insert 1-based index as value for the sorted string. 
        m[str].push_back(i+1);
    }
    for(auto it = m.begin(); it != m.end(); ++it)
    {
    	//Push the 1-based index vector to the answer 
        answer.push_back(it->second);
    }
    return answer;
}