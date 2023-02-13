#include <iostream>

using namespace std;

int Factorial(int n){

    if(n == 1 || n==0){
        return 1;
    }else{
        return n*Factorial(n-1);
    }

}

int Combination(int n,int r){

    if(n==r){
        return 1;
    }

    return (Factorial(n))/((Factorial(n-r))*Factorial(r));

}

int main(){

    int n,r;
    cout << "Find the combination (-_-)" << endl;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Enter r: " << endl;
    cin >> r;
    cout << "Answer = " << Combination(n,r) << endl;
    return 0;
}