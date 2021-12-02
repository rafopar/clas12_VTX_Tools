/* 
 * File:   TVertexAna.cc
 * Author: rafopar
 * 
 * Created on November 25, 2021, 12:17 PM
 */

#include <iostream>
#include "TVertexAna.h"

TVertexAna::TVertexAna(hipo::dictionary &aDict) {

    fEv = nullptr;
    InitDictionary(aDict);

}

TVertexAna::TVertexAna(const TVertexAna& orig) {
}

TVertexAna::~TVertexAna() {
}

void TVertexAna::InitDictionary(hipo::dictionary &aDict) {
    fDict = aDict;

    bBMT_adc = hipo::bank(fDict.getSchema("BMT::adc"));
    bBMTRec_Hits = hipo::bank(fDict.getSchema("BMTRec::Hits"));
    bBMTRec_Clusters = hipo::bank(fDict.getSchema("BMTRec::Clusters"));
    bBMTRec_Crosses = hipo::bank(fDict.getSchema("BMTRec::Crosses"));
    bBST_adc = hipo::bank(fDict.getSchema("BST::adc"));
    bBSTRec_Hits = hipo::bank(fDict.getSchema("BBSTRec::Hits"));
    bBSTRec_Clusters = hipo::bank(fDict.getSchema("BSTRec::Clusters"));
    bBSTRec_Crosses = hipo::bank(fDict.getSchema("BSTRec::Crosses"));
}

void TVertexAna::ReadEvent(hipo::event &ev) {

    if (&ev == nullptr) {
        std::cout << "The event pointer is null, Exiting" << std::endl;
        exit(1);
    }

    fEv = &ev;

    /*
     * Cleaning everything from previous event
     */
    v_BMTadcs.clear();
    v_BMTadcs.shrink_to_fit();
    v_CVTTracks.clear();
    v_CVTTracks.shrink_to_fit();
    v_BMTRecHits.clear();
    v_BMTRecHits.shrink_to_fit();

    nBMTadc = ReadBank_BMT_adc();
    nBMTRecHits = ReadBank_BMTRec_Hits();

}

int TVertexAna::ReadBank_BMT_adc() {
    fEv->getStructure(bBMT_adc);

    nBMTadc = bBMT_adc.getRows();

    for (int i = 0; i < nBMTadc; i++) {
        TBMTadc curBMTadc;

        curBMTadc.adc = bBMT_adc.getInt("ADC", i);
        curBMTadc.component = bBMT_adc.getInt("component", i);
        curBMTadc.integral = bBMT_adc.getInt("integral", i);
        curBMTadc.layer = bBMT_adc.getInt("layer", i);
        curBMTadc.order = bBMT_adc.getInt("order", i);
        curBMTadc.ped = bBMT_adc.getInt("ped", i);
        curBMTadc.sector = bBMT_adc.getInt("sector", i);
        curBMTadc.time = bBMT_adc.getFloat("time", i);
        curBMTadc.timestamp = bBMT_adc.getLong("timestamp", i);

        v_BMTadcs.push_back(curBMTadc);
    }

    return nBMTadc;
}

int TVertexAna::ReadBank_BMTRec_Hits() {
    fEv->getStructure(bBMTRec_Hits);

    nBMTRecHits = bBMTRec_Hits.getRows();

    for (int i = 0; i < nBMTRecHits; i++) {
        TBMTRecHits curBMTRecHit;

        curBMTRecHit.ID = bBMTRec_Hits.getInt("ID", i);
        curBMTRecHit.clusterID = bBMTRec_Hits.getInt("clusterID", i);
        curBMTRecHit.fitResidual = bBMTRec_Hits.getFloat("fitResidual", i);
        curBMTRecHit.layer = bBMTRec_Hits.getInt("layer", i);
        curBMTRecHit.sector = bBMTRec_Hits.getInt("layer", i);
        curBMTRecHit.strip = bBMTRec_Hits.getInt("strip", i);
        curBMTRecHit.trkID = bBMTRec_Hits.getInt("trkID", i);
        curBMTRecHit.trkingStat = bBMTRec_Hits.getInt("trkingStat", i);

        v_BMTRecHits.push_back(curBMTRecHit);

    }

    return nBMTRecHits;
}

int TVertexAna::ReadBank_BMTRec_Clusters() {
    fEv->getStructure(bBMTRec_Clusters);

    nBMTRecClusters = bBMTRec_Clusters.getRows();

    for (int i = 0; i < nBMTRecClusters; i++) {
        TBMTRecClusters curBMTRecCluster;

        curBMTRecCluster.ETot = bBMTRec_Clusters.getFloat("Etot", i);
        curBMTRecCluster.Hit1_ID = bBMTRec_Clusters.getInt("hit1_ID", i);
        curBMTRecCluster.Hit2_ID = bBMTRec_Clusters.getInt("hit2_ID", i);
        curBMTRecCluster.Hit3_ID = bBMTRec_Clusters.getInt("hit3_ID", i);
        curBMTRecCluster.Hit4_ID = bBMTRec_Clusters.getInt("hit4_ID", i);
        curBMTRecCluster.Hit5_ID = bBMTRec_Clusters.getInt("hit5_ID", i);
        curBMTRecCluster.ID = bBMTRec_Clusters.getInt("ID", i);
        curBMTRecCluster.centroid = bBMTRec_Clusters.getFloat("centroid", i);
        curBMTRecCluster.centroidResidual = bBMTRec_Clusters.getFloat("centroidResidual", i);
        curBMTRecCluster.layer = bBMTRec_Clusters.getInt("layer", i);
        curBMTRecCluster.sector = bBMTRec_Clusters.getInt("sector", i);
        curBMTRecCluster.seedE = bBMTRec_Clusters.getFloat("seedE", i);
        curBMTRecCluster.seedResidual = bBMTRec_Clusters.getFloat("seedResidual", i);
        curBMTRecCluster.seedStrip = bBMTRec_Clusters.getInt("seedStrip", i);
        curBMTRecCluster.size = bBMTRec_Clusters.getInt("size", i);
        curBMTRecCluster.trkID = bBMTRec_Clusters.getInt("trkID", i);

        v_BMTRecClusters.push_back(curBMTRecCluster);
    }

    return nBMTRecClusters;
}

TBMTadc * TVertexAna::GetBMTadc(int aind) {

    if (aind >= v_BMTadcs.size() || aind < 0) {
        std::cout << "The index is " << aind << "   which is outside of boundaries of the vector 'v_BMTadcs' having the size " << v_BMTadcs.size() << std::endl;
        std::cout << "Exiting" << std::endl;
        exit(1);
    }

    return &v_BMTadcs.at(aind);
}

TBMTRecHits * TVertexAna::GetBMTRecHit(int aind) {

    if (aind >= v_BMTRecHits.size() || aind < 0) {
        std::cout << "The index is " << aind << "   which is outside of boundaries of the vector 'v_BMTRecHits' having the size " << v_BMTRecHits.size() << std::endl;
        std::cout << "Exiting" << std::endl;
        exit(1);
    }

    return &v_BMTRecHits.at(aind);
}

TBMTRecClusters * TVertexAna::GetBMTRecCluster(int aind) {

    if (aind >= v_BMTRecClusters.size() || aind < 0) {
        std::cout << "The index is " << aind << "   which is outside of boundaries of the vector 'v_BMTRecHits' having the size " << v_BMTRecClusters.size() << std::endl;
        std::cout << "Exiting" << std::endl;
        exit(1);
    }

    return &v_BMTRecClusters.at(aind);
}