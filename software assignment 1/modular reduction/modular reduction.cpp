#include <iostream>
#include <math.h>

using namespace std;

int main()

{
    string number1;
    string number2;
	string y;
    int b;//input to base 10 to see how algorithm works
    int k, n;//others
    cin>>number1;
    cin>>number2;
    cout<<"give b : ";
    cin>>b;

    k=number1.size();
    n=number2.size();

    int* x = new int[ k ];
    int* m = new int[ n ];
    int* result = new int[ n*n ];

    int sign=0;//if the number is positive

    if(number1[0]=='-'){
        number1.erase(0,1);
        sign=1;//if the number is negative
        k--;
    }


    for(int i=0; i<k;i++){
        x[i]=0;
    }
        for(int j=0;j<n;j++){
        m[j]=0;
    }

    for(int i=k-1,j=0; i>=0; i--,j++){

            if(number1[j]=='A'){
                x[i]=10;
            }
            else if(number1[j]=='B'){
                x[i]=11;
            }
            else if(number1[j]=='C'){
                x[i]=12;
            }
            else if(number1[j]=='D'){
                x[i]=13;
            }
            else if(number1[j]=='E'){
                x[i]=14;
            }
            else if(number1[j]=='F'){
                x[i]=15;
            }
            else
            x[i] = number1[j]-48;


    }
     for(int i=n-1,j=0; i>=0; i--,j++){

            if(number2[j]=='A'){
                m[i]=10;
            }
            else if(number2[j]=='B'){
                m[i]=11;
            }
            else if(number2[j]=='C'){
                m[i]=12;
            }
            else if(number2[j]=='D'){
                m[i]=13;
            }
            else if(number2[j]=='E'){
                m[i]=14;
            }
            else if(number2[j]=='F'){
                m[i]=15;
            }
            else
            m[i] = number2[j]-48;

    }


    //xprime=abs(x);
    for(int i=k-n;i>=0;i--){
            int kk; //length of the multiplication
            int jj=i-1;
            int prod=b;
            //b to the power of i
            while (jj>0){
                prod=prod*b;
                jj--;
                cout<<1;
            }
            int prod2=prod;
            int len=0;
            while(prod2>0){
                len++;
                prod2=prod2/10;
                cout<<2;
            }
            prod2=prod;
            int* product=new int[len];
            for (int ii=len-1; ii>=0; ii--){
                product[ii]=prod%10;
                prod=prod/10;
            }
        int t;
        for (int ii=0; ii<len+n-1; ii++)
        {
            result[ii]=0;
        }
        for (int ii=0; ii<n; ii++)
        {
            int r=0;
            for (int j=0; j<len; j++)
            {
                t=result[ii+j]+m[ii]*product[j]+r;
                r=t/b;
                result[ii+j]=t-r*b;
            }
            result[ii+len]=r;
        }
        if (result[len+n-1]==0)
        {
            kk=len+n-2;//length of the product
        }
        else
        {
            kk=len+n-1;//length of the product
        }
        int l=0;
        if(k>kk){
            l=1;//length of x is bigger than length of the product
        }
        else if(k<kk){
            //cout the number i think in a string
        }
        if(k==kk){
            for (int ii=k-1; ii>=0; ii--){
                if(x[ii]>result[ii])
                {
                    l=1;
                    break;
                }
            }
        }

        int* rez=new int[k];
            while (l==1){
                  int r=0;
                    for(int ii=0;ii<k;ii++){
                        rez[ii]=x[ii]-result[ii]-r;
                        if(rez[ii]<0){
                            rez[ii]=rez[ii]+b;
                            r=1;
                        }
                        else r=0;
                    }
                    while(k>=2 && rez[k-1]==0){
                        k=k-1;
                    }
                    for(int jj=0; jj<k; jj++){
                        x[jj]=rez[jj];
                    }
                    if(k==kk){
                        for (int ii=k-1; ii>=0; ii--){
                            if(x[ii]<result[ii])
                            {
                                l=0;
                                break;
                            }
                            if(x[ii]>result[ii]){
                                l=1;
                                break;
                            }
                            
                        }
                    }
                    else if(k<kk){
                        l=0;
                    }
                    
        }
       
    }

     int v=0; //variable to check if x'is 0;
     for(int i=0; i<k; i++){
        if(x[i]==0){
            v++;
        }
        cout<<14;
     }
     int* rez=new int[k];
     int* yy = new int[k];
     if(sign==0 || v==k){
        for(int i=0; i<k; i++){
            yy[i]=x[i];
        
        }
     }
     else {
        int r=0;
        for(int ii=0;ii<k;ii++){
            rez[ii]=m[ii]-x[ii]-r;
            if(rez[ii]<0){
                rez[ii]=rez[ii]+b;
                r=1;
            }
            else r=0;
            
        }
        while(k>=2 && rez[k-1]==0){
            k=k-1;
        
        }
        for(int i=0; i<k; i++){
            yy[i]=rez[i];
        
     }

    }
     for(int i=k-1,j=0; i>=0; i--,j++){

            if(yy[i]==10){
                y[j]='A';
            }
            else if(yy[i]==11){
                y[j]='B';
            }
            else if(yy[i]==12){
                y[j]='C';
            }
            else if(yy[i]==13){
                y[j]='D';
            }
            else if(yy[i]==14){
                y[j]='E';
            }
            else if(yy[i]==15){
                y[j]='F';
            }
            else
            y[j] = yy[i]+48;
        }
    for(int i=0; i<k; i++){
        cout<<y[i];

    }



}
