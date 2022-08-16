
The following describes how the compiling process work <br/>
Note: Sample screenshots have been used on hw1Guidelines.pdf file in order to demonstrate how I have worked the program. If you encounter with any problems, the photos in the report would be helpful <hr/>
STEP1: Please go to the directory where the source code(main.py) is located

STEP2: Add the desired text file that contains a specific motif length and a pattern to the directory.(Note: input0.txt,input1.txt,input2.txt that were given are already in there)

STEP3: After, in the terminal, go to directory where main.py and the input files are located

STEP4: type 'make'

STEP5: Since there is no build stage in python, the codes test.py and main.py automatically runs. test.py just tests the search method with the input files that are already contained(input0.txt,input1.txt) prints the outputs and puts the outputs into specific outputfiles(output0.txt,output1.txt,output2.txt).

STEP6: The main.py runs with the command: python main.py input0.txt input1.txt output0.txt. Makefile makes the main.py read only input0.txt and input1.txt however you can manipulate which file you want the code to read and how many files you want code to read by writing the following:
python main.py <desiredinputfile.txt> <desiredinput2.txt> ...<desiredinputn.txt> <desiredoutputfile.txt>
Example: python main.py example1.txt example2.txt exampleOUt.txt (Output file should be the last one).

STEP7: For desired text file motif trial please type(Make sure that the text file(s) that wants to be tested is in the same directory with main.py):
python main.py <desiredtextfile1.txt> <desiredtextfile2.txt>...<desiredtextfilen.txt> <outputfile.txt> <hr/>

For a better explanation, please look at the hw1Guidelines.pdf file
<br/>
You can also alter the Makefile file to decide which input files main.py should take automatically after you type 'make'. 

IMPORTANT!!!: When the algorithm encounters with a motif length that is higher than 7. The run time of the code significantly increases. While the pdf file contains the outputs of the files input0.txt(3),input1.txt(6),input2.txt(9). The calculation time of the output of input2.txt is significantly high. <br/>
IMPORTANT!!!: 'make' command will work only in linux due to Windows shell not recognizing the make command.(Has to be downloaded) <br/>
IMPORTANT!!!: The commands that you can use are: <br/>
'make' -> To see the default outputs <br/>
python main.py <desiredinput1.txt>...<desiredoutput.txt> (You can use this command as well if you are using windows shell or want to make your own k-mer tests) 





