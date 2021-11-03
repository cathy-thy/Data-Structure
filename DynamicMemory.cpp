#include <iostream>
#include <new>
using namespace std;
int main(){
  /** Single item **/
  int *p; //pointer variable, allocated a memory space for storing an address
  p = new int; //operator new reserves a memory space that is big enough to store a value of type int
  *p = 10; //store 10 in the allocated space targeted by pointer

  /**If delete is used,
  1. cannot release a space that is not dynamically allocated by new
  2. delete will do nth if pointer is null**/
  delete p; //free space


  /** 1D array **/
  int *a;
  cin >> n;
  a=new int[n];
  for (i=0; i<n; i++)
    a[i]=i;
  delete []a;

  /** 2D array Method 1**/
  int **b;
  int row=10, col=4, i, j;

  b = new int *[row]; //each element is an int-pointer
  for (i =0; i<row; i++)
    b[i] = new int[col];

  for (i=0; i<row; i++)
    for (j=0; j<col; j++)
      foo[i][j]=j;

  //Free the space of each row
  for (i =0; i<row; i++)
    delete [] b[i];
  delete [] b; //finally, free the array of pointers

  /** 2D array Method 2**/
  int **c, *tmp;
  int row=10, col=4, i, j;

  c = new int *[row]; //each element is an int-pointer
  tmp = new int[row*col];
  for (i =0; i<row; i++)
    c[i] = &tmp[col*i];

  //Free the space
  delete [] tmp;
  delete [] foo;

}
