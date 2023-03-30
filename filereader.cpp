#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#define NSAMPLING 1024

using namespace std;

int main() {

    ifstream myReadFile;
    string skipchecker;
    string temp;
    stringstream stream;
    vector<string> v;
    vector<double> values;
    int counter=0;
    myReadFile.open("Waveform.dat");
    
    if (myReadFile.is_open()) { //Al momento distingue solo canali, non eventi -> implementare variabile di conteggio per separare eventi
        while (!myReadFile.eof()) {

            getline(myReadFile,  skipchecker);
            if(skipchecker.find('=')==0){
                skipchecker.clear();
                counter--;
            }
            else{
                stringstream stream(skipchecker);
                while (getline(stream, temp, ' ')) {
 
                // store token string in the vector
                 v.push_back(temp);
                }
                if(v.size()==NSAMPLING+1){v.erase(v.end());}

                // print the vector

                for (int i = 0; i < v.size(); i++) {
                    values.push_back(stod(v[i]));
                    cout << i+1 << "\t" << v[i] << " " << values[i] << endl;
                }

                cout<< "counter" << counter + 1 << endl;
                v.clear();
                values.clear();
                }

            counter++;
            if(counter==17){
                counter=1; //Reset the channel count
            }       
        }
    }
    v.clear();
    values.clear();
    skipchecker.clear();
    myReadFile.close();
    return 0;
}