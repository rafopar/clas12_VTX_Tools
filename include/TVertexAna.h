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

class TVertexAna {
public:
    TVertexAna(hipo::dictionary &);
    TVertexAna(const TVertexAna& orig);
    virtual ~TVertexAna();

    TCVTTrack* GetCVTTrack(int); // Return the pointer to the "i-th" element of the vector TCVTTrack
    TBMTadc* GetBMTadc(int); // Return the pointer to the "i-th" element of the vector v_BMTadcs
    TBMTRecHits* GetBMTRecHit(int); // Return the pointer to the "i-th" element of the vector v_BMTRecHits
    TBMTRecClusters* GetBMTRecCluster(int); // Return the pointer to the "i-th" element of the vector v_BMTRecClusters

    void ReadEvent(hipo::event&); // Read banks

    /*
     * Getter Methods
     */
    int GetNBMTADC() {
        return v_BMTadcs.size();
    };

    int GetNBMTRecHits() {
        return v_BMTRecHits.size();
    };
    
    

private:

    int nCVTTracks; // The number of CVT tracks in the event
    int nCVTTrajectories; // The number of CVT trajectories in the event
    int nBMTCrosses; // The number of BMT crosses
    int nBSTCrosses; // The number of BST crosses
    int nBMTadc; // The number of adc hits in BMT
    int nBMTRecHits; // The number of BMT hits
    int nBMTRecClusters; // The number of BMT Clusters
    int nBSTHits; // The number of BST hits
    int nFMTHits; // The number of FMT hits

    std::vector<TCVTTrack> v_CVTTracks; // Vector of TCVTTracks in the event
    std::vector<TBMTadc> v_BMTadcs; // Vector of TBMTadcs in the event
    std::vector<TBMTRecHits> v_BMTRecHits; // Vector of TBMTRecHits in the event
    std::vector<TBMTRecClusters> v_BMTRecClusters; // Vector of TBMTRecClusters in the event
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

};

#endif /* TVERTEXEVENT_H */