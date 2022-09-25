#include <iostream>
#include <vector>
#include <string>

using namespace std;

int limit;
vector<string> elems;

void function(vector<string>& elems1, int limit1)
{
    string max1 = "0", max2 = "0";

    for (int i = 0; i < elems1.size(); i++)
    {
        if (elems1[i].length() > max1.length()) {
            max2 = max1;
            max1 = elems1[i];
        }

    }

    string min1 = max1, min2;

    for (int i = 0; i < elems1.size(); i++)
    {
        if (elems1[i].length() <= min1.length()) {
            min2 = min1;
            min1 = elems1[i];
        }

    }

    int str_lengths = max1.length() + max2.length();

    if (str_lengths > limit) {
        elems1.push_back(min2 + min1);
        cout << "Because of lengths of two max elements is bigger than limit, there will be added new element" << endl;
    }
    
}




int main()
{
    cout << "Please the limit (integer): ";
    cin >> limit;
    cout << "Please enter the array of string(if you wanna stop entering the array, enter zero): " << endl;
    string a;
    do {
        cin >> a;
        elems.push_back(a);
        if (a == "0") {
            elems.pop_back();
        }
    } while (a != "0");

    function(elems, limit);

    cout << endl << "Just now the vector will be showed:" << endl;

    for (int i = 0; i < elems.size(); i++)
    {
        cout << elems[i] << endl;
    }

    return 0;
}