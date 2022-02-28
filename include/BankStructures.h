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

class TCVTadc {
public:
    TCVTadc();
    TCVTadc(const TCVTadc& orig);
    virtual ~TCVTadc();

    int sector;
    int layer;
    int component;
    int order;
    int ADC;
    float time;
    int ped;
    int integral;
    long timestamp;

private:

};

class TCVTRecHit {
public:
    TCVTRecHit();
    TCVTRecHit(const TCVTRecHit& orig);
    virtual ~TCVTRecHit();

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
    float time;
    float seedE;
    int seedStrip;
    float centroid;
    float centroidValue;        // *
    float centroidError;        // *
    float centroidResidual;
    float seedResidual;
    int Hit1_ID;
    int Hit2_ID;
    int Hit3_ID;
    int Hit4_ID;
    int Hit5_ID;
    int trkID;
    float x1;       // *
    float y1;       // *
    float z1;       // *
    float x2;       // *
    float y2;       // *
    float z2;       // *
    float theta;       // *
    float ax1;       // *
    float ay1;       // *
    float az1;       // *
    float ax2;       // *
    float ay2;       // *
    float az2;       // *
    float lx;       // *
    float ly;       // *
    float lz;       // *
    float sx;       // *
    float sy;       // *
    float sz;       // *
    float nx;       // *
    float ny;       // *
    float nz;       // *
    int nHits;
    std::vector <TCVTRecHit*> v_Hits;

    int GetNumberOfHits() const {
        return v_Hits.size();
    };
    
    // ========== Vector of pointers to hits ==========
    std::vector <TCVTRecHit*> GetHits() const{
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

class TBSTRecCluster {
public:
    TBSTRecCluster();
    TBSTRecCluster(const TBSTRecCluster &orig);
    virtual ~TBSTRecCluster();

    int ID;
    int sector;
    int layer;
    int size;
    float ETot;
    float time;
    float seedE;
    int seedStrip;
    float centroid;
    float centroidError;        // *
    float centroidResidual;
    float seedResidual;
    int Hit1_ID;
    int Hit2_ID;
    int Hit3_ID;
    int Hit4_ID;
    int Hit5_ID;
    int trkID;
    float x1;       // *
    float y1;       // *
    float z1;       // *
    float x2;       // *
    float y2;       // *
    float z2;       // *
    float lx;       // *
    float ly;       // *
    float lz;       // *
    float sx;       // *
    float sy;       // *
    float sz;       // *
    float nx;       // *
    float ny;       // *
    float nz;       // *
    float e;       // *
    int nHits;
    std::vector <TCVTRecHit*> v_Hits;

    int GetNumberOfHits() const {
        return v_Hits.size();
    };
    
    // ========== Vector of pointers to hits ==========
    std::vector <TCVTRecHit*> GetHits() const{
        return v_Hits;
    };

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

