#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stdint.h>
#include <stdio.h>
#include <TFile.h>
#include <TH1D.h>


#define NSAMPLING 1024 //to be checked

using namespace std;

class Waveform{
  
 public:
  
  Waveform(double *vt, double *va);
  virtual ~Waveform();

  //Getters
  double* getV_Time(); //Returns pointer to v_time[0]
  double* getV_Amplitude(); //Returns pointer to v_amplitude[0]
  double getCharge();
  double getTime();

  //Setters
  void setV_Time(int index, double value);
  void setV_Amplitude(int index, double value);
  void setCharge(double Q);
  void setTime(double t);
  
 private:


  double v_time[NSAMPLING];
  double v_amplitude[NSAMPLING];
  
  double charge;
  double time;
  
};

#endif
