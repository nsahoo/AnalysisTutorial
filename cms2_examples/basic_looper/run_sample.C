#include <iostream>
#include "TChain.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TROOT.h"
#include "interface/ScanChain.h"

int run_sample(const long num_events = -1)
{

  std::cout<<__LINE__<<std::endl;
  gSystem->Load("libcms2_looper.so");

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain chain("Events");
  chain.Add("/nfs-7/userdata/rwkelley/cms2/dyjets_ntuple_slim_10k_53X_v2.root");
  // chain.Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/merged_ntuple_1.root");
  // chain.Add("/hadoop/cms/store/user/cwelke/CMS2_V05-03-18/DYToMuMu_M-20_CT10_TuneZ2star_v2_8TeV-powheg-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/ntuple_191_1_zZL.root");
  // chain.Add("/hadoop/cms/store/user/cwelke/CMS2_V05-03-18/DYToMuMu_M-20_CT10_TuneZ2star_v2_8TeV-powheg-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/ntuple_1910_1_rOc.root");
  // chain.Add("~/MCNtupling/CMSSW/CMSSW_5_3_2_patch4_V05-03-23/crab/makecms2ntuple/post_processed_ntuple.root");

  CMS2Looper looper;
  std::cout << "running cms2 looper..." << std::endl;
  looper.ScanChain(chain, num_events);

  return 0;
}