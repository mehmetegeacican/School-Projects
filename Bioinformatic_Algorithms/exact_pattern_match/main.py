from exact_pattern_algos import *
from prime import *
import random
import argparse
import sys


#THE PARSER
parser = argparse.ArgumentParser()

#GETTING ARGUMENT 
parser.add_argument("-i",metavar='T',type=argparse.FileType())

args = parser.parse_args(["-i", sys.argv[2]])

txt= args.i.readlines()

#Converting the dna sequence into a simple string
dnaseq = ''
for j in range(0,len(txt[1])-1):
    dnaseq += str(txt[1][j])
#print(dnaseq)
#GETTING ARGUMENT -p
parser.add_argument("-p", type=argparse.FileType())

#You can choose which ever helper
#parser.print_usage()

args = parser.parse_args(["-p", sys.argv[4]])
pat= args.p.readlines()
#PATTERN HAS BEEN IDENTIFIED
patseq = ''
for k in range(0,len(pat[1])-1):
    patseq += str(pat[1][k])
#string = "TAAGTCTATACCATCGTAGTCTAATTAACGTTATGGTAGGATATCAAGGACGGAATGACCGCAGAGGCGACGTTAATGCGCCGTCAGAGACGCCCTAAAGATTGCGGTAGGGTCCCGTTGTTAAAGAGACTTGAGTGGGTGCTTGATGGGAGTGTATTAAGGGCATGTATAAGTGTTGCTGGGTCTAAGGCATTAAAGCTGAGTCAATAGTTACATTGCAGATTAACGAGATCTGAAATTAAGGGAGAGATTCCCAGAGTGGCCTAGTACTTAAGGGCACCCACGCCGCAGGCGGCCCTACGCCCGTTAATGGTTCGAGTGCTATTCACTAACACATTAACGGACGTTTAGTGTGGATTATAGGTGAAGGGTCTGCGCCACTCCAAGGCAGGGAACATATGTGTTGTTACTATCTTAACG"
#pat = "TGGGTCTAAGGCATTAAAGCTGAGTCAATAGT"

#The algorithms
primeThr = len(patseq)
while isPrime(primeThr) == False:
    primeThr = random.randint(len(patseq),101)





i1,t1 = BruteForce(patseq,dnaseq)
i2,t2 = KMPAlgorithm(patseq,dnaseq)
i3,t3 = RKAlgorithm(patseq,dnaseq,primeThr)
print("The prime number q was (For RK): ",primeThr)
#PRINTING THE BEST ONE
timelist = [t1,t2,t3]
minimum = min(timelist)
#print(minimum)
if minimum == t1:
    print("Best algorithm was Brute Force")
elif minimum == t2:
    print("Best algorithm was Knuth-Morris-Pratt")
else:
    print("Best algorithm was RK")



