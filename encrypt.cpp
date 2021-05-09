#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
    char c;
    cout << "(E)ncrypt or (D)ecrypt?: ";
    cin >> c;
    cin.ignore(1000,'\n');

    while(c != 'E' && c != 'e' && c != 'D' && c != 'd') {
        cout << "Try again: ";
        cin >> c;
        cin.ignore(1000,'\n');
    }

    if(c == 'E' || c == 'e') { //encryption process
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

        char d;
        for(int i = 0; i < k; i++) {
            //read first digits of pi before k
            file >> d;
        }
        while(file >> d && newPi.length() < m.length()) {
            if(d == '.') continue;
            newPi += d;
            //Later: have condition for when we reach end of pi and need to start from beginning?
        }

        file.close();

        cout << "Key: \n" << newPi << endl;

        //create key file and write key to it
        ofstream keyFile("key.txt");
        keyFile << newPi << endl;

        string n = m; //encrypted message

        string coinFlips, coinFlipsReverse;
        for(int i=0; i<n.length(); i++) { //encrypt message using coin flips
            int num = stoi(string(1,newPi[i])); //change ith digit from string to integer
            int coin = rand() % 2;
            if(coin == 0) { //if heads
                coinFlips += 'H';
                coinFlipsReverse += 'T';
                n[i] += num; //move value of ith letter up num positions
            }
            else if(coin == 1) { //if tails
                coinFlips += 'T';
                coinFlipsReverse += 'H';
                n[i] -= num; //move value of ith letter down num positions
            }
        }
        cout << "Coin flips: " << coinFlips << endl;

        //write reverse flips to key file
        keyFile << coinFlipsReverse;

        cout << "New message: " << n << endl;

    }
    else if(c == 'D' || c == 'd') { //decryption process
        string message;
        cout << "Enter encrypted message: ";
        getline(cin, message);

        ifstream keyFile; //open file containing key
        keyFile.open("key.txt");
        if(!keyFile.is_open()) {
            cout << "Unable to open file. Exiting..." << endl;
            exit(1);
        }
        string dm, key, cf;
        keyFile >> key >> cf; //save key and coin flips from file to variables
        cout << key << " " << cf << endl;
        dm = message; //make decrypted message equal to encrypted message before decrypt process
        for(int i=0; i<dm.length(); i++) { //decrypt message using coin flips
            if(cf[i] == 'H') { //if heads
                dm[i] += stoi(string(1,key[i])); //move value of ith letter up
            }
            else if(cf[i] == 'T') { //if tails
                dm[i] -= stoi(string(1,key[i])); //move value of ith letter down
            }
        }
        cout << "Decrypted message: " << dm << endl;

        return 0;
    }

return 0;
}
