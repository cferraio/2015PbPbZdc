//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul  8 01:30:15 2011 by ROOT version 5.27/06b
// from TTree ZDCDigiTree/ZDC Digi Tree
// found on file: /data/users/belt/PbPb_data/zdc/zdctrees_151350_151351_allev_OlegRaw.root
//////////////////////////////////////////////////////////

#ifndef HADsignal_TSfull_h
#define HADsignal_TSfull_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class HADsignal_TSfull {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         negEM1fC[10];
   Int_t           negEM1ADC[10];
   Float_t         negEM2fC[10];
   Int_t           negEM2ADC[10];
   Float_t         negEM3fC[10];
   Int_t           negEM3ADC[10];
   Float_t         negEM4fC[10];
   Int_t           negEM4ADC[10];
   Float_t         negEM5fC[10];
   Int_t           negEM5ADC[10];
   Float_t         negHD1fC[10];
   Int_t           negHD1ADC[10];
   Float_t         negHD2fC[10];
   Int_t           negHD2ADC[10];
   Float_t         negHD3fC[10];
   Int_t           negHD3ADC[10];
   Float_t         negHD4fC[10];
   Int_t           negHD4ADC[10];
   Float_t         posEM1fC[10];
   Int_t           posEM1ADC[10];
   Float_t         posEM2fC[10];
   Int_t           posEM2ADC[10];
   Float_t         posEM3fC[10];
   Int_t           posEM3ADC[10];
   Float_t         posEM4fC[10];
   Int_t           posEM4ADC[10];
   Float_t         posEM5fC[10];
   Int_t           posEM5ADC[10];
   Float_t         posHD1fC[10];
   Int_t           posHD1ADC[10];
   Float_t         posHD2fC[10];
   Int_t           posHD2ADC[10];
   Float_t         posHD3fC[10];
   Int_t           posHD3ADC[10];
   Float_t         posHD4fC[10];
   Int_t           posHD4ADC[10];
   Int_t Cent_HFtowers;

   // List of branches
   TBranch        *b_negEM1cFtsz;   //!
   TBranch        *b_negEM1ADCtsz;   //!
   TBranch        *b_negEM2cFtsz;   //!
   TBranch        *b_negEM2ADCtsz;   //!
   TBranch        *b_negEM3cFtsz;   //!
   TBranch        *b_negEM3ADCtsz;   //!
   TBranch        *b_negEM4cFtsz;   //!
   TBranch        *b_negEM4ADCtsz;   //!
   TBranch        *b_negEM5cFtsz;   //!
   TBranch        *b_negEM5ADCtsz;   //!
   TBranch        *b_negHD1cFtsz;   //!
   TBranch        *b_negHD1ADCtsz;   //!
   TBranch        *b_negHD2cFtsz;   //!
   TBranch        *b_negHD2ADCtsz;   //!
   TBranch        *b_negHD3cFtsz;   //!
   TBranch        *b_negHD3ADCtsz;   //!
   TBranch        *b_negHD4cFtsz;   //!
   TBranch        *b_negHD4ADCtsz;   //!
   TBranch        *b_posEM1cFtsz;   //!
   TBranch        *b_posEM1ADCtsz;   //!
   TBranch        *b_posEM2cFtsz;   //!
   TBranch        *b_posEM2ADCtsz;   //!
   TBranch        *b_posEM3cFtsz;   //!
   TBranch        *b_posEM3ADCtsz;   //!
   TBranch        *b_posEM4cFtsz;   //!
   TBranch        *b_posEM4ADCtsz;   //!
   TBranch        *b_posEM5cFtsz;   //!
   TBranch        *b_posEM5ADCtsz;   //!
   TBranch        *b_posHD1cFtsz;   //!
   TBranch        *b_posHD1ADCtsz;   //!
   TBranch        *b_posHD2cFtsz;   //!
   TBranch        *b_posHD2ADCtsz;   //!
   TBranch        *b_posHD3cFtsz;   //!
   TBranch        *b_posHD3ADCtsz;   //!
   TBranch        *b_posHD4cFtsz;   //!
   TBranch        *b_posHD4ADCtsz;   //!

   HADsignal_TSfull(TTree *tree=0,TTree *centtree=0);
   virtual ~HADsignal_TSfull();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree, TTree *centtree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HADsignal_TSfull_cxx
HADsignal_TSfull::HADsignal_TSfull(TTree *tree,TTree *centtree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/NoiseRun263005.root");
      if (!f) {
         f = new TFile("/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/NoiseRun263005.root");
      }
      tree = (TTree*)gDirectory->Get("ZDCDigiTree");
      centtree=(TTree*) f->Get("CentTree");

   }
   Init(tree,centtree);
}

