
#include <iostream>
using namespace std;

#include "chain.hpp"
#include "range.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "zip.hpp"
#include "badkan.hpp"

using namespace itertools;

int main() {

badkan::TestCase testcase;
int grade=0;
int number=0;

int signal = setjmp(badkan::longjmp_buffer);
if (signal == 0) {

  //range
testcase.setname("range");
for (int i : range(0, 9))
     {
       testcase.CHECK_EQUAL(i, number);
       number++;
     }
    number=10;
     for (int i : range(10, 20))
     {
       testcase.CHECK_EQUAL(i, number);
       number++;
     }
     number=22;
      for (int i : range(22, 34))
     {
       testcase.CHECK_EQUAL(i, number);
       number++;
     }
    
     number=-99;
      for (int i : range(-99, -88))
     {
       testcase.CHECK_EQUAL(i, number);
       number++;
     }
      number=0;
      for (int i : range(0, 100))
     {
       testcase.CHECK_EQUAL(i, number);
       number++;
     }
     
//chain
 testcase.setname("chain");
    number=0;
int Itest[]={1,2,3,5,6,7};
for (int i: chain(range(1,4), range(5,8)))
 {
   testcase.CHECK_EQUAL(i, Itest[number]);
   number++;
 }
 number=0;
char Stest[]={'a','b','c','h','e','l','l','o'};
for (char i: chain(range('a','d'), string("hello")))
 {
   testcase.CHECK_EQUAL(i, Stest[number]);
   number++;
 }
char Stest6[]={'1','2','3','4','h','e','l','l','o'};
for (char i: chain(range('1','5'), string("hello")))
 {
   testcase.CHECK_EQUAL(i, Stest6[number]);
  number++;
 }



 //zip
testcase.setname("zip");
number=0;
string Stest3[]={"1,n","2,a","3,o","4,m","5,i"};
for (auto pair: zip(range(1,6), string("naomi")))
{
   testcase.CHECK_OUTPUT(pair,Stest3[number]);
   number++;
}
number=0;
string Stest7[]={"1,3","2,4","3,5"};
for (auto pair: zip(range(1,6), range(3,6)))
{
   testcase.CHECK_OUTPUT(pair,Stest7[number]);
   number++;
}
number=0;
string Stest8[]={"O,N","r,a","S,o","h,m","e,i"};
for (auto pair: zip(string("OrShe"), string("Naomi")))
{
   testcase.CHECK_OUTPUT(pair,Stest8[number]);
   number++;
}
number=0;
string Stest9[]={"3,h","4,e","5,l","6,l","7,o"};
for (auto pair: zip(range(3,8), string("hello")))
{
   testcase.CHECK_OUTPUT(pair,Stest9[number]);
   number++;
}
number=0;
string Stest10[]={"3,1","4,2","5,3","6,4","7,h","8,e","9,l","10,l","11,o"};
for (auto pair: zip(range(3,12), chain(range('1','5'), string("hello"))))
{
   testcase.CHECK_OUTPUT(pair,Stest10[number]);
   number++;
}
number=0;
string Stest11[]={"l,1","o,2","l,3","o,4","l,2","o,3"};
for (auto pair: zip(string("lololo"), chain(range(1,5), range(2,4))))
{
   testcase.CHECK_OUTPUT(pair,Stest11[number]);
   number++;
}

number=0;
string Stest12[]={"n,1","a,2","o,3","m,4","i,5","T,6","s,7","a,8","b,9","a,1","r,1","i,1"};
for (auto pair: zip(string("naomiTsabari"),string("123456789111")))
{
   testcase.CHECK_OUTPUT(pair,Stest12[number]);
   number++;
}

//product
testcase.setname("product");
 number=0;
   string Stest4[]={"0,z","0,r","1,z","1,r","2,z","2,r","3,z","3,r","4,z","4,r"};
for (auto pair: product(range(0,5), string("zr")))
{
   testcase.CHECK_OUTPUT(pair,Stest4[number]);
   number++;

 }
 number=0;
  string Stest13[]={"l,z","l,r","o,z","o,r","l,z","l,r"};
for (auto pair: product(string("lol"), string("zr")))
{
   testcase.CHECK_OUTPUT(pair,Stest13[number]);
   number++;
}
 number=0;
  string Stest14[]={"1,1,h","1,2,e","1,3,l","2,1,h","2,2,e","2,3,l","3,1,h","3,2,e","3,3,l"};
for (auto pair: product(range(1,3), zip(range(1,3),string("hel"))))
{
   testcase.CHECK_OUTPUT(pair,Stest14[number]);
   number++;
}

//powerset
testcase.setname("powerset");
number=0;
   string Stest15[]={"{}","{0}","{1}","{0,1}","{2}","{0,2}","{1,2}","{0,1,2}"};
for (auto pair: powerset(range(0,3)))
{
   testcase.CHECK_OUTPUT(pair,Stest15[number]);
   number++;
 }
number=0;
   string Stest16[]={"{}","{p}","{i}","{p,i}","{p}","{p,p}","{i,p}","{p,i,p}"};
for (auto pair: powerset(string("pip"))){
   testcase.CHECK_OUTPUT(pair,Stest16[number]);
   number++;
}
number=0;
   string Stest20[]={"{}","{1,a}","{2,b}","{1,a,2,b}"};
for (auto pair: powerset(zip(range(1,3),string("ab"))))
{
   testcase.CHECK_OUTPUT(pair,Stest20[number]);
   number++;
 }
number=0;
string Stest21[]={"{}","{1,h}","{2,h}","{1,h,2,h}"};
 for (auto pair: powerset(product(range(1,3), string("h")))){
 testcase.CHECK_OUTPUT(pair,Stest21[number]);
    number++;
 }
 number=0;
string Stest23[]={"{}","{1,x}","{2,y}","{1,x,2,y}"};
 for (auto pair: powerset(zip(range(1,3), string("xy")))){
 testcase.CHECK_OUTPUT(pair,Stest23[number]);
number++;
  }
 for (auto pair: powerset(zip(range(1,4), string("xyz")))){
    number++;
 }
 testcase.CHECK_EQUAL(number==16,true);



grade = testcase.grade();
								 }else {
																testcase.print_signal(signal);
																grade = 0;
								}
								cout << "Your grade is: "  << grade << endl;
								return 0;

}