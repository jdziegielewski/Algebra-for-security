#include <iostream>

using namespace std;

int main()
{
    string number1;
	string number2;
	string result1;
	int radix;
	int r=0;
    cout << "\n\n Subtraction of two numbers:\n";
	cout << "-----------------------------------\n";
	cout << " Input the 1st number: ";
	cin>> number1;
	cout << " Input the 2nd number: ";
	cin>> number2;
	cout << " Input the radix: ";
	cin>>radix;
    int m=number1.size();
    int n=number2.size();
    int len=max(m,n);
    int* num1 = new int[ len ];
    int* num2 = new int[ len ];
    int k;
    int* result = new int[ len ];
    for(int i=0;i<len;i++){
        num1[i]=0;
        num2[i]=0;
    }

    for(int i=m-1,j=0; i>=0; i--,j++){

            if(number1[j]=='A'){
                num1[i]=10;
            }
            else if(number1[j]=='B'){
                num1[i]=11;
            }
            else if(number1[j]=='C'){
                num1[i]=12;
            }
            else if(number1[j]=='D'){
                num1[i]=13;
            }
            else if(number1[j]=='E'){
                num1[i]=14;
            }
            else if(number1[j]=='F'){
                num1[i]=15;
            }
            else
            num1[i] = number1[j]-48;


    }
     for(int i=n-1,j=0; i>=0; i--,j++){

            if(number2[j]=='A'){
                num2[i]=10;
            }
            else if(number2[j]=='B'){
                num2[i]=11;
            }
            else if(number2[j]=='C'){
                num2[i]=12;
            }
            else if(number2[j]=='D'){
                num2[i]=13;
            }
            else if(number2[j]=='E'){
                num2[i]=14;
            }
            else if(number2[j]=='F'){
                num2[i]=15;
            }
            else
            num2[i] = number2[j]-48;


    }

    for(int i=0;i<len;i++){
        result[i]=num1[i]-num2[i]-r;
        if(result[i]<0){
            result[i]=result[i]+radix;
            r=1;
        }
        else r=0;
    }
    k=m;
    while(k>=2 && result[k-1]==0){
        k=k-1;
    }

    for(int i=len-1,j=0; i>=0; i--,j++){

            if(result[i]==10){
                result1[j]='A';
            }
            else if(result[i]==11){
                result1[j]='B';
            }
            else if(result[i]==12){
                result1[j]='C';
            }
            else if(result[i]==13){
                result1[j]='D';
            }
            else if(result[i]==14){
                result1[j]='E';
            }
            else if(result[i]==15){
                result1[j]='F';
            }
            else
            result1[j] = result[i]+48;


    }

     cout<<"\n";
         for(int i=0;i<len;i++){
        cout<< result1[i]; //result reversed result1[i]
    }

}
