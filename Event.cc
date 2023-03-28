#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TF1.h>
#include <TMath.h>
#include <TSpectrum.h>
#include "Event.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <TMinuit.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

Event::Event(){
 
  tot_charge = -1000;
  time = -1000;   
}

Event::~Event(){}


void Event::ReadEvent(string inname){

  ifstream myReadFile;
  string fileline; //A line of the File
  string temp; //Single value
  stringstream stream; //Stream to navigate string fileline
  vector<string> v; //Vector of strings containing all the values (aka, temp)
  vector<double> values; //Vector containing the values converted to double
  int channel=0;
  myReadFile.open("Waveform.dat");
    
  if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {

      getline(myReadFile,  fileline); //write the line from file to string fileline
      if(fileline.find('=')==0){  //ignore lines which do not contain amplitude data
        fileline.clear();
        channel--;
      }
      else{
        stringstream stream(fileline);
        while (getline(stream, temp, ' ')) {  //Values in line are separated by space (' ')
 
          // store token string in the vector
           v.push_back(temp); //add value (still as string) to vector<string> temp
          }
        if(v.size()==NSAMPLING+1){v.erase(v.end());} //Sometimes, the program will a read an empty entry at the end. Delete that entry

          // print the vector

          for (int i = 0; i < v.size(); i++) {  //Convert vector<string> to vector<double>
            values.push_back(stod(v[i]));
            cout << i+1 << "\t" << v[i] << " " << values[i] << endl;
            }

            cout<< "channel" << channel + 1 << endl;
            v.clear();  //empty vector v
            values.clear(); //empty vector values
            }

        channel++;
        if(channel==17){
          channel=1; //Reset the channel count
        }       
    }
  }
  //Last clears and file closing, to prevent memory leaks
  v.clear();
  values.clear();
  fileline.clear();
  myReadFile.close();

}


void Event::Clear(){


  for(int iW=0;iW<myWaveforms.size();iW++){
    delete myWaveforms.at(iW);
  }
  myWaveforms.clear();

  tot_charge = -1000;
  time = -1000;

  return;

}
