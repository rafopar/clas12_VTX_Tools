/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <BankStructures.h>

/**
 *                                  TBMTadc
 */

TCVTadc::TCVTadc() {
    sector = -999;
    layer = -999;
    component = -999;
    order = -999;
    ADC = -999;
    time = -999;
    ped = -999;
    integral = -999;
    timestamp = -999;

}

TCVTadc::TCVTadc(const TCVTadc& orig) {
    sector = orig.sector;
    layer = orig.layer;
    component = orig.component;
    order = orig.order;
    ADC = orig.ADC;
    time = orig.time;
    ped = orig.ped;
    integral = orig.integral;
    timestamp = orig.timestamp;
}

TCVTadc::~TCVTadc() {
}

/**
 *                                  TBMTRecHit
 */

TCVTRecHit::TCVTRecHit() {
    ID = -999;
    sector = -999;
    layer = -999;
    strip = -999;
    fitResidual = -999;
    trkingStat = -999;
    clusterID = -999;
    trkID = -999;
}

TCVTRecHit::TCVTRecHit(const TCVTRecHit& orig) {
    ID = orig.ID;
    sector = orig.sector;
    layer = orig.layer;
    strip = orig.strip;
    fitResidual = orig.fitResidual;
    trkingStat = orig.trkingStat;
    clusterID = orig.clusterID;
    trkID = orig.trkID;
}

TCVTRecHit::~TCVTRecHit() {
}

/**
 *                                  TBMTRecCluster
 */


TBMTRecCluster::TBMTRecCluster() {

    ID = -999;
    sector = -999;
    layer = -999;
    size = -999;
    ETot = -999;
    time = -999;
    seedE = -999;
    seedStrip = -999;
    centroid = -999;
    centroidValue = -999; // *
    centroidError = -999; // *
    centroidResidual = -999;
    seedResidual = -999;
    Hit1_ID = -999;
    Hit2_ID = -999;
    Hit3_ID = -999;
    Hit4_ID = -999;
    Hit5_ID = -999;
    trkID = -999;
    x1 = -999; // *
    y1 = -999; // *
    z1 = -999; // *
    x2 = -999; // *
    y2 = -999; // *
    z2 = -999; // *
    theta = -999; // *
    ax1 = -999; // *
    ay1 = -999; // *
    az1 = -999; // *
    ax2 = -999; // *
    ay2 = -999; // *
    az2 = -999; // *
    lx = -999; // *
    ly = -999; // *
    lz = -999; // *
    sx = -999; // *
    sy = -999; // *
    sz = -999; // *
    nx = -999; // *
    ny = -999; // *
    nz = -999; // *

    nHits = 0;
    v_Hits = std::vector <TCVTRecHit*>();
}

TBMTRecCluster::TBMTRecCluster(const TBMTRecCluster& orig) {
    ID = orig.ID;
    sector = orig.ID;
    layer = orig.ID;
    size = orig.ID;
    ETot = orig.ID;
    time = orig.time;
    seedE = orig.ID;
    seedStrip = orig.ID;
    centroidValue = orig.centroidValue;
    centroidError = orig.centroidError;
    centroid = orig.ID;
    centroidResidual = orig.ID;
    seedResidual = orig.ID;
    Hit1_ID = orig.ID;
    Hit2_ID = orig.ID;
    Hit3_ID = orig.ID;
    Hit4_ID = orig.ID;
    Hit5_ID = orig.ID;
    trkID = orig.ID;
    nHits = orig.nHits;
    v_Hits = orig.v_Hits;
    x1 = orig.x1;
    y1 = orig.y1;
    z1 = orig.z1;
    x2 = orig.x2;
    y2 = orig.y2;
    z2 = orig.z2;
    theta = orig.theta;
    ax1 = orig.ax1;
    ay1 = orig.ay1;
    az1 = orig.az1;
    ax2 = orig.ax2;
    ay2 = orig.ay2;
    az2 = orig.az2;
    lx = orig.lx;
    ly = orig.ly;
    lz = orig.lz;
    sx = orig.sx;
    sy = orig.sy;
    sz = orig.sz;
    nx = orig.nx;
    ny = orig.ny;
    nz = orig.nz;
}

