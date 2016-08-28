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

    vector<char>elems = split(sentence);

    cout << "Escribio : " << sentence << endl;

    cout << "Cadena: " << elems[0] << endl;

    cout << "Cadena: " << elems[3] << endl;

    return 0;

}