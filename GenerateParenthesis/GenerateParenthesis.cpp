/*******************************************
void combinationPar(vector<string> &result, string &sub, int leftNum, int rightNum) {
    if(!rightNum) result.push_back(sub);
    else {
        if(leftNum) {
            sub.push_back('(');
            combinationPar(result, sub, leftNum - 1, rightNum);
            sub.pop_back();
        }
        if(leftNum < rightNum) {
            sub.push_back(')');
            combinationPar(result, sub, leftNum, rightNum - 1);
            sub.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string sub;
    combinationPar(result, sub, n, n);
    return result;
}

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;



/*
    leftNum and rightNum refer to the number of remianing p
*/
void combinationPar(vector<string> &result, string &sub, int leftNum, int rightNum) {
    if(!rightNum) result.push_back(sub);
    else {
        if(leftNum) {
            sub.push_back('(');
            combinationPar(result, sub, leftNum - 1, rightNum);
            sub.pop_back();
        }
        if(leftNum < rightNum) {
            sub.push_back(')');
            combinationPar(result, sub, leftNum, rightNum - 1);
            sub.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string sub;
    combinationPar(result, sub, n, n);
    return result;
}



int main()
{
    vector<string> result = generateParenthesis(4);

        for(string x : result)  cout << x << endl;
        cout << endl;

    return 0;
}

