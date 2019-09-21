#include <iostream>
#include <fstream.h>
using namespace std;

int main()
{
    do{
    string arithmetic;
    int whicharithmetic;
    cout<<"\n";
    cout << " Input the arithmetic: ";
	cin>>arithmetic;

    if(arithmetic=="integer"){
        whicharithmetic=1;
    }
    else if(arithmetic=="modular"){
        whicharithmetic=2;
    }
    //depending which arithmetic user have chosen the program will wait for 3 or 4 inputs
    switch(whicharithmetic) {
        case 1: {
    string operation; //type of operation (addition or subtraction or multiplication or karatsuba
    string number1; //x variable
	string number2; //y variable
	string result1; //result
	int radix; //radix of numbers
	int r=0; // carry (remainder)
	char sign='+'; //sign of a number, made + by default
	int switchcase;
	cout <<"[radix] : ";
	cin>>radix;
	cin>>operation;
	cout <<'['+ operation +']'<<endl;
	cout << " [x] : ";
	cin>> number1;
	cout << " [y] : ";
	cin>> number2;

	// checking the signs of the number and applying correct operation to each case


	if(number1[0]=='-' && number2[0]=='-' && operation=="addition"){ //addition of 2 negative numbers
        number1.erase(0,1);
        number2.erase(0,1);
        cout<<number1[0];
        sign='-';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]=='-' && operation=="subtraction"){ //subtraction of 2 negative numbers
        number1[0]='0';
        number2[0]='0';
        sign='-';
        operation="subtraction";
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="addition"){ //addition of positive x and negative y
        number2.erase(0,1);
        sign='+';
        operation="subtraction";
	}
    if(number1[0]=='-' && number2[0]!='-' && operation=="addition"){ //addition of negative x and positive y
        number1.erase(0,1);
        string temp = number1;
        number1=number2;
        number2=temp;
        sign='+';
        operation="subtraction";
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="subtraction"){ //subtraction of positive x and negative y
        number2.erase(0,1);
        sign='+';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]!='-' && operation=="subtraction"){ //subtraction of negative x and positive y
        sign='-';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]!='-' && operation=="multiplication"){ //multiplication of negative x and positive y
        number1.erase(0,1);
        sign='-';	cout << " Input the radix: ";
	cin>>radix;
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="multiplication"){ //multiplication of positive x and negative y
        number2.erase(0,1);
        sign='-';
	}
	if(number1[0]=='-' && number2[0]=='-' && operation=="multiplication"){ //multiplication of 2 negative numbers
        number1.erase(0,1);
        number2.erase(0,1);
        sign='+';
	}
	//program works for all other cases : addition of 2 positive numbers, subtraction of positive y from larger positive x,
    //,subtraction of positive y from smaller positive x, multiplication of 2 positive numbers
	int m=number1.size(); // x word length
    int n=number2.size(); // y word length
    int len=max(m,n); // which is grater
    // declaring arrays of int to compute the operations
    int* num1 = new int[ len ];
    int* num2 = new int[ len ];
    int k; // to change the size of array result
    int* result = new int[ len ];
    for(int i=0;i<len;i++){ //first fitting the arrays with 0's so if the numbers are different in word size the operation will be held
        num1[i]=0;
        num2[i]=0;
    }
//reversing the strings to arrays of int for x and y
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
// needed if's because switch case does not work with strings
if(operation=="addition"){
    switchcase=1;
}
else if(operation=="subtraction"){
    switchcase=2;
}
else if(operation=="multiplication"){
    switchcase=3;
}
 switch(switchcase) {
      case 1 : { //addition algorithm
          for(int i=0;i<len;i++){
        result[i]=num1[i]+num2[i]+r;
        if(result[i]>=radix){
            result[i]=result[i]-radix;
            r=1;
        }
        else r=0;
}
      for(int i=len-1,j=0; i>=0; i--,j++){ //reversing the array of int to string

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


    } // outputting the answer
        cout<<"[answer] : ";
        if(sign=='-'){
        cout<<sign;}
        if(r==1){
            cout<<r;
        }
         for(int i=0;i<len;i++){
        cout<< result1[i];
    }

         break;
      }
      case 2 : { // subtraction
          //checking which number is larger and applying correct cases
        if(sign=='+'){ //case when 2 numbers are positive
            for(int i=len-1; i>=0; i--){
                if(num1[i]>num2[i]){
                    break;
                }
                else if (num1[i]<num2[i]){//case when we should reverse the numbers
                    std::swap(num1, num2);
                sign='+';
                break;
            }

          }
          }
          else { //case when 2 numbers are negative
                        for(int i=len-1; i>=0; i--){
                if(num1[i]>num2[i]){
                        sign='-';
                    break;
                }
                else if (num1[i]<num2[i]){//case when we should reverse the numbers
                    std::swap(num1, num2);
                sign='+';
                break;
            }

          }
          }
              for(int i=0;i<len;i++){ // algorithm for subtraction
        result[i]=num1[i]-num2[i]-r;
        if(result[i]<0){
            result[i]=result[i]+radix;
            r=1;
        }
        else r=0;
    }


    for(int i=len-1,j=0; i>=0; i--,j++){ //reversing the array of int to string

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
            // outputting the answer
     cout<<"[answer] : ";
     if(sign=='-'){
        cout<<sign;}
    int a=-1;
    for(int i=0;i<len;i++){
        if(result1[i]=='0'){
            a++;
        }
        if(a!=i){
        cout<< result1[i]; //result reversed result1[i]
    }
    }
         break;
    }


      case 3: { //multiplication
        int t;
	int countadd=0;
        int countmul=0;
        for (int i=0; i<m+n-1; i++)
        {
            result[i]=0;
        }
        for (int i=0; i<m; i++) //multiplication algorithm
        {
            r=0;
            for (int j=0; j<n; j++)
            {
                t=result[i+j]+num1[i]*num2[j]+r;
                r=t/radix;
                result[i+j]=t-r*radix;
		countmul++;
            }
            result[i+n]=r;
	    countadd++;
        }
        if (result[m+n-1]==0)
        {
            k=m+n-2;
        }
        else
        {
            k=m+n-1;
        }
        for(int i=k,j=0; i>=0; i--,j++){ //reversing the array of int to string

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
        //// outputting the answer
        cout<<"[answer] : ";
        if (sign=='-'){
            cout<<sign;}
        for(int i=0;i<=k;i++){
        cout<< result1[i];
        }

	cout<<endl<<"The number of additions is: "<<countadd<<endl; //number of additions in multiplication algorithm
        cout<<"The number of multiplications is: "<<countmul; //number of multiplications in multiplication algorithm
        break;

   }
}
    break;
    }

    //modular arithmetics

      case 2: {
    string operation1;
    string m;//modulus
    string x;//x
    string y;//y
    string result1;//result
    int radix;
    cout << " Input the radix: ";
	cin>>radix;
	cout<<"Operation :";
	cin>>operation1;
	cout << " Input the 1st number: ";
	cin>> x;
	cout << " Input the 2nd number: ";
	cin>> y;
	cout << " Input the modulo: ";
	cin>> m;
    int r; //carry (remainder)
    char sign='+';
    int p=m.size(); //word length of m,x,y;
    int k=x.size();
    int n=y.size();
    int len=p+1; //p+1 because of addition
    // declaring arrays of int to compute the operations
    int* num1 = new int[ len +1];
    int* num2 = new int[ len +1];
    int* modulo = new int[ len +1];
    int* zprime = new int [ len +1];
    int* result = new int [ len+1 ];

    for(int i=0;i<len+1;i++){ //first fitting the arrays with 0's so if the numbers are different in word size the operation will be held
        num1[i]=0;
        num2[i]=0;
        modulo[i]=0;
    }
//reversing the strings to arrays of int for x and y and m
    for(int i=k-1,j=0; i>=0; i--,j++){

            if(x[j]=='A'){
                num1[i]=10;
            }
            else if(x[j]=='B'){
                num1[i]=11;
            }
            else if(x[j]=='C') {
                num1[i]=12;
            }
            else if(x[j]=='D'){
                num1[i]=13;
            }
            else if(x[j]=='E'){
                num1[i]=14;
            }
            else if(x[j]=='F'){
                num1[i]=15;
            }
            else
            num1[i] = x[j]-48;


    }
     for(int i=n-1,j=0; i>=0; i--,j++){

            if(y[j]=='A'){
                num2[i]=10;
            }
            else if(y[j]=='B'){
                num2[i]=11;
            }
            else if(y[j]=='C'){
                num2[i]=12;
            }
            else if(y[j]=='D'){
                num2[i]=13;
            }
            else if(y[j]=='E'){
                num2[i]=14;
            }
            else if(y[j]=='F'){
                num2[i]=15;
            }
            else
            num2[i] = y[j]-48;

    }
         for(int i=p-1,j=0; i>=0; i--,j++){

            if(m[j]=='A'){
                modulo[i]=10;
            }
            else if(m[j]=='B'){
                modulo[i]=11;
            }
            else if(m[j]=='C'){
                modulo[i]=12;
            }
            else if(m[j]=='D'){
                modulo[i]=13;
            }
            else if(m[j]=='E'){
                modulo[i]=14;
            }
            else if(m[j]=='F'){
                modulo[i]=15;
            }
            else
            modulo[i] = m[j]-48;

    }
    //now x,y,m are reversed
    // needed if's because switch case does not work with strings
    int opr;
    if(operation1=="addition"){
        opr=1;
    }
    else if(operation1=="subtraction"){
        opr=2;
    }
switch(opr){
case 1: { // modular addition algorithm
    for(int i=0;i<len+1;i++){
        zprime[i]=num1[i]+num2[i]+r;
        if(zprime[i]>=radix){
            zprime[i]=zprime[i]-radix;
            r=1;
        }
        else r=0;
}
if(r==1){
    zprime[len]=1;
}

//check which is bigger
bool smaller;
     for(int i=len; i>=0; i--){
            if(modulo[i]>zprime[i]){
                smaller=true;
                break;
            }
            else if (modulo[i]<zprime[i]){//case when we integer

                smaller=false;
                break;
            }

          }

if(smaller==true){
   for(int i=0;i<len+1;i++){
        result[i]=zprime[i];
   }
}
else if(smaller==false){
    r=0;
    for(int i=0;i<len+1;i++){
        result[i]=zprime[i]-modulo[i]-r;
        if(result[i]<0){
            result[i]=result[i]+radix;
            r=1;
        }
        else r=0;
    }

}
  for(int i=len,j=0; i>=0; i--,j++){ //reversing the array of int to string

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
    // outputting the answer
    int c=-1;
    cout<<"[answer] : ";
    for(int i=0;i<len+1;i++){

            if(result1[i]=='0'){
                    c++;
            }
            if(c!=i){
        cout<< result1[i];
    }
    }

    break;
}//end mod add case
case 2: { // modular subtraction
 for(int i=len; i>=0; i--){
            if(num1[i]>num2[i]){
                break;
            }
            else if (num1[i]<num2[i]){//case when we should reverse the numbers
           std::swap(num1, num2);
                sign='-';
                break;
            }

          }
  for(int i=0;i<len+1;i++){ // algorithm for subtraction (mod m)
        zprime[i]=num1[i]-num2[i]-r;
        if(zprime[i]<0){
            zprime[i]=zprime[i]+radix;
            r=1;
        }
        else r=0;
    }


//check which is bigger
bool smaller;
            if(sign=='+'){
                smaller=true;
            }
            else smaller=false;


if(smaller==true){
   for(int i=0;i<len+1;i++){
        result[i]=zprime[i];
   }
}
else{
    r=0;
    for(int i=0;i<len+1;i++){
        result[i]=modulo[i]-zprime[i]-r;
        if(result[i]<0){
            result[i]=result[i]+radix;
            r=1;
        }
        else r=0;
    }

}
  for(int i=len,j=0; i>=0; i--,j++){ //reversing the array of int to string

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
    // outputting the answer
    int c=-1;
    cout<<"[answer] : ";
    for(int i=0;i<len+1;i++){

            if(result1[i]=='0'){
                    c++;
            }
            if(c!=i){
        cout<< result1[i];
    }
    }
}
}
//step 1.1

      }//end of modular case

      }//end of integer / modular switch case






    }while(cin.get() == '\n');
}
