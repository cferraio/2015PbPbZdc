{
   
  TFile f("/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_263005.root");   
  //TTree *CENT = (TTree *) f->Get("BeamTree"); //This is in order to make centrality cups
  TTree *ZDCHI = (TTree *) f.Get("ZDCDigiTree"); //Grabs part of the root file that is called ZDCDigiTree
  Int_t NumberOfEvents = ZDCHI->GetEntries();  //Scans the file and finds the number of events
  //the following adds 2d graph capabilities
  TH2F* histogram_2D = new TH2F("neg-EM vs. Neg-HAD", "neg-EM vs. neg-HAD TS:45_PromptReco_NS", 200, 0, 3000, 200, 0, 18000);
  
  TH1F* histogram_1D = new TH1F("MTotalHAD_TS45_PromptReco_NS", "MTotalHAD_TS45_PromptReco_NS", 200, 100, 6000);
   TH1F* histogram_1DSum = new TH1F("MTotalHAD+pt1TotalEM_TS45_PromptReco_NS", "MTotalHAD+0.1TotalEM_TS45_PromptReco_NS", 200, 100, 6000);
 
  /////////////Get Info From the Leaves/////////////////////////

  //CENTRAL= (TLeaf*)CENT->GetLeaf("CentralityBin"); //Uncomment in order to apply a centrality cut
  NEM4fC= (TLeaf*)ZDCHI->GetLeaf("negHD1cFtsz");//NHAD1
  NEM4ADC= (TLeaf*)ZDCHI->GetLeaf("negHD1ADCtsz");
  NHAD2fC= (TLeaf*)ZDCHI->GetLeaf("negHD2cFtsz");//NHAD2
  NHAD2ADC= (TLeaf*)ZDCHI->GetLeaf("negHD2ADCtsz");
  NHAD3fC= (TLeaf*)ZDCHI->GetLeaf("negHD3cFtsz");//NHAD3
  NHAD3ADC= (TLeaf*)ZDCHI->GetLeaf("negHD3ADCtsz");
  NHAD4fC= (TLeaf*)ZDCHI->GetLeaf("negHD4cFtsz");//NHAD4
  NHAD4ADC= (TLeaf*)ZDCHI->GetLeaf("negHD4ADCtsz");
  NEM1fC= (TLeaf*)ZDCHI->GetLeaf("negEM1cFtsz");//NEM1
  NEM1ADC= (TLeaf*)ZDCHI->GetLeaf("negEM1ADCtsz");
  NEM2fC= (TLeaf*)ZDCHI->GetLeaf("negEM2cFtsz");//NEM2
  NEM2ADC= (TLeaf*)ZDCHI->GetLeaf("negEM2ADCtsz");
  NEM3fC= (TLeaf*)ZDCHI->GetLeaf("negEM3cFtsz");//NEM3
  NEM3ADC= (TLeaf*)ZDCHI->GetLeaf("negEM3ADCtsz");
  NHAD1fC= (TLeaf*)ZDCHI->GetLeaf("negEM4cFtsz");//NEM4
  NHAD1ADC= (TLeaf*)ZDCHI->GetLeaf("negEM4ADCtsz");
  NEM5fC= (TLeaf*)ZDCHI->GetLeaf("negEM5cFtsz");//NEM5
  NEM5ADC= (TLeaf*)ZDCHI->GetLeaf("negEM5ADCtsz");

  // Declaration of leaf types//////////////////////////
  Double_t         negEM1fC[10];
  Double_t         negEM1ADC[10];
  Double_t         negEM2fC[10];
  Double_t         negEM2ADC[10];
  Double_t         negEM3fC[10];
  Double_t         negEM3ADC[10];
  Double_t         negEM4fC[10];
  Double_t         negEM4ADC[10];
  Double_t         negEM5fC[10];
  Double_t         negEM5ADC[10];
  Double_t         negHD1fC[10];
  Double_t         negHD1ADC[10];
  Double_t         negHD2fC[10];
  Double_t         negHD2ADC[10];
  Double_t         negHD3fC[10];
  Double_t         negHD3ADC[10];
  Double_t         negHD4fC[10];
  Double_t         negHD4ADC[10];
  Double_t         centrality[1];

  Double_t HADsum=0;
  Double_t EMsum=0;
  Double_t ETsum=0;
  
  //Double_tHADcal=0;
  //Double_tEMcal=0;

 
 

  for(Int_t i =0;i<NumberOfEvents;i++)
    {
      ZDCHI->GetEntry(i);
      //   CENT->GetEntry(i); //This line grabs the events centrality value

      //centrality[1]=(CENTRAL->GetValue()); //this grabs the value of the centrality and stuffs it in the matrix
      //if(centrality[1]<=39){        //this line makes a decision on whether or not the data fits the centrality decision you make

      //floatEMcal=0;
      //floatHADcal=0;
      float NHAD1TotalSignal=0;
      float NHAD2TotalSignal=0;
      float NHAD3TotalSignal=0;
      float NHAD4TotalSignal=0;
      float NEM1TotalSignal=0;
      float NEM2TotalSignal=0;
      float NEM3TotalSignal=0;
      float NEM4TotalSignal=0;
      float NEM5TotalSignal=0;
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

      }
      //NOISE
      float NEM1TotalNoise=0;
      float NEM2TotalNoise=0;
      float NEM3TotalNoise=0;
      float NEM4TotalNoise=0;
      float NEM5TotalNoise=0;
      float NHAD1TotalNoise=0;
      float NHAD2TotalNoise=0;
      float NHAD3TotalNoise=0;
      float NHAD4TotalNoise=0;

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
 
 
      //No Noise Subtraction
      
      HADsum=(NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal);
      ETsum=(NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal)+(.1*NEM1TotalSignal)+(.1*NEM2TotalSignal)+(.1*NEM3TotalSignal)+(.1*NEM4TotalSignal)+(.1*NEM5TotalSignal);
 
      EMsum=(NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal);



      //Noise Subtraction
      //HADsum=(NHAD1TotalSignal-NHAD1TotalNoise)+(NHAD2TotalSignal-NHAD2TotalNoise)+(NHAD3TotalSignal-NHAD3TotalNoise)+(NHAD4TotalSignal-NHAD4TotalNoise);

      //ETsum=(NHAD1TotalSignal-NHAD1TotalNoise)+(NHAD2TotalSignal-NHAD2TotalNoise)+(NHAD3TotalSignal-NHAD3TotalNoise)+(NHAD4TotalSignal-NHAD4TotalNoise)+(.1)*(NEM1TotalSignal-NEM1TotalNoise)+(.1)*(NEM2TotalSignal-NEM2TotalNoise)+(.1)*(NEM3TotalSignal-NEM3TotalNoise)+(.1)*(NEM4TotalSignal-NEM4TotalNoise)+(.1)*(NEM5TotalSignal-NEM5TotalNoise);

      //EMsum=(NEM1TotalSignal-NEM1TotalNoise)+(NEM2TotalSignal-NEM2TotalNoise)+(NEM3TotalSignal-NEM3TotalNoise)+(NEM4TotalSignal-NEM4TotalNoise)+(NEM5TotalSignal-NEM5TotalNoise);

      histogram_1D->Fill(HADsum);
      histogram_1DSum->Fill(ETsum);

      //HADcal=(.1825)*((NHAD1TotalSignal)+(NHAD2TotalSignal)+(NHAD3TotalSignal)+(NHAD4TotalSignal)+(NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal))

      //EMcal=(.006)*((NEM1TotalSignal)+(NEM2TotalSignal)+(NEM3TotalSignal)+(NEM4TotalSignal)+(NEM5TotalSignal))

    
	 
	  histogram_2D->Fill(HADsum, EMsum);

 
      
    }  
    

 	  c1 = new TCanvas();
      histogram_2D->SetXTitle("SumHAD (fC)");
      histogram_2D->SetYTitle("SumEM (fC)"); 
//      c1->SetPalette(1);
      c1->SetLogz();
      histogram_2D->Draw("colz");
      c1->SaveAs("plots/histo_2dNS.pdf");
      
    c2 = new TCanvas();
    histogram_1D->SetXTitle("SumHad (fC)");
    histogram_1D->SetYTitle("Counts");
    c2->SetLogy();
    histogram_1D->Draw();
    c2->SaveAs("plots/histo_1DNS.pdf");
 
    c3 = new TCanvas();
    histogram_1DSum->SetXTitle(".1*SumEM+SumHad (fC)");
    histogram_1DSum->SetYTitle("Counts");
    c3->SetLogy();
    histogram_1DSum->Draw();    
    c3->SaveAs("plots/histo_1DsumNS.pdf");
}

