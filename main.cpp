#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "postfix.h"

using namespace std;


int main(){

    string sentence ;

    cout <<"Escribir cadena ";

    getline(cin,sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";
    return 0;

}