/*******************************************

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_map>




using namespace std;


vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    if(words.size() == 0) return result;
    int i = 0;
    while(i < words.size()) {
        int start = i;
        int sum = 0;
        while(i < words.size() && sum + words[i].size() <= L) {
            sum += words[i].size() + 1;
            i++;
        }
        int end = i - 1;
        int intervalCount = end - start;
        int average = 0, remain = 0;
        if(intervalCount > 0) {
            average = (L - sum + intervalCount + 1) / intervalCount;
            remain = (L - sum + intervalCount + 1) % intervalCount;
        }
        string line;
        for(int j = start; j < end; ++j) {
            line += words[j];
            if(i == words.size()) line.append(1, ' ');
            else {
                line.append(average, ' ');
                if(remain > 0) {
                    line.append(1, ' ');
                    remain--;
                }
            }
        }
        line += words[end];
        if(line.size() < L) line.append(L - line.size(), ' ');
        result.push_back(line);
    }

    return result;
}


int main()
{
    vector<string>  words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result;
    result = fullJustify(words, 16);
    for(string i : result) cout << i << endl;


    return 0;
}

