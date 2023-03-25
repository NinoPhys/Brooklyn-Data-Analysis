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


using namespace std;

Event::Event(){
 
  tot_charge = -1000;
  time = -1000;   
}

Event::~Event(){}


char* Event::ReadEvent(FILE *file){


  
  //da capire come si fa, userei la funzione fgets




  return NULL;
  

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
