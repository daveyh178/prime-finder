#include <iostream>
#include <fstream>
using namespace std;
ofstream out;
int main(int argc, char ** argv){
  long n = 1;
  out.open("primes.txt");
  if (out.is_open()) {
    cout << "Running!!!" << endl;
    while (true){
      n+=2;
      bool p = true;
      for(long i=2;i<n;i++){
        if(n%i==0){
          p=false;
        }
      }
      if(p){
        out << n << " ";
      }
    }
  }
  out.close();
  return 0;
}
