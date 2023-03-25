#include <TCanvas.h>
#include <vector>
#include <iostream>
#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>
#include <TF1.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TSystem.h>
#include <stdio.h>
#include <TStyle.h>
#include <stdint.h>
#include "AnaTools.h"
#include "Event.h"

using namespace std;


int main(int argc, char *argv[]){

  string inname("in.dat");
  string outname("out.root");

  int nevent=1e9;
  
  for(int i=0; i< argc; i++){
    if(strcmp("-in",argv[i])==0){
      inname.assign(argv[++i]);
    }
    if(strcmp("-out",argv[i])==0){
      outname.assign(argv[++i]);
    }
    if(strcmp("-nev",argv[i])==0){
      nevent = atoi(argv[++i]);
    }
  }


  //open output file
  TFile *f = new TFile(outname.data(), "RECREATE");
  f->cd();

  
  //create an Event object
  Event * myEvent = new Event();


  //create an Analysys Tool object and create histograms
  AnaTools *myAnaTools = new AnaTools(f,myEvent);
  myAnaTools->BookingHistograms();

  //open input file
  //to do according to the file format, example:
  FILE *infile;
  // infile= fopen(inname.data(),"r");
  // if(infile==NULL){
  // printf("***************88File %s not found, exiting from the program*****************\n",inname.data());
  //  exit(-1);
  // }
  

  //loop on events, read an event until file is finished
  while(myEvent->ReadEvent(infile)!=NULL){

    myAnaTools->Process();

    myAnaTools->Clear();
    myEvent->Clear();


  }



  //close input file
  //fclose(infile);
  
  //close output file
  f->Write();
  f->Close();






  return 0;

}
