#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct coffee {
    string volume;
    string name;
    string cost;
};

int main() {

    vector<coffee> coffee; /*я створив вектор, що складається із структури 'кава', і просто хочу вивести його у вигляді прайс-листа*/
    coffee.push_back({"120ml", "ESPRESSO", "15hrn"});
    coffee.push_back({"350ml", "LATTE", "35hrn"});
    coffee.push_back({"410ml", "CAPPUCCINO", "40hrn"});
    coffee.push_back({"250ml", "ICED LATTE", "25hrn"});
    coffee.push_back({"320ml", "FLAT WHITE", "45hrn"});
    coffee.push_back({"150ml", "ESPRESSO MACCHIATO", "29hrn"});
    coffee.push_back({"170ml", "DOPPIO", "55hrn"});

    cout<<"Price:"<<endl;

    int i=0;  /*виведемо прайс за допомогою циклу*/
    while(i<7)
    {
          cout<<coffee[i].name<<" - "<<coffee[i].cost<<" - "<<coffee[i].volume<<endl;
          i++;
    }

    return 0;
}
