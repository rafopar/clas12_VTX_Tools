/* 
 * File:   TVertexAna.cc
 * Author: rafopar
 * 
 * Created on November 25, 2021, 12:17 PM
 */

#include <iostream>
#include <map>
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
    m_BMTadcs.clear();
    v_CVTTracks.clear();
    v_CVTTracks.shrink_to_fit();
    m_BMTRecHits.clear();
    m_BMTRecClusters.clear();
    m_BMTRecCrosses.clear();

    nBMTadc = ReadBank_BMT_adc();
    nBMTRecHits = ReadBank_BMTRec_Hits();
    nBMTRecClusters = ReadBank_BMTRec_Clusters();
    nBMTCrosses = ReadBank_BMTRec_Crosses();
}

int TVertexAna::ReadBank_BMT_adc() {
    fEv->getStructure(bBMT_adc);

    nBMTadc = bBMT_adc.getRows();

    for (int i = 0; i < nBMTadc; i++) {
        TBMTadc curBMTadc;

        curBMTadc.ADC = bBMT_adc.getInt("ADC", i);
        curBMTadc.component = bBMT_adc.getInt("component", i);
        curBMTadc.integral = bBMT_adc.getInt("integral", i);
        curBMTadc.layer = bBMT_adc.getInt("layer", i);
        curBMTadc.order = bBMT_adc.getInt("order", i);
        curBMTadc.ped = bBMT_adc.getInt("ped", i);
        curBMTadc.sector = bBMT_adc.getInt("sector", i);
        curBMTadc.time = bBMT_adc.getFloat("time", i);
        curBMTadc.timestamp = bBMT_adc.getLong("timestamp", i);

        m_BMTadcs[i + 1] = curBMTadc;
    }

    return nBMTadc;
}

int TVertexAna::ReadBank_BMTRec_Hits() {
    fEv->getStructure(bBMTRec_Hits);

    nBMTRecHits = bBMTRec_Hits.getRows();

    for (int i = 0; i < nBMTRecHits; i++) {
        TBMTRecHit curBMTRecHit;

        curBMTRecHit.ID = bBMTRec_Hits.getInt("ID", i);
        curBMTRecHit.clusterID = bBMTRec_Hits.getInt("clusterID", i);
        curBMTRecHit.fitResidual = bBMTRec_Hits.getFloat("fitResidual", i);
        curBMTRecHit.layer = bBMTRec_Hits.getInt("layer", i);
        curBMTRecHit.sector = bBMTRec_Hits.getInt("layer", i);
        curBMTRecHit.strip = bBMTRec_Hits.getInt("strip", i);
        curBMTRecHit.trkID = bBMTRec_Hits.getInt("trkID", i);
        curBMTRecHit.trkingStat = bBMTRec_Hits.getInt("trkingStat", i);

        m_BMTRecHits[curBMTRecHit.ID] = curBMTRecHit;
    }

    return nBMTRecHits;
}

