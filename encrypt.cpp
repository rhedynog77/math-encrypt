#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
    //pi.length() = 100 digits pi[0-99]
    string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067"; //pi
    string euler = "2718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427"; //e
    string phi = "1618033988749894848204586834365638117720309179805762862135448622705260462818902449707207204189391137"; //golden ratio
    string tau = "6283185307179586476925286766559005768394338798750211641949889184615632812572417997256069650684234135"; //2*pi
    string gauss = "0834626841674073186281429732799046808993993013490347002449827370103681992709526411869691160351275324"; //Gauss's constant
    string sq2sq2 = "1632526919438152844773495381024719602079108857053114117247780684383035205998616642247855507506626041"; //square(2)^(square(2))

    string m;
    cout << "Type your message: ";
    getline(cin, m);

    //cout << "Your message: " << m << endl;

    int w;
    cout << "Which number do you want to encrypt with?" << endl;
    cout << "(1) pi\n(2) e (Euler's number)\n(3) phi (Golden Ratio)\n";
    cout << "(4) tau (2pi)\n(5) Gauss's constant\n(6) sqrt(2)^(sqrt(2))" << endl;
    cin >> w;

    while(w != 1 && w != 2 && w != 3 && w != 4 && w != 5 && w != 6) {
        cout << "Try again: ";
        cin >> w;
    }

    string numCopy; //copy of chosen number
    switch(w) {
        case 1: numCopy = pi; break;
        case 2: numCopy = euler; break;
        case 3: numCopy = phi; break;
        case 4: numCopy = tau; break;
        case 5: numCopy = gauss; break;
        case 6: numCopy = sq2sq2;
    }
    int l = numCopy.length();
    srand(time(NULL));
    int k = rand() % l; //each number has the same amount of digits, so using the length of pi is fine for all of them
    cout << "Chosen Number: " << numCopy << endl;

    string newNum; //offset of chosen number
    for(int i=0; i<l; i++) {
        if(k+i == l) {
            break;
        }
        else {
            newNum += numCopy[k+i];
            //cout << pi[k+i];
        }
    }
    for(int i=0; i<k; i++) {
        newNum += numCopy[i];
        //cout << pi[i];
    }

    cout << "New key of offset " << k << ": " << endl;
    cout << newNum << endl;

    string n = m; //encrypted message
    string coinFlips;
    for(int i=0; i<n.length(); i++) { //encrypt message
        int num = stoi(string(1,newNum[i]));
        int c = rand() % 2;
        if(c == 0) {
            coinFlips += 'H';
            n[i] += num;
        }
        else if(c == 1) {
            coinFlips += 'T';
            n[i] -= num;
        }
    }
    cout << "Coin flips: " << coinFlips << endl;
    //Later: if message is longer than the key, wrap around to the beginning of the key again

    cout << "New message: " << n << endl;

return 0;
}
