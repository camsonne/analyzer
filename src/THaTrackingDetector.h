#ifndef ROOT_THaTrackingDetector
#define ROOT_THaTrackingDetector

//////////////////////////////////////////////////////////////////////////
//
// THaTrackingDetector.h
//
//////////////////////////////////////////////////////////////////////////

#include "THaSpectrometerDetector.h"

class TClonesArray;
class THaTrack;
class THaTrackID;

class THaTrackingDetector : public THaSpectrometerDetector {
  
public:
  virtual ~THaTrackingDetector();
  
  virtual Int_t    CoarseTrack( TClonesArray& tracks ) = 0;
  virtual Int_t    FineTrack( TClonesArray& tracks )  = 0;
  virtual Int_t    FindVertices( TClonesArray& tracks ) = 0;
          Bool_t   IsTracking() { return kTRUE; }
          Bool_t   IsPid()      { return kFALSE; }

protected:

  virtual THaTrack* AddTrack( TClonesArray& tracks,
			      Double_t x, Double_t y, 
			      Double_t theta, Double_t phi,
			      THaTrackID* ID = NULL );

  //Only derived classes may construct me

  THaTrackingDetector( const char* name, const char* description,
		       THaApparatus* a = NULL );

  ClassDef(THaTrackingDetector,0)   //ABC for a Hall A tracking detector
};

#endif
