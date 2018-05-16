//
// Created by Sneha on 4/11/2018.
//

#ifndef CALCULATORTWO_CALCULATE_H
#define CALCULATORTWO_CALCULATE_H

//
// Created by Sneha on 4/7/2018.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include "multiplication.h"
#include "addition.h"
#include "subtraction.h"
#include "exponent.h"
#include "division.h"
using namespace std;

extern bool validInput;

//function to change string to postfix
vector<string> toPostfix(const vector<string>& tokens);

//parse string
vector<string> parse(string input);

// function to check operator's precedence
bool GreaterPrecedence(string operator1, string operator2);

// function to check whether a character is an operator.
bool IsOperator(string str);

//function for operator precedence
int GetOperatorPrecedence(string opt);

//function for equal precedence
bool EqualPrecedence(string operator1, string operator2);

// Function to verify operand
bool IsOperand(string opd);

//function to check left associativity
bool IsLeftAssociative(string opt);

bool IsNumber( string Oprd);

int gcd(int a, int b);

string lowest(int num3, int den3);




vector <string> solve(vector<string>);




#endif //CALCULATORTWO_CALCULATE_H
