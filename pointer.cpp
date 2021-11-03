#include <iostream>
#include <new>
using namespace std;
int main(){
  int k=2;
  int *ptr;

  ptr=&k; //ptr gets the address of y
  cout << ptr << endl; //will print out the address
  cout << *ptr << endl; //2

  *ptr = 3 * *ptr+1;
  cout << k <<endl; //7
  cout << *ptr <<endl; //7
  
  return 0;

}