int TVertexAna::ReadBank_BMTRec_Clusters() {
    fEv->getStructure(bBMTRec_Clusters);

    nBMTRecClusters = bBMTRec_Clusters.getRows();

    for (int i = 0; i < nBMTRecClusters; i++) {
        TBMTRecCluster curBMTRecCluster;

        curBMTRecCluster.ETot = bBMTRec_Clusters.getFloat("ETot", i);
        curBMTRecCluster.time = bBMTRec_Clusters.getFloat("time", i);
        curBMTRecCluster.Hit1_ID = bBMTRec_Clusters.getInt("Hit1_ID", i);
        curBMTRecCluster.Hit2_ID = bBMTRec_Clusters.getInt("Hit2_ID", i);
        curBMTRecCluster.Hit3_ID = bBMTRec_Clusters.getInt("Hit3_ID", i);
        curBMTRecCluster.Hit4_ID = bBMTRec_Clusters.getInt("Hit4_ID", i);
        curBMTRecCluster.Hit5_ID = bBMTRec_Clusters.getInt("Hit5_ID", i);
        curBMTRecCluster.ID = bBMTRec_Clusters.getInt("ID", i);
        curBMTRecCluster.centroid = bBMTRec_Clusters.getFloat("centroid", i);
        curBMTRecCluster.centroidValue = bBMTRec_Clusters.getFloat("centroidValue", i);
        curBMTRecCluster.centroidError = bBMTRec_Clusters.getFloat("centroidError", i);
        curBMTRecCluster.centroidResidual = bBMTRec_Clusters.getFloat("centroidResidual", i);
        curBMTRecCluster.layer = bBMTRec_Clusters.getInt("layer", i);
        curBMTRecCluster.sector = bBMTRec_Clusters.getInt("sector", i);
        curBMTRecCluster.seedE = bBMTRec_Clusters.getFloat("seedE", i);
        curBMTRecCluster.seedResidual = bBMTRec_Clusters.getFloat("seedResidual", i);
        curBMTRecCluster.seedStrip = bBMTRec_Clusters.getInt("seedStrip", i);
        curBMTRecCluster.size = bBMTRec_Clusters.getInt("size", i);
        curBMTRecCluster.trkID = bBMTRec_Clusters.getInt("trkID", i);
        curBMTRecCluster.x1 = bBMTRec_Clusters.getFloat("x1", i);
        curBMTRecCluster.y1 = bBMTRec_Clusters.getFloat("y1", i);
        curBMTRecCluster.z1 = bBMTRec_Clusters.getFloat("z1", i);
        curBMTRecCluster.x2 = bBMTRec_Clusters.getFloat("x2", i);
        curBMTRecCluster.y2 = bBMTRec_Clusters.getFloat("y2", i);
        curBMTRecCluster.z2 = bBMTRec_Clusters.getFloat("z2", i);
        curBMTRecCluster.theta = bBMTRec_Clusters.getFloat("theta", i);
        curBMTRecCluster.ax1 = bBMTRec_Clusters.getFloat("ax1", i);
        curBMTRecCluster.ay1 = bBMTRec_Clusters.getFloat("ay1", i);
        curBMTRecCluster.az1 = bBMTRec_Clusters.getFloat("az1", i);
        curBMTRecCluster.ax2 = bBMTRec_Clusters.getFloat("ax2", i);
        curBMTRecCluster.ay2 = bBMTRec_Clusters.getFloat("ay2", i);
        curBMTRecCluster.az2 = bBMTRec_Clusters.getFloat("az2", i);
        curBMTRecCluster.lx = bBMTRec_Clusters.getFloat("lx", i);
        curBMTRecCluster.ly = bBMTRec_Clusters.getFloat("ly", i);
        curBMTRecCluster.lz = bBMTRec_Clusters.getFloat("lz", i);
        curBMTRecCluster.sx = bBMTRec_Clusters.getFloat("sx", i);
        curBMTRecCluster.sy = bBMTRec_Clusters.getFloat("sy", i);
        curBMTRecCluster.sz = bBMTRec_Clusters.getFloat("sz", i);
        curBMTRecCluster.nx = bBMTRec_Clusters.getFloat("nx", i);
        curBMTRecCluster.ny = bBMTRec_Clusters.getFloat("ny", i);
        curBMTRecCluster.nz = bBMTRec_Clusters.getFloat("nz", i);

        m_BMTRecClusters[curBMTRecCluster.ID] = curBMTRecCluster;
    }

    return nBMTRecClusters;
}

int TVertexAna::ReadBank_BMTRec_Crosses() {
    fEv->getStructure(bBMTRec_Crosses);

    nBMTCrosses = bBMTRec_Crosses.getRows();

    for (int i = 0; i < nBMTCrosses; i++) {
        TBMTRecCross curBMTCross;
        curBMTCross.Cluster1_ID = bBMTRec_Crosses.getInt("Cluster1_ID", i);
        curBMTCross.Cluster2_ID = bBMTRec_Crosses.getInt("Cluster2_ID", i);
        curBMTCross.ID = bBMTRec_Crosses.getInt("ID", i);
        curBMTCross.err_x = bBMTRec_Crosses.getFloat("err_x", i);
        curBMTCross.err_y = bBMTRec_Crosses.getFloat("err_y", i);
        curBMTCross.err_z = bBMTRec_Crosses.getFloat("err_z", i);
        curBMTCross.region = bBMTRec_Crosses.getInt("region", i);
        curBMTCross.sector = bBMTRec_Crosses.getInt("sector", i);
        curBMTCross.trkID = bBMTRec_Crosses.getInt("trkID", i);
        curBMTCross.ux = bBMTRec_Crosses.getFloat("ux", i);
        curBMTCross.uy = bBMTRec_Crosses.getFloat("uy", i);
        curBMTCross.uz = bBMTRec_Crosses.getFloat("uz", i);
        curBMTCross.x = bBMTRec_Crosses.getFloat("x", i);
        curBMTCross.y = bBMTRec_Crosses.getFloat("y", i);
        curBMTCross.z = bBMTRec_Crosses.getFloat("z", i);

        m_BMTRecCrosses[curBMTCross.ID] = curBMTCross;
    }

    return nBMTCrosses;
}

