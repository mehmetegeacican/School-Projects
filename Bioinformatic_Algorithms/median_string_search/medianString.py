import itertools

#def HDcalc(dnastr1,dnastr2):


def totalDistance(v, DNA):
    totalDist = 0
    k = len(v)
    for seq in DNA:
        minHammingDist = k
        for s in range(len(seq)-k+1):
            HammingDist =  sum([1 for i in range(k) if v[i] != seq[s+i]])

            if (HammingDist < minHammingDist):
                minHammingDist = HammingDist
                
        totalDist += minHammingDist

    return totalDist




def MedianStringMotifSearch(DNA,k):
    
    bestDistance = k*len(DNA)
    bestWord = ''
    for pattern in itertools.product('ACTG', repeat=k):
        motif = ''.join(pattern)
        dist = totalDistance(motif, DNA)
        if (dist < bestDistance):
            bestDistance = dist
            bestWord = motif

    return bestWord


