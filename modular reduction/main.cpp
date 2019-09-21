#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string number1;
	string number2;
	string result1;
    int b;//input to base 10 to see how algorithm works
    int k, n,xprime; //others
    int y;//result
    cout<<"give x : ";
    cin>>x;
    cout<<"give m : ";
    cin>>m;
    cout<<"give b : ";
    cin>>b;
    k=number1.size();
    n=number2.size();
    int* x = new int[ k ];
    int* m = new int[ n ];
    int* result = new int[ n ];
    for(int i=0,j=0;i<k,j<n;i++,j++){
        x[i]=0;
        m[j]=0;
    }

    //xprime=abs(x);
    for(int i=k-n;i>=0;i--){
        while(xprime>=m*pow(b,i)){
            xprime=xprime-m*pow(b,i);
        }
    }
    if(x>=0 || xprime==0){
        y=xprime;
    }
    else {
        y=m-xprime;
    }
    cout<<y;

}
