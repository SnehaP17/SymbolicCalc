#include "calculate.h"
using namespace std;

vector <string> calculate(string input)
{
    vector<string> tokens = parse(input);  // parse  function

    vector <string> postfix; //vector stores postfix tokens

    postfix = toPostfix(tokens);   // pass the parsed tokens to topostfix function which returns postfix vector string

    vector <string> answer = solve(postfix);

    return answer;

}

void printTestresults(const string x, const string y, const string z)
{
    cout << "Expression: " << x << endl;
    cout << "Expected result: " << z << endl;
    cout << "Calculated result: "<< y << endl;
    if( z == y)
    {
        cout << "Test Result: SUCCESS." << endl;

    } else
    {
        cout << "Test Result: Failure." << endl;

    }

}

void test1()
{
    string x = "1 / 6 + 5 / 6";
    vector <string> ans = calculate(x);
    string y = ans[0];
    string z = "1";
    printTestresults(x,y ,z);
    cout << "Floating point representation: " << ans[1] << endl;
    cout << " " << endl;


}

void test2()
{
    string x = "( 1 / 5 ) ^ 2 + 2 / 3";
    vector <string> ans = calculate(x);
    string y = ans[0];
    string z = "1/25+2/3";
    printTestresults(x,y ,z);
    cout << "Floating point representation: " << ans[1] << endl;
    cout << " " << endl;

}

void test3()
{
    string x = "8 + 4 * ( 9 - 6 )";
    vector <string> ans = calculate(x);
    string y = ans[0];
    string z = "20";
    printTestresults(x,y ,z);
    cout << "Floating point representation: " << ans[1] << endl;
    cout << " " << endl;

}

void test4()
{
    string x = "-2 ^ 3 + 4 * ( 1 / 2 + 1 / 2 )";
    vector <string> ans = calculate(x);
    string y = ans[0];
    string z = "-4";
    printTestresults(x,y ,z);
    cout << "Floating point representation: " << ans[1] << endl;
    cout << " " << endl;


}
int main()
{
    test1();
    test2();
    test3();
    test4();

    string input;
    vector<string> tokens;
    vector <string> postfix; //vector stores postfix tokens


    do
    {
        cout << "Enter expression to calculate:- " << endl;
        getline(cin, input);     //stores input in a string named input

        tokens = parse(input);  // parse  function returns vector <string> type parsed string

        postfix = toPostfix(tokens); // tokens are stored in postfix notation
    }
    while(!validInput);


    // solve method is called on postfix tokens to do final calculation
    vector <string> answer = solve(postfix);


    cout << "Answer:  " << answer[0] << endl;
    cout << "Floating point representation: " << answer[1] << endl;

    return 0;
}