#include <bits/stdc++.h>

int char_to_priority(char targetChar)
{
    /// [ operand ] < [ ( ] < [ ) ] < [ - ] = [ + ] < [ / ] = [ * ]
    switch (targetChar)
    {
    case '*':
        return 4;
    case '/':
        return 4;
    case '+':
        return 3;
    case '-':
        return 3;
    case ')':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}

void pop_stack_until_priority(char postfix[], std::stack <char> & operators, int & outIndex, int priority)
{
    int topPriority;  char topChar;
    while (!operators.empty())
    {
        /// obtain the top-most operator on stack
        topChar = operators.top();
        /// obtain that operator's precedence level
        topPriority = char_to_priority(topChar);
        if (priority <= topPriority)
        {
            /// remove operator with greater-equal precedence
            operators.pop();
            /// write that operator to output
            postfix[outIndex++] = topChar;
        }
        else
        {
            return;
        }
    }
}

void infix_to_postfix(char postfix[], char infix[], int length)
{
    std::stack <char> operators;
    int priority, index, outIndex = 0;
    for (index = 0; index < length; ++index)
    {
        priority = char_to_priority(infix[index]);
        if (priority == 0)
        {
            /// for operands, simply write to output
            postfix[outIndex++] = infix[index];
        }
        else if (infix[index] == '(')
        {
            /// for opening braces, simply push to stack
            operators.push(infix[index]);
        }
        else if (infix[index] == ')')
        {
            /// for closing braces, pop out all operators after an opening brace from the stack
            /// and write them to the output accordingly
            pop_stack_until_priority(postfix, operators, outIndex, priority);
            /// remove the opening brace from stack
            operators.pop();
        }
        else
        {
            /// for operators, pop out all operators with greater-equal (>=) precedence compared to the latest one
            /// and write them to the output accordingly
            pop_stack_until_priority(postfix, operators, outIndex, priority);
            /// add the latest operators onto stack
            operators.push(infix[index]);
        }
    }
    /// pop out remaining operators from stack
    pop_stack_until_priority(postfix, operators, outIndex, -10);
}

int main()
{
    char infix[] = "A+B*C-D/E";
    int length = strlen(infix);
    char postfix[20] = {  '\0'  };
    infix_to_postfix(postfix, infix, length);
    printf("%s", postfix);

    return 0;
}
