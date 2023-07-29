import numpy as np
import sys
import os

def read_fasta(fname):
#read fasta file
    seq=''
    with open(fname,'r') as f:
        gname = f.readline()[1:]
        lines = f.readlines()
        for line in lines:
            lst = line.strip()
            seq += lst

    seq = seq.upper()

    return gname,seq

def check_DNAseq(seq):
#check if this is really a DNA sequence, which only contains 'A', 'C', 'G', 'T', and 'N' (means gap or inaccessible regions)
    len1 = seq.count('A') + seq.count('C') + seq.count('G') + seq.count('T') + seq.count('N')
    len2 = len(seq)
    return len1==len2

def check_RNAseq(seq):
#check if this is really a RNA sequence
    len1 = seq.count('A') + seq.count('C') + seq.count('G') + seq.count('U')
    len2 = len(seq)
    return len1==len2

def lcs_calc(string1, string2):
#Calculate the longest common subsequence
    answer1 = ""
    answer2 = ""
    len1, len2 = len(string1), len(string2)
    for i in range(len1):
        for j in range(len2):
            lcs_temp=0
            match1=''
            match2=''
            while ((i+lcs_temp < len1) and (j+lcs_temp<len2) and ((string1[i+lcs_temp] == string2[j+lcs_temp]) or ((string1[i+lcs_temp] == 'T') and (string2[j+lcs_temp] == 'U'))) ):
            # treat the 'T' in DNA and the 'U' in RNA the same
                match1 += string1[i+lcs_temp]
                match2 += string2[j+lcs_temp]
                lcs_temp+=1
            if (len(match1) > len(answer1)):
                answer1 = match1
                answer2 = match2
    
    return len(answer1), answer1, answer2


if __name__ == "__main__":
'''
    The first sequence should be DNA, the second one should be RNA
'''
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
    if (not check_DNAseq(seqA)) or (not check_RNAseq(seqB)):
        print('The first file is not DNA sequence file or the second file is not RNA sequence file!')
        sys.exit(-1)

    seqA = seqA.replace('N', '').replace('n','')

    if (len(seqA) < 10):
        print(f'The sequence of {geneA} is too short!')
        sys.exit(-1)
    if (len(seqB) < 10):
        print(f'The sequence of {geneB} is too short!')
        sys.exit(-1)


    lens, lcs1, lcs2 = lcs_calc(seqA,seqB)

    print(f"The longest matching segment is:")
    print(f"\t{lcs1}")
    print(f"\t{lcs2}")
    print(f"It has {lens} base pairs and covers {(lens/len(seqB)*100):.2f} percent of the RNA sequence.")
