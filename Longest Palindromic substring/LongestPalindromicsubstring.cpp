/*******************************************

Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    string str1;
    vector<int> p(s.length() * 2 + 1, 0);
    int pivot = 0, cover = 0, maxLength = 0, id = 0;
    str1.push_back('#');
    for(int i = 0; i < s.length(); i++) {
        str1.push_back(s[i]);
        str1.push_back('#');
    }

    for(int i = 0; i < str1.length(); i++) {
        if(i > pivot && i < cover) {
            p[i] = min(cover - i, p[2 * pivot - i]);
        }
        while(i - p[i] >= 0 && i + p[i] < str1.length()
              && str1[i-p[i]] == str1[i+p[i]]) p[i]++;
        p[i]--;
        if(i + p[i] > cover) cover = i + p[i], pivot = i;
        if(p[i] > maxLength) maxLength = p[i], id = i;
    }

    //for(int i = 0; i < str1.length(); i++) cout << p[i] << endl;
    //cout << pivot << " and " << id << endl;
    return s.substr((id - maxLength) / 2, maxLength);
}


int main()
{
    string s1 = "ccd";
    string s2 = "cd";

    cout << longestPalindrome(s1) << endl;



    return 0;
}

