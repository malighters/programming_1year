
#include <iostream>
#include <string>
using namespace std;


string contour(double param, double x, double y){ 
    if (x == param or y == param) {
        return "The point is located on the side of the square";
    }
    else
    if ((0 < x and x < param) and (0 < y and y < param)) {
        return "The point is located in the square";
    }
    else
    if ((x > param or x < param) or (y > param or y < param)) {
        return "The point is located outside the square";
    }
  
}


int main()
{
    double a, x, y;

    cout << "Please enter a parameter for countour:\n";
    cin >>  a;

    if (a <= 0) {
        cout << endl << "<<<WRONG PARAMETER>>>" << endl;
        exit(0);
    }
    
    cout << "And now enter the coordinates of point you wanna find(separated by space): ";
    cin >>  x >>  y;

    cout<< endl << contour(a, x, y) << endl;
    return 0;
}

