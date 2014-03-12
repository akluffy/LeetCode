/*******************************************

Given a string, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty?
This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

**********************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isan(char c) {
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool issame(char a, char b) {
    if(a >= '0' && a <= '9') return a == b;
    if(a >= 'a' && a <= 'z') return a == b || (a == b + 'a' - 'A');
    if(a >= 'A' && a <= 'Z') return a == b || (a == b + 'A' - 'a');
}

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i <= j) {
            while(i <= j && !isan(s[i])) i++;
            while(i <= j && !isan(s[j])) j--;
            if(i <= j && !issame(s[i], s[j])) return false;
            i++;
            j--;
        }

        return true;
    }
};



int main()
{
    string a = "A man, a plan, a canal: Panama";
    string b = "race a car";

    Solution s;
    cout << s.isPalindrome(a);
    cout << endl;
    cout << s.isPalindrome(b);

    return 0;
}

