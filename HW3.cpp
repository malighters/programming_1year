#include <iostream>
#include <vector>

using namespace std;

//реалізовано підтримку переведення натуральних чисел з основою 10 у числа з основою від 1 до 20
int main() {

    vector<char> whole;
    vector<char> fractional;
    int base;
    int number;
    cout<<"Please enter the base(0<base<=20) and then the number(with base 10)"<<endl;
    cin>>base>>number;
    char buffer;
    int buffer1;
    do{
        buffer1=number % base;
        if(buffer1<10){
            buffer = '0'+buffer1;}
        else
            {buffer = '7'+buffer1;}
        whole.push_back(buffer);
        number = (number-buffer1) / base;
    }while(number !=0 );

    int size=whole.size();
    cout<<endl<<"Your number is ";
    for(int i = size-1;i>=0;i--)
    {
        cout<<whole[i];
    }
    cout<<" with the base "<<base;



    return 0;
}
