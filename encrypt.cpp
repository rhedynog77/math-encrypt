#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
    //pi.length() = 100 digits pi[0-99]
    string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    string newPi; //new string
    string m;

    cout << "Type your message: ";
    getline(cin, m);

    cout << "Your message: " << m << endl;

    srand(time(NULL));
    int k = rand() % pi.length();
    cout << "Pi string: " << pi << endl;
    for(int i=0; i<pi.length(); i++) {
        if(k+i == pi.length()) {
            break;
        }
        else {
            newPi += pi[k+i];
            //cout << pi[k+i];
        }
    }
    for(int i=0; i<k; i++) {
        newPi += pi[i];
        //cout << pi[i];
    }

    cout << "New key of offset " << k << ": " << endl;
    cout << newPi << endl;

    string n = m;

    for(int i=0; i<n.length(); i++) { //encrypt message without flipping a coin
        int num = stoi(string(1,newPi[i]));
        n[i] += num;
    }
    //Later: if message is longer than the key, wrap around to the beginning of the key again

    cout << "New message: " << n << endl;

return 0;
}
