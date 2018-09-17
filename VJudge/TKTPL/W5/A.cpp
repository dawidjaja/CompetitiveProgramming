// Simple C++ program to multiply two polynomials
#include <iostream>
using namespace std;
 
// A[] represents coefficients of first polynomial
// B[] represents coefficients of second polynomial
// m and n are sizes of A[] and B[] respectively
long long *multiply(long long A[], long long B[], long long m, long long n)
{
   long long *prod = new long long[m+n-1];
 
   // Initialize the porduct polynomial
   for (long long i = 0; i<m+n-1; i++)
     prod[i] = 0;
 
   // Multiply two polynomials term by term
 
   // Take ever term of first polynomial
   for (long long i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (long long j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
 
   return prod;
}
 
// A utility function to print a polynomial
void printPoly(long long poly[], long long n)
{
    for (long long i=0; i<n; i++)
    {
       cout << poly[i];
       // if (i != 0)
       //  cout << "x^" << i ;
       if (i != n-1)
       cout << " ";
    }
}
 
// Driver program to test above functions
int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    // long long A[] = {5, 0, 10, 6};
 
    // The following array represents polynomial 1 + 2x + 4x^2
    // long long B[] = {1, 2, 4};
    long long t;
    scanf("%lld", &t);
    while(t--) {
      long long n;
      scanf("%lld", &n);
      n++;
      long long A[n], B[n];
      for(long long i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
      }
      for(long long i = 0; i < n; i++) {
        scanf("%lld", &B[i]);
      }
      // long long m = sizeof(A)/sizeof(A[0]);
      // long long n = sizeof(B)/sizeof(B[0]);

   
      // cout << "First polynomial is n";
      // printPoly(A, n);
      // cout << endl;
      // cout << "nSecond polynomial is n";
      // printPoly(B, n);
      // cout << endl;
   
      long long *prod = multiply(A, B, n, n);
   
      // cout << "nProduct polynomial is n";
      printPoly(prod, n+n-1);
      cout << endl;
    }

 
    return 0;
}