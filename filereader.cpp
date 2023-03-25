#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

int main() {

    ifstream myReadFile;
    myReadFile.open("Waveform1ev.dat");
    char output[100000];
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {

            myReadFile >> output;
            cout << output;

        }
    }
    myReadFile.close();
    return 0;
}