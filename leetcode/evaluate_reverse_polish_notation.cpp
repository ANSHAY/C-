/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

*/
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
