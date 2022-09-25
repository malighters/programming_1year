#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout << "Please enter the vector. The program will check if it is saw-numbers. If you want stop filling the vector, enter the number same as previous." << endl;
    int buffer;
    vector<int> vec;

    for (int i = 0; i < 2; i++) {
        cin >> buffer;
        vec.push_back(buffer);
    }

    {
        int i = 1;
        cin >> buffer;
        while (vec[i] != buffer) {
            vec.push_back(buffer);
            cin >> buffer;
            i++;
        };
    }

    int counter = 0, i = 2;
    while (i < vec.size()) {
        bool a = (vec[i - 2] < vec[i - 1] and vec[i] < vec[i - 1]);
        bool b = (vec[i - 2] > vec[i - 1] and vec[i] > vec[i - 1]);
        if (a or b) {
            counter++;
        }
        i++;
    }

    if (i == (counter + 2)) {
        cout << "This vector is a saw-numbers";
    }
    else {
        cout << "This vector is not a saw-numbers";
    }
    return 0;
}
