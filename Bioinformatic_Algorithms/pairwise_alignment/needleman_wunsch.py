#BASE MATRIX(UNFILLED IS BEONG FORMED)
#*********************MATCH-CHECKER-MATRIX******************************
def matchCheckerMatrix(seq1,seq2):
    length1 = len(seq1)
    length2 = len(seq2)
    OPT = [[0 for i in range(length2)] for j in range(length1)]
    return OPT
#*****************MAIN MATRIX*************************************
def mainMatrix(seq1,seq2):
    length1 = len(seq1)
    length2 = len(seq2)
    OPT = [[0 for i in range(len(seq2) + 1)] for j in range(len(seq1) + 1)]
    return OPT
#***********PRINTING THE MATRIX IF REQUIRED****************************
def printMatrix(OPT):
    for line in OPT:
        print(line)
#*************************MATCH-MISMATCH-GAP****************************
match = 1
mismatch = -1
gap = -2
#*********************FILLING THE CHECKER MATRIX**********************************
def fillChecker(OPT,seq1,seq2,m,mm):
    for i in range(len(seq1)):
        for j in range(len(seq2)):
            if seq1[i] == seq2[j]:
                OPT[i][j] = m
            else:
                OPT[i][j] = mm
    return OPT
#******************NEEDLEMAN-WUNSCH*******************************************************
def NeedlemanWunsch(seq1,seq2,m,mm,g):
    match = m
    mismatch = mm
    gap = g
    #STEP1-INITIALIZATION--THE MAIN ROWS AND COLS
    check = matchCheckerMatrix(seq1,seq2)
    check = fillChecker(check,seq1,seq2,m,mm)
    #printMatrix(check,seq1,seq2)
    OPT = mainMatrix(seq1,seq2)
    for i in range(len(seq1)+1):
        OPT[i][0] = i*g
    for j in range(len(seq2)+1):
        OPT[0][j] = j*g
    #STEP2-FILLING THE REMAINING PARTS
    for i in range(1,len(seq1)+1):
        for j in range(1,len(seq2)+1):
            OPT[i][j] = max(OPT[i-1][j-1] + check[i-1][j-1],
            OPT[i-1][j]+g,
            OPT[i][j-1]+g)
    #GETTING THE SCORE
    score = OPT[len(seq1)][len(seq2)]
    #*****************STEP3--TRACEBACK************************************
    aligned_1 = ""
    aligned_2 = ""
    ti =  len(seq1)
    tj = len(seq2)

    while(ti > 0 and tj > 0):
        if (ti > 0 and tj > 0 and OPT[ti][tj] == OPT[ti-1][tj-1]+check[ti-1][tj-1]):

            aligned_1 = seq1[ti-1]+aligned_1
            aligned_2 = seq2[tj-1]+aligned_2
            ti = ti - 1
            tj = tj - 1

        elif(ti > 0 and tj > 0 and OPT[ti][tj] ==  OPT[ti-1][tj]+gap):
            aligned_1 = seq1[ti-1] + aligned_1
            aligned_2 = "-" + aligned_2
            ti = ti-1
        else:
            aligned_1 = "-" + aligned_1
            aligned_2 = seq2[tj-1] + aligned_2
            tj = tj-1

    return OPT,aligned_1,aligned_2,score
    
#*****MAIN*****
