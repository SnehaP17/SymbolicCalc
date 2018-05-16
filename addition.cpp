//
// Created by Sneha on 4/11/2018.
//

#include "addition.h"
//
// Created by Sneha on 4/10/2018.
//


addition::addition(string r, string l){
    this->rhs = r;
    this->lhs = l;
}

//simplify method for double-type values
string addition:: dbsimplify(string lhs, string rhs)
{
    double l = stod(lhs);
    double r = stod(rhs);
    double ans = l+r;

    string result  = to_string(ans);
    return result;

}

//simplify method for expression
string addition::simplify(string lhs, string rhs)
{

    //if both operands are integers
    if (IsNumber(lhs) && IsNumber(rhs))
    {

        int x = stoi(lhs);
        int y = stoi(rhs);
        int res = x+y;


        string result = to_string(res);
        return result;

    }


    else
    {
        //operands are fractions in symbolic forms- separate each operand's numerator and denominator
        size_t lpos;
        size_t rpos;

        lpos = lhs.find('/');
        rpos = rhs.find('/');
        string lnum = lhs.substr(0,lpos); //string fromm 0 to i-1
        string ldenom = lhs.substr(lpos+1,lhs.size());

        string rnum = rhs.substr(0,rpos); //string fromm 0 to i-1
        string rdenom = rhs.substr(rpos+1,rhs.size());

        //if both are symbolic fractions with integer numerator and innteger denominator
        if (lpos!=string::npos && rpos!=string::npos && IsNumber(lnum) && IsNumber(ldenom) && IsNumber(rnum) && IsNumber(rdenom))
        {
            // if common denominator
            if(ldenom == rdenom)
            {
                int x = stoi(lnum);
                int y = stoi(rnum);
                int z = stoi(rdenom);
                int sum = x + y;

                string res = lowest(sum, z);
                return res;
            }

            else
            {
                return lhs+ "+" + rhs ;
            }




        }

        else
        {
            return "(" + lhs+ ")+(" + rhs + ")";
        }

    }


}