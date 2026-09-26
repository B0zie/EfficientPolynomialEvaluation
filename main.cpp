#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

//page 239
int BruteForce(vector<int> P,int x){
   int n = P.size()-1;
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


//Walk through with paper
//Mark page number
int Horners(vector<int> P, int x){
   int n = P.size()-1;   
   int p = P.at(n);  // p <- P[n]

   for(int i = n-1; i >= 0; --i){
      p = x * p + P[i];
   }
   return p;
}

void TestBruteForce(){
   vector<int> P;
   P = {1,1,2,3};
   assert(BruteForce(P,2) == 35);

   cout << "BruteForce Function Testing Passed!" << endl;
}

void TestHorners(){
   vector<int> P;
   P = {1,1,2,3};
   assert(Horners(P,2) == 35);
   cout << "Horners Function Testing Passed!" << endl;
}


int main () {
	int n;
	int x;
   vector<int> P;

   TestBruteForce(); 
   TestHorners();
   cin >> x >> n; 

   for(int i = 0; i <= n; ++i) {
      if(i == 0) 
        P.push_back(1);
      else
        P.push_back(i);
   } 
  
  cout << BruteForce(P,x) << endl;
    

   return 0;
}
