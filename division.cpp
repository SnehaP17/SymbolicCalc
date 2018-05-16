//
// Created by Sneha on 4/11/2018.
//

#include "division.h"



division::division(string r, string l)
{
    this->rhs = r;
    this->lhs = l;
}

//simplify method for floating point calculation
string division:: dbsimplify(string lhs, string rhs)
{
    double l = stod(lhs);
    double r = stod(rhs);
    double ans = l/r;

    string result  = to_string(ans);
    return result;

}

//simplify method for symbolic calculation
string division::simplify(string lhs, string rhs)
{

    //if both operands are integers
    if (IsNumber(lhs) && IsNumber(rhs))
    {
        int x = stoi(lhs);
        int y = stoi(rhs);
        string res = lowest(x,y);
        return res;
    }

    else
    {

        size_t lpos;
        size_t rpos;

        lpos = lhs.find('/');
        rpos = rhs.find('/');
        string lnum = lhs.substr(0, lpos); //string fromm 0 to i-1
        string ldenom = lhs.substr(lpos + 1, lhs.size());

        string rnum = rhs.substr(0, rpos); //string fromm 0 to i-1
        string rdenom = rhs.substr(rpos + 1, rhs.size());

        //if both operands are simple fractions
        if (lpos != string::npos && rpos != string::npos && IsNumber(lnum) && IsNumber(ldenom) && IsNumber(rnum) &&
            IsNumber(rdenom)) {


            int x = stoi(lnum);
            int y = stoi(rnum);
            int u = stoi(ldenom);
            int v = stoi(rdenom);

            int divnum = x * v;
            int divdenom = y * u;

            string res = lowest(divnum, divdenom);
            return res;


        }

        //if rhs is integer and lhs is a simple fraction
        else if (lpos != string::npos && IsNumber(rhs) && IsNumber(lnum) && IsNumber(ldenom)) {
            int num = stoi(rhs);
            int x = stoi(lnum);
            int y = stoi(ldenom);

            int divdenom = y * num;

            string res = lowest(x, divdenom);
            return res;


        }

        //if lhs is a number and rhs is a simple fraction
        else if (rpos != string::npos && IsNumber(lhs) && IsNumber(rnum) && IsNumber(rdenom)) {
            int num = stoi(lhs);
            int x = stoi(rnum);
            int y = stoi(rdenom);

            int divnum = num * y;

            string res = lowest(divnum, x);
            return res;


        }

        else
        {
            return lhs+"/"+rhs;
        }

    }


}
