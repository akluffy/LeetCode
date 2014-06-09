/*******************************************

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <climits>


using namespace std;





void helper(string s, int start, int section, string solution, vector<string> &result) {
    if(s.size() - start > (4-section) * 3) return;
    if(s.size() < 4 - section) return;
    if(start == s.size() && section == 4) {
        solution.resize(solution.size() - 1);// remove last '.'
        result.push_back(solution);
        return;
    }

    int digit = 0;
    for(int i = start; i < start + 3 && i < s.size(); i++) {
        digit = digit * 10 + (s[i] - '0');
        if(i > 5) cout << i << "   " << s[i] << endl;
        if(digit <= 255) {
            solution += s[i];
            helper(s, i + 1, section + 1, solution + '.', result);
        }
        if(digit == 0) {break;}
    }

}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string solution;
    helper(s, 0, 0, solution, result);
    return result;
}


int main()
{
    string s1 = "123456";
    vector<string> vs = restoreIpAddresses(s1);
    for(string &x : vs) cout << x << endl;


    return 0;
}

