#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> GetCoefficients(int n){
   vector<int> P;
   for(int i = 0; i <= n; ++i) {
      if(i == 0) 
        P.push_back(1);
      else
        P.push_back(i);
   }
  return P; 
}

//example of overflow scenario
int BruteForceOverflow(int x, int n){
   vector<int> P = GetCoefficients(n);
   int p = 0;//init sum val to 0  

   for (int i = n; i >= 0; --i ){
      int power = 1;//init multiplication val by 1

      for(int j = 1; j <= i; ++j ){
         power = power * x;
      }
      p = p + P.at(i) * power;
   } 

   return p;
}



//p236
int BruteForce(int x, int n){
   vector<int> P = GetCoefficients(n);
   long long p = 0;//init sum val to 0  

   for (int i = n; i >= 0; --i ){
      long long  power = 1;//init multiplication val by 1

      for(int j = 1; j <= i; ++j ){
         power = power * x;
      }
      p = p + P.at(i) * power;
   } 

   return p;
}

//Walk through with paper
//Mark page number
int Horners(int x,int n){
   vector<int> P = GetCoefficients(n);   
   long long p = P.at(n);  // p <- P[n]

   for(int i = n-1; i >= 0; --i){
      p = x * p + P[i];
   }
   return p;
}


//evaluates monomial
int RepeatedSquaring(int x, int n){
   int prod;
   int result;
   
   if(n == 0)
      return 1;
   else if (n == 1)
      return x;
   else{
      prod = RepeatedSquaring(x,n/2);
      result = prod * prod;
   }
   if((n%2) == 1)
      result = x * result;

   return result;

}

//int RepeatedSquringAlg(int x, int n){
//  
//
//}

void TestBruteForce(){
   assert(BruteForce(2,3) == 35);
   cout << "BruteForce Function Testing Passed!" << endl;
}

void TestHorners(){
   assert(Horners(2,3) == 35);
   cout << "Horners Function Testing Passed!" << endl;
}

void TestRepeatedSquaring(){
   assert(RepeatedSquaring(5,2) == 25);
   cout << "RepeatedSquaring Function Tests Passed!" << endl;
}

int main () {
	int n;
	int x;

   //TestBruteForce(); 
   //TestHorners();
  //TestRepeatedSquaring();
   cout << "x = " ;
   cin >> x;
   cout << "n = " ;
   cin >> n;


   cout << "BruteForceOverflow -> " << BruteForceOverflow(x,n) << endl;

   auto start = high_resolution_clock::now();
   cout << "BruteForce = " << BruteForce(x,n) << endl;
   auto end = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(end - start);
   cout << "BruteForce: " << duration.count() << "ms" << endl;


   
  
   return 0;
}
