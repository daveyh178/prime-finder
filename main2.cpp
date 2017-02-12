#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
  using namespace std;
  template <typename T>
string to_string(T value)
  {
    std::ostringstream os ;
    os << value ;
    return os.str() ;
  }
ofstream out;
long f = 0;
long found = 0;
string filename = "primes"+to_string(f)+".txt";
int main(int argc, char ** argv){
  unsigned long long n = 1;
  long c = 0;
  out.open(filename.c_str());
  if (out.is_open()) {
    cout << "Running!!!" << endl;
    while (true){
      n+=2;
      bool p = true;
      for(unsigned long long i=2;i<n;i++){
        if(n%i==0){
          p=false;
        }
      }
      if(p){
        out << n << " ";
        c++;
        found++;
        if(c%500==0){if(c>1000000){c=0;}
          ifstream is;
          is.open (filename.c_str(), ios::binary );
          is.seekg (0, ios::end);
          int length = is.tellg();
          if(length>100000){
            f++;
            cout << "found : " << found << ", files : " << f << endl;
            filename = "primes"+to_string(f)+".txt";
            out.close();
            out.open(filename.c_str());
          }
        }
      }
    }
  }
  out.close();
  return 0;
}
