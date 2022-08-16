from upgma import *
import argparse
import sys

#*********************ARGPARSE********************************************
parser = argparse.ArgumentParser()

parser.add_argument("--fasta",metavar='T',type=argparse.FileType())
parser.add_argument("--match",metavar='N',type=int)
parser.add_argument("--mismatch",metavar='N',type = int)
parser.add_argument("--gapopen",metavar='N',type = int)
parser.add_argument("--gapext",metavar='N',type = int)
parser.add_argument("--out",metavar='T',type=argparse.FileType())

fasta_file = parser.parse_args(["--fasta", sys.argv[2]])
#STORING THE INPUTS
match = int(sys.argv[4])
mismatch = int(sys.argv[6])
gapOp = int(sys.argv[8])
gapExt = int(sys.argv[10])
#GETTING THE OUTPUT FILE
outputfileName = str(sys.argv[12])
outfile = open(outputfileName,'w')
#READING FILE AND GETTING THE CHARACTERS AND NUMBERS
file_lines = fasta_file.fasta.readlines()
sequences = []
names = []
for line in file_lines:
    if line[0] =='>':
        line = line.replace(">","")
        names.append(line.replace("\n",""))
    elif line[0] != '>':
        line = line.replace("\n","")
        sequences.append(line)
#GETTING THE SYSTEM VALUES

opt =  [[9999999999 for i in range(len(names))] for j in range(len(names))]
no_of_elmts = 0
for i in range(1,len(names)):
    for j in range(0,i):
        opt[i][j]= matrix_fill(sequences[i],sequences[j],gapOp, gapExt,match,mismatch)
        no_of_elmts +=1
newick_output = ""
newick_output = upgma_algorithm(names,opt)
print(newick_output)
outfile.write(newick_output + '\n')
