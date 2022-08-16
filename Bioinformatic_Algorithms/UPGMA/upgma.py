import numpy as nump
#****RETURNS MATCH OR MISMATCH SCORE BASED ON THE CHARS
def get_match_mismatch(ch1,ch2,match,mismatch):
    if ch1 == ch2:
        return match
    else:
        return mismatch
#***RETURNS MATCH OR MISMATCH SCORE BASED ON THE CHARS
#***MATRIX INITIALIZATIONS*********************************
def matrix_s(seq1,seq2,gapOpen,gapExt):
    row = len(seq1)+1
    col = len(seq2)+1
    OPT_s = [[0 for i in range(col)] for j in range(row)]
    OPT_s[0][0] = -10000
    for j in range(1,col):
        OPT_s[0][j] = gapOpen+j*gapExt
    return OPT_s

def matrix_e(seq1,seq2,gapOpen,gapExt):
    row = len(seq1)+1
    col = len(seq2)+1
    OPT_e = [[0 for i in range(col)] for j in range(row)]
    OPT_e[0][0] = -10000
    for i in range(1,row):
        OPT_e[i][0] = gapOpen+i*gapExt
    return OPT_e

def matrix_d(seq1,seq2,gapOpen,gapExt):
    row = len(seq1)+1
    col = len(seq2)+1
    OPT_d = [[0 for i in range(col)] for j in range(row)]
    OPT_d[0][0] = -10000
    return OPT_d

def matrix_in(seq1,seq2,gapOpen,gapExt):
    row = len(seq1)+1
    col = len(seq2)+1
    OPT = [[0 for i in range(col)] for j in range(row)]
    OPT[0][0] = 0
    for i in range(1,row):
        OPT[i][0] = gapOpen+i*gapExt
    for j in range(1,col):
        OPT[0][j] = gapOpen+j*gapExt
    return OPT
#****MATRIX INITIALIZATIONS*******************
#*****NEEDLEMAN-WUNSCH ALGORITHM******
#*****BACKTRACING PART FROM HW5*******
def back_trace(OPT, s1,s2, gapOpen, gapExt,match,mismatch):

    aligned_1 = ""
    aligned_2 = ""
    is_match = 0
    distance = 0
    ti = len(s1)
    tj = len(s2)

    while ti > 0 and tj > 0:
        #INSTEAD OF HOLDING A CHECK MATRIX, A SIMPLE IF STATEMENT HAS BEEN USED
        if s1[ti-1] == s2[tj-1]:
            is_match = match
        else:
            is_match = mismatch
            distance = distance + 1

        if(ti > 0 and tj > 0 and  OPT[ti][tj] == OPT[ti-1][tj-1] + is_match):
            aligned_1 = s1[ti-1] + aligned_1
            aligned_2 = s2[tj-1] + aligned_2
            ti = ti - 1
            tj = tj - 1

        elif (ti >0 and tj > 0) and (OPT[ti][tj] == OPT[ti][tj-1] + gapExt) or (OPT[ti][tj] == OPT[ti][tj-1] + gapOpen+ gapExt):
            aligned_1 = s1[ti] + aligned_1
            aligned_2 = "-" + aligned_2
            distance = distance + 1
            tj = tj - 1
            

        elif (ti > 0 and tj > 0) and (OPT[ti][tj] == OPT[ti-1][tj] + gapExt) or (OPT[ti][tj] == OPT[ti-1][tj] + gapOpen+ gapExt):
            aligned_1 = "-" + aligned_1
            aligned_2 = s2[tj] + aligned_2
            distance = distance + 1
            ti = ti - 1
            
        
    return aligned_1, aligned_2, distance
#***************MATRIX-FILLING*****************************************
def matrix_fill(seq1,seq2,gapOpen, gapExt,match,mismatch):
    row = len(seq1)+1
    col = len(seq2)+1
    e_OPT = matrix_e(seq1, seq2,gapOpen,gapExt)
    s_OPT = matrix_s(seq1, seq2,gapOpen,gapExt)
    d_OPT = matrix_d(seq1, seq2,gapOpen,gapExt)
    OPT = matrix_in(seq1, seq2,gapOpen,gapExt)
    for i in range(1,row):
        for j in range(1,col):
            e_OPT[i][j] = max(0,e_OPT[i][j-1]+gapExt,OPT[i][j-1]+gapOpen+gapExt)
            s_OPT[i][j] = max(0,s_OPT[i-1][j]+gapExt,OPT[i-1][j]+gapOpen+gapExt)
            d_OPT[i][j] = OPT[i-1][j-1]+ get_match_mismatch(seq1[i-1],seq2[j-1],match,mismatch)
            OPT[i][j] = max(0,d_OPT[i][j],e_OPT[i][j],s_OPT[i][j])

    aligned_1,aligned_2,distance = back_trace(OPT, seq1,seq2, gapOpen, gapExt,match,mismatch)
    return distance
#****MATRIX FILLING***************************************************************************
#****UPDATING MATRIX**************************************************************************
def update_matrix(OPT,x,y):
    for i in range(1,x):
        OPT[x][i] = (OPT[x][i]+OPT[y][i])/2
    for i in range(x,len(OPT[0])):
        OPT[i][x] = (OPT[i][x] +OPT[i][y])/2

    #NUMPY USED TO QUICKLY DIVIDE BLOCK BY BLOCK OPT
    OPT = nump.delete(OPT, y, axis = 1)
    OPT = nump.delete(OPT, x, axis = 0)

    return OPT
#***UPDATING MATRIX*****************************************************************************
#***UPGMA ALGORITHM*****************************************************************************
def upgma_algorithm(names,OPT):
    newick = []
    height_list = []
    len_count = len(names)
    copy_names = names

    while len(names) > 1:
        #NUMPY USED TO PREVENT OUT OF RANGE
        x = nump.where(OPT == nump.min(OPT))[0][0]
        y = nump.where(OPT == nump.min(OPT))[1][0]
        height = OPT[x][y]/2
        minimum = min(x,y)
        maximum = max(x,y)
        newick.append( "("+names[minimum]+": "+str(height)+" "+names[maximum]+": "+str(height)+")")
        height_list.append(height)
        OPT = update_matrix(OPT,minimum,maximum)

        new_name = names[minimum]+""+names[maximum]

        names[minimum] = new_name

    
        names = nump.delete(names,maximum)

    if len_count == 3:
        result = ""
        for i in range(0,len(height_list)):
            if i != len(height_list)-1:
                result = result +  str(newick[i])+":"+str(height_list[len(height_list)-1]-height_list[i])+" "+copy_names[len(copy_names)-1]+":"+str(height_list[len(height_list)-1])
    else:
        result = ""
        for i in range(0,len(height_thres)):   
            result = result +  str(newick[i])+":"+str(height_list[len(height_list)-1]-height_list[i])+" "

    return  "(" + result + ")"

#***UPGMA ALGORITHM*******************************************************************************************