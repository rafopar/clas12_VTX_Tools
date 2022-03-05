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
    centroidValue = -999;        // *
    centroidError = -999;        // *
    centroidResidual = -999;
    seedResidual = -999;
    Hit1_ID = -999;
    Hit2_ID = -999;
    Hit3_ID = -999;
    Hit4_ID = -999;
    Hit5_ID = -999;
    trkID = -999;
    x1 = -999;       // *
    y1 = -999;       // *
    z1 = -999;       // *
    x2 = -999;       // *
    y2 = -999;       // *
    z2 = -999;       // *
    theta = -999;       // *
    ax1 = -999;       // *
    ay1 = -999;       // *
    az1 = -999;       // *
    ax2 = -999;       // *
    ay2 = -999;       // *
    az2 = -999;       // *
    lx = -999;       // *
    ly = -999;       // *
    lz = -999;       // *
    sx = -999;       // *
    sy = -999;       // *
    sz = -999;       // *
    nx = -999;       // *
    ny = -999;       // *
    nz = -999;       // *
    
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
    sy =  orig.sy;
    sz =  orig.sz;
    nx =  orig.nx;
    ny =  orig.ny;
    nz =  orig.nz;    
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

TCVTRecCross::~TCVTRecCross(){
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
    centroidError = -999;        // *
    centroidResidual = -999;
    seedResidual = -999;
    Hit1_ID = -999;
    Hit2_ID = -999;
    Hit3_ID = -999;
    Hit4_ID = -999;
    Hit5_ID = -999;
    trkID = -999;
    x1 = -999;       // *
    y1 = -999;       // *
    z1 = -999;       // *
    x2 = -999;       // *
    y2 = -999;       // *
    z2 = -999;       // *
    lx = -999;       // *
    ly = -999;       // *
    lz = -999;       // *
    sx = -999;       // *
    sy = -999;       // *
    sz = -999;       // *
    nx = -999;       // *
    ny = -999;       // *
    nz = -999;       // *
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
    sy =  orig.sy;
    sz =  orig.sz;
    nx =  orig.nx;
    ny =  orig.ny;
    nz =  orig.nz;    
    e = orig.e;
}

TBSTRecCluster::~TBSTRecCluster() {
}

/**
 *                                  TBMTRecCross
 */

TCVTTrack::TCVTTrack() {
}

TCVTTrack::TCVTTrack(const TCVTTrack& orig) {
}

TCVTTrack::~TCVTTrack() {
}