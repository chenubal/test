/* 
 * File:   main.cpp
 * Author: jheers
 *
 * Created on 26. Februar 2013, 08:03
 */

#include "BasicEBC.h"

using namespace std;

int main(int argc, char** argv)
{
    //BUILD
    Multiplier<string> m(3);
    ConsoleWriter w1("mueller: "), w2("meier: "), w3("heers: ");
    //BIND
    m.Out(0, w1.In(0));
    m.Out(1, w2.In(0));
    m.Out(2, w3.In(0));
    //RUN
    boost::get<StringAction>(m.In(0))("Harry");
    return 0;
}

