//
// Created by Sneha on 4/11/2018.
//

#ifndef CALCULATORTWO_SUBTRACTION_H
#define CALCULATORTWO_SUBTRACTION_H

#include <iostream>
using namespace std;
#include "calculate.h"


class subtraction
{
private:
    string lhs;
    string rhs;

public:
    subtraction(string, string);
    string simplify(string lhs, string rhs);
    string dbsimplify(string lhs, string rhs);
};


#endif //CALCULATORTWO_SUBTRACTION_H
