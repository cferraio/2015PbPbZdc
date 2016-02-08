#define HADsignal_TSfull_cxx
#include "HADsignal_TSfull.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void HADsignal_TSfull::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L HADsignal_TSfull.C
//      Root > HADsignal_TSfull t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

 TChain *chain=new TChain("ZDCDigiTree","");
 TFile *f = new TFile("/data/users/ferraioc/ZDC2015/PbPb2015_PromptReco_MinBias2_262811.root");
 TTree *aTree=(TTree*) f->Get("ZDCRecTree");
 Int_t Cent_HFtowers;
 aTree->SetBranchAddress("Cent_HFtowers",&Cent_HFtowers);
  
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


  if (fChain == 0) return;

//   Long64_t eventinput;
   Long64_t nentries = fChain->GetEntriesFast();
   cout<<"There are "<<nentries<<" entires in this file."<<endl;
//   cout<<"Please enter an event number to make a histo: ";
//   cin>>eventinput;

/*   if (eventinput < 0 || eventinput > nentries) {
     cout<<"Entry number out of range"<<endl;
	 cout<<"Please enter an event number to make histos: ";
     cin>>eventinput;
   }
   */
   vector<int> centrality;
   vector<int> eventnumber;
   int n = 0;
   for(Long64_t jentry = 0; jentry < nentries; jentry++){
     aTree->GetEntry(jentry);
     if(Cent_HFtowers>74 && Cent_HFtowers<126){
       centrality.push_back (Cent_HFtowers);
       eventnumber.push_back (jentry);
       n++;
    }
       
   }
   cout<<"Of those, "<<n<<" are withing cent bins 75 - 125."<<endl;
   srand(time(0));
   Long64_t random = rand() % n; 

   Int_t thecent = centrality.at(random);
   Long64_t jentry = eventnumber.at(random);
   cout<<"The event number is "<<jentry<<", which has a cent bin of "<<thecent<<endl;
   fChain->GetEntry(jentry);
