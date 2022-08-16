import sys
from medianString import *
from timeit import default_timer as timer

startTime = timer()
x = range(1,len(sys.argv)-1)

outputfileName = str(sys.argv[len(sys.argv)-1])
outfile = open(outputfileName,'w')
for n in x:
    print(n)
    fileName = str(sys.argv[n])
    file1 = open(fileName,'r')
    DNASTRING = file1.readlines()
    k = int(DNASTRING[0])
    kmer = MedianStringMotifSearch(DNASTRING,k)
    print("The k-mer is:")
    print(kmer)
    outfile.write(kmer +'\n')
endTime = timer()
print("The time that the process took was:")
print(endTime-startTime)


