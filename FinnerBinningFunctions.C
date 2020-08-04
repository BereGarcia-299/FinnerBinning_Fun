#include "TMath.h"
#include <iostream>
#include <stdio.h>

using namespace std;



//----LogBins Function

//-----x_low is your lowest bound for the x-axis
//-----x_high is your highest bound for the x_axis
//-----num_bins is the number of bins you would like
//-----*bins is the points to the array where you will be saving your array


void log_bins(const float x_low, const float x_high, const int num_bins, double *bins){

  int const size = num_bins+1;
  float logbins[26] = {};
  
  *(bins+0)= x_low;
  *(bins+ num_bins) = x_high;


  logbins[0] = TMath::Log10(x_low);
  logbins[num_bins] = TMath::Log10(x_high);
  

  float interval = (logbins[25] - logbins[0])/num_bins;

  for(int index = 1; index < num_bins; index++){
    logbins[index] = logbins[0] + index*interval;
    *(bins +index) = TMath::Power(10, logbins[index]);
    cout << "This went into  your bins_new array " << *(bins+index) << endl;
  }

  return;
}

int FinnerBinningFunctions(){
  //---This is an example


double bins_new[55]={}; //----Creating an array that can hole 55 elements

double *ptr = bins_new;  //---Pointer will point to the array's first element 

log_bins(1,40,55,ptr);   //----Out domain is 1-40. We want 55 bins and we also insert our pointer to this function. 


  return 0;
}