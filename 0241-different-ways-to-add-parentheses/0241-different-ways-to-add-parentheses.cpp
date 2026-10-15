
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> L = diffWaysToCompute(left);
                vector<int> R = diffWaysToCompute(right);

                for (int a : L) {
                    for (int b : R) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, expression is a number.
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};
