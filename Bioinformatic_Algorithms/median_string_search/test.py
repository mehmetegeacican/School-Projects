from medianString import *
from timeit import default_timer as timer

#THIS PROGRAM TESTS THE MedianStringMotifSearch METHOD TO FIND THE K-MER PATTERN
#The timer is set in order to start the time calculations

startTime = timer()
dnasequence = []
file1 = open('input0.txt', 'r')
outputfile1 = open('output0.txt','w')
file2 = open('input1.txt', 'r')
outputfile2 = open('output1.txt','w')
file3 = open('input2.txt', 'r')
outputfile3 = open('output2.txt','w')


#PRINTING AN WRITING THE K-MER TO OUTPUT0.TXT
DNASTRING = file1.readlines()
k = int(DNASTRING[0])
print("THE MEDIAN STRING FOR OUTPUT FILE 1")
print(MedianStringMotifSearch(DNASTRING,k))
kmer = MedianStringMotifSearch(DNASTRING,k)
outputfile1.write(kmer)

#PRINTING AN WRITING THE K-MER TO OUTPUT1.txt
DNASTRING = file2.readlines()
k = int(DNASTRING[0])
print("THE MEDIAN STRING FOR OUTPUT FILE 2")
print(MedianStringMotifSearch(DNASTRING,k))

kmer = MedianStringMotifSearch(DNASTRING,k)
outputfile2.write(kmer)

#PRINTING AN WRITING THE K-MER TO OUTPUT1.txt
#DNASTRING = file3.readlines()
#k = int(DNASTRING[0])
#print("THE MEDIAN STRING FOR OUTPUT FILE 3 \n",MedianStringMotifSearch(DNASTRING,k))
#kmer = MedianStringMotifSearch(DNASTRING,k)
#outputfile3.write(kmer)

#PRINTING AND WRITING THE K-MER BY USING A RANDOMLY GENERATED DNA

endTime = timer()

print("The Amount of time the process took:",endTime-startTime)
