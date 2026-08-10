#include <iostream>
using namespace std;

int main()
{
    cout << "Grammar:" << endl;
    cout << "E -> E + T | T" << endl;
    cout << "T -> T * F | F" << endl;
    cout << "F -> ( E ) | id" << endl;

    cout << "\nTRAILING Sets:" << endl;

    cout << "TRAILING(E) = { +, ), id }" << endl;
    cout << "TRAILING(T) = { +, *, ), id }" << endl;
    cout << "TRAILING(F) = { *, ), id }" << endl;

    return 0;
}
