/*******************************************

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <map>


using namespace std;

string simplifyPath(string const& path) {
    vector<string> stack;
    assert(path[0] == '/');
    int i = 0;
    while(i < path.size()) {
        while(path[i] == '/' && i < path.size()) i++; // 连续的/跳过
        if(i == path.size()) break;
        int start = i; // start 记录每个element的起始位置
        while(path[i] != '/' && i < path.size()) i++; // 两个/ element / 之间的string
        int end = i - 1; // end 记录每个element的末尾位置
        string element = path.substr(start, end + 1 - start);
        if(element == "..") { // 如果是..就弹出一个element
            if(stack.size() > 0)
                stack.pop_back();
        } else if(element != ".") { // 如果不是.和.. 就压入element（目录名）到stack
            stack.push_back(element);
        }
    }

    if(stack.size() == 0) return "/";
    string simpPath;
    for(int i = 0; i < stack.size(); i++) {
        simpPath += "/" + stack[i];
    }

    return simpPath;
}

int main()
{

    string path1 = "/a/./b/../../c/";
    string result = simplifyPath(path1);
    cout << result << endl;

    return 0;
}

