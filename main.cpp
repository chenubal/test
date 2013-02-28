/* 
 * File:   main.cpp
 * Author: jheers
 *
 * Created on 26. Februar 2013, 08:03
 */

#include <typeinfo>
#include <cstdlib>
#include "AbstractEBC.h"
#include <stdexcept>

using namespace std;

/*
 * 
 */


 
int main(int argc, char** argv) {

   Multiplier<string> m(2);
   ConsoleWriter w1("mueller: "), w2("meier: ");
   m.Out(0) = w1.In(0);
   m.Out(1) = w2.In(0);
   action_type x = w1.In(0);
   cout << x.type().name() << endl;
   cout << m.Out(0).type().name() << endl;
   string msg("jheers");
   apply_action(x,msg);
   return 0;
}

