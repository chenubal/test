/* 
 * File:   main.cpp
 * Author: jheers
 *
 * Created on 26. Februar 2013, 08:03
 */

#include "BasicEBC.h"
#include <memory>

// github test

using namespace std;

int main(int argc, char** argv)
{
    //BUILD
    vector< shared_ptr<ConsoleWriter> > c;
    Multiplier<string> m(3);
    c.push_back( std::make_shared<ConsoleWriter>("console x gets ")  );
    c.push_back( std::make_shared<ConsoleWriter>("console y gets ")  );
    c.push_back( std::make_shared<ConsoleWriter>("console z gets ")  );
    //BIND
    m.Out(0, c[0]->In(0));
    m.Out(1, c[1]->In(0));
    m.Out(2, c[2]->In(0));
    //RUN
    boost::get<StringAction>(m.In(0))("Harry");
    return 0;
}

