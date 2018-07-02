/**************** QUESTION **************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

*/


/*************** APPROACH *************

If we observe carefully, the next character index is a fixed number increment of either top or bottom count.
On further observation, we observe a pattern always. a difference of two per each row.
For the input as below string
RAJAJITENDRAISAGOODBOY
5
                                                     Next indexes
 * 5 Strings in order  *  indexexes of characters *  Top, Bottom
R.......N.......O.....    0  8 16                      8, 0
.A.....E.D.....G.O....    1  7  9 15 17                6, 2
..J...T...R...A...D...    2  6 10 14 18                4, 4
...A.I.....A.S.....B.Y    3  5 11 13 19 21             2, 6
....J.......I.......O.    4 12 20                      0, 8
 */
	
/*************** SOLUTION *************/

string Solution::convert(string A, int B) 
{
    string answer;
    //Base case
    if(B<2 || A.length()<2)
        return A;
    //Extra space is added at the end of the string, even though we are not adding in input
    if(A[A.length()-1] == 13)
        A.pop_back();//Removing the extra space (ASCII 13)
    int nextViaBottom = 2*(B-1), nextViaTop = 0;
    for(int i = 0; i < B; i++)
    {
        int index = i;
        bool flipDirection = false;
        while(index < A.length())
        {
            answer += A[index];
            //Extreme cases --> Top most or bottom most, where only one direction is possible
            if(!nextViaBottom || !nextViaTop)
                index += nextViaBottom + nextViaTop;
            else
            {
            	//Change direction every 2nd time and add to answer;
                if(flipDirection)
                {
                    index += nextViaTop;
                    flipDirection = false;
                }
                else
                {
                    index += nextViaBottom;
                    flipDirection = true;
                }
            }
        }
        //When row changes, the next index changes as below
        nextViaBottom -=2;
        nextViaTop += 2;
    }
    return answer;
}