The following describes how the compiling process work

 
STEP1: Please go to the directory where the source code(main.py) is located

STEP2: Add the desired text file that contains a specific motif length and a pattern to the directory.(Note: input0.txt,input1.txt,input2.txt that were given are already in there)

STEP3: After, in the terminal, go to directory where main.py and the input files are located

STEP4:type: python main.py -i T.fa -p P.fa

If you are using linux, you can also type 'make'
For Linux, when using 'make' command, since there is no build stage in python, the code main.py automatically runs.
The main.py takes the input sequence(T.fa) and input pattern(P.fa), and uses the algorithms in the exact_pattern_algos to find the index number in which the pattern has been first observed, calculates the number of comparisons and the run time of the algorithms.
<hr/>
IMPORTANT!!!: The input sequence shuold be in one line.(See the example T.fa) <br/>
IMPORTANT!!!: 'make' command will work only in linux due to Windows shell not recognizing the make command.(Has to be downloaded)
