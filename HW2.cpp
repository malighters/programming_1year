#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    int i,j=10;
    string max="0";
    vector<string> numbers(100);


    for (i=0;i<5;i++){
        cout<<"Please enter number, which has index "<<i+1<<", in array:"<<endl;
        cin>>numbers[i];
        if(numbers[i]>=max){
            max = numbers[i];
        }
    }

    cout<<"The max number is:"<<max<<endl<<"Please enter some more numbers(if this number is equal to the max, the program will stop):";

    while(max != numbers[j-1]){
        cin>>numbers[j];
        if(numbers[j]>=max){
            max = numbers[j];
        }
        j++;
    }
    cout<<"Now the max element is "<<max<<"."<<endl<< "The program will close.";
    return 0;
}
