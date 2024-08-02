/**
 *  @brief  Evaluate a postfix expression(Reverse Polish Notation Expression, RPN).
 *  @param  strings
 *  @return The value of the postfix expression.
 *  
 *  All the operators and operands are string objects and stored in the 
 *  vector opstrings. So we need to convert the string to an integer first.
 *  You can also choose stoll() instead.
 */
int evalRPN(vector<string>& opstrings)
{
    stack<long long> st;  // The st store the operands.
    for (const auto& s : opstrings)
    {   
        // The size of s is greater than 1 or the first character is
        // between '0' and '9' means that the s represent an integer.
        if (s.size() > 1 || ('0' <= s[0] && s[0] <= '9'))
        {
            long long num = 0;  // Use long long in case of overflow.
            int i = (s[0] == '-') ? 1 : 0;  // The i need to skip the '-'.
            for (; i < s.size(); ++i)
                num = num * 10  + s[i] - '0';
            st.push((s[0] == '-') ? -1 * num : num);
        }
        else
        {
            long long num1 = st.top();    // Get the right operand.
            st.pop();
            long long num2 = st.top();    // Get the left operand.
            st.pop();
            if (s == "+") st.push(num2 + num1);
            else if (s == "-") st.push(num2 - num1);
            else if (s == "*") st.push(num2 * num1);
            else st.push(num2 / num1);
        }
    }

    return st.top();
}
