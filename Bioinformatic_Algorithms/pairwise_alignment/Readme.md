To run the program:<hr/>

Step 1: Enter the file directory in cmd (cd Desktop-->cd pairwise_alignment)

Step (Optional): Add your .fasta,.aln files to the file directory(The default .fasta,.aln files are already in the directory)
Step 2: type python pairwise_aln.py --fasta <> --aln <> --gap [] --match [] --mismatch []
(The [] indicates the optional integers that can be put there)
(The <> indicates the optional files that can be put there)

Step 3(Optional):You can use make command in linux which will automatically execute the following
python pairwise_aln.py --fasta seq.fasta --aln seq_2.fasta --gap -1 --match 2 --mismatch -1 <hr/>

The program takes 2 sequences and uses the Needleman_Wunsch algorithm to align both of them.
**Naive implementation of the Needleman_Wunsch has been utilized**
