//
// Created by Sneha on 4/11/2018.
//

#include "multiplication.h"

multiplication::multiplication(string r, string l){
    this->rhs = r;
    this->lhs = l;
}

//simplify method for integers
string multiplication:: dbsimplify(string lhs, string rhs)
{
    double l = stod(lhs);
    double r = stod(rhs);
    double ans = l*r;

    string result  = to_string(ans);
    return result;

}

//simmplify method for expression multiplication
string multiplication::simplify(string lhs, string rhs)
{
    //if both operands are integers
    if (IsNumber(lhs) && IsNumber(rhs))
    {
        int x = stoi(lhs);
        int y = stoi(rhs);
        int res = x*y;

        string result = to_string(res);
        return result;
    }

    else
    {

        size_t lpos;
        size_t rpos;

        lpos = lhs.find('/');
        rpos = rhs.find('/');
        string lnum = lhs.substr(0,lpos); //string fromm 0 to i-1
        string ldenom = lhs.substr(lpos+1,lhs.size());

        string rnum = rhs.substr(0,rpos); //string fromm 0 to i-1
        string rdenom = rhs.substr(rpos+1,rhs.size());

        //both operands are  simple fractions
        if (lpos!=string::npos && rpos!=string::npos && IsNumber(lnum) && IsNumber(ldenom) && IsNumber(rnum) && IsNumber(rdenom) )
        {

                int x = stoi(lnum);
                int y = stoi(rnum);
                int u = stoi(ldenom);
                int v = stoi(rdenom);

                int multnum = x * y;
                int multdenom = u * v;

                string res = lowest(multnum, multdenom);
                return res;



        }

        //else right operand is an integer and left operand is a simple fraction
        else if(lpos!=string::npos && IsNumber(rhs) && IsNumber(lnum) && IsNumber(ldenom))
        {
            int num = stoi(rhs);
            int x = stoi(lnum);
            int y = stoi(ldenom);

            int multnum = num * x;

            string res = lowest(multnum, y);
            return res;


        }

            //else left operand is an integer anf right operand is a simple fraction
        else if(rpos!=string::npos && IsNumber(lhs) && IsNumber(rnum) && IsNumber(rdenom))
        {
            int num = stoi(lhs);
            int x = stoi(rnum);
            int y = stoi(rdenom);

            int multnum = num * x;

            string res = lowest(multnum, y);
            return res;


        }

        else
        {
            return "(" + lhs+ ")*(" +rhs + ")";
        }

    }


}