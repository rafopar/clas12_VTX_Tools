/* 
 * File:   TVertexAna.h
 * Author: rafopar
 *
 * Created on November 25, 2021, 12:17 PM
 */

#ifndef TVERTEXANA_H
#define TVERTEXANA_H

#include <iostream>

// ===== Hipo headers =====
#include <reader.h>
#include <writer.h>
#include <dictionary.h>

// ===== Vertex sub includes =====
#include <BankStructures.h>
#include <vector>
#include <map>

typedef TCVTadc TBMTadc;
typedef TCVTadc TBSTadc;
typedef TCVTRecHit TBMTRecHit;
typedef TCVTRecHit TBSTRecHit;

class TVertexAna {
public:
    TVertexAna(hipo::dictionary &);
    TVertexAna(const TVertexAna& orig);
    virtual ~TVertexAna();

    TCVTTrack* GetCVTTrack(int); // Return the pointer to the "i-th" element of the vector TCVTTrack
    TBMTadc* GetBMTadc(int); // Return the pointer to the TBMTadc, where the argument is the index of the element in the bank
    TBMTRecHit* GetBMTRecHit(int); // Return the pointer to the TBMTRecHit, where the argument is the hitID of the hit
    TBMTRecCluster* GetBMTRecCluster(int); // Return the pointer to the TBMTRecCluster, where the argument is the KEY (ID) of the TBMTRecCluster
    TBSTadc* GetBSTadc(int); // Return the pointer to the TBSTadc, where the argument is the index of the element in the bank

    void ReadEvent(hipo::event&); // Read banks

    /*
     * Getter Methods
     */
    int GetNBMTADC() {
        return m_BMTadcs.size();
    };

    int GetNBMTRecHits() {
        return m_BMTRecHits.size();
    };
    
    int GetNBMTRecCrosses(){
        return m_BMTRecCrosses.size();
    }
    
    std::map<int, TBMTRecHit> * GetBMTRecHits(){
        return &m_BMTRecHits;
    }
    int GetNBSTADC() {
        return m_BSTadcs.size();
    };
    

private:

    int nCVTTracks; // The number of CVT tracks in the event
    int nCVTTrajectories; // The number of CVT trajectories in the event
    int nBMTCrosses; // The number of BMT crosses
    int nBMTadc; // The number of adc hits in BMT
    int nBMTRecHits; // The number of BMT hits
    int nBMTRecClusters; // The number of BMT Clusters
    int nBSTadc; // The number of adc hits in BST
    int nBSTRecHits; // The number of BMT hits
    int nBSTCrosses; // The number of BST crosses
    int nBSTHits; // The number of BST hits
    int nFMTHits; // The number of FMT hits

    std::vector<TCVTTrack> v_CVTTracks; // Vector of TCVTTracks in the event
    std::map<int, TBMTadc> m_BMTadcs; // Map of TBMTadcs in the event, where the key of the map is the index of the adc hit in the bank
    std::map<int, TBMTRecHit> m_BMTRecHits; // Map of TBMTRecHits in the event, where the key of the map is the hitID
    std::map<int, TBMTRecCluster> m_BMTRecClusters; // Map of TBMTRecClusters in the event, where the key of the map is the ID of the cluster
    std::map<int, TBMTRecCross> m_BMTRecCrosses; // Map of TBMTRecCross in the event, where the key of the map is the ID of the cross
    std::map<int, TBSTadc> m_BSTadcs; // Map of TSMTadcs in the event, where the key of the map is the index of the adc hit in the bank
    hipo::dictionary fDict; // Hipo dictionary for the file

    hipo::event *fEv; // Current Event

    /**
     * Banks 
     */

    hipo::bank bBMT_adc;
    hipo::bank bBMTRec_Clusters;
    hipo::bank bBMTRec_Crosses;
    hipo::bank bBMTRec_Hits;
    hipo::bank bBST_adc;
    hipo::bank bBSTRec_Clusters;
    hipo::bank bBSTRec_Crosses;
    hipo::bank bBSTRec_Hits;
    hipo::bank bCVTRec_Seeds;
    hipo::bank bCVTRec_Tracks;
    hipo::bank bCVTRec_Trajectory;

    /*
     * Functions
     */
    void InitDictionary(hipo::dictionary &); // Get the bank structures from the dictionary
    int ReadBank_BMT_adc();
    int ReadBank_BMTRec_Hits();
    int ReadBank_BMTRec_Clusters();
    int ReadBank_BMTRec_Crosses();
    int ReadBank_BST_adc();
    int ReadBank_BSTRec_Hits();

};

#endif /* TVERTEXEVENT_H */