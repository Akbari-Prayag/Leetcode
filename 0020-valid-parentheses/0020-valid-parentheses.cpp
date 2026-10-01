class Solution {
public:
    
    bool isValid(string s) {
        string stack;

        for (char current_char : s) {
            if (current_char == '(' || current_char == '{' || current_char == '[') {
                stack.push_back(current_char);
            }
            else if (stack.empty() || !isMatchingPair(stack.back(), current_char)) {
                return false;
            }
            else {
                stack.pop_back();
            }
        }

        return stack.empty();
    }

private:
    
    
    bool isMatchingPair(char left_bracket, char right_bracket) {
        return (left_bracket == '(' && right_bracket == ')') ||
               (left_bracket == '[' && right_bracket == ']') ||
               (left_bracket == '{' && right_bracket == '}');
    }
};
