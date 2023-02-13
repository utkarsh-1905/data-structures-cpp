#include <iostream>

using namespace std;

int Factorial(int n){

    if(n == 1){
        return 1;
    }else{
        return n*Factorial(n-1);
    }

}

int main(){

    int num;
    cout << "Enter the number for which you want to find factorial: " << endl;
    cin >> num;
    cout << "Answer = " << Factorial(num) << endl;
    return 0;
}