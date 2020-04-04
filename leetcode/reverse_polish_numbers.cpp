#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int l = tokens.size();

        string t;
        int a, b;
        vector<int> stack;
        for (int i=0; i<l; ++i){
            if (tokens[i] == "*"){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                stack.push_back(a*b);
            }
            else if (tokens[i] == "/"){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                stack.push_back(a/b);
            }
            else if (tokens[i] == "-"){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                stack.push_back(a-b);
            }
            else if (tokens[i] == "+"){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                stack.push_back(a+b);
            }
            else{
                stack.push_back(stoi(tokens[i]));
            }
        }
        if(stack.size()==1){
            return stack.back();
        }
        return -1;
    }
};
