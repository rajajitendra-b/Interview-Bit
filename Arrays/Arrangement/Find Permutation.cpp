/****************,QUESTION,**************

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

/***************,APPROACH,*************

If we take extreme cases, there can be all increments or all decrements. 
In case of all increments, we fill 1 to N
In case of all decrements, we fill N to 1
It means, if we count number of one value (say decrement), 
	we can keep filling the next value as the next value, either increment or decrement. 

,*/
	
/***************,SOLUTION,*************/
vector<int> Solution::findPerm(const string A, int B) 
{
    int dec = 1, i = 0;
    vector<int> answer(B, 0);
    //Count the number of decrements
    for(auto a : A)
        if(a == 'D')
            dec++;
    //Have 2 pointers, inc and dec
    int inc = dec;
    //Initialize 1st element with number of decrements
    answer[i++] = dec--;
    //For every element in string, based on increment/decrement, 
        //fill the corresponding next value
    for(auto a : A)
    {
        if(a == 'D')
            answer[i++] = dec--;
        else
            answer[i++] = ++inc;
    }
    return answer;
}