#include <iostream>
#include <stack>
using namespace std;
 
// Function to find the length of the longest balanced parenthesis in a string
int findMaxLen(string str)
{
    // create a stack of integers for storing an index of parenthesis in the string
    stack<int> stack;
 
    // initialize the stack by -1
    stack.push(-1);
 
    // stores the length of the longest balanced parenthesis
    int len = 0;
 
    // iterate over the characters of the string
    for (int i = 0; i < str.length(); i++)
    {
        // if the current character is an opening parenthesis,
        // push its index in the stack
        if (str[i] == '(') {
            stack.push(i);
        }
 
        // if the current character is a closing parenthesis
        else {
            // pop the top index from the stack
            stack.pop();
            
            // if the stack becomes empty, push the current index into the stack
            if (stack.empty())
            {
                stack.push(i);
            }
 
            // get length of the longest balanced parenthesis ending
            // at current character
            int curr_len = i - stack.top();
 
            // update the length of the longest balanced parenthesis
            if (len < curr_len) {
                len = curr_len;
            }
        }
    }
 
    return len;
}
 
int main()
{
    cout << findMaxLen("(((()") << endl;       // prints 4
    //cout << findMaxLen("(((()") << endl;        // prints 2
    //cout << findMaxLen("((((") << endl;         // prints 0
    //cout << findMaxLen("()()") << endl;         // prints 4
    //cout << findMaxLen("(()())(()");            // prints 6
 
    return 0;
}
//----------------------------------- 2nd approach --------------------------------------------------------
int findMaxLen(string s) {
        // code here
         int n = s.length();

        // Variables for left and right counter.
        // maxlength to store the maximum length found so far
        int left = 0, right = 0, maxlength = 0;

        // Iterating the string from left to right
        for (int i = 0; i < n; i++) {
            // If "(" is encountered,
            // then left counter is incremented
            // else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies
            // that the subsequence is valid and
            if (left == right) maxlength = max(maxlength, 2 * right);

            // Reseting the counters when the subsequence
            // becomes invalid
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        // Iterating the string from right to left
        for (int i = n - 1; i >= 0; i--) {

            // If "(" is encountered,
            // then left counter is incremented
            // else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies
            // that the subsequence is valid and
            if (left == right) maxlength = max(maxlength, 2 * left);

            // Reseting the counters when the subsequence
            // becomes invalid
            else if (left > right)
                left = right = 0;
        }
        return maxlength;
    }

