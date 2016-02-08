#!/bin/sh

while IFS='' read -r line || [ -n "$line" ]; do
runNumber=$line
command='lcg-ls -b -D srmv2 'srm://se1.accre.vanderbilt.edu:6288/srm/v2/server?SFN=/lio/lfs/cms/store/user/cferraio/HIMinimumBias2/crab_PbPb2015_PromptReco_MinBias2_${runNumber}/''
#  $command
$command > commandholder.txt
nextfolder=`cat commandholder.txt`
nextcommand='lcg-ls -b -D srmv2 'srm://se1.accre.vanderbilt.edu:6288/srm/v2/server?SFN=${nextfolder}/0000''
$nextcommand > rootfileholder.txt
totallines=`wc -l < rootfileholder.txt`
rootlines=`expr $totallines - 1`

echo "There are ${rootlines} files for run number ${runNumber}"

prefix="/lio/lfs/cms"
xrootd=${nextfolder#$prefix}

#if [ 1 -eq 0 ]; then
n=1
while [ $n -le $rootlines ]; do
echo "File ${n} started copying"
command="xrdcp root://xrootd-cms.infn.it/${xrootd}/0000/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/"
output=$($command)
while [ "$(echo $output | grep 'ERROR')" ]; do
   echo "Rerunning ${runNumber}_${n}"
   output=$($command)
done

echo $command >> rootcommands.txt
echo "File ${n} finished copying"
(( n++ ))
done
#fi

#if [ 1 -eq 0 ]; then
rm rootcommands.txt

echo "All files for ${runNumber} finished copying"

mv /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_1.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root

echo "First rootfile has been renamed. Merging beginning."

n=2
while [ $n -le $rootlines ]; do
hadd /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_holder.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root
mv /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_holder.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root 
rm /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root
(( n++ ))
done

echo "Finished merging all root files for run ${runNumber}."

n=2
while [ $n -le $rootlines ]; do
rm /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root
(( n++ ))
done
#fi

done < "filelist.txt"