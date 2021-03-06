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
typedef TCVTRecCross TBSTRecCross;
typedef TCVTRecCross TBMTRecCross;

class TVertexAna {
public:
    TVertexAna(hipo::dictionary &);
    TVertexAna(const TVertexAna& orig);
    virtual ~TVertexAna();

    TCVTRecTrack* GetCVTTrack(int); // Return the pointer to the "i-th" element of the vector TCVTTrack
    TBMTadc* GetBMTadc(int); // Return the pointer to the TBMTadc, where the argument is the index of the element in the bank
    TBMTRecHit* GetBMTRecHit(int); // Return the pointer to the TBMTRecHit, where the argument is the hitID of the hit
    TBMTRecCluster* GetBMTRecCluster(int); // Return the pointer to the TBMTRecCluster, where the argument is the KEY (ID) of the TBMTRecCluster
    TBMTRecCross* GetBMTRecCross(int); // Return the pointer to the TBMTRecCross, where the argument is the KEY (ID) of the TBMTRecCross
    TBSTadc* GetBSTadc(int); // Return the pointer to the TBSTadc, where the argument is the index of the element in the bank
    TBSTRecHit* GetBSTRecHit(int); // Return the pointer to the TBSTRecHit, where the argument is the hitID of the hit
    TBSTRecCluster* GetBSTRecCluster(int); // Return the pointer to the TBSTRecCluster, where the argument is the KEY (ID) of the TBSTRecCluster
    TBSTRecCross* GetBSTRecCross(int); // Return the pointer to the TBSTRecCross, where the argument is the KEY (ID) of the TBSTRecCross

    void ReadEvent(hipo::event&); // Read banks

    /*
     * Getter Methods
     */
    int GetNBMTADC() {
        return m_BMTadcs.size();
    };
    
    std::map<int, TBMTadc> *GetBMTADCs(){
        return &m_BMTadcs;
    };

    int GetNBMTRecHits() {
        return m_BMTRecHits.size();
    };
    
    std::map<int, TBMTRecHit> * GetBMTRecHits(){
        return &m_BMTRecHits;
    };

    int GetNBMTRecClusters(){
        return m_BMTRecClusters.size();
    }
    
    std::map<int, TBMTRecCluster> *GetBMTRecClusters(){
        return &m_BMTRecClusters;
    }

    int GetNBMTRecCrosses(){
        return m_BMTRecCrosses.size();
    }
    
    std::map<int, TBMTRecCross> *GetBMTRecCrosses(){
        return &m_BMTRecCrosses;
    }
        
    int GetNBSTADC() {
        return m_BSTadcs.size();
    };
    
    std::map<int, TBMTadc> *GetBSTADC(){
        return &m_BSTadcs;
    }
    
    int GetNBSTRecHits() {
        return m_BSTRecHits.size();
    };
    
    std::map<int, TBSTRecHit> * GetBSTRecHits(){
        return &m_BSTRecHits;
    };
    
    int GetNBSTRecClusters(){
        return m_BSTRecClusters.size();
    }
        
    std::map<int, TBSTRecCluster> *GetBSTRecClusters(){
        return &m_BSTRecClusters;
    }
    
    int GetNCVTRecTracks(){
        return m_CVTRecTracks.size();
    }
    
    std::map<int, TCVTRecTrack> *GetCracks(){
        return &m_CVTRecTracks;
    }
    
    
    

private:

    int nCVTRecTracks; // The number of CVT tracks in the event
    int nCVTTrajectories; // The number of CVT trajectories in the event
    int nBMTadc; // The number of adc hits in BMT
    int nBMTRecHits; // The number of BMT hits
    int nBMTRecClusters; // The number of BMT Clusters
    int nBMTCrosses; // The number of BMT crosses
    int nBSTadc; // The number of adc hits in BST
    int nBSTRecHits; // The number of BST hits
    int nBSTRecClusters; // The number of BST Clusters
    int nBSTCrosses; // The number of BST crosses
    int nBSTHits; // The number of BST hits
    int nFMTHits; // The number of FMT hits

    std::map<int, TCVTRecTrack> m_CVTRecTracks; // Map of TCVTTracks in the event. The Key is the index in the bank
    std::map<int, TBMTadc> m_BMTadcs; // Map of TBMTadcs in the event, where the key of the map is the index of the adc hit in the bank
    std::map<int, TBMTRecHit> m_BMTRecHits; // Map of TBMTRecHits in the event, where the key of the map is the hitID
    std::map<int, TBMTRecCluster> m_BMTRecClusters; // Map of TBMTRecClusters in the event, where the key of the map is the ID of the cluster
    std::map<int, TBMTRecCross> m_BMTRecCrosses; // Map of TBMTRecCross in the event, where the key of the map is the ID of the cross
    std::map<int, TBSTadc> m_BSTadcs; // Map of TBSTadcs in the event, where the key of the map is the index of the adc hit in the bank
    std::map<int, TBSTRecHit> m_BSTRecHits; // Map of TBSTRecHits in the event, where the key of the map is the hitID
    std::map<int, TBSTRecCluster> m_BSTRecClusters; // Map of TBSTRecHits in the event, where the key of the map is the ClusterID
    std::map<int, TBSTRecCross> m_BSTRecCrosses; // Map of TBSTRecCrossess in the event, where the key of the map is the CrossID
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
    int ReadBank_BSTRec_Clusters();
    int ReadBank_BSTRec_Crosses();

    int ReadBank_CVTRecTracks();
};

#endif /* TVERTEXEVENT_H */