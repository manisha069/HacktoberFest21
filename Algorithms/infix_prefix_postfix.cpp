#include <iostream>
#include <string.h>
#include <math.h> //for using the pow function for '^'
#include <stack>
#include <algorithm>
using namespace std;

#define BLANK ' ' //whitespace in a string
#define TAB '\t'  //tab gap in a string
#define MAX 50    //maximum 50 characters in a string
char inf[MAX], post[MAX];
long int st[MAX];
int top;
int whitespace(char c) //checks for whitespaces in the string
{
    if (c == BLANK || c == TAB)
        return 1;
    else
        return 0;
}
int isEmpty() //checks if the stack is empty or not
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(long int x) //pushes element in the stack
{
    if (top > MAX)
    {
        cout << "Stack Overflow" << endl;
        exit(1);
    }
    st[++top] = x;
}
long int pop() //pops out element from the stack
{
    if (isEmpty())
    {
        cout << "Stack Undeflow" << endl;
        exit(1);
    }
    return (st[top--]);
}
int priority(char c) //checks the priority of various operators and return respective values
{
    switch (c)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
void convert() //pushes brackets and operands to the stack and pop them out when required
{
    unsigned int j, a = 0;
    char cp;
    char c;
    for (j = 0; j < strlen(inf); j++)
    {
        c = inf[j];
        if (!whitespace(c)) //checks for whitespace and if no whitespace is there, then enters the condition
        {
            switch (c)
            {
            case '(':
                push(c);
                break;
            case ')':
                while ((cp = pop()) != '(')
                    post[a++] = cp;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isEmpty() && priority(st[top]) >= priority(c)) //checks the priority and then pops out from the stack
                    post[a++] = pop();
                push(c);
                break;
            default: //this is the condition when an operand is enocuntered
                post[a++] = c;
            }
        }
    }
    while (!isEmpty())
        post[a++] = pop();
    post[a] = '\0'; //string creation
}
long int evaluate()
{
    long int x, y, temp, eval;
    unsigned int k;
    for (k = 0; k < strlen(post); k++)
    {
        if (post[k] <= '9' && post[k] >= '0')
            push(post[k] - '0');
        else
            x = pop();
        y = pop();
        switch (post[k])
        {
        case '+': //performing various operations depending on the operators
            temp = x + y;
            break;
        case '-':
            temp = x - y;
            break;
        case '*':
            temp = x * y;
            break;
        case '/':
            temp = x / y;
            break;
        case '%':
            temp = x % y;
            break;
        case '^':
            temp = pow(x, y);
        }
        push(temp); //at last, pushing the final result to the stack
    }
eval = pop(); //popping the result
return eval;  //returning the result
}
int op(char oper) //function that checks for operators in prefix expression
{
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int preced(char ch) //checks precedence of the operators in prefix expression
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
string convert2(stack<char> str, string inn) //converts infix to prefix
{
    string pre;
    reverse(inn.begin(), inn.end());
    for (int i = 0; i < inn.length(); i++)
    {
        if (inn[i] == '(')
        {
            inn[i] = ')';
        }
        else if (inn[i] == ')')
        {
            inn[i] = '(';
        }
    }
    for (
        int i =
            0;
        i <
        inn.length();
        i++)
    {
        if ((inn[i] >= 'a' && inn[i] <= 'z') || (inn[i] >= 'A' && inn[i] <= 'Z')) //ASCII Range
        {
            pre += inn[i];
        }
        else if (inn[i] == '(')
        {
            str.push(inn[i]);
        }
        else if (inn[i] == ')')
        {
            while ((str.top() != '(') && (!str.empty()))
            {
                pre += str.top();
                str.pop();
            }
            if (str.top() == '(')
            {
                str.pop();
            }
        }
        else if (op(inn[i]) == 1)
        {
            if (str.empty())
            {
                str.push(inn[i]);
            }
            else
            {
                if (preced(inn[i]) > preced(str.top()))
                {
                    str.push(inn[i]);
                }
                else if ((preced(inn[i]) == preced(str.top())) && (inn[i] == '^')) //checking the precedence of the special case of '^'
                {
                    while ((preced(inn[i]) == preced(str.top())) && (inn[i] == '^'))
                    {
                        pre += str.top();
                        str.pop();
                    }
                    str.push(inn[i]);
                }
                else if (preced(inn[i]) == preced(str.top()))
                {
                    str.push(inn[i]);
                }
                else
                {
                    while ((!str.empty()) && (preced(inn[i]) < preced(str.top())))
                    {
                        pre += str.top();
                        str.pop();
                    }
                    str.push(inn[i]);
                }
            }
        }
    }
    while (!str.empty()) //checks if the stack is empty or not
    {
        pre += str.top();
        str.pop();
    }
    reverse(pre.begin(), pre.end());
    return pre;
}
//Main Function
int main()
{
    int c;
    int cont;
    string inf2, pref;
    do
    {
        cout << "1. Postfix Conversion" << endl; //Menu Options
        cout << "2. Prefix Conversion" << endl;
        cout << "Enter the option" << endl;
        cin >> c; //User Choice
        switch (c)
        {
        case 1:
            cout << "Enter the Expression: " << endl; //takes the infix expression
            cin >> inf;
            convert(); //converts infix to postfix
            cout << endl
                 << "Postfix: " << endl
                 << post << endl;
            break;
        case 2:
            cout << "Enter the Expression :" << endl;
            cin >> inf2; //takes the infix expression
            stack<char> stack;
            pref = convert2(stack, inf2); //converts infix to prefix
            cout << endl
                 << "Prefix: " << endl
                 << pref << endl;
            break;
        }
    } while (1); //infinite loop
}