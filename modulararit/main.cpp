#include <iostream>
#include <string>

using namespace std;

int main()
{
    string operation;
    string number1;
	string number2;
	string result1;
	string method; //integer arithmetic or modular arithmetic
	int radix;
	string mods;
	int r=0;
	char sign;
	int switchcase;
    cout << " Input the radix: ";
	cin>>radix;
	cout << " Input the operation: ";
	cin>>operation;
	cout << " Input the 1st number: ";
	cin>> number1;
	cout << " Input the 2nd number: ";
	cin>> number2;

        cout<<" Input the modulus: ";
        cin>>mods;

	int m=number1.size();
    int n=number2.size();
    int len=max(m,n);
    int* num1 = new int[ len ];
    int* num2 = new int[ len ];
    int k;
    int* result = new int[ 2*len ];
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

    //multiplication
    if (operation == "multiplication")
    {
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

        int var=mods.size();
        int* modn=new int [var]; //modulus put in an array


        for(int i=var-1,j=0; i>=0; i--,j++){
            if(mods[j]=='A'){
                modn[i]=10;
            }
            else if(mods[j]=='B'){
                modn[i]=11;
            }
            else if(mods[j]=='C'){
                modn[i]=12;
            }
            else if(mods[j]=='D'){
                modn[i]=13;
            }
            else if(mods[j]=='E'){
                modn[i]=14;
            }
            else if(mods[j]=='F'){
                modn[i]=15;
            }
            else
                modn[i] = mods[j]-48;
            }

        int l=0;
        int ll=0;

        if(k+1==var){
            int i;
            for(i=k; i>=0; i--){
                if(result[i]>modn[i]){
                    l=1; //it means the multiplication of the two numbers is bigger than the modulus
                    break;
                }
                else if (result[i]<modn[i]){
                    l=0;
                    break;
                }
                else if(result[i]==modn[i]){
                    ll++; //it means the multiplications of the two numbers is equal with the modulus
                }
            }

        }
        else if(k+1>var){ //if the length of the multiplication of the two numbers is bigger than the length of the modulus
            l=1;
        }


       if(ll==var){
            cout<<0; //result is equal with the modulus
        }

        else if (l==0){ //result is smaller than the modulus;

            for (int i=0; i<=k; i++){
                cout<<result1[i];
            }
        }
        else //result is bigger than the modulus
        {
            int len2=max(k+1,var);
            int* rez=new int [2*len2];
            for(int i=0;i<len2;i++){
                rez[i]=0;
            }
            k++;

            while (l==1){


                    r=0;
                    for(int i=0;i<k;i++){
                        rez[i]=result[i]-modn[i]-r;
                        if(rez[i]<0){
                            rez[i]=rez[i]+radix;
                            r=1;
                        }
                        else r=0;
                    }
                    while(k>=2 && rez[k-1]==0){
                        k=k-1;
                    }

                    for(int i=0; i<k; i++){
                        result[i]=rez[i];
                    }

                    /*for(int i=k-1,j=0; i>=0; i--,j++){

                        if(rez[i]==10){
                            result1[j]='A';
                        }
                        else if(rez[i]==11){
                            result1[j]='B';
                        }
                        else if(rez[i]==12){
                            result1[j]='C';
                        }
                        else if(rez[i]==13){
                            result1[j]='D';
                        }
                        else if(rez[i]==14){
                            result1[j]='E';
                        }
                        else if(rez[i]==15){
                            result1[j]='F';
                        }
                        else
                        result1[j] = rez[i]+48;
                    }*/

                    if (k<var){
                        l=0;
                    }
                    else if(k==var){
                            ll=0;
                        for(int i=k-1; i>=0; i--){
                            if(result[i]<modn[i]){
                                l=0; //it means the new result is smaller than the modulus
                                break;
                            }
                            else if(result[i]>modn[i]){
                                l=1;
                                break;
                            }
                            else if(result[i]==modn[i]){
                                ll++;
                            }
                        }
                        if(ll==var){
                            cout<<0;
                        }

                    }
                    for(int i=0;i<k;i++){
                        rez[i]=0;
                    }

            }

                    for(int i=k-1,j=0; i>=0; i--,j++){

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
                for(int i=0; i<k; i++){
                    cout<<result1[i];
            }
        }
    }
}