//   

  for(int iTS=0;iTS<10;iTS++){
    nhad1y[iTS] = negHD1fC[iTS];
    nhad2y[iTS] = negHD2fC[iTS];
    nhad3y[iTS] = negHD3fC[iTS];
    nhad4y[iTS] = negHD4fC[iTS];
	phad1y[iTS] = posHD1fC[iTS];
    phad2y[iTS] = posHD2fC[iTS];
    phad3y[iTS] = posHD3fC[iTS];
    phad4y[iTS] = posHD4fC[iTS];
    
    nem1y[iTS] = negEM1fC[iTS];
    nem2y[iTS] = negEM2fC[iTS];
    nem3y[iTS] = negEM3fC[iTS];
    nem4y[iTS] = negEM4fC[iTS];
    nem5y[iTS] = negEM5fC[iTS];
	pem1y[iTS] = posEM1fC[iTS];
    pem2y[iTS] = posEM2fC[iTS];
    pem3y[iTS] = posEM3fC[iTS];
    pem4y[iTS] = posEM4fC[iTS];
    pem5y[iTS] = posEM5fC[iTS];
  }

  double y[10] = {0,0,0,0,0,0,0,0,0,0};
  double xl[10] = {0,0,0,0,0,0,0,0,0,0};
  double yl[10] = {0,0,0,0,0,0,0,0,0,0};
  double xh[10] = {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15};
  NEM1 = new TGraphAsymmErrors(10,em1x,y,xl,xh,yl,nem1y);
  NEM2 = new TGraphAsymmErrors(10,em2x,y,xl,xh,yl,nem2y);
  NEM3 = new TGraphAsymmErrors(10,em3x,y,xl,xh,yl,nem3y);
  NEM4 = new TGraphAsymmErrors(10,em4x,y,xl,xh,yl,nem4y);
  NEM5 = new TGraphAsymmErrors(10,em5x,y,xl,xh,yl,nem5y);
  PEM1 = new TGraphAsymmErrors(10,em1x,y,xl,xh,yl,pem1y);
  PEM2 = new TGraphAsymmErrors(10,em2x,y,xl,xh,yl,pem2y);
  PEM3 = new TGraphAsymmErrors(10,em3x,y,xl,xh,yl,pem3y);
  PEM4 = new TGraphAsymmErrors(10,em4x,y,xl,xh,yl,pem4y);
  PEM5 = new TGraphAsymmErrors(10,em5x,y,xl,xh,yl,pem5y);
  NHAD1 = new TGraphAsymmErrors(10,had1x,y,xl,xh,yl,nhad1y);
  NHAD2 = new TGraphAsymmErrors(10,had2x,y,xl,xh,yl,nhad2y);
  NHAD3 = new TGraphAsymmErrors(10,had3x,y,xl,xh,yl,nhad3y);
  NHAD4 = new TGraphAsymmErrors(10,had4x,y,xl,xh,yl,nhad4y);
  PHAD1 = new TGraphAsymmErrors(10,had1x,y,xl,xh,yl,phad1y);
  PHAD2 = new TGraphAsymmErrors(10,had2x,y,xl,xh,yl,phad2y);
  PHAD3 = new TGraphAsymmErrors(10,had3x,y,xl,xh,yl,phad3y);
  PHAD4 = new TGraphAsymmErrors(10,had4x,y,xl,xh,yl,phad4y);
  
  
  char nemtitle[200];
  char pemtitle[200];
  char phadtitle[200];
  char nhadtitle[200];
  sprintf(nemtitle,"NEM Signal in different time slices, Event %llu",jentry);
  sprintf(pemtitle,"PEM Signal in different time slices, Event %llu",jentry);
  sprintf(phadtitle,"PHAD Signal in different time slices, Event %llu",jentry);
  sprintf(nhadtitle,"NHAD Signal in different time slices, Event %llu",jentry);
  NEM1->GetYaxis()->SetTitle("Signal Response");
  NEM1->GetXaxis()->SetTitle("Time Slice");
  NEM1->SetTitle(nemtitle);
  PEM1->SetTitle(pemtitle);
  PEM1->GetYaxis()->SetTitle("Signal Response");
  PEM1->GetXaxis()->SetTitle("Time Slice");
  NHAD1->SetTitle(nhadtitle);
  PHAD1->SetTitle(phadtitle);
  NHAD1->GetYaxis()->SetTitle("Signal Response");
  NHAD1->GetXaxis()->SetTitle("Time Slice");
  PHAD1->GetYaxis()->SetTitle("Signal Response");
  PHAD1->GetXaxis()->SetTitle("Time Slice");
  
  double largest = 0;
  for(int iTS = 0; iTS < 10; iTS++){
  	if(phad1y[iTS] > largest) largest = phad1y[iTS];
  	if(phad2y[iTS] > largest) largest = phad2y[iTS];
  	if(phad3y[iTS] > largest) largest = phad3y[iTS];
  	if(phad4y[iTS] > largest) largest = phad4y[iTS];
  }
  
  PHAD1->SetMaximum(largest*1.1); 
  
  
  char savename[100];
  c1 = new TCanvas("c1","PHAD Signal in different time slices",300,10,700,500);
  c1->SetLeftMargin(0.15);
  PHAD1->SetFillColor(1);
  PHAD1->GetXaxis()->SetRangeUser(-0.3,9.5);
  PHAD1->GetYaxis()->SetTitleOffset(1.75);
  PHAD1->GetYaxis()->CenterTitle();  
  PHAD1->Draw("a2");
  PHAD2->SetFillColor(2);
  PHAD2->Draw("2same");
  PHAD3->SetFillColor(3);
  PHAD3->Draw("2same");
  PHAD4->SetFillColor(4);
  PHAD4->Draw("2same");
  leg1 = new TLegend(0.175,0.675,0.35,0.875);
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->AddEntry(PHAD1,"PHAD1","f");
  leg1->AddEntry(PHAD2,"PHAD2","f");
  leg1->AddEntry(PHAD3,"PHAD3","f");
  leg1->AddEntry(PHAD4,"PHAD4","f");
  leg1->Draw();
  sprintf(savename,"PHAD_Event%llu.pdf",jentry);
  c1->SaveAs(savename);
  
  largest = 0;
  for(int iTS = 0; iTS < 10; iTS++){
  	if(nhad1y[iTS] > largest) largest = nhad1y[iTS];
  	if(nhad2y[iTS] > largest) largest = nhad2y[iTS];
  	if(nhad3y[iTS] > largest) largest = nhad3y[iTS];
  	if(nhad4y[iTS] > largest) largest = nhad4y[iTS];
  }
  
  NHAD1->SetMaximum(largest*1.1);  
  
  c1 = new TCanvas("c1","NHAD Signal in different time slices",300,10,700,500);
  c1->SetLeftMargin(0.15);
  NHAD1->SetFillColor(1);
  NHAD1->GetXaxis()->SetRangeUser(-0.3,9.5);
  NHAD1->GetYaxis()->SetTitleOffset(1.75);
  NHAD1->GetYaxis()->CenterTitle();  
  NHAD1->Draw("a2");
  NHAD2->SetFillColor(2);
  NHAD2->Draw("2same");
  NHAD3->SetFillColor(3);
  NHAD3->Draw("2same");
  NHAD4->SetFillColor(4);
  NHAD4->Draw("2same");
  leg1 = new TLegend(0.175,0.675,0.35,0.875);
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->AddEntry(NHAD1,"NHAD1","f");
  leg1->AddEntry(NHAD2,"NHAD2","f");
  leg1->AddEntry(NHAD3,"NHAD3","f");
  leg1->AddEntry(NHAD4,"NHAD4","f");
  leg1->Draw();
  sprintf(savename,"NHAD_Event%llu.pdf",jentry);
  c1->SaveAs(savename);
  
  
  
  if(nem1y[5] > nem2y[5] && nem1y[5] > nem3y[5] && nem1y[5] > nem4y[5] && nem1y[5] > nem5y[5]) NEM1->SetMaximum(nem1y[5]*1.1);
  if(nem2y[5] > nem1y[5] && nem2y[5] > nem3y[5] && nem2y[5] > nem4y[5] && nem2y[5] > nem5y[5]) NEM1->SetMaximum(nem2y[5]*1.1);
  if(nem3y[5] > nem1y[5] && nem3y[5] > nem2y[5] && nem3y[5] > nem4y[5] && nem3y[5] > nem5y[5]) NEM1->SetMaximum(nem3y[5]*1.1);
  if(nem4y[5] > nem1y[5] && nem4y[5] > nem3y[5] && nem4y[5] > nem2y[5] && nem4y[5] > nem5y[5]) NEM1->SetMaximum(nem4y[5]*1.1);
  if(nem5y[5] > nem1y[5] && nem5y[5] > nem3y[5] && nem5y[5] > nem4y[5] && nem5y[5] > nem2y[5]) NEM1->SetMaximum(nem5y[5]*1.1);
  
  largest = 0;
  for(int iTS = 0; iTS < 10; iTS++){
  	if(nem1y[iTS] > largest) largest = nem1y[iTS];
  	if(nem2y[iTS] > largest) largest = nem2y[iTS];
  	if(nem3y[iTS] > largest) largest = nem3y[iTS];
  	if(nem4y[iTS] > largest) largest = nem4y[iTS];
  	if(nem5y[iTS] > largest) largest = nem5y[iTS];
  }
  
  NEM1->SetMaximum(largest*1.1);  
  
  c1 = new TCanvas("c1","NEM Signal in different time slices",300,10,700,500);
  c1->SetLeftMargin(0.15);
  NEM1->SetFillColor(1);
  NEM1->GetXaxis()->SetRangeUser(-0.3,9.5);
  NEM1->GetYaxis()->SetTitleOffset(1.75);
  NEM1->GetYaxis()->CenterTitle();
  NEM1->Draw("a2");
  NEM2->SetFillColor(2);
  NEM2->Draw("2same");
  NEM3->SetFillColor(3);
  NEM3->Draw("2same");
  NEM4->SetFillColor(4);
  NEM4->Draw("2same");
  NEM5->SetFillColor(6);
  NEM5->Draw("2same");
  leg1 = new TLegend(0.175,0.675,0.35,0.875);
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->AddEntry(NEM1,"NEM1","f");
  leg1->AddEntry(NEM2,"NEM2","f");
  leg1->AddEntry(NEM3,"NEM3","f");
  leg1->AddEntry(NEM4,"NEM4","f");
  leg1->AddEntry(NEM5,"NEM5","f");
  leg1->Draw();
  sprintf(savename,"NEM_Event%llu.pdf",jentry);
  c1->SaveAs(savename);
  
  largest = 0;
  for(int iTS = 0; iTS < 10; iTS++){
  	if(pem1y[iTS] > largest) largest = pem1y[iTS];
  	if(pem2y[iTS] > largest) largest = pem2y[iTS];
  	if(pem3y[iTS] > largest) largest = pem3y[iTS];
  	if(pem4y[iTS] > largest) largest = pem4y[iTS];
  	if(pem5y[iTS] > largest) largest = pem5y[iTS];
  }
  
  PEM1->SetMaximum(largest*1.1); 

  c1 = new TCanvas("c1","PEM Signal in different time slices",300,10,700,500);
  c1->SetLeftMargin(0.15);
  PEM1->SetFillColor(1);
  PEM1->GetXaxis()->SetRangeUser(-0.3,9.5);
  PEM1->GetYaxis()->SetTitleOffset(1.75);
  PEM1->GetYaxis()->CenterTitle();
  PEM1->Draw("a2");
  PEM2->SetFillColor(2);
  PEM2->Draw("2same");
  PEM3->SetFillColor(3);
  PEM3->Draw("2same");
  PEM4->SetFillColor(4);
  PEM4->Draw("2same");
  PEM5->SetFillColor(6);
  PEM5->Draw("2same");
  leg1 = new TLegend(0.175,0.675,0.35,0.875);
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->AddEntry(PEM1,"PEM1","f");
  leg1->AddEntry(PEM2,"PEM2","f");
  leg1->AddEntry(PEM3,"PEM3","f");
  leg1->AddEntry(PEM4,"PEM4","f");
  leg1->AddEntry(PEM5,"PEM5","f");
  leg1->Draw();
  sprintf(savename,"PEM_Event%llu.pdf",jentry);
  c1->SaveAs(savename);
  

}
