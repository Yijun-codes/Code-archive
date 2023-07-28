from matplotlib import pyplot as plt
import sys
import os

def read_fasta(fname):
    seq=''
    with open(fname,'r') as f:
        gname = f.readline()[1:]
        lines = f.readlines()
        for line in lines:
            lst = line.strip()
            seq += lst

    return gname,seq

def check_DNAseq(seq):
    len1 = seq.count('A') + seq.count('C') + seq.count('G') + seq.count('T') + seq.count('a') + seq.count('c') + seq.count('g') + seq.count('t') + seq.count('N') + seq.count('n')
    len2 = len(seq)
    return len1==len2


if __name__ == "__main__":
    fnameA = sys.argv[1]
    fnameB = sys.argv[2]
    if not os.path.isfile(fnameA):
        print(f'{fnameA} does not exist!')
        sys.exit(-1)
    if not os.path.isfile(fnameB):
        print(f'{fnameB} does not exist!')
        sys.exit(-1)

    geneA, seqA = read_fasta(fnameA)
    geneB, seqB = read_fasta(fnameB)
    if (not check_DNAseq(seqA)) or (not check_DNAseq(seqB)):
        print('At least one file is not DNA sequence file!')
        sys.exit(-1)

    seqA = seqA.replace('N', '').replace('n','')
    seqB = seqB.replace('N', '').replace('n','')

    if (len(seqA) < 10):
        print(f'The sequence of {geneA} is too short!')
        sys.exit(-1)
    if (len(seqB) < 10):
        print(f'The sequence of {geneB} is too short!')
        sys.exit(-1)

    cA1 = (seqA.count('A')+seqA.count('a'))/len(seqA)
    cC1 = (seqA.count('C')+seqA.count('c'))/len(seqA)
    cG1 = (seqA.count('G')+seqA.count('g'))/len(seqA)
    cT1 = (seqA.count('T')+seqA.count('t'))/len(seqA)


    cA2 = (seqB.count('A')+seqB.count('a'))/len(seqB)
    cC2 = (seqB.count('C')+seqB.count('c'))/len(seqB)
    cG2 = (seqB.count('G')+seqB.count('g'))/len(seqB)
    cT2 = (seqB.count('T')+seqB.count('t'))/len(seqB)

    plt.bar([1,4,7,10],[cA1,cC1,cG1,cT1],color='blue')
    plt.bar([2,5,8,11],[cA2,cC2,cG2,cT2],color='red')
    plt.xticks([1.5,4.5,7.5,10.5],['A','C','G','T'])
    plt.ylabel('Percentage of nucleotides')
    plt.legend([geneA,geneB])
    plt.show()
