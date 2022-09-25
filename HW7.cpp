#include <iostream>
using namespace std;
void swap_min(int *m[], unsigned rows, unsigned cols) {
    int min = m[0][0];
    int rowMin = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(m[i][j] < min){
                min = m[i][j];
                rowMin = i;
            }
        }
    }
    int *t = m[0];
    m[0] = m[rowMin];
    m[rowMin] = t;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout <<  m[i][j] << " ";
        }
        cout << endl;
    }

}


int main() {
    int rows, cols;
    cout << "Please enter the number of rows and cols:" << endl;
    cin >> rows >> cols;

    int ** m = new int *[rows];
    for( int i = 0; i < rows; ++i )
        m[i] = new int[cols];

    cout << "Now the array will filled by random numbers, then it will be displayed twice: before swapping and after"<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m[i][j] = rand() % 11;
            cout <<  m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    swap_min(m, rows, cols);

    for( int i = 0; i < rows; ++i )
        delete [] m[i];             // знищуються масиви цілих
    delete [] m;

    return 0;
}
