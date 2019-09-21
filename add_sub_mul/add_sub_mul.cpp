#include <iostream>

using namespace std;

int main()
{
    string arithmetic;
    int whicharithmetic;
    cout << " Input the arithmetic: ";
	cin>>arithmetic;

    if(arithmetic=="integer"){
        whicharithmetic=1;
    }
    else if(arithmetic=="modular"){
        whicharithmetic=2;
    }
    switch(whicharithmetic) {
        case 1: {
            string operation;
    string number1;
	string number2;
	string result1;
	int radix;
	int r=0;
	char sign='+';
	int switchcase;
    cout << " Input the radix: ";
	cin>>radix;
	cout << " Input the operation: ";
	cin>>operation;
	cout << " Input the 1st number: ";
	cin>> number1;
	cout << " Input the 2nd number: ";
	cin>> number2;

	//checking th

	if(number1[0]=='-' && number2[0]=='-' && operation=="addition"){ //case 3
        number1.erase(0,1);
        number2.erase(0,1);
        cout<<number1[0];
        sign='-';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]=='-' && operation=="subtraction"){ //case 7
        number1[0]='0';
        number2[0]='0';
        sign='-';
        operation="subtraction";
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="addition"){ //case 2a
        number2.erase(0,1);
        sign='+';
        operation="subtraction";
	}
    if(number1[0]=='-' && number2[0]!='-' && operation=="addition"){ //case 2b
        number1.erase(0,1);
        string temp = number1;
        number1=number2;
        number2=temp;
        sign='+';
        operation="subtraction";
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="subtraction"){ //case6a
        number2.erase(0,1);
        sign='+';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]!='-' && operation=="subtraction"){ //case6b
        number1.erase(0,1);
        sign='-';
        operation="addition";
	}
	if(number1[0]=='-' && number2[0]!='-' && operation=="multiplication"){
        number1.erase(0,1);
        sign='-';
	}
	if(number1[0]!='-' && number2[0]=='-' && operation=="multiplication"){
        number2.erase(0,1);
        sign='-';
	}
	if(number1[0]=='-' && number2[0]=='-' && operation=="multiplication"){
        number1.erase(0,1);
        number2.erase(0,1);
        sign='+';
	}

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
      case 1 : {
          for(int i=0;i<len;i++){
        result[i]=num1[i]+num2[i]+r;
        if(result[i]>=radix){
            result[i]=result[i]-radix;
            r=1;
        }
        else r=0;
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
        if(sign=='-'){
        cout<<sign;}
        if(r==1){
            cout<<r;
        }
         for(int i=0;i<len;i++){
        cout<< result1[i]; //result reversed result1[i]
    }
         break;
      }
      case 2 : {
               for(int i=len-1; i>=0; i--){
            if(num1[i]>num2[i]){
                break;
            }
            else if (num1[i]<num2[i]){//case when we should reverse the numbers
           std::swap(num1, num2);
                sign='-';
                break;
            }

          }

              for(int i=0;i<len;i++){
        result[i]=num1[i]-num2[i]-r;
        if(result[i]<0){
            result[i]=result[i]+radix;
            r=1;
        }
        else r=0;
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


      case 3: {
        int t;
        for (int i=0; i<m+n-1; i++)
        {
            result[i]=0;
        }
        for (int i=0; i<m; i++)
        {
            r=0;
            for (int j=0; j<n; j++)
            {
                t=result[i+j]+num1[i]*num2[j]+r;
                r=t/radix;
                result[i+j]=t-r*radix;
            }
            result[i+n]=r;
        }
        if (result[m+n-1]==0)
        {
            k=m+n-2;
        }
        else
        {
            k=m+n-1;
        }
        for(int i=k,j=0; i>=0; i--,j++){

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
        if (sign=='-'){
            cout<<sign;}
        for(int i=0;i<=k;i++){
        cout<< result1[i];
        }
        break;

   }
}

    }
      case 2: {
      string m;//modulus
  string x;//x
  string y;//y
  string result1;//result
  int radix;
  cout << "\n\n Modular addition:\n";
	cout << "-----------------------------------\n";
	cout << " Input the 1st number: ";
	cin>> x;
	cout << " Input the 2nd number: ";
	cin>> y;
	cout << " Input the modulo: ";
	cin>> m;
	cout << " Input the radix: ";
	cin>>radix;
  int r;arithmetic
    int p=m.size();
    int k=x.size();
    int n=y.size();
    int len=p+1;
    int* num1 = new int[ len +1];
    int* num2 = new int[ len +1];
    int* modulo = new int[ len +1];
    int* zprime = new int [ len +1];
    int* result = new int [ len+1 ];

    for(int i=0;i<len+1;i++){
        num1[i]=0;
        num2[i]=0;
        modulo[i]=0;
    }

    for(int i=k-1,j=0; i>=0; i--,j++){

            if(x[j]=='A'){
                num1[i]=10;
            }
            else if(x[j]=='B'){
                num1[i]=11;
            }
            else if(x[j]=='C'){
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

//step 1.1
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
            else if (modulo[i]<zprime[i]){//case when we should reverse the numbers
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
  for(int i=len,j=0; i>=0; i--,j++){

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
    int c=-1;
    for(int i=0;i<len+1;i++){

            if(result[i]==0){
                    c++;
            }
            if(c!=i){
        cout<< result1[i]; //result reversed result1[i]
    }
    }
      }

    }





}
