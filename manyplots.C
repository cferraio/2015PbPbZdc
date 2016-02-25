{

//energy distros (neutron peaks)
//channel integrated TS distros
//individual channel TS distros

gROOT->Reset();

int runnumber=263005;
Int_t NumberOfEvents;

char fCplot[200];
char outputfile[200];
char subdirname[200];
char TSname[200];
char TSsavename[200];
TDirectory *subdir;
sprintf(outputfile,"Allplots_run%i.root",runnumber);
TFile outfile(outputfile,"RECREATE");

TTree *centtree;
TTree *digitree;

double entriescol;
double entriesothers;
double ymax;
double ymin=0;

TH2F* histogram_2D_N_NS[4]; 
TH2F* histogram_2D_P_NS[4]; 
TH2F* histogram_2D_N_NNS[4];
TH2F* histogram_2D_P_NNS[4];

TH1F* histogram_1D_N_NS[4]; 
TH1F* histogram_1D_P_NS[4]; 
TH1F* histogram_1D_N_NNS[4]; 
TH1F* histogram_1D_P_NNS[4]; 

TH1F* histogram_1DSum_N_NS[4]; 
TH1F* histogram_1DSum_P_NS[4]; 
TH1F* histogram_1DSum_N_NNS[4];
TH1F* histogram_1DSum_P_NNS[4];

TH1F* histogram_1D_PosHAD1[4];
TH1F* histogram_1D_PosHAD2[4];
TH1F* histogram_1D_PosHAD3[4];
TH1F* histogram_1D_PosHAD4[4];
TH1F* histogram_1D_NegHAD1[4];
TH1F* histogram_1D_NegHAD2[4];
TH1F* histogram_1D_NegHAD3[4];
TH1F* histogram_1D_NegHAD4[4];

TH1F* histogram_1D_PosEM1[4];
TH1F* histogram_1D_PosEM2[4];
TH1F* histogram_1D_PosEM3[4];
TH1F* histogram_1D_PosEM4[4];
TH1F* histogram_1D_PosEM5[4];
TH1F* histogram_1D_NegEM1[4];
TH1F* histogram_1D_NegEM2[4];
TH1F* histogram_1D_NegEM3[4];
TH1F* histogram_1D_NegEM4[4];
TH1F* histogram_1D_NegEM5[4];

double NHADsumNNS;
double NHADsumNS;
double PHADsumNNS;
double PHADsumNS;
double NETsumNNS;
double NETsumNS;
double PETsumNNS;
double PETsumNS;
double PEMsumNNS;
double PEMsumNS;
double NEMsumNNS;
double NEMsumNS;


double em1x[10] = {-.3,0.7,1.7,2.7,3.7,4.7,5.7,6.7,7.7,8.7};
double em2x[10] = {-.15,0.85,1.85,2.85,3.85,4.85,5.85,6.85,7.85,8.85};
double em3x[10] = {0,1,2,3,4,5,6,7,8,9};
double em4x[10] = {0.15,1.15,2.15,3.15,4.15,5.15,6.15,7.15,8.15,9.15};
double em5x[10] = {0.3,1.3,2.3,3.3,4.3,5.3,6.3,7.3,8.3,9.3};
double had1x[10] = {-0.3,0.7,1.7,2.7,3.7,4.7,5.7,6.7,7.7,8.7};
double had2x[10] = {-0.1,0.9,1.9,2.9,3.9,4.9,5.9,6.9,7.9,8.9};
double had3x[10] = {0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1};
double had4x[10] = {0.3,1.3,2.3,3.3,4.3,5.3,6.3,7.3,8.3,9.3};
double nhad1y[10];
double nhad2y[10];
double nhad3y[10];
double nhad4y[10];
double phad1y[10];
double phad2y[10];
double phad3y[10];
double phad4y[10];

double nem1y[10];
double nem2y[10];
double nem3y[10];
double nem4y[10];
double nem5y[10];
double pem1y[10];
double pem2y[10];
double pem3y[10];
double pem4y[10];
double pem5y[10];  

float NHAD1TotalSignal;
float NHAD2TotalSignal;
float NHAD3TotalSignal;
float NHAD4TotalSignal;
float NEM1TotalSignal;
float NEM2TotalSignal;
float NEM3TotalSignal;
float NEM4TotalSignal;
float NEM5TotalSignal;

float PHAD1TotalSignal;
float PHAD2TotalSignal;
float PHAD3TotalSignal;
float PHAD4TotalSignal;
float PEM1TotalSignal;
float PEM2TotalSignal;
float PEM3TotalSignal;
float PEM4TotalSignal;
float PEM5TotalSignal;

Float_t negEM1fC[10];
Int_t negEM1ADC[10];
Float_t negEM2fC[10];
Int_t negEM2ADC[10];
Float_t negEM3fC[10];
Int_t negEM3ADC[10];
Float_t negEM4fC[10];
Int_t negEM4ADC[10];
Float_t negEM5fC[10];
Int_t negEM5ADC[10];
Float_t negHD1fC[10];
Int_t negHD1ADC[10];
Float_t negHD2fC[10];
Int_t negHD2ADC[10];
Float_t negHD3fC[10];
Int_t negHD3ADC[10];
Float_t negHD4fC[10];
Int_t negHD4ADC[10];
Float_t posEM1fC[10];
Int_t posEM1ADC[10];
Float_t posEM2fC[10];
Int_t posEM2ADC[10];
Float_t posEM3fC[10];
Int_t posEM3ADC[10];
Float_t posEM4fC[10];
Int_t posEM4ADC[10];
Float_t posEM5fC[10];
Int_t posEM5ADC[10];
Float_t posHD1fC[10];
Int_t posHD1ADC[10];
Float_t posHD2fC[10];
Int_t posHD2ADC[10];
Float_t posHD3fC[10];
Int_t posHD3ADC[10];
Float_t posHD4fC[10];
Int_t posHD4ADC[10];
double centrality[1];
Int_t Cent_HFtowers;

float NEM1TotalNoise;
float NEM2TotalNoise;
float NEM3TotalNoise;
float NEM4TotalNoise;
float NEM5TotalNoise;
float NHAD1TotalNoise;
float NHAD2TotalNoise;
float NHAD3TotalNoise;
float NHAD4TotalNoise;

float PEM1TotalNoise;
float PEM2TotalNoise;
float PEM3TotalNoise;
float PEM4TotalNoise;
float PEM5TotalNoise;
float PHAD1TotalNoise;
float PHAD2TotalNoise;
float PHAD3TotalNoise;
float PHAD4TotalNoise;

// List of branches
TBranch *b_negEM1cFtsz;   //!
TBranch *b_negEM1ADCtsz;   //!
TBranch *b_negEM2cFtsz;   //!
TBranch *b_negEM2ADCtsz;   //!
TBranch *b_negEM3cFtsz;   //!
TBranch *b_negEM3ADCtsz;   //!
TBranch *b_negEM4cFtsz;   //!
TBranch *b_negEM4ADCtsz;   //!
TBranch *b_negEM5cFtsz;   //!
TBranch *b_negEM5ADCtsz;   //!
TBranch *b_negHD1cFtsz;   //!
TBranch *b_negHD1ADCtsz;   //!
TBranch *b_negHD2cFtsz;   //!
TBranch *b_negHD2ADCtsz;   //!
TBranch *b_negHD3cFtsz;   //!
TBranch *b_negHD3ADCtsz;   //!
TBranch *b_negHD4cFtsz;   //!
TBranch *b_negHD4ADCtsz;   //!
TBranch *b_posEM1cFtsz;   //!
TBranch *b_posEM1ADCtsz;   //!
TBranch *b_posEM2cFtsz;   //!
TBranch *b_posEM2ADCtsz;   //!
TBranch *b_posEM3cFtsz;   //!
TBranch *b_posEM3ADCtsz;   //!
TBranch *b_posEM4cFtsz;   //!
TBranch *b_posEM4ADCtsz;   //!
TBranch *b_posEM5cFtsz;   //!
TBranch *b_posEM5ADCtsz;   //!
TBranch *b_posHD1cFtsz;   //!
TBranch *b_posHD1ADCtsz;   //!
TBranch *b_posHD2cFtsz;   //!
TBranch *b_posHD2ADCtsz;   //!
TBranch *b_posHD3cFtsz;   //!
TBranch *b_posHD3ADCtsz;   //!
TBranch *b_posHD4cFtsz;   //!
TBranch *b_posHD4ADCtsz;   //!


TLeaf *NEM4fC;
TLeaf *NEM4ADC;
TLeaf *NHAD2fC;
TLeaf *NHAD2ADC;
TLeaf *NHAD3fC;
TLeaf *NHAD3ADC;
TLeaf *NHAD4fC;
TLeaf *NHAD4ADC;
TLeaf *NEM1fC;
TLeaf *NEM1ADC;
TLeaf *NEM2fC;
TLeaf *NEM2ADC;
TLeaf *NEM3fC;
TLeaf *NEM3ADC;
TLeaf *NHAD1fC;
TLeaf *NHAD1ADC;
TLeaf *NEM5fC;
TLeaf *NEM5ADC;

TLeaf *PHAD1fC;
TLeaf *PHAD1ADC;
TLeaf *PHAD2fC;
TLeaf *PHAD2ADC;
TLeaf *PHAD3fC;
TLeaf *PHAD3ADC;
TLeaf *PHAD4fC;
TLeaf *PHAD4ADC;
TLeaf *PEM1fC;
TLeaf *PEM1ADC;
TLeaf *PEM2fC;
TLeaf *PEM2ADC;
TLeaf *PEM3fC;
TLeaf *PEM3ADC;
TLeaf *PEM4fC;
TLeaf *PEM4ADC;
TLeaf *PEM5fC;
TLeaf *PEM5ADC;

char filename[100];
char save1DNNS_N[100];
char save1DNS_N[100];
char save2DNNS_N[100];
char save2DNS_N[100];
char save1DNNS_P[100];
char save1DNS_P[100];
char save2DNNS_P[100];
char save2DNS_P[100];
char saveSumNS_N[100];
char saveSumNS_P[100];
char saveSumNNS_N[100];
char saveSumNNS_P[100];
char output1DNNS_N[100];
char output1DNS_N[100];
char output2DNNS_N[100];
char output2DNS_N[100];
char output1DNNS_P[100];
char output1DNS_P[100];
char output2DNNS_P[100];
char output2DNS_P[100];
char outputSumNS_N[100];
char outputSumNS_P[100];
char outputSumNNS_N[100];
char outputSumNNS_P[100];
char title[100];

TFile *f[4];

for(int file = 0; file < 4; file++){
//gROOT->Reset();
  if(file==0){
    sprintf(filename,"/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/HLT_HIL1Tech7_NoBPTX_263005.root");
    f[file] = TFile::Open(filename);
    centtree = (TTree*) f[file]->Get("CentTree");
    digitree = (TTree*) f[file]->Get("ZDCDigiTree");
  }
  if(file==1){
    sprintf(filename,"/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/HLT_HIL1Tech5_BPTX_PlusOnly_263005.root");
    f[file] = TFile::Open(filename);
    centtree = (TTree*) f[file]->Get("CentTree");
    digitree = (TTree*) f[file]->Get("ZDCDigiTree");
  }
  if(file==2){
    sprintf(filename,"/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/HLT_HIL1Tech6_BPTX_MinusOnly_263005.root");
    f[file] = TFile::Open(filename);
    centtree = (TTree*) f[file]->Get("CentTree");
    digitree = (TTree*) f[file]->Get("ZDCDigiTree");
  }
  if(file==3){
    sprintf(filename,"/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_263005.root");
    f[file] = TFile::Open(filename);
    centtree = (TTree*) f[file]->Get("ZDCRecTree");
    digitree = (TTree*) f[file]->Get("ZDCDigiTree");
  }
  
histogram_2D_N_NS[file] = new TH2F("NEM_vs_NHAD_Noise_Sub", "NEM_vs_NHAD_Noise_Sub", 200, 0, 3000, 200, 0, 18000);  
histogram_2D_P_NS[file] = new TH2F("PEM_vs_PHAD_Noise_Sub", "PEM_vs_PHAD_Noise_Sub", 200, 0, 3000, 200, 0, 18000);  
histogram_2D_N_NNS[file] = new TH2F("NEM_vs_NHAD_No_Noise_Sub", "NEM_vs_NHAD_No_Noise_Sub", 200, 0, 3000, 200, 0, 18000);  
histogram_2D_P_NNS[file] = new TH2F("PEM_vs_PHAD_No_Noise_Sub", "PEM_vs_PHAD_No_Noise_Sub", 200, 0, 3000, 200, 0, 18000);  

histogram_1D_N_NS[file] = new TH1F("MTotalHAD_TS45_NS", "MTotalHAD_TS45_PromptReco_NS", 200, 100, 6000);
histogram_1D_P_NS[file] = new TH1F("PTotalHAD_TS45_NS", "PTotalHAD_TS45_PromptReco_NS", 200, 100, 6000);
histogram_1D_N_NNS[file] = new TH1F("MTotalHAD_TS45_NoNS", "MTotalHAD_TS45_PromptReco_NoNS", 200, 100, 6000);
histogram_1D_P_NNS[file] = new TH1F("PTotalHAD_TS45_NoNS", "PTotalHAD_TS45_PromptReco_NoNS", 200, 100, 6000);

histogram_1DSum_N_NS[file] = new TH1F("M_SumHADEM_TS45_NS", "MTotalHAD+0.1TotalEM_TS45_PromptReco_NS", 200, 100, 6000);
histogram_1DSum_P_NS[file] = new TH1F("P_SumHADEM_TS45_NS", "PTotalHAD+0.1TotalEM_TS45_PromptReco_NS", 200, 100, 6000);
histogram_1DSum_N_NNS[file] = new TH1F("M_SumHADEM_TS45_NoNS", "MTotalHAD+0.1TotalEM_TS45_PromptReco_NoNS", 200, 100, 6000);
histogram_1DSum_P_NNS[file] = new TH1F("P_SumHADEM_TS45_NoNS", "PTotalHAD+0.1TotalEM_TS45_PromptReco_NoNS", 200, 100, 6000);

histogram_1D_PosHAD1[file] = new TH1F("PHAD1signal_TS_fC", "PHAD1signal_fC_TS", 10, 0, 10); 
histogram_1D_PosHAD2[file] = new TH1F("PHAD2signal_TS_fC", "PHAD2signal_fC_TS", 10, 0, 10); 
histogram_1D_PosHAD3[file] = new TH1F("PHAD3signal_TS_fC", "PHAD3signal_fC_TS", 10, 0, 10); 
histogram_1D_PosHAD4[file] = new TH1F("PHAD4signal_TS_fC", "PHAD4signal_fC_TS", 10, 0, 10); 
histogram_1D_NegHAD1[file] = new TH1F("NHAD1signal_TS_fC", "NHAD1signal_fC_TS", 10, 0, 10); 
histogram_1D_NegHAD2[file] = new TH1F("NHAD2signal_TS_fC", "NHAD2signal_fC_TS", 10, 0, 10); 
histogram_1D_NegHAD3[file] = new TH1F("NHAD3signal_TS_fC", "NHAD3signal_fC_TS", 10, 0, 10); 
histogram_1D_NegHAD4[file] = new TH1F("NHAD4signal_TS_fC", "NHAD4signal_fC_TS", 10, 0, 10); 

histogram_1D_PosEM1[file] = new TH1F("PEM1signal_TS_fC", "PEM1signal_fC_TS", 10, 0, 10); 
histogram_1D_PosEM2[file] = new TH1F("PEM2signal_TS_fC", "PEM2signal_fC_TS", 10, 0, 10); 
histogram_1D_PosEM3[file] = new TH1F("PEM3signal_TS_fC", "PEM3signal_fC_TS", 10, 0, 10); 
histogram_1D_PosEM4[file] = new TH1F("PEM4signal_TS_fC", "PEM4signal_fC_TS", 10, 0, 10); 
histogram_1D_PosEM5[file] = new TH1F("PEM5signal_TS_fC", "PEM5signal_fC_TS", 10, 0, 10); 
histogram_1D_NegEM1[file] = new TH1F("NEM1signal_TS_fC", "NEM1signal_fC_TS", 10, 0, 10); 
histogram_1D_NegEM2[file] = new TH1F("NEM2signal_TS_fC", "NEM2signal_fC_TS", 10, 0, 10); 
histogram_1D_NegEM3[file] = new TH1F("NEM3signal_TS_fC", "NEM3signal_fC_TS", 10, 0, 10); 
histogram_1D_NegEM4[file] = new TH1F("NEM4signal_TS_fC", "NEM4signal_fC_TS", 10, 0, 10); 
histogram_1D_NegEM5[file] = new TH1F("NEM5signal_TS_fC", "NEM5signal_fC_TS", 10, 0, 10); 

   centtree->SetBranchAddress("Cent_HFtowers",&Cent_HFtowers);
   digitree->SetBranchAddress("negEM1fC", negEM1fC, &b_negEM1cFtsz);
   digitree->SetBranchAddress("negEM1ADC", negEM1ADC, &b_negEM1ADCtsz);
   digitree->SetBranchAddress("negEM2fC", negEM2fC, &b_negEM2cFtsz);
   digitree->SetBranchAddress("negEM2ADC", negEM2ADC, &b_negEM2ADCtsz);
   digitree->SetBranchAddress("negEM3fC", negEM3fC, &b_negEM3cFtsz);
   digitree->SetBranchAddress("negEM3ADC", negEM3ADC, &b_negEM3ADCtsz);
   digitree->SetBranchAddress("negEM4fC", negHD1fC, &b_negHD1cFtsz);
   digitree->SetBranchAddress("negEM4ADC", negHD1ADC, &b_negHD1ADCtsz);
   digitree->SetBranchAddress("negHD1fC", negEM4fC, &b_negEM4cFtsz);
   digitree->SetBranchAddress("negHD1ADC", negEM4ADC, &b_negEM4ADCtsz);
   digitree->SetBranchAddress("negEM5fC", negEM5fC, &b_negEM5cFtsz);
   digitree->SetBranchAddress("negEM5ADC", negEM5ADC, &b_negEM5ADCtsz);
   digitree->SetBranchAddress("negHD2fC", negHD2fC, &b_negHD2cFtsz);
   digitree->SetBranchAddress("negHD2ADC", negHD2ADC, &b_negHD2ADCtsz);
   digitree->SetBranchAddress("negHD3fC", negHD3fC, &b_negHD3cFtsz);
   digitree->SetBranchAddress("negHD3ADC", negHD3ADC, &b_negHD3ADCtsz);
   digitree->SetBranchAddress("negHD4fC", negHD4fC, &b_negHD4cFtsz);
   digitree->SetBranchAddress("negHD4ADC", negHD4ADC, &b_negHD4ADCtsz);
   digitree->SetBranchAddress("posEM1fC", posEM1fC, &b_posEM1cFtsz);
   digitree->SetBranchAddress("posEM1ADC", posEM1ADC, &b_posEM1ADCtsz);
   digitree->SetBranchAddress("posEM2fC", posEM2fC, &b_posEM2cFtsz);
   digitree->SetBranchAddress("posEM2ADC", posEM2ADC, &b_posEM2ADCtsz);
   digitree->SetBranchAddress("posEM3fC", posEM3fC, &b_posEM3cFtsz);
   digitree->SetBranchAddress("posEM3ADC", posEM3ADC, &b_posEM3ADCtsz);
   digitree->SetBranchAddress("posEM4fC", posEM4fC, &b_posEM4cFtsz);
   digitree->SetBranchAddress("posEM4ADC", posEM4ADC, &b_posEM4ADCtsz);
   digitree->SetBranchAddress("posEM5fC", posEM5fC, &b_posEM5cFtsz);
   digitree->SetBranchAddress("posEM5ADC", posEM5ADC, &b_posEM5ADCtsz);
   digitree->SetBranchAddress("posHD1fC", posHD1fC, &b_posHD1cFtsz);
   digitree->SetBranchAddress("posHD1ADC", posHD1ADC, &b_posHD1ADCtsz);
   digitree->SetBranchAddress("posHD2fC", posHD2fC, &b_posHD2cFtsz);
   digitree->SetBranchAddress("posHD2ADC", posHD2ADC, &b_posHD2ADCtsz);
   digitree->SetBranchAddress("posHD3fC", posHD3fC, &b_posHD3cFtsz);
   digitree->SetBranchAddress("posHD3ADC", posHD3ADC, &b_posHD3ADCtsz);
   digitree->SetBranchAddress("posHD4fC", posHD4fC, &b_posHD4cFtsz);
   digitree->SetBranchAddress("posHD4ADC", posHD4ADC, &b_posHD4ADCtsz);
   NHAD1fC= digitree->GetLeaf("negEM4cFtsz");//NHAD4
   NHAD1ADC= digitree->GetLeaf("negEM4ADCtsz");
   NHAD2fC= digitree->GetLeaf("negHD2cFtsz");//NHAD2
   NHAD2ADC= digitree->GetLeaf("negHD2ADCtsz");
   NHAD3fC= digitree->GetLeaf("negHD3cFtsz");//NHAD3
   NHAD3ADC= digitree->GetLeaf("negHD3ADCtsz");
   NHAD4fC= digitree->GetLeaf("negHD4cFtsz");//NHAD4
   NHAD4ADC= digitree->GetLeaf("negHD4ADCtsz");
   NEM1fC= digitree->GetLeaf("negEM1cFtsz");//NEM1
   NEM1ADC= digitree->GetLeaf("negEM1ADCtsz");
   NEM2fC= digitree->GetLeaf("negEM2cFtsz");//NEM2
   NEM2ADC= digitree->GetLeaf("negEM2ADCtsz");
   NEM3fC= digitree->GetLeaf("negEM3cFtsz");//NEM3
   NEM3ADC= digitree->GetLeaf("negEM3ADCtsz");
   NEM4fC= digitree->GetLeaf("negHD1cFtsz");//NEM1
   NEM4ADC= digitree->GetLeaf("negHD1ADCtsz");
   NEM5fC= digitree->GetLeaf("negEM5cFtsz");//NEM5
   NEM5ADC= digitree->GetLeaf("negEM5ADCtsz");
   PHAD1fC= digitree->GetLeaf("posHD1cFtsz");//PHAD1
   PHAD1ADC= digitree->GetLeaf("posHD1ADCtsz");
   PHAD2fC= digitree->GetLeaf("posHD2cFtsz");//PHAD2
   PHAD2ADC= digitree->GetLeaf("posHD2ADCtsz");
   PHAD3fC= digitree->GetLeaf("posHD3cFtsz");//PHAD3
   PHAD3ADC= digitree->GetLeaf("posHD3ADCtsz");
   PHAD4fC= digitree->GetLeaf("posHD4cFtsz");//PHAD4
   PHAD4ADC= digitree->GetLeaf("posHD4ADCtsz");
   PEM1fC= digitree->GetLeaf("posEM1cFtsz");//PEM1
   PEM1ADC= digitree->GetLeaf("posEM1ADCtsz");
   PEM2fC= digitree->GetLeaf("posEM2cFtsz");//PEM2
   PEM2ADC= digitree->GetLeaf("posEM2ADCtsz");
   PEM3fC= digitree->GetLeaf("posEM3cFtsz");//PEM3
   PEM3ADC= digitree->GetLeaf("posEM3ADCtsz");
   PEM4fC= digitree->GetLeaf("posEM4cFtsz");//PEM4
   PEM4ADC= digitree->GetLeaf("posEM4ADCtsz");
   PEM5fC= digitree->GetLeaf("posEM5cFtsz");//PEM5
   PEM5ADC= digitree->GetLeaf("posEM5ADCtsz");

	  if(file==0){
	    sprintf(TSname,"NoBPTX");
	    sprintf(subdirname,"NoBPTX/");
	    sprintf(save1DNNS_N,"plots/1D_N_NNS_NoBPTX_%i.pdf",runnumber);	    
	    sprintf(save1DNS_N,"plots/1D_N_NS_NoBPTX_%i.pdf",runnumber);
	    sprintf(save1DNNS_P,"plots/1D_P_NNS_NoBPTX_%i.pdf",runnumber);
	    sprintf(save1DNS_P,"plots/1D_P_NS_NoBPTX_%i.pdf",runnumber);
	    
	    sprintf(save2DNNS_P,"plots/2D_P_NNS_NoBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_P,"plots/2D_P_NS_NoBPTX_%i.pdf",runnumber);
	    sprintf(save2DNNS_N,"plots/2D_N_NNS_NoBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_N,"plots/2D_N_NS_NoBPTX_%i.pdf",runnumber);
	    
	    sprintf(saveSumNS_N,"plots/1Dsum_N_NS_NoBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNS_P,"plots/1Dsum_P_NS_NoBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_N,"plots/1Dsum_N_NNS_NoBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_P,"plots/1Dsum_P_NNS_NoBPTX_%i.pdf",runnumber);
	    
	    sprintf(output1DNNS_N,"1D_N_NNS_NoBPTX");	    
	    sprintf(output1DNS_N,"1D_N_NS_NoBPTX");
	    sprintf(output1DNNS_P,"1D_P_NNS_NoBPTX");
	    sprintf(output1DNS_P,"1D_P_NS_NoBPTX");
	    
	    sprintf(output2DNNS_P,"2D_P_NNS_NoBPTX");
	    sprintf(output2DNS_P,"2D_P_NS_NoBPTX");
	    sprintf(output2DNNS_N,"2D_N_NNS_NoBPTX");
	    sprintf(output2DNS_N,"2D_N_NS_NoBPTX");
	    
	    sprintf(outputSumNS_N,"1Dsum_N_NS_NoBPTX");
	    sprintf(outputSumNS_P,"1Dsum_P_NS_NoBPTX");
	    sprintf(outputSumNNS_N,"1Dsum_N_NNS_NoBPTX");
	    sprintf(outputSumNNS_P,"1Dsum_P_NNS_NoBPTX");
	  }
	  
	  if(file==1){
	    sprintf(TSname,"PlusDirection_BPTX");
  	    sprintf(subdirname,"PlusDirection_BPTX/");
	    sprintf(save1DNNS_N,"plots/1D_N_NNS_PlusBPTX_%i.pdf",runnumber);	    
	    sprintf(save1DNS_N,"plots/1D_N_NS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(save1DNNS_P,"plots/1D_P_NNS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(save1DNS_P,"plots/1D_P_NS_PlusBPTX_%i.pdf",runnumber);
	    
	    sprintf(save2DNNS_P,"plots/2D_P_NNS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_P,"plots/2D_P_NS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNNS_N,"plots/2D_N_NNS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_N,"plots/2D_N_NS_PlusBPTX_%i.pdf",runnumber);
	    
	    sprintf(saveSumNS_N,"plots/1Dsum_N_NS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNS_P,"plots/1Dsum_P_NS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_N,"plots/1Dsum_N_NNS_PlusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_P,"plots/1Dsum_P_NNS_PlusBPTX_%i.pdf",runnumber);
	    
	    sprintf(output1DNNS_N,"1D_N_NNS_PlusBPTX");	    
	    sprintf(output1DNS_N,"1D_N_NS_PlusBPTX");
	    sprintf(output1DNNS_P,"1D_P_NNS_PlusBPTX");
	    sprintf(output1DNS_P,"1D_P_NS_PlusBPTX");
	    
	    sprintf(output2DNNS_P,"2D_P_NNS_PlusBPTX");
	    sprintf(output2DNS_P,"2D_P_NS_PlusBPTX");
	    sprintf(output2DNNS_N,"2D_N_NNS_PlusBPTX");
	    sprintf(output2DNS_N,"2D_N_NS_PlusBPTX");
	    
	    sprintf(outputSumNS_N,"1Dsum_N_NS_PlusBPTX");
	    sprintf(outputSumNS_P,"1Dsum_P_NS_PlusBPTX");
	    sprintf(outputSumNNS_N,"1Dsum_N_NNS_PlusBPTX");
	    sprintf(outputSumNNS_P,"1Dsum_P_NNS_PlusBPTX");
	  }
	  
	  if(file==2){
	    sprintf(TSname,"MinusDirection_BPTX");
	    sprintf(subdirname,"MinusDirection_BPTX/");
	    sprintf(save1DNNS_N,"plots/1D_N_NNS_MinusBPTX_%i.pdf",runnumber);	    
	    sprintf(save1DNS_N,"plots/1D_N_NS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(save1DNNS_P,"plots/1D_P_NNS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(save1DNS_P,"plots/1D_P_NS_MinusBPTX_%i.pdf",runnumber);
	    
	    sprintf(save2DNNS_P,"plots/2D_P_NNS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_P,"plots/2D_P_NS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNNS_N,"plots/2D_N_NNS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(save2DNS_N,"plots/2D_N_NS_MinusBPTX_%i.pdf",runnumber);
	    
	    sprintf(saveSumNS_N,"plots/1Dsum_N_NS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNS_P,"plots/1Dsum_P_NS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_N,"plots/1Dsum_N_NNS_MinusBPTX_%i.pdf",runnumber);
	    sprintf(saveSumNNS_P,"plots/1Dsum_P_NNS_MinusBPTX_%i.pdf",runnumber);
	    
	    sprintf(output1DNNS_N,"1D_N_NNS_MinusBPTX");	    
	    sprintf(output1DNS_N,"1D_N_NS_MinusBPTX");
	    sprintf(output1DNNS_P,"1D_P_NNS_MinusBPTX");
	    sprintf(output1DNS_P,"1D_P_NS_MinusBPTX");
	    
	    sprintf(output2DNNS_P,"2D_P_NNS_MinusBPTX");
	    sprintf(output2DNS_P,"2D_P_NS_MinusBPTX");
	    sprintf(output2DNNS_N,"2D_N_NNS_MinusBPTX");
	    sprintf(output2DNS_N,"2D_N_NS_MinusBPTX");
	    
	    sprintf(outputSumNS_N,"1Dsum_N_NS_MinusBPTX");
	    sprintf(outputSumNS_P,"1Dsum_P_NS_MinusBPTX");
	    sprintf(outputSumNNS_N,"1Dsum_N_NNS_MinusBPTX");
	    sprintf(outputSumNNS_P,"1Dsum_P_NNS_MinusBPTX");
	  }
	  
	  if(file==3){
	    sprintf(TSname,"Collisions");
	    sprintf(subdirname,"Collisions/");
	    sprintf(save1DNNS_N,"plots/1D_N_NNS_Collisions_%i.pdf",runnumber);	    
	    sprintf(save1DNS_N,"plots/1D_N_NS_Collisions_%i.pdf",runnumber);
	    sprintf(save1DNNS_P,"plots/1D_P_NNS_Collisions_%i.pdf",runnumber);
	    sprintf(save1DNS_P,"plots/1D_P_NS_Collisions_%i.pdf",runnumber);
	    
	    sprintf(save2DNNS_P,"plots/2D_P_NNS_Collisions_%i.pdf",runnumber);
	    sprintf(save2DNS_P,"plots/2D_P_NS_Collisions_%i.pdf",runnumber);
	    sprintf(save2DNNS_N,"plots/2D_N_NNS_Collisions_%i.pdf",runnumber);
	    sprintf(save2DNS_N,"plots/2D_N_NS_Collisions_%i.pdf",runnumber);
	    
	    sprintf(saveSumNS_N,"plots/1Dsum_N_NS_Collisions_%i.pdf",runnumber);
	    sprintf(saveSumNS_P,"plots/1Dsum_P_NS_Collisions_%i.pdf",runnumber);
	    sprintf(saveSumNNS_N,"plots/1Dsum_N_NNS_Collisions_%i.pdf",runnumber);
	    sprintf(saveSumNNS_P,"plots/1Dsum_P_NNS_Collisions_%i.pdf",runnumber);
	    
	    sprintf(output1DNNS_N,"1D_N_NNS_Collisions");	    
	    sprintf(output1DNS_N,"1D_N_NS_Collisions");
	    sprintf(output1DNNS_P,"1D_P_NNS_Collisions");
	    sprintf(output1DNS_P,"1D_P_NS_Collisions");
	    
	    sprintf(output2DNNS_P,"2D_P_NNS_Collisions");
	    sprintf(output2DNS_P,"2D_P_NS_Collisions");
	    sprintf(output2DNNS_N,"2D_N_NNS_Collisions");
	    sprintf(output2DNS_N,"2D_N_NS_Collisions");
	    
	    sprintf(outputSumNS_N,"1Dsum_N_NS_Collisions");
	    sprintf(outputSumNS_P,"1Dsum_P_NS_Collisions");
	    sprintf(outputSumNNS_N,"1Dsum_N_NNS_Collisions");
	    sprintf(outputSumNNS_P,"1Dsum_P_NNS_Collisions");
	  }


NumberOfEvents = digitree->GetEntries();
cout<<"entries = "<<NumberOfEvents<<" for file "<<file<<endl;
  for(Int_t i =0;i<NumberOfEvents;i++)
    {
      digitree->GetEntry(i);
      //   CENT->GetEntry(i); //This line grabs the events centrality value

      //centrality[1]=(CENTRAL->GetValue()); //this grabs the value of the centrality and stuffs it in the matrix
      //if(centrality[1]<=39){        //this line makes a decision on whether or not the data fits the centrality decision you make
      //floatEMcal=0;
      //floatHADcal=0;
      NHAD1TotalSignal=0;
      NHAD2TotalSignal=0;
      NHAD3TotalSignal=0;
      NHAD4TotalSignal=0;
      NEM1TotalSignal=0;
      NEM2TotalSignal=0;
      NEM3TotalSignal=0;
      NEM4TotalSignal=0;
      NEM5TotalSignal=0;
      
      PHAD1TotalSignal=0;
      PHAD2TotalSignal=0;
      PHAD3TotalSignal=0;
      PHAD4TotalSignal=0;
      PEM1TotalSignal=0;
      PEM2TotalSignal=0;
      PEM3TotalSignal=0;
      PEM4TotalSignal=0;
      PEM5TotalSignal=0;
      //ABOVE we have made 9 signals corresponding to the 9 different sections of the N-ZDC, we have declared them to be 0 and will fill them in the next section
  
      for(int iTS=4;iTS<6;iTS++){//This is the part of the code that declares which Timeslices we are interested in analyzing
	negHD1fC[iTS]=(NHAD1fC->GetValue(iTS));//NHAD1
	negHD2fC[iTS]=(NHAD2fC->GetValue(iTS));//NHAD2
	negHD3fC[iTS]=(NHAD3fC->GetValue(iTS));//NHAD3
	negHD4fC[iTS]=(NHAD4fC->GetValue(iTS));//NHAD4
	negEM1fC[iTS]=(NEM1fC->GetValue(iTS));//NEM1
	negEM2fC[iTS]=(NEM2fC->GetValue(iTS));//NEM2
	negEM3fC[iTS]=(NEM3fC->GetValue(iTS));//NEM3
	negEM4fC[iTS]=(NEM4fC->GetValue(iTS));//NEM4
	negEM5fC[iTS]=(NEM5fC->GetValue(iTS));//NEM5
	posHD1fC[iTS]=(PHAD1fC->GetValue(iTS));//NHAD1
	posHD2fC[iTS]=(PHAD2fC->GetValue(iTS));//NHAD2
	posHD3fC[iTS]=(PHAD3fC->GetValue(iTS));//NHAD3
	posHD4fC[iTS]=(PHAD4fC->GetValue(iTS));//NHAD4
	posEM1fC[iTS]=(PEM1fC->GetValue(iTS));//NEM1
	posEM2fC[iTS]=(PEM2fC->GetValue(iTS));//NEM2
	posEM3fC[iTS]=(PEM3fC->GetValue(iTS));//NEM3
	posEM4fC[iTS]=(PEM4fC->GetValue(iTS));//NEM4
	posEM5fC[iTS]=(PEM5fC->GetValue(iTS));//NEM5
	//HAD1
	if(negHD1fC[iTS]<0){
	  negHD1fC[iTS]=0;
	}  //this replacement ensures that we cannot have negative values of charge
	NHAD1TotalSignal=NHAD1TotalSignal+negHD1fC[iTS];//takes the fC value of that timeslice and adds it to the "TotalSignal" of that HAD1 section
	//HAD2
	if(negHD2fC[iTS]<0){
	  negHD2fC[iTS]=0;
	}  
	NHAD2TotalSignal=NHAD2TotalSignal+negHD2fC[iTS];
	//HAD3
	if(negHD3fC[iTS]<0){
	  negHD3fC[iTS]=0;
	}  
	NHAD3TotalSignal=NHAD3TotalSignal+negHD3fC[iTS];
	//HAD4
	if(negHD4fC[iTS]<0){
	  negHD4fC[iTS]=0;
	}  
	NHAD4TotalSignal=NHAD4TotalSignal+negHD4fC[iTS];
	//EM1
	if(negEM1fC[iTS]<0){
	  negEM1fC[iTS]=0;
	}     
	NEM1TotalSignal=NEM1TotalSignal+negEM1fC[iTS];
	//EM2
	if(negEM2fC[iTS]<0){
	  negEM2fC[iTS]=0;
	}     
	NEM2TotalSignal=NEM2TotalSignal+negEM2fC[iTS];
	//EM3
	if(negEM3fC[iTS]<0){
	  negEM3fC[iTS]=0;
	}     
	NEM3TotalSignal=NEM3TotalSignal+negEM3fC[iTS];
	//EM4
	if(negEM4fC[iTS]<0){
	  negEM4fC[iTS]=0;
	}     
	NEM4TotalSignal=NEM4TotalSignal+negEM4fC[iTS];
	//EM5
	if(negEM5fC[iTS]<0){
	  negEM5fC[iTS]=0;
	}     
	NEM5TotalSignal=NEM5TotalSignal+negEM5fC[iTS];
	
	//HAD1
	if(posHD1fC[iTS]<0){
	  posHD1fC[iTS]=0;
	}  //this replacement ensures that we cannot have posative values of charge
	PHAD1TotalSignal=PHAD1TotalSignal+posHD1fC[iTS];//takes the fC value of that timeslice and adds it to the "TotalSignal" of that HAD1 section
	//HAD2
	if(posHD2fC[iTS]<0){
	  posHD2fC[iTS]=0;
	}  
	PHAD2TotalSignal=PHAD2TotalSignal+posHD2fC[iTS];
	//HAD3
	if(posHD3fC[iTS]<0){
	  posHD3fC[iTS]=0;
	}  
	PHAD3TotalSignal=PHAD3TotalSignal+posHD3fC[iTS];
	//HAD4
	if(posHD4fC[iTS]<0){
	  posHD4fC[iTS]=0;
	}  
	PHAD4TotalSignal=PHAD4TotalSignal+posHD4fC[iTS];
	//EM1
	if(posEM1fC[iTS]<0){
	  posEM1fC[iTS]=0;
	}     
	PEM1TotalSignal=PEM1TotalSignal+posEM1fC[iTS];
	//EM2
	if(posEM2fC[iTS]<0){
	  posEM2fC[iTS]=0;
	}     
	PEM2TotalSignal=PEM2TotalSignal+posEM2fC[iTS];
	//EM3
	if(posEM3fC[iTS]<0){
	  posEM3fC[iTS]=0;
	}     
	PEM3TotalSignal=PEM3TotalSignal+posEM3fC[iTS];
	//EM4
	if(posEM4fC[iTS]<0){
	  posEM4fC[iTS]=0;
	}     
	PEM4TotalSignal=PEM4TotalSignal+posEM4fC[iTS];
	//EM5
	if(posEM5fC[iTS]<0){
	  posEM5fC[iTS]=0;
	}     
	PEM5TotalSignal=PEM5TotalSignal+posEM5fC[iTS];	
      }
      //NOISE
      NEM1TotalNoise=0;
      NEM2TotalNoise=0;
      NEM3TotalNoise=0;
      NEM4TotalNoise=0;
      NEM5TotalNoise=0;
      NHAD1TotalNoise=0;
      NHAD2TotalNoise=0;
      NHAD3TotalNoise=0;
      NHAD4TotalNoise=0;
      
      PEM1TotalNoise=0;
      PEM2TotalNoise=0;
      PEM3TotalNoise=0;
      PEM4TotalNoise=0;
      PEM5TotalNoise=0;
      PHAD1TotalNoise=0;
      PHAD2TotalNoise=0;
      PHAD3TotalNoise=0;
      PHAD4TotalNoise=0;

      //we will repeat the above loop for the noise
      for(int iTS=8;iTS<9;iTS++)
	{
	  //EM1
	  negEM1fC[iTS]=(NEM1fC->GetValue(iTS));
	  NEM1TotalNoise=NEM1TotalNoise+negEM1fC[iTS];
	  //EM2
	  negEM2fC[iTS]=(NEM2fC->GetValue(iTS));
	  NEM2TotalNoise=NEM2TotalNoise+negEM2fC[iTS];
	  //EM3
	  negEM3fC[iTS]=(NEM3fC->GetValue(iTS));
	  NEM3TotalNoise=NEM3TotalNoise+negEM3fC[iTS];
	  //EM4
	  negEM4fC[iTS]=(NEM4fC->GetValue(iTS));
	  NEM4TotalNoise=NEM4TotalNoise+negEM4fC[iTS];
	  //EM5
	  negEM5fC[iTS]=(NEM5fC->GetValue(iTS));
	  NEM5TotalNoise=NEM5TotalNoise+negEM5fC[iTS];
	  //HAD1
	  negHD1fC[iTS]=(NHAD1fC->GetValue(iTS));
	  NHAD1TotalNoise=NHAD1TotalNoise+negHD1fC[iTS];
	  //HAD2
	  negHD2fC[iTS]=(NHAD2fC->GetValue(iTS));
	  NHAD2TotalNoise=NHAD2TotalNoise+negHD2fC[iTS];
	  //HAD3
	  negHD3fC[iTS]=(NHAD3fC->GetValue(iTS));
	  NHAD3TotalNoise=NHAD3TotalNoise+negHD3fC[iTS];
	  //HAD4
	  negHD4fC[iTS]=(NHAD4fC->GetValue(iTS));
	  NHAD4TotalNoise=NHAD4TotalNoise+negHD4fC[iTS];

	}
      for(int iTS=9;iTS<10;iTS++)
	{
	  //EM1
	  negEM1fC[iTS]=(NEM1fC->GetValue(iTS));
	  NEM1TotalNoise=NEM1TotalNoise+negEM1fC[iTS];
	  //EM2
	  negEM2fC[iTS]=(NEM2fC->GetValue(iTS));
	  NEM2TotalNoise=NEM2TotalNoise+negEM2fC[iTS];
	  //EM3
	  negEM3fC[iTS]=(NEM3fC->GetValue(iTS));
	  NEM3TotalNoise=NEM3TotalNoise+negEM3fC[iTS];
	  //EM4
	  negEM4fC[iTS]=(NEM4fC->GetValue(iTS));
	  NEM4TotalNoise=NEM4TotalNoise+negEM4fC[iTS];
	  //EM5
	  negEM5fC[iTS]=(NEM5fC->GetValue(iTS));
	  NEM5TotalNoise=NEM5TotalNoise+negEM5fC[iTS];
	  //HAD1
	  negHD1fC[iTS]=(NHAD1fC->GetValue(iTS));
	  NHAD1TotalNoise=NHAD1TotalNoise+negHD1fC[iTS];
	  //HAD2
	  negHD2fC[iTS]=(NHAD2fC->GetValue(iTS));
	  NHAD2TotalNoise=NHAD2TotalNoise+negHD2fC[iTS];
	  //HAD3
	  negHD3fC[iTS]=(NHAD3fC->GetValue(iTS));
	  NHAD3TotalNoise=NHAD3TotalNoise+negHD3fC[iTS];
	  //HAD4
	  negHD4fC[iTS]=(NHAD4fC->GetValue(iTS));
	  NHAD4TotalNoise=NHAD4TotalNoise+negHD4fC[iTS];

	}	
	
	      for(int iTS=8;iTS<9;iTS++)
	{
	  //EM1
	  posEM1fC[iTS]=(PEM1fC->GetValue(iTS));
	  PEM1TotalNoise=PEM1TotalNoise+posEM1fC[iTS];
	  //EM2
	  posEM2fC[iTS]=(PEM2fC->GetValue(iTS));
	  PEM2TotalNoise=PEM2TotalNoise+posEM2fC[iTS];
	  //EM3
	  posEM3fC[iTS]=(PEM3fC->GetValue(iTS));
	  PEM3TotalNoise=PEM3TotalNoise+posEM3fC[iTS];
	  //EM4
	  posEM4fC[iTS]=(PEM4fC->GetValue(iTS));
	  PEM4TotalNoise=PEM4TotalNoise+posEM4fC[iTS];
	  //EM5
	  posEM5fC[iTS]=(PEM5fC->GetValue(iTS));
	  PEM5TotalNoise=PEM5TotalNoise+posEM5fC[iTS];
	  //HAD1
	  posHD1fC[iTS]=(PHAD1fC->GetValue(iTS));
	  PHAD1TotalNoise=PHAD1TotalNoise+posHD1fC[iTS];
	  //HAD2
	  posHD2fC[iTS]=(PHAD2fC->GetValue(iTS));
	  PHAD2TotalNoise=PHAD2TotalNoise+posHD2fC[iTS];
	  //HAD3
	  posHD3fC[iTS]=(PHAD3fC->GetValue(iTS));
	  PHAD3TotalNoise=PHAD3TotalNoise+posHD3fC[iTS];
	  //HAD4
	  posHD4fC[iTS]=(PHAD4fC->GetValue(iTS));
	  PHAD4TotalNoise=PHAD4TotalNoise+posHD4fC[iTS];

	}
      for(int iTS=9;iTS<10;iTS++)
	{
	  //EM1
	  posEM1fC[iTS]=(PEM1fC->GetValue(iTS));
	  PEM1TotalNoise=PEM1TotalNoise+posEM1fC[iTS];
	  //EM2
	  posEM2fC[iTS]=(PEM2fC->GetValue(iTS));
	  PEM2TotalNoise=PEM2TotalNoise+posEM2fC[iTS];
	  //EM3
	  posEM3fC[iTS]=(PEM3fC->GetValue(iTS));
	  PEM3TotalNoise=PEM3TotalNoise+posEM3fC[iTS];
	  //EM4
	  posEM4fC[iTS]=(PEM4fC->GetValue(iTS));
	  PEM4TotalNoise=PEM4TotalNoise+posEM4fC[iTS];
	  //EM5
	  posEM5fC[iTS]=(PEM5fC->GetValue(iTS));
	  PEM5TotalNoise=PEM5TotalNoise+posEM5fC[iTS];
	  //HAD1
	  posHD1fC[iTS]=(PHAD1fC->GetValue(iTS));
	  PHAD1TotalNoise=PHAD1TotalNoise+posHD1fC[iTS];
	  //HAD2
	  posHD2fC[iTS]=(PHAD2fC->GetValue(iTS));
	  PHAD2TotalNoise=PHAD2TotalNoise+posHD2fC[iTS];
	  //HAD3
	  posHD3fC[iTS]=(PHAD3fC->GetValue(iTS));
	  PHAD3TotalNoise=PHAD3TotalNoise+posHD3fC[iTS];
	  //HAD4
	  posHD4fC[iTS]=(PHAD4fC->GetValue(iTS));
	  PHAD4TotalNoise=PHAD4TotalNoise+posHD4fC[iTS];

	}	
 
      //No Noise Subtraction (NNS)
      NHADsumNNS=0;
      NETsumNNS=0;
      NEMsumNNS=0;
      NHADsumNS=0;
      NETsumNS=0;
      NEMsumNS=0;
      PHADsumNNS=0;
      PETsumNNS=0;
      PEMsumNNS=0;
      PHADsumNS=0;
      PETsumNS=0;
      PEMsumNS=0;
      
      NHADsumNNS=(NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal);
      NETsumNNS=(NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal)+(.1*NEM1TotalSignal)+(.1*NEM2TotalSignal)+(.1*NEM3TotalSignal)+(.1*NEM4TotalSignal)+(.1*NEM5TotalSignal);
 
      NEMsumNNS=(NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal);
      
      PHADsumNNS=(PHAD1TotalSignal)+(PHAD2TotalSignal)+(PHAD3TotalSignal)+(PHAD4TotalSignal);
      PETsumNNS=(PHAD1TotalSignal)+(PHAD2TotalSignal)+(PHAD3TotalSignal)+(PHAD4TotalSignal)+(.1*PEM1TotalSignal)+(.1*PEM2TotalSignal)+(.1*PEM3TotalSignal)+(.1*PEM4TotalSignal)+(.1*PEM5TotalSignal);
 
      PEMsumNNS=(PEM1TotalSignal)+(PEM2TotalSignal)+(PEM3TotalSignal)+(PEM4TotalSignal)+(PEM5TotalSignal);


      //Noise Subtraction (NS)
      NHADsumNS=(NHAD1TotalSignal-NHAD1TotalNoise)+(NHAD2TotalSignal-NHAD2TotalNoise)+(NHAD3TotalSignal-NHAD3TotalNoise)+(NHAD4TotalSignal-NHAD4TotalNoise);

      NETsumNS=(NHAD1TotalSignal-NHAD1TotalNoise)+(NHAD2TotalSignal-NHAD2TotalNoise)+(NHAD3TotalSignal-NHAD3TotalNoise)+(NHAD4TotalSignal-NHAD4TotalNoise)+(.1)*(NEM1TotalSignal-NEM1TotalNoise)+(.1)*(NEM2TotalSignal-NEM2TotalNoise)+(.1)*(NEM3TotalSignal-NEM3TotalNoise)+(.1)*(NEM4TotalSignal-NEM4TotalNoise)+(.1)*(NEM5TotalSignal-NEM5TotalNoise);

      NEMsumNS=(NEM1TotalSignal-NEM1TotalNoise)+(NEM2TotalSignal-NEM2TotalNoise)+(NEM3TotalSignal-NEM3TotalNoise)+(NEM4TotalSignal-NEM4TotalNoise)+(NEM5TotalSignal-NEM5TotalNoise);
      
      PHADsumNS=(PHAD1TotalSignal-PHAD1TotalNoise)+(PHAD2TotalSignal-PHAD2TotalNoise)+(PHAD3TotalSignal-PHAD3TotalNoise)+(PHAD4TotalSignal-PHAD4TotalNoise);

      PETsumNS=(PHAD1TotalSignal-PHAD1TotalNoise)+(PHAD2TotalSignal-PHAD2TotalNoise)+(PHAD3TotalSignal-PHAD3TotalNoise)+(PHAD4TotalSignal-PHAD4TotalNoise)+(.1)*(PEM1TotalSignal-PEM1TotalNoise)+(.1)*(PEM2TotalSignal-PEM2TotalNoise)+(.1)*(PEM3TotalSignal-PEM3TotalNoise)+(.1)*(PEM4TotalSignal-PEM4TotalNoise)+(.1)*(PEM5TotalSignal-PEM5TotalNoise);

      PEMsumNS=(PEM1TotalSignal-PEM1TotalNoise)+(PEM2TotalSignal-PEM2TotalNoise)+(PEM3TotalSignal-PEM3TotalNoise)+(PEM4TotalSignal-PEM4TotalNoise)+(PEM5TotalSignal-PEM5TotalNoise);


 /*     histogram_1D_N_NS->Reset();
      histogram_1DSum_N_NS->Reset();
      histogram_1D_P_NS->Reset();
      histogram_1DSum_P_NS->Reset();      
      histogram_1D_N_NNS->Reset();
      histogram_1DSum_N_NNS->Reset();
      histogram_1D_P_NNS->Reset();
      histogram_1DSum_P_NNS->Reset();
	  histogram_2D_N_NS->Reset();
	  histogram_2D_P_NS->Reset();
	  histogram_2D_N_NNS->Reset();
	  histogram_2D_P_NNS->Reset();
*/
      histogram_1D_N_NS[file]->Fill(NHADsumNS);
      histogram_1DSum_N_NS[file]->Fill(NETsumNS);
      
      histogram_1D_P_NS[file]->Fill(PHADsumNS);
      histogram_1DSum_P_NS[file]->Fill(PETsumNS);

      histogram_1D_N_NNS[file]->Fill(NHADsumNNS);
      histogram_1DSum_N_NNS[file]->Fill(NETsumNNS);

      histogram_1D_P_NNS[file]->Fill(PHADsumNNS);
      histogram_1DSum_P_NNS[file]->Fill(PETsumNNS);

	  histogram_2D_N_NS[file]->Fill(NHADsumNS, NEMsumNS);
	  histogram_2D_P_NS[file]->Fill(PHADsumNS, PEMsumNS);

	  histogram_2D_N_NNS[file]->Fill(NHADsumNNS, NEMsumNNS);
	  histogram_2D_P_NNS[file]->Fill(PHADsumNNS, PEMsumNNS);
	  
	  //HADcal=(.1825)*((NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal)+(NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal))

      //EMcal=(.006)*((NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal)) 
      
      
      
//////////start time slide plots
   for(int iTS=0;iTS<10;iTS++){
   
        histogram_1D_PosHAD1[file]->Fill(iTS,posHD1fC[iTS]); 
        histogram_1D_PosHAD2[file]->Fill(iTS,posHD2fC[iTS]); 
        histogram_1D_PosHAD3[file]->Fill(iTS,posHD3fC[iTS]); 
        histogram_1D_PosHAD4[file]->Fill(iTS,posHD4fC[iTS]); 
        histogram_1D_NegHAD1[file]->Fill(iTS,negHD1fC[iTS]); 
        histogram_1D_NegHAD2[file]->Fill(iTS,negHD2fC[iTS]); 
        histogram_1D_NegHAD3[file]->Fill(iTS,negHD3fC[iTS]); 
        histogram_1D_NegHAD4[file]->Fill(iTS,negHD4fC[iTS]); 
        histogram_1D_PosEM1[file]->Fill(iTS,posEM1fC[iTS]); 
        histogram_1D_PosEM2[file]->Fill(iTS,posEM2fC[iTS]); 
        histogram_1D_PosEM3[file]->Fill(iTS,posEM3fC[iTS]); 
        histogram_1D_PosEM4[file]->Fill(iTS,posEM4fC[iTS]); 
        histogram_1D_PosEM5[file]->Fill(iTS,posEM5fC[iTS]); 
        histogram_1D_NegEM1[file]->Fill(iTS,negEM1fC[iTS]); 
        histogram_1D_NegEM2[file]->Fill(iTS,negEM2fC[iTS]); 
        histogram_1D_NegEM3[file]->Fill(iTS,negEM3fC[iTS]); 
        histogram_1D_NegEM4[file]->Fill(iTS,negEM4fC[iTS]); 
        histogram_1D_NegEM5[file]->Fill(iTS,negEM5fC[iTS]); 
        
        histogram_1D_PosHAD1[file]->SetDirectory(subdir);
        histogram_1D_PosHAD2[file]->SetDirectory(subdir);
        histogram_1D_PosHAD3[file]->SetDirectory(subdir);
        histogram_1D_PosHAD4[file]->SetDirectory(subdir);
        histogram_1D_NegHAD1[file]->SetDirectory(subdir);
        histogram_1D_NegHAD2[file]->SetDirectory(subdir);
        histogram_1D_NegHAD3[file]->SetDirectory(subdir);
        histogram_1D_NegHAD4[file]->SetDirectory(subdir);
        histogram_1D_PosEM1[file]->SetDirectory(subdir);
        histogram_1D_PosEM2[file]->SetDirectory(subdir);
        histogram_1D_PosEM3[file]->SetDirectory(subdir);
        histogram_1D_PosEM4[file]->SetDirectory(subdir);
        histogram_1D_PosEM5[file]->SetDirectory(subdir);
        histogram_1D_NegEM1[file]->SetDirectory(subdir);
        histogram_1D_NegEM2[file]->SetDirectory(subdir);
        histogram_1D_NegEM3[file]->SetDirectory(subdir);
        histogram_1D_NegEM4[file]->SetDirectory(subdir);
        histogram_1D_NegEM5[file]->SetDirectory(subdir);
   }
      
      
    }  
	   


outfile.cd();
subdir = outfile.mkdir(subdirname);
gDirectory->cd(subdirname);

histogram_1D_PosHAD1[file]->Write();
histogram_1D_PosHAD2[file]->Write();
histogram_1D_PosHAD3[file]->Write();
histogram_1D_PosHAD4[file]->Write();
histogram_1D_NegHAD1[file]->Write();
histogram_1D_NegHAD2[file]->Write();
histogram_1D_NegHAD3[file]->Write();
histogram_1D_NegHAD4[file]->Write();
histogram_1D_PosEM1[file]->Write();
histogram_1D_PosEM2[file]->Write();
histogram_1D_PosEM3[file]->Write();
histogram_1D_PosEM4[file]->Write();
histogram_1D_PosEM5[file]->Write();
histogram_1D_NegEM1[file]->Write();
histogram_1D_NegEM2[file]->Write();
histogram_1D_NegEM3[file]->Write();
histogram_1D_NegEM4[file]->Write();
histogram_1D_NegEM5[file]->Write();
     
     gROOT->Reset();
     
 	  c1 = new TCanvas();
      histogram_2D_N_NS[file]->SetXTitle("SumHAD (fC)");
      histogram_2D_N_NS[file]->SetYTitle("SumEM (fC)"); 
      c1->SetLogz();
      c1->SetLogy(0);
      histogram_2D_N_NS[file]->Draw("colz");
      histogram_2D_N_NS[file]->SetDirectory(subdir);
      histogram_2D_N_NS[file]->Write(output2DNS_N);
      c1->SaveAs(save2DNS_N);
      
      histogram_2D_P_NS[file]->SetXTitle("SumHAD (fC)");
      histogram_2D_P_NS[file]->SetYTitle("SumEM (fC)"); 
      c1->SetLogz();
      c1->SetLogy(0);
      histogram_2D_P_NS[file]->Draw("colz");
      histogram_2D_P_NS[file]->SetDirectory(subdir);
      histogram_2D_P_NS[file]->Write(output2DNS_P);
      c1->SaveAs(save2DNS_P);
      
      histogram_2D_N_NNS[file]->SetXTitle("SumHAD (fC)");
      histogram_2D_N_NNS[file]->SetYTitle("SumEM (fC)"); 
      c1->SetLogz();
      c1->SetLogy(0);
      histogram_2D_N_NNS[file]->Draw("colz");
      histogram_2D_N_NNS[file]->SetDirectory(subdir);
      histogram_2D_N_NNS[file]->Write(output2DNNS_N);
      c1->SaveAs(save2DNNS_N);
      
      histogram_2D_P_NNS[file]->SetXTitle("SumHAD (fC)");
      histogram_2D_P_NNS[file]->SetYTitle("SumEM (fC)"); 
      c1->SetLogz();
      c1->SetLogy(0);
      histogram_2D_P_NNS[file]->Draw("colz");
      histogram_2D_P_NNS[file]->SetDirectory(subdir);
      histogram_2D_P_NNS[file]->Write(output2DNNS_P);
      c1->SaveAs(save2DNNS_P);
      
      histogram_1D_N_NS[file]->SetXTitle("SumHad (fC)");
      histogram_1D_N_NS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1D_N_NS[file]->Draw();
      histogram_1D_N_NS[file]->SetDirectory(subdir);
      histogram_1D_N_NS[file]->Write(output1DNS_N);
      c1->SaveAs(save1DNS_N);
      
      histogram_1D_N_NNS[file]->SetXTitle("SumHad (fC)");
      histogram_1D_N_NNS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1D_N_NNS[file]->Draw();
      histogram_1D_N_NNS[file]->SetDirectory(subdir);
      histogram_1D_N_NNS[file]->Write(output1DNNS_N);
      c1->SaveAs(save1DNNS_N);
      
      histogram_1D_P_NS[file]->SetXTitle("SumHad (fC)");
      histogram_1D_P_NS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1D_P_NS[file]->Draw();
      histogram_1D_P_NS[file]->SetDirectory(subdir);
      histogram_1D_P_NS[file]->Write(output1DNS_P);
      c1->SaveAs(save1DNS_P);
      
      histogram_1D_P_NNS[file]->SetXTitle("SumHad (fC)");
      histogram_1D_P_NNS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1D_P_NNS[file]->Draw();
      histogram_1D_P_NNS[file]->SetDirectory(subdir);
      histogram_1D_P_NNS[file]->Write(output1DNNS_P);
      c1->SaveAs(save1DNNS_P);
 

      histogram_1DSum_N_NS[file]->SetXTitle(".1*SumEM+SumHad (fC)");
      histogram_1DSum_N_NS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1DSum_N_NS[file]->Draw();
      histogram_1DSum_N_NS[file]->SetDirectory(subdir);
      histogram_1DSum_N_NS[file]->Write(outputSumNS_N);
      c1->SaveAs(saveSumNS_N);
      
      histogram_1DSum_N_NNS[file]->SetXTitle(".1*SumEM+SumHad (fC)");
      histogram_1DSum_N_NNS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1DSum_N_NNS[file]->Draw();
      histogram_1DSum_N_NNS[file]->SetDirectory(subdir);
      histogram_1DSum_N_NNS[file]->Write(outputSumNNS_N);
      c1->SaveAs(saveSumNNS_N);
      
      histogram_1DSum_P_NS[file]->SetXTitle(".1*SumEM+SumHad (fC)");
      histogram_1DSum_P_NS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1DSum_P_NS[file]->Draw();
      histogram_1DSum_P_NS[file]->SetDirectory(subdir);
      histogram_1DSum_P_NS[file]->Write(outputSumNS_P);
      c1->SaveAs(saveSumNS_P);
      
      histogram_1DSum_P_NNS[file]->SetXTitle(".1*SumEM+SumHad (fC)");
      histogram_1DSum_P_NNS[file]->SetYTitle("Counts");
      c1->SetLogy();
      histogram_1DSum_P_NNS[file]->Draw();
      histogram_1DSum_P_NNS[file]->SetDirectory(subdir);
      histogram_1DSum_P_NNS[file]->Write(outputSumNNS_P);
      c1->SaveAs(saveSumNNS_P);
 
}


outfile.Close();

gStyle->SetOptStat(0);
gStyle->SetCanvasColor(-1); 
gStyle->SetPadColor(-1); 
gStyle->SetFrameFillColor(-1); 
gStyle->SetHistFillColor(-1); 
gStyle->SetTitleFillColor(-1); 
gStyle->SetFillColor(-1); 
gStyle->SetFillStyle(4000); 
gStyle->SetStatStyle(0); 
gStyle->SetTitleStyle(0); 
gStyle->SetCanvasBorderSize(0); 
gStyle->SetFrameBorderSize(0); 
gStyle->SetLegendBorderSize(0); 
gStyle->SetStatBorderSize(0); 
gStyle->SetTitleBorderSize(0); 

Double_t normalize = 1;
output = TFile::Open(outputfile);
leg = new TLegend(0.05,0.7,0.35,0.85);
TLegendEntry* l1 = leg->AddEntry("PHAD1signal_TS_fC","NoBPTX","");
l1->SetTextColor(4);
TLegendEntry* l2 = leg->AddEntry("PHAD1signal_TS_fC","PlusDirection_BPTX","");
l2->SetTextColor(2);
TLegendEntry* l3 = leg->AddEntry("PHAD1signal_TS_fC","MinusDirection_BPTX","");
l3->SetTextColor(3);
TLegendEntry* l4 = leg->AddEntry("PHAD1signal_TS_fC","Collisions","");
l4->SetTextColor(1);

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD1signal_TS_fC->SetMarkerColor(1);
PHAD1signal_TS_fC->SetLineColor(1);
PHAD1signal_TS_fC->SetFillColor(1);
entriescol=PHAD1signal_TS_fC->GetEntries();
ymax=PHAD1signal_TS_fC->GetMaximum();
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(2);
PHAD1signal_TS_fC->SetLineColor(2);
PHAD1signal_TS_fC->SetFillColor(2);
entriesothers=PHAD1signal_TS_fC->GetEntries();
PHAD1signal_TS_fC->Scale(entriescol/entriesothers);
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(3);
PHAD1signal_TS_fC->SetLineColor(3);
PHAD1signal_TS_fC->SetFillColor(3);
entriesothers=PHAD1signal_TS_fC->GetEntries();
PHAD1signal_TS_fC->Scale(entriescol/entriesothers);
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(4);
PHAD1signal_TS_fC->SetLineColor(4);
PHAD1signal_TS_fC->SetFillColor(4);
entriesothers=PHAD1signal_TS_fC->GetEntries();
PHAD1signal_TS_fC->Scale(entriescol/entriesothers);
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PHAD1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD2signal_TS_fC->SetMarkerColor(1);
PHAD2signal_TS_fC->SetLineColor(1);
PHAD2signal_TS_fC->SetFillColor(1);
entriescol=PHAD2signal_TS_fC->GetEntries();
ymax=PHAD2signal_TS_fC->GetMaximum();
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(2);
PHAD2signal_TS_fC->SetLineColor(2);
PHAD2signal_TS_fC->SetFillColor(2);
entriesothers=PHAD2signal_TS_fC->GetEntries();
PHAD2signal_TS_fC->Scale(entriescol/entriesothers);
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(3);
PHAD2signal_TS_fC->SetLineColor(3);
PHAD2signal_TS_fC->SetFillColor(3);
entriesothers=PHAD2signal_TS_fC->GetEntries();
PHAD2signal_TS_fC->Scale(entriescol/entriesothers);
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(4);
PHAD2signal_TS_fC->SetLineColor(4);
PHAD2signal_TS_fC->SetFillColor(4);
entriesothers=PHAD2signal_TS_fC->GetEntries();
PHAD2signal_TS_fC->Scale(entriescol/entriesothers);
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PHAD2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD3signal_TS_fC->SetMarkerColor(1);
PHAD3signal_TS_fC->SetLineColor(1);
PHAD3signal_TS_fC->SetFillColor(1);
entriescol=PHAD3signal_TS_fC->GetEntries();
ymax=PHAD3signal_TS_fC->GetMaximum();
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(2);
PHAD3signal_TS_fC->SetLineColor(2);
PHAD3signal_TS_fC->SetFillColor(2);
entriesothers=PHAD3signal_TS_fC->GetEntries();
PHAD3signal_TS_fC->Scale(entriescol/entriesothers);
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(3);
PHAD3signal_TS_fC->SetLineColor(3);
PHAD3signal_TS_fC->SetFillColor(3);
entriesothers=PHAD3signal_TS_fC->GetEntries();
PHAD3signal_TS_fC->Scale(entriescol/entriesothers);
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(4);
PHAD3signal_TS_fC->SetLineColor(4);
PHAD3signal_TS_fC->SetFillColor(4);
entriesothers=PHAD3signal_TS_fC->GetEntries();
PHAD3signal_TS_fC->Scale(entriescol/entriesothers);
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PHAD3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD4signal_TS_fC->SetMarkerColor(1);
PHAD4signal_TS_fC->SetLineColor(1);
PHAD4signal_TS_fC->SetFillColor(1);
entriescol=PHAD4signal_TS_fC->GetEntries();
ymax=PHAD4signal_TS_fC->GetMaximum();
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymax*.9,ymax*1.1);
PHAD4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(2);
PHAD4signal_TS_fC->SetLineColor(2);
PHAD4signal_TS_fC->SetFillColor(2);
entriesothers=PHAD4signal_TS_fC->GetEntries();
PHAD4signal_TS_fC->Scale(entriescol/entriesothers);
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(3);
PHAD4signal_TS_fC->SetLineColor(3);
PHAD4signal_TS_fC->SetFillColor(3);
entriesothers=PHAD4signal_TS_fC->GetEntries();
PHAD4signal_TS_fC->Scale(entriescol/entriesothers);
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(4);
PHAD4signal_TS_fC->SetLineColor(4);
PHAD4signal_TS_fC->SetFillColor(4);
entriesothers=PHAD4signal_TS_fC->GetEntries();
PHAD4signal_TS_fC->Scale(entriescol/entriesothers);
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymax*.5,ymax*1.1);
PHAD4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PHAD4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM1signal_TS_fC->SetMarkerColor(1);
PEM1signal_TS_fC->SetLineColor(1);
PEM1signal_TS_fC->SetFillColor(1);
entriescol=PEM1signal_TS_fC->GetEntries();
ymax=PEM1signal_TS_fC->GetMaximum();
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(2);
PEM1signal_TS_fC->SetLineColor(2);
PEM1signal_TS_fC->SetFillColor(2);
entriesothers=PEM1signal_TS_fC->GetEntries();
PEM1signal_TS_fC->Scale(entriescol/entriesothers);
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(3);
PEM1signal_TS_fC->SetLineColor(3);
PEM1signal_TS_fC->SetFillColor(3);
entriesothers=PEM1signal_TS_fC->GetEntries();
PEM1signal_TS_fC->Scale(entriescol/entriesothers);
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(4);
PEM1signal_TS_fC->SetLineColor(4);
PEM1signal_TS_fC->SetFillColor(4);
entriesothers=PEM1signal_TS_fC->GetEntries();
PEM1signal_TS_fC->Scale(entriescol/entriesothers);
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PEM1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM2signal_TS_fC->SetMarkerColor(1);
PEM2signal_TS_fC->SetLineColor(1);
PEM2signal_TS_fC->SetFillColor(1);
entriescol=PEM2signal_TS_fC->GetEntries();
ymax=PEM2signal_TS_fC->GetMaximum();
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(2);
PEM2signal_TS_fC->SetLineColor(2);
PEM2signal_TS_fC->SetFillColor(2);
entriesothers=PEM2signal_TS_fC->GetEntries();
PEM2signal_TS_fC->Scale(entriescol/entriesothers);
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(3);
PEM2signal_TS_fC->SetLineColor(3);
PEM2signal_TS_fC->SetFillColor(3);
entriesothers=PEM2signal_TS_fC->GetEntries();
PEM2signal_TS_fC->Scale(entriescol/entriesothers);
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(4);
PEM2signal_TS_fC->SetLineColor(4);
PEM2signal_TS_fC->SetFillColor(4);
entriesothers=PEM2signal_TS_fC->GetEntries();
PEM2signal_TS_fC->Scale(entriescol/entriesothers);
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PEM2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM3signal_TS_fC->SetMarkerColor(1);
PEM3signal_TS_fC->SetLineColor(1);
PEM3signal_TS_fC->SetFillColor(1);
entriescol=PEM3signal_TS_fC->GetEntries();
ymax=PEM3signal_TS_fC->GetMaximum();
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(2);
PEM3signal_TS_fC->SetLineColor(2);
PEM3signal_TS_fC->SetFillColor(2);
entriesothers=PEM3signal_TS_fC->GetEntries();
PEM3signal_TS_fC->Scale(entriescol/entriesothers);
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(3);
PEM3signal_TS_fC->SetLineColor(3);
PEM3signal_TS_fC->SetFillColor(3);
entriesothers=PEM3signal_TS_fC->GetEntries();
PEM3signal_TS_fC->Scale(entriescol/entriesothers);
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(4);
PEM3signal_TS_fC->SetLineColor(4);
PEM3signal_TS_fC->SetFillColor(4);
entriesothers=PEM3signal_TS_fC->GetEntries();
PEM3signal_TS_fC->Scale(entriescol/entriesothers);
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PEM3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM4signal_TS_fC->SetMarkerColor(1);
PEM4signal_TS_fC->SetLineColor(1);
PEM4signal_TS_fC->SetFillColor(1);
entriescol=PEM4signal_TS_fC->GetEntries();
ymax=PEM4signal_TS_fC->GetMaximum();
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(2);
PEM4signal_TS_fC->SetLineColor(2);
PEM4signal_TS_fC->SetFillColor(2);
entriesothers=PEM4signal_TS_fC->GetEntries();
PEM4signal_TS_fC->Scale(entriescol/entriesothers);
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(3);
PEM4signal_TS_fC->SetLineColor(3);
PEM4signal_TS_fC->SetFillColor(3);
entriesothers=PEM4signal_TS_fC->GetEntries();
PEM4signal_TS_fC->Scale(entriescol/entriesothers);
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(4);
PEM4signal_TS_fC->SetLineColor(4);
PEM4signal_TS_fC->SetFillColor(4);
entriesothers=PEM4signal_TS_fC->GetEntries();
PEM4signal_TS_fC->Scale(entriescol/entriesothers);
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PEM4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM5signal_TS_fC->SetMarkerColor(1);
PEM5signal_TS_fC->SetLineColor(1);
PEM5signal_TS_fC->SetFillColor(1);
entriescol=PEM5signal_TS_fC->GetEntries();
ymax=PEM5signal_TS_fC->GetMaximum();
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM5signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(2);
PEM5signal_TS_fC->SetLineColor(2);
PEM5signal_TS_fC->SetFillColor(2);
entriesothers=PEM5signal_TS_fC->GetEntries();
PEM5signal_TS_fC->Scale(entriescol/entriesothers);
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(3);
PEM5signal_TS_fC->SetLineColor(3);
PEM5signal_TS_fC->SetFillColor(3);
entriesothers=PEM5signal_TS_fC->GetEntries();
PEM5signal_TS_fC->Scale(entriescol/entriesothers);
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(4);
PEM5signal_TS_fC->SetLineColor(4);
PEM5signal_TS_fC->SetFillColor(4);
entriesothers=PEM5signal_TS_fC->GetEntries();
PEM5signal_TS_fC->Scale(entriescol/entriesothers);
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
PEM5signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_PEM5signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD1signal_TS_fC->SetMarkerColor(1);
NHAD1signal_TS_fC->SetLineColor(1);
NHAD1signal_TS_fC->SetFillColor(1);
entriescol=NHAD1signal_TS_fC->GetEntries();
ymax=NHAD1signal_TS_fC->GetMaximum();
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(2);
NHAD1signal_TS_fC->SetLineColor(2);
NHAD1signal_TS_fC->SetFillColor(2);
entriesothers=NHAD1signal_TS_fC->GetEntries();
NHAD1signal_TS_fC->Scale(entriescol/entriesothers);
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(3);
NHAD1signal_TS_fC->SetLineColor(3);
NHAD1signal_TS_fC->SetFillColor(3);
entriesothers=NHAD1signal_TS_fC->GetEntries();
NHAD1signal_TS_fC->Scale(entriescol/entriesothers);
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(4);
NHAD1signal_TS_fC->SetLineColor(4);
NHAD1signal_TS_fC->SetFillColor(4);
entriesothers=NHAD1signal_TS_fC->GetEntries();
NHAD1signal_TS_fC->Scale(entriescol/entriesothers);
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NHAD1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD2signal_TS_fC->SetMarkerColor(1);
NHAD2signal_TS_fC->SetLineColor(1);
NHAD2signal_TS_fC->SetFillColor(1);
entriescol=NHAD2signal_TS_fC->GetEntries();
ymax=NHAD2signal_TS_fC->GetMaximum();
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(2);
NHAD2signal_TS_fC->SetLineColor(2);
NHAD2signal_TS_fC->SetFillColor(2);
entriesothers=NHAD2signal_TS_fC->GetEntries();
NHAD2signal_TS_fC->Scale(entriescol/entriesothers);
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(3);
NHAD2signal_TS_fC->SetLineColor(3);
NHAD2signal_TS_fC->SetFillColor(3);
entriesothers=NHAD2signal_TS_fC->GetEntries();
NHAD2signal_TS_fC->Scale(entriescol/entriesothers);
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(4);
NHAD2signal_TS_fC->SetLineColor(4);
NHAD2signal_TS_fC->SetFillColor(4);
entriesothers=NHAD2signal_TS_fC->GetEntries();
NHAD2signal_TS_fC->Scale(entriescol/entriesothers);
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NHAD2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD3signal_TS_fC->SetMarkerColor(1);
NHAD3signal_TS_fC->SetLineColor(1);
NHAD3signal_TS_fC->SetFillColor(1);
entriescol=NHAD3signal_TS_fC->GetEntries();
ymax=NHAD3signal_TS_fC->GetMaximum();
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(2);
NHAD3signal_TS_fC->SetLineColor(2);
NHAD3signal_TS_fC->SetFillColor(2);
entriesothers=NHAD3signal_TS_fC->GetEntries();
NHAD3signal_TS_fC->Scale(entriescol/entriesothers);
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(3);
NHAD3signal_TS_fC->SetLineColor(3);
NHAD3signal_TS_fC->SetFillColor(3);
entriesothers=NHAD3signal_TS_fC->GetEntries();
NHAD3signal_TS_fC->Scale(entriescol/entriesothers);
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(4);
NHAD3signal_TS_fC->SetLineColor(4);
NHAD3signal_TS_fC->SetFillColor(4);
entriesothers=NHAD3signal_TS_fC->GetEntries();
NHAD3signal_TS_fC->Scale(entriescol/entriesothers);
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NHAD3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD4signal_TS_fC->SetMarkerColor(1);
NHAD4signal_TS_fC->SetLineColor(1);
NHAD4signal_TS_fC->SetFillColor(1);
entriescol=NHAD4signal_TS_fC->GetEntries();
ymax=NHAD4signal_TS_fC->GetMaximum();
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(2);
NHAD4signal_TS_fC->SetLineColor(2);
NHAD4signal_TS_fC->SetFillColor(2);
entriesothers=NHAD4signal_TS_fC->GetEntries();
NHAD4signal_TS_fC->Scale(entriescol/entriesothers);
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(3);
NHAD4signal_TS_fC->SetLineColor(3);
NHAD4signal_TS_fC->SetFillColor(3);
entriesothers=NHAD4signal_TS_fC->GetEntries();
NHAD4signal_TS_fC->Scale(entriescol/entriesothers);
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(4);
NHAD4signal_TS_fC->SetLineColor(4);
NHAD4signal_TS_fC->SetFillColor(4);
entriesothers=NHAD4signal_TS_fC->GetEntries();
NHAD4signal_TS_fC->Scale(entriescol/entriesothers);
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NHAD4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NHAD4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM1signal_TS_fC->SetMarkerColor(1);
NEM1signal_TS_fC->SetLineColor(1);
NEM1signal_TS_fC->SetFillColor(1);
entriescol=NEM1signal_TS_fC->GetEntries();
ymax=NEM1signal_TS_fC->GetMaximum();
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(2);
NEM1signal_TS_fC->SetLineColor(2);
NEM1signal_TS_fC->SetFillColor(2);
entriesothers=NEM1signal_TS_fC->GetEntries();
NEM1signal_TS_fC->Scale(entriescol/entriesothers);
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(3);
NEM1signal_TS_fC->SetLineColor(3);
NEM1signal_TS_fC->SetFillColor(3);
entriesothers=NEM1signal_TS_fC->GetEntries();
NEM1signal_TS_fC->Scale(entriescol/entriesothers);
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(4);
NEM1signal_TS_fC->SetLineColor(4);
NEM1signal_TS_fC->SetFillColor(4);
entriesothers=NEM1signal_TS_fC->GetEntries();
NEM1signal_TS_fC->Scale(entriescol/entriesothers);
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NEM1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM2signal_TS_fC->SetMarkerColor(1);
NEM2signal_TS_fC->SetLineColor(1);
NEM2signal_TS_fC->SetFillColor(1);
entriescol=NEM2signal_TS_fC->GetEntries();
ymax=NEM2signal_TS_fC->GetMaximum();
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(2);
NEM2signal_TS_fC->SetLineColor(2);
NEM2signal_TS_fC->SetFillColor(2);
entriesothers=NEM2signal_TS_fC->GetEntries();
NEM2signal_TS_fC->Scale(entriescol/entriesothers);
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(3);
NEM2signal_TS_fC->SetLineColor(3);
NEM2signal_TS_fC->SetFillColor(3);
entriesothers=NEM2signal_TS_fC->GetEntries();
NEM2signal_TS_fC->Scale(entriescol/entriesothers);
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(4);
NEM2signal_TS_fC->SetLineColor(4);
NEM2signal_TS_fC->SetFillColor(4);
entriesothers=NEM2signal_TS_fC->GetEntries();
NEM2signal_TS_fC->Scale(entriescol/entriesothers);
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NEM2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM3signal_TS_fC->SetMarkerColor(1);
NEM3signal_TS_fC->SetLineColor(1);
NEM3signal_TS_fC->SetFillColor(1);
entriescol=NEM3signal_TS_fC->GetEntries();
ymax=NEM3signal_TS_fC->GetMaximum();
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(2);
NEM3signal_TS_fC->SetLineColor(2);
NEM3signal_TS_fC->SetFillColor(2);
entriesothers=NEM3signal_TS_fC->GetEntries();
NEM3signal_TS_fC->Scale(entriescol/entriesothers);
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(3);
NEM3signal_TS_fC->SetLineColor(3);
NEM3signal_TS_fC->SetFillColor(3);
entriesothers=NEM3signal_TS_fC->GetEntries();
NEM3signal_TS_fC->Scale(entriescol/entriesothers);
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(4);
NEM3signal_TS_fC->SetLineColor(4);
NEM3signal_TS_fC->SetFillColor(4);
entriesothers=NEM3signal_TS_fC->GetEntries();
NEM3signal_TS_fC->Scale(entriescol/entriesothers);
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NEM3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM4signal_TS_fC->SetMarkerColor(1);
NEM4signal_TS_fC->SetLineColor(1);
NEM4signal_TS_fC->SetFillColor(1);
entriescol=NEM4signal_TS_fC->GetEntries();
ymax=NEM4signal_TS_fC->GetMaximum();
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(2);
NEM4signal_TS_fC->SetLineColor(2);
NEM4signal_TS_fC->SetFillColor(2);
entriesothers=NEM4signal_TS_fC->GetEntries();
NEM4signal_TS_fC->Scale(entriescol/entriesothers);
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(3);
NEM4signal_TS_fC->SetLineColor(3);
NEM4signal_TS_fC->SetFillColor(3);
entriesothers=NEM4signal_TS_fC->GetEntries();
NEM4signal_TS_fC->Scale(entriescol/entriesothers);
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(4);
NEM4signal_TS_fC->SetLineColor(4);
NEM4signal_TS_fC->SetFillColor(4);
entriesothers=NEM4signal_TS_fC->GetEntries();
NEM4signal_TS_fC->Scale(entriescol/entriesothers);
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NEM4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM5signal_TS_fC->SetMarkerColor(1);
NEM5signal_TS_fC->SetLineColor(1);
NEM5signal_TS_fC->SetFillColor(1);
entriescol=NEM5signal_TS_fC->GetEntries();
ymax=NEM5signal_TS_fC->GetMaximum();
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM5signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(2);
NEM5signal_TS_fC->SetLineColor(2);
NEM5signal_TS_fC->SetFillColor(2);
entriesothers=NEM5signal_TS_fC->GetEntries();
NEM5signal_TS_fC->Scale(entriescol/entriesothers);
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(3);
NEM5signal_TS_fC->SetLineColor(3);
NEM5signal_TS_fC->SetFillColor(3);
entriesothers=NEM5signal_TS_fC->GetEntries();
NEM5signal_TS_fC->Scale(entriescol/entriesothers);
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(4);
NEM5signal_TS_fC->SetLineColor(4);
NEM5signal_TS_fC->SetFillColor(4);
entriesothers=NEM5signal_TS_fC->GetEntries();
NEM5signal_TS_fC->Scale(entriescol/entriesothers);
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(ymin,ymax*1.1);
NEM5signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/scaledTScomp_run%i_NEM5signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD1signal_TS_fC->SetMarkerColor(1);
PHAD1signal_TS_fC->SetLineColor(1);
PHAD1signal_TS_fC->SetFillColor(1);

PHAD1signal_TS_fC->Scale(normalize/PHAD1signal_TS_fC->Integral("width"));
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(2);
PHAD1signal_TS_fC->SetLineColor(2);
PHAD1signal_TS_fC->SetFillColor(2);
PHAD1signal_TS_fC->Scale(normalize/PHAD1signal_TS_fC->Integral("width"));
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(3);
PHAD1signal_TS_fC->SetLineColor(3);
PHAD1signal_TS_fC->SetFillColor(3);
PHAD1signal_TS_fC->Scale(normalize/PHAD1signal_TS_fC->Integral("width"));
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD1signal_TS_fC->SetMarkerColor(4);
PHAD1signal_TS_fC->SetLineColor(4);
PHAD1signal_TS_fC->SetFillColor(4);
PHAD1signal_TS_fC->Scale(normalize/PHAD1signal_TS_fC->Integral("width"));
PHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PHAD1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD2signal_TS_fC->SetMarkerColor(1);
PHAD2signal_TS_fC->SetLineColor(1);
PHAD2signal_TS_fC->Scale(normalize/PHAD2signal_TS_fC->Integral("width"));
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(2);
PHAD2signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PHAD2signal_TS_fC->Scale(normalize/PHAD2signal_TS_fC->Integral("width"));
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD2signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(3);
PHAD2signal_TS_fC->SetLineColor(3);
PHAD2signal_TS_fC->Scale(normalize/PHAD2signal_TS_fC->Integral("width"));
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD2signal_TS_fC->SetMarkerColor(4);
PHAD2signal_TS_fC->SetLineColor(4);
PHAD2signal_TS_fC->Scale(normalize/PHAD2signal_TS_fC->Integral("width"));
PHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PHAD2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD3signal_TS_fC->SetMarkerColor(1);
PHAD3signal_TS_fC->SetLineColor(1);
PHAD3signal_TS_fC->Scale(normalize/PHAD3signal_TS_fC->Integral("width"));
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(2);
PHAD3signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PHAD3signal_TS_fC->Scale(normalize/PHAD3signal_TS_fC->Integral("width"));
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD3signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(3);
PHAD3signal_TS_fC->SetLineColor(3);
PHAD3signal_TS_fC->Scale(normalize/PHAD3signal_TS_fC->Integral("width"));
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD3signal_TS_fC->SetMarkerColor(4);
PHAD3signal_TS_fC->SetLineColor(4);
PHAD3signal_TS_fC->Scale(normalize/PHAD3signal_TS_fC->Integral("width"));
PHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PHAD3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PHAD4signal_TS_fC->SetMarkerColor(1);
PHAD4signal_TS_fC->SetLineColor(1);
PHAD4signal_TS_fC->Scale(normalize/PHAD4signal_TS_fC->Integral("width"));
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(2);
PHAD4signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PHAD4signal_TS_fC->Scale(normalize/PHAD4signal_TS_fC->Integral("width"));
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD4signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(3);
PHAD4signal_TS_fC->SetLineColor(3);
PHAD4signal_TS_fC->Scale(normalize/PHAD4signal_TS_fC->Integral("width"));
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PHAD4signal_TS_fC->SetMarkerColor(4);
PHAD4signal_TS_fC->SetLineColor(4);
PHAD4signal_TS_fC->Scale(normalize/PHAD4signal_TS_fC->Integral("width"));
PHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PHAD4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PHAD4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD1signal_TS_fC->SetMarkerColor(1);
NHAD1signal_TS_fC->SetLineColor(1);
NHAD1signal_TS_fC->Scale(normalize/NHAD1signal_TS_fC->Integral("width"));
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(2);
NHAD1signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NHAD1signal_TS_fC->Scale(normalize/NHAD1signal_TS_fC->Integral("width"));
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD1signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(3);
NHAD1signal_TS_fC->SetLineColor(3);
NHAD1signal_TS_fC->Scale(normalize/NHAD1signal_TS_fC->Integral("width"));
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD1signal_TS_fC->SetMarkerColor(4);
NHAD1signal_TS_fC->SetLineColor(4);
NHAD1signal_TS_fC->Scale(normalize/NHAD1signal_TS_fC->Integral("width"));
NHAD1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NHAD1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

/////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD2signal_TS_fC->SetMarkerColor(1);
NHAD2signal_TS_fC->SetLineColor(1);
NHAD2signal_TS_fC->Scale(normalize/NHAD2signal_TS_fC->Integral("width"));
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(2);
NHAD2signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NHAD2signal_TS_fC->Scale(normalize/NHAD2signal_TS_fC->Integral("width"));
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD2signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(3);
NHAD2signal_TS_fC->SetLineColor(3);
NHAD2signal_TS_fC->Scale(normalize/NHAD2signal_TS_fC->Integral("width"));
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD2signal_TS_fC->SetMarkerColor(4);
NHAD2signal_TS_fC->SetLineColor(4);
NHAD2signal_TS_fC->Scale(normalize/NHAD2signal_TS_fC->Integral("width"));
NHAD2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NHAD2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD3signal_TS_fC->SetMarkerColor(1);
NHAD3signal_TS_fC->SetLineColor(1);
NHAD3signal_TS_fC->Scale(normalize/NHAD3signal_TS_fC->Integral("width"));
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(2);
NHAD3signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NHAD3signal_TS_fC->Scale(normalize/NHAD3signal_TS_fC->Integral("width"));
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD3signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(3);
NHAD3signal_TS_fC->SetLineColor(3);
NHAD3signal_TS_fC->Scale(normalize/NHAD3signal_TS_fC->Integral("width"));
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD3signal_TS_fC->SetMarkerColor(4);
NHAD3signal_TS_fC->SetLineColor(4);
NHAD3signal_TS_fC->Scale(normalize/NHAD3signal_TS_fC->Integral("width"));
NHAD3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NHAD3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////
gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NHAD4signal_TS_fC->SetMarkerColor(1);
NHAD4signal_TS_fC->SetLineColor(1);
NHAD4signal_TS_fC->Scale(normalize/NHAD4signal_TS_fC->Integral("width"));
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(2);
NHAD4signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NHAD4signal_TS_fC->Scale(normalize/NHAD4signal_TS_fC->Integral("width"));
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD4signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(3);
NHAD4signal_TS_fC->SetLineColor(3);
NHAD4signal_TS_fC->Scale(normalize/NHAD4signal_TS_fC->Integral("width"));
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NHAD4signal_TS_fC->SetMarkerColor(4);
NHAD4signal_TS_fC->SetLineColor(4);
NHAD4signal_TS_fC->Scale(normalize/NHAD4signal_TS_fC->Integral("width"));
NHAD4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NHAD4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NHAD4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);
///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM1signal_TS_fC->SetMarkerColor(1);
PEM1signal_TS_fC->SetLineColor(1);
PEM1signal_TS_fC->Scale(normalize/PEM1signal_TS_fC->Integral("width"));
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(2);
PEM1signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PEM1signal_TS_fC->Scale(normalize/PEM1signal_TS_fC->Integral("width"));
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM1signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(3);
PEM1signal_TS_fC->SetLineColor(3);
PEM1signal_TS_fC->Scale(normalize/PEM1signal_TS_fC->Integral("width"));
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM1signal_TS_fC->SetMarkerColor(4);
PEM1signal_TS_fC->SetLineColor(4);
PEM1signal_TS_fC->Scale(normalize/PEM1signal_TS_fC->Integral("width"));
PEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PEM1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM2signal_TS_fC->SetMarkerColor(1);
PEM2signal_TS_fC->SetLineColor(1);
PEM2signal_TS_fC->Scale(normalize/PEM2signal_TS_fC->Integral("width"));
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(2);
PEM2signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PEM2signal_TS_fC->Scale(normalize/PEM2signal_TS_fC->Integral("width"));
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM2signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(3);
PEM2signal_TS_fC->SetLineColor(3);
PEM2signal_TS_fC->Scale(normalize/PEM2signal_TS_fC->Integral("width"));
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM2signal_TS_fC->SetMarkerColor(4);
PEM2signal_TS_fC->SetLineColor(4);
PEM2signal_TS_fC->Scale(normalize/PEM2signal_TS_fC->Integral("width"));
PEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PEM2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM3signal_TS_fC->SetMarkerColor(1);
PEM3signal_TS_fC->SetLineColor(1);
PEM3signal_TS_fC->Scale(normalize/PEM3signal_TS_fC->Integral("width"));
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(2);
PEM3signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PEM3signal_TS_fC->Scale(normalize/PEM3signal_TS_fC->Integral("width"));
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM3signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(3);
PEM3signal_TS_fC->SetLineColor(3);
PEM3signal_TS_fC->Scale(normalize/PEM3signal_TS_fC->Integral("width"));
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM3signal_TS_fC->SetMarkerColor(4);
PEM3signal_TS_fC->SetLineColor(4);
PEM3signal_TS_fC->Scale(normalize/PEM3signal_TS_fC->Integral("width"));
PEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PEM3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM4signal_TS_fC->SetMarkerColor(1);
PEM4signal_TS_fC->SetLineColor(1);
PEM4signal_TS_fC->Scale(normalize/PEM4signal_TS_fC->Integral("width"));
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(2);
PEM4signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PEM4signal_TS_fC->Scale(normalize/PEM4signal_TS_fC->Integral("width"));
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM4signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(3);
PEM4signal_TS_fC->SetLineColor(3);
PEM4signal_TS_fC->Scale(normalize/PEM4signal_TS_fC->Integral("width"));
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM4signal_TS_fC->SetMarkerColor(4);
PEM4signal_TS_fC->SetLineColor(4);
PEM4signal_TS_fC->Scale(normalize/PEM4signal_TS_fC->Integral("width"));
PEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PEM4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
PEM5signal_TS_fC->SetMarkerColor(1);
PEM5signal_TS_fC->SetLineColor(1);
PEM5signal_TS_fC->Scale(normalize/PEM5signal_TS_fC->Integral("width"));
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM5signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(2);
PEM5signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
PEM5signal_TS_fC->Scale(normalize/PEM5signal_TS_fC->Integral("width"));
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM5signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(3);
PEM5signal_TS_fC->SetLineColor(3);
PEM5signal_TS_fC->Scale(normalize/PEM5signal_TS_fC->Integral("width"));
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
PEM5signal_TS_fC->SetMarkerColor(4);
PEM5signal_TS_fC->SetLineColor(4);
PEM5signal_TS_fC->Scale(normalize/PEM5signal_TS_fC->Integral("width"));
PEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
PEM5signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_PEM5signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM1signal_TS_fC->SetMarkerColor(1);
NEM1signal_TS_fC->SetLineColor(1);
NEM1signal_TS_fC->Scale(normalize/NEM1signal_TS_fC->Integral("width"));
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM1signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(2);
NEM1signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NEM1signal_TS_fC->Scale(normalize/NEM1signal_TS_fC->Integral("width"));
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM1signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(3);
NEM1signal_TS_fC->SetLineColor(3);
NEM1signal_TS_fC->Scale(normalize/NEM1signal_TS_fC->Integral("width"));
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM1signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM1signal_TS_fC->SetMarkerColor(4);
NEM1signal_TS_fC->SetLineColor(4);
NEM1signal_TS_fC->Scale(normalize/NEM1signal_TS_fC->Integral("width"));
NEM1signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM1signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NEM1signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM2signal_TS_fC->SetMarkerColor(1);
NEM2signal_TS_fC->SetLineColor(1);
NEM2signal_TS_fC->Scale(normalize/NEM2signal_TS_fC->Integral("width"));
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM2signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(2);
NEM2signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NEM2signal_TS_fC->Scale(normalize/NEM2signal_TS_fC->Integral("width"));
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM2signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(3);
NEM2signal_TS_fC->SetLineColor(3);
NEM2signal_TS_fC->Scale(normalize/NEM2signal_TS_fC->Integral("width"));
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM2signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM2signal_TS_fC->SetMarkerColor(4);
NEM2signal_TS_fC->SetLineColor(4);
NEM2signal_TS_fC->Scale(normalize/NEM2signal_TS_fC->Integral("width"));
NEM2signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM2signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NEM2signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM3signal_TS_fC->SetMarkerColor(1);
NEM3signal_TS_fC->SetLineColor(1);
NEM3signal_TS_fC->Scale(normalize/NEM3signal_TS_fC->Integral("width"));
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM3signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(2);
NEM3signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NEM3signal_TS_fC->Scale(normalize/NEM3signal_TS_fC->Integral("width"));
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM3signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(3);
NEM3signal_TS_fC->SetLineColor(3);
NEM3signal_TS_fC->Scale(normalize/NEM3signal_TS_fC->Integral("width"));
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM3signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM3signal_TS_fC->SetMarkerColor(4);
NEM3signal_TS_fC->SetLineColor(4);
NEM3signal_TS_fC->Scale(normalize/NEM3signal_TS_fC->Integral("width"));
NEM3signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM3signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NEM3signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM4signal_TS_fC->SetMarkerColor(1);
NEM4signal_TS_fC->SetLineColor(1);
NEM4signal_TS_fC->Scale(normalize/NEM4signal_TS_fC->Integral("width"));
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM4signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(2);
NEM4signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NEM4signal_TS_fC->Scale(normalize/NEM4signal_TS_fC->Integral("width"));
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM4signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(3);
NEM4signal_TS_fC->SetLineColor(3);
NEM4signal_TS_fC->Scale(normalize/NEM4signal_TS_fC->Integral("width"));
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM4signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM4signal_TS_fC->SetMarkerColor(4);
NEM4signal_TS_fC->SetLineColor(4);
NEM4signal_TS_fC->Scale(normalize/NEM4signal_TS_fC->Integral("width"));
NEM4signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM4signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NEM4signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////

///////////////////////////////
///////////////////////////////

gROOT->cd();
output->cd();
Collisions->cd();
c1->SetLogy(0);
NEM5signal_TS_fC->SetMarkerColor(1);
NEM5signal_TS_fC->SetLineColor(1);
NEM5signal_TS_fC->Scale(normalize/NEM5signal_TS_fC->Integral("width"));
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM5signal_TS_fC->Draw();

gROOT->cd();
output->cd();
PlusDirection_BPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(2);
NEM5signal_TS_fC->SetLineColor(2);


l2->SetTextColor(2);
NEM5signal_TS_fC->Scale(normalize/NEM5signal_TS_fC->Integral("width"));
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM5signal_TS_fC->Draw("same");
gROOT->cd();
output->cd();
MinusDirection_BPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(3);
NEM5signal_TS_fC->SetLineColor(3);
NEM5signal_TS_fC->Scale(normalize/NEM5signal_TS_fC->Integral("width"));
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM5signal_TS_fC->Draw("same");

gROOT->cd();
output->cd();
NoBPTX->cd();
NEM5signal_TS_fC->SetMarkerColor(4);
NEM5signal_TS_fC->SetLineColor(4);
NEM5signal_TS_fC->Scale(normalize/NEM5signal_TS_fC->Integral("width"));
NEM5signal_TS_fC->GetYaxis()->SetRangeUser(0,.25);
NEM5signal_TS_fC->Draw("same");

leg->Draw();

sprintf(TSsavename,"plots/normTScomp_run%i_NEM5signal_TS_fC.pdf",runnumber);
c1->SaveAs(TSsavename);

///////////////////////////////
///////////////////////////////



}