int TVertexAna::ReadBank_BST_adc() {
    fEv->getStructure(bBST_adc);

    nBSTadc = bBST_adc.getRows();

    for (int i = 0; i < nBSTadc; i++) {
        TBSTadc curBSTadc;

        curBSTadc.ADC = bBST_adc.getInt("ADC", i);
        curBSTadc.component = bBST_adc.getInt("component", i);
        curBSTadc.layer = bBST_adc.getInt("layer", i);
        curBSTadc.order = bBST_adc.getInt("order", i);
        curBSTadc.ped = bBST_adc.getInt("ped", i);
        curBSTadc.sector = bBST_adc.getInt("sector", i);
        curBSTadc.time = bBST_adc.getFloat("time", i);
        curBSTadc.timestamp = bBST_adc.getLong("timestamp", i);
        curBSTadc.integral = 0; // This doesn't apply to BST so we assign to 0
        m_BSTadcs[i + 1] = curBSTadc;
    }

    return nBSTadc;
}

int TVertexAna::ReadBank_BSTRec_Hits() {
    fEv->getStructure(bBSTRec_Hits);

    nBSTRecHits = bBSTRec_Hits.getRows();

    for (int i = 0; i < nBSTRecHits; i++) {
        TBSTRecHit curBSTRecHit;

        curBSTRecHit.ID = bBMTRec_Hits.getInt("ID", i);
        curBSTRecHit.clusterID = bBMTRec_Hits.getInt("clusterID", i);
        curBSTRecHit.fitResidual = bBMTRec_Hits.getFloat("fitResidual", i);
        curBSTRecHit.layer = bBMTRec_Hits.getInt("layer", i);
        curBSTRecHit.sector = bBMTRec_Hits.getInt("layer", i);
        curBSTRecHit.strip = bBMTRec_Hits.getInt("strip", i);
        curBSTRecHit.trkID = bBMTRec_Hits.getInt("trkID", i);
        curBSTRecHit.trkingStat = bBMTRec_Hits.getInt("trkingStat", i);

        m_BMTRecHits[curBSTRecHit.ID] = curBSTRecHit;
    }

    return nBMTRecHits;
}


TBMTadc * TVertexAna::GetBMTadc(int aind) {

    if (m_BMTadcs.find(aind) == m_BMTadcs.end()) {
        std::cout << " The map m_BMTadcs doesn't have an entry with index = " << aind << std::endl;
        std::cout << "Elements of the map are    ";
    }
    for (const auto element : m_BMTadcs) {
        std::cout << element.first << "   ";
    }
    std::cout << std::endl << "Exiting" << std::endl;
    exit(1);

    return &m_BMTadcs.at(aind);
}

TBMTRecHit * TVertexAna::GetBMTRecHit(int aHitID) {

    if (m_BMTRecHits.find(aHitID) == m_BMTRecHits.end()) {
        std::cout << " The map m_BMTRecHits doesn't have an entry with HitID = " << aHitID << std::endl;
        std::cout << "Elements of the map are    ";

        for (const auto element : m_BMTRecHits) {
            std::cout << element.first << "   ";
        }

        std::cout << std::endl << "Exiting" << std::endl;
        exit(1);
    }


    return &m_BMTRecHits[aHitID];
}

TBMTRecCluster * TVertexAna::GetBMTRecCluster(int aClID) {

    if (m_BMTRecClusters.find(aClID) == m_BMTRecClusters.end()) {
        std::cout << " The map m_BMTRecClusters doesn't have an entry with ID = " << aClID << std::endl;
        std::cout << "Elements of the map are    ";

        for (const auto element : m_BMTRecClusters) {
            std::cout << element.first << "   ";
        }

        std::cout << std::endl << "Exiting" << std::endl;
        exit(1);
    }


    return &m_BMTRecClusters[aClID];
}

TBSTadc * TVertexAna::GetBSTadc(int aind) {

    if (m_BSTadcs.find(aind) == m_BSTadcs.end()) {
        std::cout << " The map m_BSTadcs doesn't have an entry with index = " << aind << std::endl;
        std::cout << "Elements of the map are    ";
    }
    for (const auto element : m_BSTadcs) {
        std::cout << element.first << "   ";
    }
    std::cout << std::endl << "Exiting" << std::endl;
    exit(1);

    return &m_BSTadcs.at(aind);
}