HADsignal_TSfull::~HADsignal_TSfull()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HADsignal_TSfull::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HADsignal_TSfull::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HADsignal_TSfull::Init(TTree *tree, TTree *centtree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   centtree->SetBranchAddress("Cent_HFtowers",&Cent_HFtowers);
 
   fChain->SetBranchAddress("negEM1fC", negEM1fC, &b_negEM1cFtsz);
   fChain->SetBranchAddress("negEM1ADC", negEM1ADC, &b_negEM1ADCtsz);
   fChain->SetBranchAddress("negEM2fC", negEM2fC, &b_negEM2cFtsz);
   fChain->SetBranchAddress("negEM2ADC", negEM2ADC, &b_negEM2ADCtsz);
   fChain->SetBranchAddress("negEM3fC", negEM3fC, &b_negEM3cFtsz);
   fChain->SetBranchAddress("negEM3ADC", negEM3ADC, &b_negEM3ADCtsz);

   fChain->SetBranchAddress("negEM4fC", negHD1fC, &b_negHD1cFtsz);
   fChain->SetBranchAddress("negEM4ADC", negHD1ADC, &b_negHD1ADCtsz);
   fChain->SetBranchAddress("negHD1fC", negEM4fC, &b_negEM4cFtsz);
   fChain->SetBranchAddress("negHD1ADC", negEM4ADC, &b_negEM4ADCtsz);





   fChain->SetBranchAddress("negEM5fC", negEM5fC, &b_negEM5cFtsz);
   fChain->SetBranchAddress("negEM5ADC", negEM5ADC, &b_negEM5ADCtsz);
   fChain->SetBranchAddress("negHD2fC", negHD2fC, &b_negHD2cFtsz);
   fChain->SetBranchAddress("negHD2ADC", negHD2ADC, &b_negHD2ADCtsz);
   fChain->SetBranchAddress("negHD3fC", negHD3fC, &b_negHD3cFtsz);
   fChain->SetBranchAddress("negHD3ADC", negHD3ADC, &b_negHD3ADCtsz);
   fChain->SetBranchAddress("negHD4fC", negHD4fC, &b_negHD4cFtsz);
   fChain->SetBranchAddress("negHD4ADC", negHD4ADC, &b_negHD4ADCtsz);
   fChain->SetBranchAddress("posEM1fC", posEM1fC, &b_posEM1cFtsz);
   fChain->SetBranchAddress("posEM1ADC", posEM1ADC, &b_posEM1ADCtsz);
   fChain->SetBranchAddress("posEM2fC", posEM2fC, &b_posEM2cFtsz);
   fChain->SetBranchAddress("posEM2ADC", posEM2ADC, &b_posEM2ADCtsz);
   fChain->SetBranchAddress("posEM3fC", posEM3fC, &b_posEM3cFtsz);
   fChain->SetBranchAddress("posEM3ADC", posEM3ADC, &b_posEM3ADCtsz);
   fChain->SetBranchAddress("posEM4fC", posEM4fC, &b_posEM4cFtsz);
   fChain->SetBranchAddress("posEM4ADC", posEM4ADC, &b_posEM4ADCtsz);
   fChain->SetBranchAddress("posEM5fC", posEM5fC, &b_posEM5cFtsz);
   fChain->SetBranchAddress("posEM5ADC", posEM5ADC, &b_posEM5ADCtsz);
   fChain->SetBranchAddress("posHD1fC", posHD1fC, &b_posHD1cFtsz);
   fChain->SetBranchAddress("posHD1ADC", posHD1ADC, &b_posHD1ADCtsz);
   fChain->SetBranchAddress("posHD2fC", posHD2fC, &b_posHD2cFtsz);
   fChain->SetBranchAddress("posHD2ADC", posHD2ADC, &b_posHD2ADCtsz);
   fChain->SetBranchAddress("posHD3fC", posHD3fC, &b_posHD3cFtsz);
   fChain->SetBranchAddress("posHD3ADC", posHD3ADC, &b_posHD3ADCtsz);
   fChain->SetBranchAddress("posHD4fC", posHD4fC, &b_posHD4cFtsz);
   fChain->SetBranchAddress("posHD4ADC", posHD4ADC, &b_posHD4ADCtsz);
   Notify();
}

Bool_t HADsignal_TSfull::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HADsignal_TSfull::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HADsignal_TSfull::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HADsignal_TSfull_cxx
