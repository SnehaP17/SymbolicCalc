//
// Created by Sneha on 4/11/2018.
//

#include "calculate.h"
//
// Created by Sneha on 4/7/2018.
//

bool validInput = true;
//-------------parse input ------------------------
vector<string>  parse(string str)
{

    istringstream s2(str); // it converts string variable to stream variable  s2

    vector<string> tokens;   //stores tokens that are obtained after getting rid of whitespaces

    string tmp  ;    // from stream variable s2, each token will be accepted one by one in string variable tmp

    while (s2 >> tmp)
    {

        //push back the extracted word
        tokens.push_back(tmp);
    }

    return tokens;

}

//--------------infix to postfix-------------------
vector<string> toPostfix(const vector<string>& tokens)
{
    validInput = true;
    stack<string> opStack;  // declare  stack opstack  to temporarily store operators

    vector<string> postfix;  // declare vector postfix  to store postfix tokens / expression

    if(tokens.size() < 3) // if input is '3', '3 +' etc (we need minimum 3 tokens for an operation)
    {
        cout << "Invalid input!" << endl;
        validInput = false;
        return postfix;
        //exit(0);
    }

    if(IsOperator(tokens[0])) //if first token is an operator. (First token should be an operand)
    {
        cout << "Invalid input!" << endl;
        validInput = false;
        return postfix;
        //exit(0);
    }


    for(int i = 0; i < tokens.size(); i++)    //while there are tokens to be read: read a token
    {

        if (IsOperand(tokens[i]))    //if the token is a number, then push it to the output queue.
        {
            postfix.push_back(tokens[i]);
        }


        else if (IsOperator(tokens[i]))   // if the token is an operator, then:
        {
            /*  while ((there is an operator at the top of the operator stack with greater precedence) or
                       (the operator at the top of the operator stack has equal precedence and the operator is left associative))
                              and (the operator at the top of the stack is not a left bracket) */

            if  (!opStack.empty())  // Returns true if stack is empty so continue if not empty
            {

                while (
                        ((GreaterPrecedence(opStack.top(), tokens[i])) ||
                         (EqualPrecedence(opStack.top(), tokens[i]) && IsLeftAssociative(opStack.top()))) &&
                        opStack.top() != "(" )
                {
                    postfix.push_back(opStack.top()); //copy operators from top of stack onto output queue.
                    opStack.pop();                    // then pop the operator from stack

                    if(opStack.empty())
                    {
                        break;
                    }

                }
            }

            opStack.push(tokens[i]);
        }
        else if (tokens[i] == "(")              //if the token is a left bracket
        {
            opStack.push(tokens[i]);       //push it onto the operator stack.
        }
        else if (tokens[i] == ")")              // if the token is a right bracket
        {
            // while the operator at the top of the operator stack is not a left bracket:
            while (!opStack.empty() && opStack.top() != "(")
            {
                // pop operators from the operator stack onto the output queue.
                postfix.push_back(opStack.top());
                opStack.pop();

            }

            //check for mismatched parentheses---------
            if(opStack.empty() || opStack.top() != "(")
            {
                cout << "Invalid input!" << endl;
                validInput = false;
                return postfix;

            }
            //---------
            opStack.pop();
        }

        //else invalid
        else
        {
            return postfix;
        }

    }      //end of reading tokens for loop as no more tokens to be read

    while(!opStack.empty())   // copy  the remaining operators from stack onto the output queue and pop them
    {
        //code to check if any brackets still remain
        if(opStack.top() == "(" || opStack.top() == ")")
        {
            cout << "Invalid input!" << endl;
            validInput = false;
            return postfix;
        }
        //end code
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    //----end of postfix work-------
    return postfix;
}

bool IsOperand( string Oprd)
{

    if(Oprd == "+" || Oprd == "-" || Oprd == "*" || Oprd == "/"||  Oprd == "^" )
        return false;
    else if (Oprd == "(" || Oprd == ")")
        return false;
    else
    {
        bool onlyDigits = true;

        //if negative operand
        if(Oprd[0] == '-')
        {

            for (size_t n = 1; n < Oprd.length(); n++)
            {
                if (!isdigit( Oprd[ n ] ))
                {
                    onlyDigits = false;
                    break;
                }
            }
        }

            //else positive operand
        else
        {
            for (size_t i = 0; i < Oprd.length(); i++)
            {
                if (!isdigit(Oprd[i]))
                {
                    onlyDigits = false;
                    break;
                }
            }
        }


        if(onlyDigits)
        {
            return true;
        }
        else
        {
            cout << "Invalid input!" << endl;
            validInput = false;
            return false;
            //exit(0);
        }
    }

    return false;
}

bool IsOperator( string Oprt)
{

    if(Oprt == "+" || Oprt == "-" || Oprt == "*" || Oprt == "/"||  Oprt == "^" )
        return true;

    else
        return false;
}

// function to check operator's precedence
//operator1 - of stack, operator2 - of token
bool GreaterPrecedence(string operator1, string operator2)
{
    if(GetOperatorPrecedence(operator1) > GetOperatorPrecedence(operator2))
    {
        return true;
    }

    else
        return false;
}

bool EqualPrecedence(string operator1, string operator2)
{
    if(GetOperatorPrecedence(operator1) == GetOperatorPrecedence(operator2))
    {
        return true;
    }

    else
        return false;
}

//
int GetOperatorPrecedence(string op)
{
    if(op == "^" )
    {
        return 3;
    }

    if(op == "*" || op == "/" )
    {
        return 2;
    }

    if(op == "+" || op == "-" )
    {
        return 1;
    }

}

bool IsLeftAssociative(string opt)
{
    if (opt == "^" || opt == "rt")
    {
        return false;
    }

    return true;
}

bool IsNumber( string Oprd)
{


        bool onlyDigits = true;

        //if negative operand
        if(Oprd[0] == '-')
        {

            for (size_t n = 1; n < Oprd.length(); n++)
            {
                if (!isdigit( Oprd[ n ] ))
                {
                    onlyDigits = false;
                    break;
                }
            }
        }

            //else positive operand
        else
        {
            for (size_t i = 0; i < Oprd.length(); i++)
            {
                if (!isdigit(Oprd[i]))
                {
                    onlyDigits = false;
                    break;
                }
            }
        }


        if(onlyDigits)
        {
            return true;
        }


    return false;
}

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Function to convert fraction into it's simplest form
string lowest(int num3, int den3)
{
    // Finding gcd of both terms
    int common_factor = gcd(num3,den3);

    //convert into simpler form
    den3 = den3/common_factor;
    num3 = num3/common_factor;
    string den = to_string(den3);
    string num = to_string(num3);

    if(den == "1")
    {
        return num;
    }
    else
    {
        string res = num+"/"+den;
        return res;
    }


}

//returns vector containing solved expression and solved floating point value
vector <string> solve(vector<string> postfix)
{
    stack <string> expStack;
    stack <string> doubleStack;
    vector <string> answer; //stores answer in expression and answer in floating point
    for(string token : postfix)
    {
        if(IsOperand(token))
        {
            expStack.push(token);
            doubleStack.push(token);

        }

        else
        {
            string rhs = expStack.top();
            expStack.pop();

            string drhs = doubleStack.top();
            doubleStack.pop();

            string lhs = expStack.top();
            expStack.pop();

            string dlhs = doubleStack.top();
            doubleStack.pop();

            if(token == "+")
            {
                addition add(lhs,rhs);
                expStack.push(add.simplify(lhs,rhs));
                doubleStack.push(add.dbsimplify(dlhs,drhs));

            }

            if(token == "-")
            {
                subtraction sub(lhs,rhs);
                expStack.push(sub.simplify(lhs,rhs));
                doubleStack.push(sub.dbsimplify(dlhs,drhs));
            }

            if(token == "*")
            {
                multiplication mult(lhs,rhs);
                expStack.push(mult.simplify(lhs,rhs));
                doubleStack.push(mult.dbsimplify(dlhs,drhs));
            }

            if(token == "^")
            {
                exponent expo(lhs,rhs);
                expStack.push(expo.simplify(lhs,rhs));
                doubleStack.push(expo.dbsimplify(dlhs,drhs));
            }

            if(token == "/")
            {
                division div(lhs,rhs);
                expStack.push(div.simplify(lhs,rhs));
                doubleStack.push(div.dbsimplify(dlhs,drhs));
            }

        }
    }

    answer.push_back(expStack.top()); //first element
    answer.push_back(doubleStack.top()); // second element i.e floating point value

    return answer;

   // cout << doubleStack.top() << endl;
    //return expStack.top();
}