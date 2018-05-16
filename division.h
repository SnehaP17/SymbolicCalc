//
// Created by Sneha on 4/11/2018.
//


#ifndef CALCULATORTWO_DIVISION_H
#define CALCULATORTWO_DIVISION_H

#include <iostream>
using namespace std;
#include "calculate.h"


class division
{
private:
    string lhs;
    string rhs;
    bool Integer = true;

public:
    division(string, string);
    string simplify(string lhs, string rhs);
    string dbsimplify(string lhs, string rhs);
};



#endif //CALCULATORTWO_DIVISION_H
