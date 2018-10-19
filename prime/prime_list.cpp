#include <iostream.h>

int check_prime(int n)
{ int i,c;
  c=0;
  for(i=2; i<n; i++)
  { if (n%i!=0)
    {c=1;
    break;
    }
  }
  if (c==0)
  { cout<<n << '\n";}
}

void main()
{ int m;
  cout<< "enter limit:";
  cin>> m;
  
  for (j=2; j<m; j++)
  { check_prime(j);}
} 
 
