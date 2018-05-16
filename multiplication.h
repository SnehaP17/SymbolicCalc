//
// Created by Sneha on 4/11/2018.
//

#ifndef CALCULATORTWO_MULTIPLICATION_H
#define CALCULATORTWO_MULTIPLICATION_H
//
// Created by Sneha on 4/9/2018.
//
#include <iostream>
using namespace std;
#include "calculate.h"


class multiplication
{
private:
    string lhs;
    string rhs;

public:
    multiplication(string, string);
    string simplify(string lhs, string rhs);
    string dbsimplify(string lhs, string rhs);
};


#endif //CALCULATORTWO_MULTIPLICATION_H