TBMTRecCluster::~TBMTRecCluster() {
}

/**
 *                                  TBMTRecCross
 */

TCVTRecCross::TCVTRecCross() {
    ID = -999;
    sector = -999;
    region = -999;
    x = -999;
    y = -999;
    z = -999;
    err_x = -999;
    err_y = -999;
    err_z = -999;
    ux = -999;
    uy = -999;
    uz = -999;
    Cluster1_ID = -999;
    Cluster2_ID = -999;
    trkID = -999;
}

TCVTRecCross::TCVTRecCross(const TCVTRecCross &orig) {
    ID = orig.ID;
    sector = orig.sector;
    region = orig.region;
    x = orig.x;
    y = orig.y;
    z = orig.z;
    err_x = orig.err_x;
    err_y = orig.err_y;
    err_z = orig.err_z;
    ux = orig.ux;
    uy = orig.uy;
    uz = orig.uz;
    Cluster1_ID = orig.Cluster1_ID;
    Cluster2_ID = orig.Cluster2_ID;
    trkID = orig.trkID;

}

TCVTRecCross::~TCVTRecCross() {
}

TBSTRecCluster::TBSTRecCluster() {

    ID = -999;
    sector = -999;
    layer = -999;
    size = -999;
    ETot = -999;
    time = -999;
    seedE = -999;
    seedStrip = -999;
    centroid = -999;
    centroidError = -999; // *
    centroidResidual = -999;
    seedResidual = -999;
    Hit1_ID = -999;
    Hit2_ID = -999;
    Hit3_ID = -999;
    Hit4_ID = -999;
    Hit5_ID = -999;
    trkID = -999;
    x1 = -999; // *
    y1 = -999; // *
    z1 = -999; // *
    x2 = -999; // *
    y2 = -999; // *
    z2 = -999; // *
    lx = -999; // *
    ly = -999; // *
    lz = -999; // *
    sx = -999; // *
    sy = -999; // *
    sz = -999; // *
    nx = -999; // *
    ny = -999; // *
    nz = -999; // *
    e = -999;
    nHits = 0;
    v_Hits = std::vector <TCVTRecHit*>();
}

TBSTRecCluster::TBSTRecCluster(const TBSTRecCluster& orig) {
    ID = orig.ID;
    sector = orig.ID;
    layer = orig.ID;
    size = orig.ID;
    ETot = orig.ID;
    time = orig.time;
    seedE = orig.ID;
    seedStrip = orig.ID;
    centroidError = orig.centroidError;
    centroid = orig.ID;
    centroidResidual = orig.ID;
    seedResidual = orig.ID;
    Hit1_ID = orig.ID;
    Hit2_ID = orig.ID;
    Hit3_ID = orig.ID;
    Hit4_ID = orig.ID;
    Hit5_ID = orig.ID;
    trkID = orig.ID;
    nHits = orig.nHits;
    v_Hits = orig.v_Hits;
    x1 = orig.x1;
    y1 = orig.y1;
    z1 = orig.z1;
    x2 = orig.x2;
    y2 = orig.y2;
    z2 = orig.z2;
    lx = orig.lx;
    ly = orig.ly;
    lz = orig.lz;
    sx = orig.sx;
    sy = orig.sy;
    sz = orig.sz;
    nx = orig.nx;
    ny = orig.ny;
    nz = orig.nz;
    e = orig.e;
}

TBSTRecCluster::~TBSTRecCluster() {
}

/**
 *                                  TBMTRecCross
 */

