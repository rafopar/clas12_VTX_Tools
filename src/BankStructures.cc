/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <BankStructures.h>

/**
 *                                  TBMTadc
 */

TBMTadc::TBMTadc() {
    sector = -999;
    layer = -999;
    component = -999;
    order = -999;
    adc = -999;
    time = -999;
    ped = -999;
    integral = -999;
    timestamp = -999;

}

TBMTadc::TBMTadc(const TBMTadc& orig) {
    sector = orig.sector;
    layer = orig.layer;
    component = orig.component;
    order = orig.order;
    adc = orig.adc;
    time = orig.time;
    ped = orig.ped;
    integral = orig.integral;
    timestamp = orig.timestamp;
}

TBMTadc::~TBMTadc() {
}

/**
 *                                  TBMTRecHit
 */

TBMTRecHit::TBMTRecHit() {
    ID = -999;
    sector = -999;
    layer = -999;
    strip = -999;
    fitResidual = -999;
    trkingStat = -999;
    clusterID = -999;
    trkID = -999;
}

TBMTRecHit::TBMTRecHit(const TBMTRecHit& orig) {
    ID = orig.ID;
    sector = orig.sector;
    layer = orig.layer;
    strip = orig.strip;
    fitResidual = orig.fitResidual;
    trkingStat = orig.trkingStat;
    clusterID = orig.clusterID;
    trkID = orig.trkID;
}

TBMTRecHit::~TBMTRecHit() {
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
    seedE = -999;
    seedStrip = -999;
    centroid = -999;
    centroidResidual = -999;
    seedResidual = -999;
    Hit1_ID = -999;
    Hit2_ID = -999;
    Hit3_ID = -999;
    Hit4_ID = -999;
    Hit5_ID = -999;
    trkID = -999;
    nHits = 0;
    v_Hits = std::vector <TBMTRecHit*>();
}

TBMTRecCluster::TBMTRecCluster(const TBMTRecCluster& orig) {
    ID = orig.ID;
    sector = orig.ID;
    layer = orig.ID;
    size = orig.ID;
    ETot = orig.ID;
    seedE = orig.ID;
    seedStrip = orig.ID;
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
}

TBMTRecCluster::~TBMTRecCluster() {
}

/**
 *                                  TBMTRecCross
 */

TBMTRecCross::TBMTRecCross() {
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

TBMTRecCross::TBMTRecCross(const TBMTRecCross &orig) {
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

TCVTTrack::TCVTTrack() {
}

TCVTTrack::TCVTTrack(const TCVTTrack& orig) {
}

TCVTTrack::~TCVTTrack() {
}