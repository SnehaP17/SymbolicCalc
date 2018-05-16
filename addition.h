//
// Created by Sneha on 4/11/2018.
//

#ifndef CALCULATORTWO_ADDITION_H
#define CALCULATORTWO_ADDITION_H
//
// Created by Sneha on 4/10/2018.
//


#include <iostream>
using namespace std;
#include "calculate.h"

class addition
{
private:
    string lhs;
    string rhs;

public:
    addition(string, string);
    string simplify(string lhs, string rhs);
    string dbsimplify(string lhs, string rhs);
};



#endif //CALCULATORTWO_ADDITION_H
