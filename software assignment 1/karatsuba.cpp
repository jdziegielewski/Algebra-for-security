#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int b;
char x[1000], y[1000], z[1000];

void addition (char x[1000], char y[1000], int b, char z[1000])
{
    int r = 0;
    for (int i=strlen(x)-1;i>=0;i--)
    {
        int m = x[i] - '0';
        int n = y[i] - '0';
        if (m>9)
            m = m-7;
        if (n>9)
            n=n-7;
        int s = m+n+r;
        if (s>b)
        {
            s = s-b;
            r = 1;
        }
        if (s<10)
            z[i] = s +'0';
        else
            if (s==10)
            z[i]='A';
        else
            if (s==11)
            z[i]='B';
        else
            if (s==12)
            z[i]='C';
        else
            if(s==13)
            z[i]='D';
        else
            if (s==14)
            z[i]='E';
        else
            if (s==15)
            z[i]='F';

    }
}

void equalLength (char a[1000], char b[1000])
{
    int n = strlen(a);
    int m = strlen(b);


    if (n>m)
    {

       char c[1000];
       int h=0;
       for (int i =m-1; i>=0;i--)
       {
           c[h]=b[i];
           h++;
       }
       h++;
       c[h]=NULL;

        int k = m;

        for (int i =0; i<n-m; i++)
        {
            c[k]='0';
            k++;
        }
        k++;
        c[k]= NULL;

        int j=0;
        for (int i = strlen(c)-1;i>=0;i--)
        {
            b[j]=c[i];
            j++;

        }
        j++;
        b[j]=NULL;


    }
 else
     if (n<m)
    {
        char c[1000];
       int h=0;
       for (int i =n-1; i>=0;i--)
       {
           c[h]=a[i];
           h++;
       }
       h++;
       c[h]=NULL;

        int k = n;
        for (int i =0; i<m-n; i++)
        {
            c[k]='0';
            k++;
        }
        k++;
        c[k]= NULL;

        int j=0;
        for (int i = strlen(c)-1;i>=0;i--)
        {
            a[j]=c[i];
            j++;

        }
        j++;
        a[j]=NULL;
    }
}

int oneFigureMultiplication (char m, char n, int base)

{
   int x = m - '0' ;
   int y = n - '0';
   int p = x*y ;
 return p;

}



int karatsubaMultiplication (char x[], char y[], int b)
{
    int n = strlen(x);
    int m = strlen(y);
    if (n==1 && n==m)
    {
        char a = x[0];
        char c = y[0];
        int p = oneFigureMultiplication (a,c,b);
        return p;
    }

    else
    {


    char xLeft [1000], yLeft[1000], xRight[1000], yRight[1000];

    equalLength(x,y);

    n = strlen(x);

    int k = -1;
    for (int i=0; i<=n/2-1; i++ )
    {
        k++;
        xLeft[k]=x[i];
    }
    k++;
    xLeft[k]=NULL;

      k = -1;
    for (int i=0; i<=n/2-1; i++ )
    {
        k++;
        yLeft[k]=y[i];
    }
    k++;
    yLeft[k]=NULL;

     k = -1;
    for (int i=n/2; i<n;i++)
    {
         k++;
        xRight[k]=x[i];
    }
    k++;
    xRight[k]=NULL;

     k = -1;
    for (int i=n/2; i<n;i++)
    {
         k++;
        yRight[k]=y[i];
    }
    k++;
    yRight[k]=NULL;

  int p1 = karatsubaMultiplication (xRight, yRight, b);
  int p2  = karatsubaMultiplication (xLeft, yLeft, b);
  char v[1000],w[1000];
  addition (xLeft,xRight,b,v);
  addition (yLeft,yRight,b,v);
  int p3 = karatsubaMultiplication (v,w,b);
  int q = 1;

  for (int i=1; i<=n/2;i++)
  int q = q*10;

  int g = q*q;
  return g*p2 + q*(p3-p2-p1) + p1;


    }




}



int main()
{
    cin >>x>>y>>b;

     addition(x,y,b,z);


   cout<<z;






    return 0;
}
