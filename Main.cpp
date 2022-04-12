//
// Created by rivka on 12/04/2022.
#include "sources/Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace zich;

int main() {
    bool con = true;
    Matrix mat1{};
    Matrix mat2{};
    try {
        cout << "enter mat1" << endl;
        cin >> mat1;
        cout << "enter mat2" << endl;
        cin >> mat2;
    }
    catch (std::out_of_range ex) {
        cout << ex.what() << endl;
        con = false;
    }
    while (con) {
        try {
            string m;
            string result;
            double num;
            cout
                    << "enter  +, +=,  -, -=,  *,  *=,  number*,  *number,  mat++, ++mat, mat--, --mat, <, <=, >, >=, ==, !=, -unary, +unary, show, stop"
                    << endl;
            string s;
            cin >> s;
            if (s == "+") {
                cout << mat1 + mat2 << endl;
            } else if (s == "+=") {
                cout << "enter yes if mat1+=mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    mat1 += mat2;
                    cout << mat1 << endl;
                }
                else{
                    mat2 += mat1;
                    cout << mat2 << endl;
                }
            } else if (s == "-") {
                cout << "enter yes if mat1-mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    cout << mat1 - mat2 << endl;
                }
                else{
                    cout << mat2 - mat1 << endl;
                }
            } else if (s == "-=") {
                cout << "enter yes if mat1-=mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    mat1 -= mat2;
                    cout << mat1 << endl;
                }
                else{
                    mat2 -= mat1;
                    cout << mat2 << endl;
                }

            } else if (s == "*") {
                cout << "enter yes if mat1*mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    cout << mat1 * mat2 << endl;
                }
                else{
                    cout << mat2 * mat1 << endl;
                }
            } else if (s == "*=") {
                cout << "enter yes if mat1*=mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    mat1 *= mat2;
                    cout << mat1 << endl;
                }
                else{
                    mat2 *= mat1;
                    cout << mat2 << endl;                }

            } else if (s == "number*") {
                cout << "enter number" << endl;
                cin >> num;
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << num * mat1 << endl;
                } else {
                    cout << num * mat2 << endl;
                }
            } else if (s == "*number") {
                cout << "enter number" << endl;
                cin >> num;
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << mat2 * num << endl;
                } else {
                    cout << mat2 * num << endl;

                }
            } else if (s == "mat++") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << (mat1++) << endl;
                } else {
                    cout << (mat2++) << endl;
                }

            } else if (s == "++mat") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") { ;
                    cout << (++mat1) << endl;
                } else {
                    cout << (++mat2) << endl;
                }

            } else if (s == "mat--") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << (mat1--) << endl;
                } else {
                    cout << (mat2--) << endl;
                }

            } else if (s == "--mat") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << (--mat1) << endl;
                } else {
                    cout << (--mat2) << endl;
                }

            } else if (s == "<") {
                cout << "enter yes if mat1<mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    result = (mat1 < mat2) ? "true" : "false";
                    cout << result << endl;
                } else {
                    result =(mat2 < mat1) ? "true" : "false";
                    cout << result << endl;
                }
            } else if (s == "<=") {
                cout << "enter yes if mat1<=mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    result = (mat1 <= mat2) ? "true" : "false";
                    cout << result << endl;
                } else {
                    result = (mat2 <= mat1) ? "true" : "false";
                    cout << result << endl;
                }
            } else if (s == ">") {
                cout << "enter yes if mat1>mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    result =  (mat1 > mat2)? "true" : "false";
                    cout << result << endl;
                } else {
                    result = (mat2 > mat1)? "true" : "false";
                    cout << result << endl;
                }
            } else if (s == ">=") {
                cout << "enter yes if mat1>=mat2" << endl;
                cin >> m;
                if (m == "yes") {
                    result =  (mat1 >= mat2)? "true" : "false";
                    cout << result << endl;
                } else {
                    result = (mat2 >= mat1)? "true" : "false";
                    cout << result << endl;
                }
            } else if (s == "==") {
                result = (mat1 == mat2) ? "true" : "false";
                cout << result << endl;
            } else if (s == "!=") {
                result = (mat1 != mat2) ? "true" : "false";
                cout << result << endl;
            } else if (s == "+unary") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << (+mat1) << endl;
                } else {
                    cout << (+mat2) << endl;
                }
            } else if (s == "-unary") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << (-mat1) << endl;
                } else {
                    cout << (-mat2) << endl;
                }
            } else if (s == "show") {
                cout << "enter mat1 or mat2" << endl;
                cin >> m;
                if (m == "mat1") {
                    cout << mat1 << endl;
                } else {
                    cout <<mat2 << endl;
                }
            } else if (s == "stop") {
                con = false;
                cout << "bye" << endl;
            } else {
                cout << "Invalid operation" << endl;
            }
        }
        catch (std::out_of_range ex) {
            cout << ex.what() << endl;
        }
    }
    return 0;

}


