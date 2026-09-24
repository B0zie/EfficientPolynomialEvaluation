#include <iostream>
#include <cassert>
using namespace std;


//Evaluates an exponent >= 0 
//P_n(x) = x^0 + 1x^1 + 2x^2 + 3x^3 + nx^n
int EvalMonomial(int x, int n) {
   if(n == 0)
      return 1;
   else if(n == 1)
      return x;
   else{
    x = x*EvalMonomial(x,n-1);
   }
  return n*x;
}

int BruteForce(int x, int n){
  int p = 0;
  for(int i = 0; i <= n; ++i) {
     p += EvalMonomial(x,i);
  } 

  return p;
}

//P(x) = 1 + x + 2x^2 + 3x^3
//P(x) = 1 + x(1 + 2x + 3x^2)
//P(x) = 1 + x(1 + x(2 + 3x)
//int Horners (int x, int n) {
   

//}



void TestMonomial(){
//P_n(x) = x^0 + 1x^1 + 2x^2 + 3x^3 + nx^n
 	assert(EvalMonomial(5,2) == 50);
   assert(EvalMonomial(3,2) == 18);
	assert(EvalMonomial(0,1000) == 0);// 0 raised to any exponent is still 0
	assert(EvalMonomial(1000,0) == 1); // Exponent of 0 makes number 1
   cout << "EvalMonomial function Paseed Testing!" << endl;
}

void TestBruteForce(){
   assert(BruteForce(5,2) == 56);
   cout << "BruteForce function Passed Testing!" << endl;
}

void TestHorners(){


}

int main () {
   //5. Hardcode x,n
	int n = 2;
	int x = 5;
   
   BruteForce(x,n);
   TestMonomial();
   TestBruteForce();
  
    

   return 0;
}
