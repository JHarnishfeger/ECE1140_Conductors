#include "swtcunittests.h"

void SWTCUnitTests::createWaysides()
{
    SWTrackController tc;
    Block a(10,"g","a","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block b(10,"g","a","SWITCH","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block c(10,"g","a","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block d(10,"g","b","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block e(10,"g","b","CROSSING","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block f(10,"g","b","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block g(10,"g","b","SWITCH","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block h(10,"g","b","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block i(10,"g","c","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block j(10,"g","c","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block k(10,"g","c","SWITCH","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block l(10,"g","d","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block m(10,"g","d","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block n(10,"r","d","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block o(10,"r","d","SWITCH","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block p(10,"r","e","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block q(10,"r","e","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block r(10,"r","e","CROSSING","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block s(10,"r","f","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block t(10,"r","f","RAIL","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);

    vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
    vector<Block> red{n,o,p,q,r,s,t};
    tc.initialize(red,green,0);

    tc.createWaysides(3);
    QCOMPARE(tc.waysides.size(),3);
}
