#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    string number1;
	string number2;
	string result1;
	int B; //b = radix
    cout << " Input the radix: ";
	cin>>B;
	cout << " Input the 1st number: ";
	cin>> number1;
	cout << " Input the 2nd number: ";
	cin>> number2;

	int k = number1.length();//length of first number
	int l = number2.length();//length of second number

    //we initiate the arrays in which we store the characters of the strings
	int* num1 = new int[ k ];
    int* num2 = new int[ l ];

    int* r = new int[ k ]; //remainder array
    int* q = new int[ k - l ]; //quotient array
    int c;//carry variable
    int tmp;

    //fill arrays with 0s
    for(int i=0;i<k;i++){
        num1[i]=0;
    }

    for(int i=0;i<l;i++){
        num2[i]=0;
    }

	//translate the first string into an array
	for(int i=k-1,j=0; i>=0; i--,j++){

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

    //translate second string into array
    for(int i=l-1,j=0; i>=0; i--,j++){

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

    //start of algorithm
    for (int i = 0; i <= k-1; i++) {
        r[i] = num1[i];
    }
    r[k] = 0;

    for (int i = k - l; i >= 0; i--) {
        q[i] = (r[i+l]* B + r[i+l-1])/num2[l-1]; //compute every element of the quotient array

        if (q[i] >= B) {//reduce the element of the quotient array
            q[i] = B - 1;
        }

        c = 0;
        for (int j = 0; j <= l-1; j++) {
            tmp = r[i+j] + num2[i] + c;
            c = tmp/B;
            r[i+j] = tmp%B;
        }
        r[i+l] = r[i+l] + c;

        while (r[i+l] < 0) {//if r[i+l] is negative, then q[i] is too large, in lines 111 - 119 this condition is corrected
            c = 0;
            for (int j = 0; j <= l-1; j++) {
                tmp = r[i+j] + num2[i] + c;
                c = tmp/B;
                r[i+j] = tmp%B;
            }
            r[i+l] = r[i+l] + c;
            q[i] = q[i] - 1;
        }
    }

    cout<<"Quotient: ";
    for (int i = k-l; i>=0; i--) {
        cout<<q[i];
	}

	cout<<endl;

	cout<<"Remainder: ";
	for (int i = l-1; i>=0; i--) {
        cout<<r[i];
	}

}
