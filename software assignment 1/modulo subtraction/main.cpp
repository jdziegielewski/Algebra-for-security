    #include <iostream>

using namespace std;

int main()
{
  string m;//modulus
  string x;//x
  string y;//y
  string result1;//result
  int radix;
  cout << "\n\n Subtraction of two numbers:\n";
	cout << "-----------------------------------\n";
	cout << " Input the 1st number: ";
	cin>> x;
	cout << " Input the 2nd number: ";
	cin>> y;
	cout << " Input the modulo: ";
	cin>> m;
	cout << " Input the radix: ";
	cin>>radix;
    int r;
    int p=m.size();
    int k=x.size();
    int n=y.size();
    int len=p+1;
    int* num1 = new int[ len+1 ];
    int* num2 = new int[ len +1];
    int* modulo = new int[ len +1];
    int* zprime = new int [ len +1];
    int* result = new int [ len +1];
    char sign='+';
    for(int i=0;i<len;i++){
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
  for(int i=0;i<len+1;i++){
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
    for(int i=0;i<len;i++){

        cout<< result1[i]; //result reversed result1[i]
    }


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
        for(int i=0;i<len+1;i++){

        cout<< result1[i]; //result reversed result1[i]
    }
    }



