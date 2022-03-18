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

class TCVTRecCross{
public:
    TCVTRecCross();
    TCVTRecCross( const TCVTRecCross &orig );
    virtual ~TCVTRecCross();
    
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


class TCVTRecTrack {
public:
    TCVTRecTrack();
    TCVTRecTrack(const TCVTRecTrack& orig);
    virtual ~TCVTRecTrack();

    int ID;
    int fittingMethod; // fitting method (1 for global fit, 2 for Kalman Filter)
    float c_x; // x-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_y; // y-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_z; // z-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_ux; // x-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float c_uy; // y-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float c_uz; // z-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float pathlength; // total pathlength from the origin to the reference point (in cm)"
    int q; // charge
    float p; // total momentum
    float pt; // transverse momentum
    float phi0; // phi0
    float tandip; // this is probably tanLambda
    float z0; // z0
    float d0; // d0
    float cov_d02; // helical track fit covariance matrix element : delta_d0^2
    float cov_d0phi0; // helical track fit covariance matrix element : delta_d0.delta_phi
    float cov_d0rho; // helical track fit covariance matrix element : delta_d0.delta_rho
    float cov_phi02; // helical track fit covariance matrix element : delta_phi0^2
    float cov_phi0rho; // helical track fit covariance matrix element : delta_phi0.delta_rho
    float cov_rho2; // helical track fit covariance matrix element : delta_rho.delta_rho
    float cov_z02; // helical track fit covariance matrix element : delta_z0^2
    float cov_tandip2; // helical track fit covariance matrix element : delta_tandip^2
    float circlefit_chi2_per_ndf; // Circle Fit chi^2/ndf
    float linefit_chi2_per_ndf; // linefit_chi2_per_ndf
    float chi2; // Fit chi^2 
    int ndf; // Fit ndf 
    int Cross1_ID; // ID of cross in the track
    int Cross2_ID; // ID of cross in the track
    int Cross3_ID; // ID of cross in the track
    int Cross4_ID; // ID of cross in the track
    int Cross5_ID; // ID of cross in the track
    int Cross6_ID; // ID of cross in the track
    int Cross7_ID; // ID of cross in the track
    int Cross8_ID; // ID of cross in the track
    int Cross9_ID; // ID of cross in the track
    int seedID; // ID of track seed
    float xb; // x Offset
    float yb; // y Offset
    int status; // track status : nabc (n = KF iterations a = nb SVT crosses, b = nb BMT Z clusters, c = nb BMT C clusters, used in fit)
    
    
    
private:

};



#endif /* BANKSTRUCTURES_H */

