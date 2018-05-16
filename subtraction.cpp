//
// Created by Sneha on 4/11/2018.
//

#include "subtraction.h"

subtraction::subtraction(string r, string l){
    this->rhs = r;
    this->lhs = l;
}

//simplify for integer
string subtraction :: dbsimplify(string lhs, string rhs)
{
    double l = stod(lhs);
    double r = stod(rhs);
    double ans = l-r;

    string result  = to_string(ans);
    return result;

}

//simplify for symbolic calculation
string subtraction::simplify(string lhs, string rhs)
{
    //if both operands are integers
    if (IsNumber(lhs) && IsNumber(rhs))
    {

        int x = stoi(lhs);
        int y = stoi(rhs);
        int res = x-y;


        string result = to_string(res);
        return result;

    }

    // if both operands are fractions
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

        if (lpos!=string::npos && rpos!=string::npos && IsNumber(lnum) && IsNumber(ldenom) && IsNumber(rnum) && IsNumber(rdenom) )
        {

            if(ldenom == rdenom)
            {

                int x = stoi(lnum);
                int y = stoi(rnum);
                int z = stoi(rdenom);
                int sum = x - y;

                string res = lowest(sum, z);
                return res;
            }

            else
            {
                return  lhs+ "-" + rhs;
            }




        }

        else
        {
            return "(" + lhs+ ")-(" + rhs + ")";
        }

    }


}