TCVTRecTrack::TCVTRecTrack() {
    int ID = -999;
    int fittingMethod = -999; // fitting method (1 for global fit, 2 for Kalman Filter)
    float c_x = -999; // x-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_y = -999; // y-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_z = -999; // z-coordinate of a helical trk point extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)
    float c_ux = -999; // x-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float c_uy = -999; // y-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float c_uz = -999; // z-coordinate of a helical trk direction extrapolated to a cylinder at 25 cm radius from the lab origin (cm unit)"
    float pathlength = -999; // total pathlength from the origin to the reference point (in cm)"
    int q = -999; // charge
    float p = -999; // total momentum
    float pt = -999; // transverse momentum
    float phi0 = -999; // phi0
    float tandip = -999; // this is probably tanLambda
    float z0 = -999; // z0
    float d0 = -999; // d0
    float cov_d02 = -999; // helical track fit covariance matrix element : delta_d0^2
    float cov_d0phi0 = -999; // helical track fit covariance matrix element : delta_d0.delta_phi
    float cov_d0rho = -999; // helical track fit covariance matrix element : delta_d0.delta_rho
    float cov_phi02 = -999; // helical track fit covariance matrix element : delta_phi0^2
    float cov_phi0rho = -999; // helical track fit covariance matrix element : delta_phi0.delta_rho
    float cov_rho2 = -999; // helical track fit covariance matrix element : delta_rho.delta_rho
    float cov_z02 = -999; // helical track fit covariance matrix element : delta_z0^2
    float cov_tandip2 = -999; // helical track fit covariance matrix element : delta_tandip^2
    float circlefit_chi2_per_ndf = -999; // Circle Fit chi^2/ndf
    float linefit_chi2_per_ndf = -999; // linefit_chi2_per_ndf
    float chi2 = -999; // Fit chi^2 
    int ndf = -999; // Fit ndf 
    int Cross1_ID = -999; // ID of cross in the track
    int Cross2_ID = -999; // ID of cross in the track
    int Cross3_ID = -999; // ID of cross in the track
    int Cross4_ID = -999; // ID of cross in the track
    int Cross5_ID = -999; // ID of cross in the track
    int Cross6_ID = -999; // ID of cross in the track
    int Cross7_ID = -999; // ID of cross in the track
    int Cross8_ID = -999; // ID of cross in the track
    int Cross9_ID = -999; // ID of cross in the track
    int seedID = -999; // ID of track seed
    float xb = -999; // x Offset
    float yb = -999; // y Offset
    int status = -999; // track status : nabc (n = KF iterations a = nb SVT crosses, b = nb BMT Z clusters, c = nb BMT C clusters, used in fit)
}

TCVTRecTrack::TCVTRecTrack(const TCVTRecTrack& orig) {
    ID = orig.ID;
    fittingMethod = orig.fittingMethod;
    c_x = orig.c_x;
    c_y = orig.c_y;
    c_z = orig.c_z;
    c_ux = orig.c_ux;
    c_uy = orig.c_uy;
    c_uz = orig.c_uz;
    pathlength = orig.pathlength;
    q = orig.q;
    p = orig.p;
    pt = orig.pt;
    phi0 = orig.phi0;
    tandip = orig.tandip;
    z0 = orig.z0;
    d0 = orig.d0;
    cov_d02 = orig.cov_d02;
    cov_d0phi0 = orig.cov_d0phi0;
    cov_d0rho = orig.cov_d0rho;
    cov_phi02 = orig.cov_phi02;
    cov_phi0rho = orig.cov_phi0rho;
    cov_rho2 = orig.cov_rho2;
    cov_z02 = orig.cov_z02;
    cov_tandip2 = orig.cov_tandip2;
    circlefit_chi2_per_ndf = orig.circlefit_chi2_per_ndf;
    linefit_chi2_per_ndf = orig.linefit_chi2_per_ndf;
    chi2 = orig.chi2;
    ndf = orig.ndf;
    Cross1_ID = orig.Cross1_ID;
    Cross2_ID = orig.Cross2_ID;
    Cross3_ID = orig.Cross3_ID;
    Cross4_ID = orig.Cross4_ID;
    Cross5_ID = orig.Cross5_ID;
    Cross6_ID = orig.Cross6_ID;
    Cross7_ID = orig.Cross7_ID;
    Cross8_ID = orig.Cross8_ID;
    Cross9_ID = orig.Cross9_ID;
    seedID = orig.seedID;
    xb = orig.xb;
    yb = orig.yb;
    status = orig.status;
}

TCVTRecTrack::~TCVTRecTrack() {
}