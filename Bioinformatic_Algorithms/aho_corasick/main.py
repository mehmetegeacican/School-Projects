from aho_cora import *
import argparse
import sys

#THE CONVERT FUNCTION****************************************
def arrafy(lst): 
    return ([i for item in lst for i in item.split()]) 
#THE ARRAFY FUNCTION************************************** 


#THE PARSER
parser = argparse.ArgumentParser()

#GETTING ARGUMENT 
parser.add_argument("-i",metavar='T',type=argparse.FileType())

args = parser.parse_args(["-i", sys.argv[2]])

txt= args.i.readlines()

#print(txt[2])
#THE ARRAFYING THE INPUT*******************************************
sentence =  txt[0] # THE FIRST LINE IS THE PATTERN
lst = [sentence] 
arrafied = arrafy(lst)
#THE ARRAFYING THE INPUT*************************************************
textseq = ''
for j in range(1,len(txt)):
    textseq = textseq + txt[j] + ''
#print(textseq)
#USING THE AHO_CORASICK AND PRINTING***************************************
init_trie(arrafied)
theIndexes = get_keywords_found(textseq)
print("********************************************************************")
for y in range(0,len(theIndexes)):
    print(theIndexes[y])
#USING THE AHO_CORASICK AND PRINTING***************************************