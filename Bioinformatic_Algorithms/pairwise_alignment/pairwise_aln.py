from needleman_wunsch import *
import argparse
import collections
import sys

#**********************PARSING******************************************************
parser = argparse.ArgumentParser()
#********GETTING THE ARGUMENTS********************************
parser.add_argument("--fasta",metavar='T',type=argparse.FileType())
parser.add_argument("--aln",metavar='T',type=argparse.FileType())
parser.add_argument("--gap",metavar='N',type = int)
parser.add_argument("--match",metavar='N',type=int)
parser.add_argument("--mismatch",metavar='N',type = int)
#*******GETTING THE ARGUMENTS*********************************
#GETTING THE SEQUENCE 1
sequence_1 = parser.parse_args(["--fasta", sys.argv[2]])
#GETTING THE SEQUENCE 2
sequence_2 = parser.parse_args(["--aln",sys.argv[4]])
#GETTING MATCH,MISMATCH AND GAP SCORES
gap = int(sys.argv[6])
match = int(sys.argv[8])
mismatch = int(sys.argv[10])
#******GETTING THE ARGUMENTS**********************************
#READING THE SEQUENCES
txt= sequence_1.fasta.readlines()
txt_2 = sequence_2.aln.readlines()
#PUTTING THE SEQUENCE INTO A VARIABLE
seq_1 = str(txt[1])
seq_2 = str(txt_2[1])
#****PRINTING THE ALIGNMENT(GLOBAL NEEDLEMAN WUNSCH)
al1 =""
al2 =""
maximum = -8
#*****************PRINTING THE SEQUENCES*******************************
matrix,alg1,alg2,score= NeedlemanWunsch(seq_1,seq_2,match,mismatch,gap)
print("sequence_1:",alg1)
print("sequence_2:",alg2)
