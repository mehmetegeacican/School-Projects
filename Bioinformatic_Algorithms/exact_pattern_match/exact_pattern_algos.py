#THIS FILE CONTAINS THE ALGORITHMS
from timeit import default_timer as timer
#******************BRUTE FORCE ALGORITHM**********************************
def BruteForce(p,t):

    print("***********Brute Force*************")
    current = 0 #represents the index that is currently looked on in the txt
    n = len(t)
    m = len(p)
    i = 0 #represents index in pattern, j takes the place of i in the pseudo-code
    j =0
    comparison = 0

    startTime = timer()

    while j < n:
        if p[i] == t[j]:
            if i == m-1:
                end = timer()
                totTime = 1000 * (end-startTime)
                print("Given Pattern found in the text in position: ", j-m+2)
                print("Number of comparisons: ", comparison)
                print("The amount of time that it took: ", totTime)
                return j-m+2,totTime
            else:
                i = i + 1
                j = j + 1
                comparison += 1
        else:
            i = 0
            current = current + 1
            j = current
        comparison = comparison +1

    end = timer()
    totTime = 1000 * (end-startTime)
    print("Given pattern is not in text")
    print("Number of comparisons: ", comparison)
    print("The amount of time that it took: ", totTime)
    return -1,totTime
#************* END OF THE BRUTE FORCE ALGORITHM***************************

#****************START OF THE KMP ALGORTIHM**********************************
#**********************FAILURE FUNCTION*********************************
def failureFunction(P):
    f = [0]
    i = 1
    j = 0
    m = len(P)
    while i<m:
        if P[i] == P[j]:
            f.insert(i,j+1)
            i = i+1
            j = j+1
        elif j>0:
            j = f[j-1]
        else:
            f.insert(i, 0)
            i = i+1
    return f
#*******************END OF FAILURE FUNCTION*************************************
#*******START OF KMP SEARCH FUNCTION**********************************
def KMPAlgorithm(pat, txt):
    print("***********KMP*************")
    M = len(pat)
    N = len(txt)
    comparison = 0

    startTime = timer()
    F = failureFunction(pat)

    j = 0 # index for pat[]


    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1

        if j == M:
            comparison = comparison + j - 1
            end = timer()
            totTime = 1000 * (end-startTime)
            print ("Found pattern at index " + str(i-j + 1))
            print("Number of comparisons: ", comparison)
            print("The amount of time that it took: ", totTime)
            j = F[j-1]
            return i-j,totTime

        # mismatch after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = F[j-1]
                comparison = comparison + j -1
            else:
                i += 1
                comparison += 1

        comparison += 1

    end = timer()
    totTime = 1000 * (end-startTime)

    print("Given pattern is not in text")
    print("Number of comparisons: ", comparison)
    print("The amount of time that it took: ", totTime)
    return -1,totTime # No match has been found
#******************END OF KMPSearch FUNCTION**************************
#*************START OF RABIN KARP ALGORITHM*******************
# Rabin-Karp algorithm in python
# d is the number of characters in the input alphabet
d = 4 # The base has been taken as 4 since there are 4 letters in the pattern

def RKAlgorithm(pat, txt, q):
    print("***********RK*************")
    M = len(pat)
    N = len(txt)
    i = 0
    j = 0
    fp = 0
    ft = 0
    h = 1
    comp = 0

    startTime = timer()

    for i in range(M-1):
        h = (h*d)%q


    for i in range(M):
        fp = (d*fp + ord(pat[i]))%q
        ft = (d*ft + ord(txt[i]))%q



    for i in range(N-M+1):

        if fp==ft:#check if the hashed functions are equal
            for j in range(M):#check deeper, if the pattern matches
                if txt[i+j] == pat[j]:
                    j+=1
                else:
                    break
            comp += M
            # if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if j==M:
                end = timer()
                totTime = 1000 * (end-startTime)
                print("Pattern found at index " + str(i + 1))
                print("Number of comparisons: ", comp)
                print("The amount of time that it took: ", totTime)

                return i + 1,totTime

        #pattern is not EXACTLY matched with text portion.
        if i < N-M:
            comp += 1
            ft = (d*(ft-ord(txt[i])*h) + ord(txt[i+M]))%q

            # We might get negative values of t, converting it to
            # positive
            if ft < 0:
                ft = ft+q

    end = timer()
    totTime = 1000 * (end-startTime)
    print("Given pattern is not in text")
    print("The amount of time that it took: ", totTime)
    return -1,totTime
#*****END OF RKSearch Function ********************************
#*********************END OF RK ALGORITHM*************************

txt = "TAAGTCTATACCATCGTAGTCTAATTAACGTTATGGTAGGATATCAAGGACGGAATGACCGCAGAGGCGACGTTAATGCGCCGTCAGAGACGCCCTAAAGATTGCGGTAGGGTCCCGTTGTTAAAGAGACTTGAGTGGGTGCTTGATGGGAGTGTATTAAGGGCATGTATAAGTGTTGCTGGGTCTAAGGCATTAAAGCTGAGTCAATAGTTACATTGCAGATTAACGAGATCTGAAATTAAGGGAGAGATTCCCAGAGTGGCCTAGTACTTAAGGGCACCCACGCCGCAGGCGGCCCTACGCCCGTTAATGGTTCGAGTGCTATTCACTAACACATTAACGGACGTTTAGTGTGGATTATAGGTGAAGGGTCTGCGCCACTCCAAGGCAGGGAACATATGTGTTGTTACTATCTTAACG"
pat = "TGGGTCTAAGGCATTAAAGCTGAGTCAATAGT"

