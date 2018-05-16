//
// Created by Sneha on 4/11/2018.
//

#include "exponent.h"
#include <cmath>
exponent::exponent(string r, string l){
    this->rhs = r;
    this->lhs = l;
}

//simplify method for floating point calculation
string exponent:: dbsimplify(string lhs, string rhs)
{
    double l = stod(lhs);
    double r = stod(rhs);
    double ans = pow(l,r);

    string result  = to_string(ans);
    return result;

}

//simplify method for symbolic exponentiation
string exponent::simplify(string lhs, string rhs)
{
    if (IsNumber(lhs) && IsNumber(rhs))
    {
        int x = stoi(lhs);
        int y = stoi(rhs);
        int res = round(pow(x,y));

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

        string rnum = rhs.substr(0,rpos);
        string rdenom = rhs.substr(rpos+1,rhs.size());

        //power i.e rhs is an integer and lhs is a simple fraction
        if(lpos!=string::npos && IsNumber(rhs) && IsNumber(lnum) && IsNumber(ldenom))
        {

            int num = stoi(rhs);
            int x = stoi(lnum);
            int y = stoi(ldenom);

            int expnum = round(pow(x,num));

            int expdenom = round(pow(y,num));
            string res = lowest(expnum, expdenom);
            return res;


        }


        else
        {
            return  "("+lhs + ")^(" + rhs + ")";
        }

    }




}