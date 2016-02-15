#!/bin/sh

while IFS='' read -r line || [ -n "$line" ]; do
runNumber=$line
#runNumber=263005
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

#command='lcg-cp -b -D srmv2 'srm://se1.accre.vanderbilt.edu:6288/srm/v2/server?SFN=${nextfolder}/0000/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root'' #save="/afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root"

#next="$command $save"
#$next

#command="lcg-cp -b -D srmv2 'srm://se1.accre.vanderbilt.edu:6288/srm/v2/server?SFN=${xrootd}/0000/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root' /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root"
command="xrdcp root://cmsxrootd.fnal.gov/${xrootd}/0000/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/"
echo $command
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

echo "All files for ${runNumber} finished copying. Now merging."

#mv /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_1.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root

#echo "First rootfile has been renamed. Merging beginning."

haddlscommand=`ls -1x /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_* | tr '\n' ' '`
haddmergecommand="hadd /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root ${haddlscommand}"
$haddmergecommand

if [ 1 -eq 0 ]; then
n=2
while [ $n -le $rootlines ]; do
hadd /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_holder.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root
mv /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_holder.root /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}.root 
rm /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_${n}.root
(( n++ ))
done
fi

echo "Finished merging all root files for run ${runNumber}."

#if [ 1 -eq 0 ]; then
#n=2
#while [ $n -le $rootlines ]; do
rm /afs/cern.ch/work/c/cferraio/public/2015ZDCTreeHolder/PbPb2015_PromptReco_MinBias2_${runNumber}_*
#(( n++ ))
#done
#fi

echo "Deleted unmerged files for run ${runNumber}"

done < "filelist.txt"