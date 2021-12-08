/* 
 * File:   BankStructures.h
 * Author: rafopar
 *
 * Created on November 30, 2021, 2:45 PM
 */

#ifndef BANKSTRUCTURES_H
#define BANKSTRUCTURES_H

#include <vector>

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

class TBMTRecHit {
public:
    TBMTRecHit();
    TBMTRecHit(const TBMTRecHit& orig);
    virtual ~TBMTRecHit();

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

class TBMTRecCluster {
public:
    TBMTRecCluster();
    TBMTRecCluster(const TBMTRecCluster &orig);
    virtual ~TBMTRecCluster();

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
    int nHits;
    std::vector <TBMTRecHit*> v_Hits;

    int GetNumberOfHits() const {
        return v_Hits.size();
    };
    
    // ========== Vector of pointers to hits ==========
    std::vector <TBMTRecHit*> GetHits() const{
        return v_Hits;
    };

private:
};

class TBMTRecCross{
public:
    TBMTRecCross();
    TBMTRecCross( const TBMTRecCross &orig );
    virtual ~TBMTRecCross();
    
    int ID;
    int sector;
    int region;
    float x;
    float y;
    float z;
    float err_x;
    float err_y;
    float err_z;
    float ux;
    float uy;
    float uz;
    int Cluster1_ID;
    int Cluster2_ID;
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

