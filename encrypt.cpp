#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
    //pi.length() = 100 digits pi[0-99]
    string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    srand(time(NULL));
    int k = rand() % pi.length();
    cout << "Pi string: " << pi << endl;
    cout << "Offset: " << k << endl;
    cout << "Pi with offset: ";
    for(int i=0; i<pi.length(); i++) {
        if(k+i > pi.length()) {
            break;
        }
        else {
            cout << pi[k+i];
        }
    }
    for(int i=0; i<k; i++) {
        cout << pi[i];
    }

return 0;
}
