#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
    string m;
    cout << "Type your message: ";
    getline(cin, m);

    ifstream file;
    file.open("pi-billion.txt"); //downloaded from: https://stuff.mit.edu/afs/sipb/contrib/pi/
    if(!file.is_open()) {
        cout << "Unable to open file. Exiting..." << endl;
        exit(1);
    }
    string newPi; //key that starts from offset of pi, same length as message

    int l = 1000000001; //one billion plus initial '3';
    srand(time(NULL));
    int k = rand() % l;
    cout << "Offset: " << k << endl;

    char c;
    for(int i = 0; i < k; i++) {
        //read first digits of pi before k
        file >> c;
    }
    while(file >> c && newPi.length() < m.length()) {
        if(c == '.') continue;
        newPi += c;
        //Later: have condition for when we reach end of pi and need to start from beginning?
    }
    /*if(newPi.length() < m.length()) {
        while(file >> c && c < k) {
            newPi += c;
        }
    }*/

    file.close();

    cout << "Key: \n" << newPi << endl;

    string n = m; //encrypted message

    string coinFlips;
    for(int i=0; i<n.length(); i++) { //encrypt message using coin flips
        int num = stoi(string(1,newPi[i])); //change ith digit from string to integer
        int coin = rand() % 2;
        if(coin == 0) { //if heads
            coinFlips += 'H';
            n[i] += num; //move value of ith letter up num positions
        }
        else if(coin == 1) { //if tails
            coinFlips += 'T';
            n[i] -= num; //move value of ith letter down num positions
        }
    }
    cout << "Coin flips: " << coinFlips << endl;

    cout << "New message: " << n << endl;

return 0;
}
