/* 
 * File:   BankStructures.h
 * Author: rafopar
 *
 * Created on November 30, 2021, 2:45 PM
 */

#ifndef BANKSTRUCTURES_H
#define BANKSTRUCTURES_H

/**
 *  BMT ADC class
 */

class TBMTadc {
public:
    TBMTadc();
    TBMTadc(const TBMTadc& orig);
    virtual ~TBMTadc();

    int sector;
    int layer;
    int component;
    int order;
    int adc;
    float time;
    int ped;
    int integral;
    long timestamp;

private:

};

class TBMTRecHits {

public:
    TBMTRecHits();
    TBMTRecHits( const TBMTRecHits& orig );
    virtual ~TBMTRecHits();
    
    int ID;
    int sector;
    int layer;
    int strip;
    float fitResidual;
    int trkingStat;
    int clusterID;
    int trkID;
    
private:
    
};

class TBMTRecClusters{
public:
   TBMTRecClusters();
   TBMTRecClusters( const TBMTRecClusters &orig );
   virtual ~TBMTRecClusters();
   
   int ID;
   int sector;
   int layer;
   int size;
   float ETot;
   float seedE;
   int seedStrip;
   float centroid;
   float centroidResidual;
   float seedResidual;
   int Hit1_ID;
   int Hit2_ID;
   int Hit3_ID;
   int Hit4_ID;
   int Hit5_ID;
   int trkID;
    
private:
};

class TCVTTrack {
public:
    TCVTTrack();
    TCVTTrack(const TCVTTrack& orig);
    virtual ~TCVTTrack();
private:

};



#endif /* BANKSTRUCTURES_H */

