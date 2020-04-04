#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

class Solution {
public:
    map<char, char> mapper{{'}', '{'}, {']', '['}, {')', '('}};
    bool isValid(string s) {
        if (s == ""){
            return true;
        }
        vector<char> stack;
        for(char ch : s){
            if (mapper[ch] && !stack.empty() && mapper[ch] == stack.back()){
                stack.pop_back();
            }
            else{
                stack.push_back(ch);
            }
        }
        return stack.empty();
    }
};
