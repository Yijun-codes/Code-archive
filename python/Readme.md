### Archive of source codes in Python.
There are two ready-to-use Python pipelines to analyze genomic sequencing and transcriptomic sequencing data.
+ ```DNA_sequence_comparator.py```
  1. Read two input files and check if they are DNA sequence files.
  2. For the verified DNA sequences, it preprocesses them to filter too-short sequences and remove gaps or inaccessible segments (the letter 'N' or 'n' in the sequences).
  3. Plot the percentage of each nucleotide in each sequence, and make a comparison of the histograms between these two sequences.
+ ```DNA_RNA_sequence_comparator.py```:
  1. Read two input files and check if the first one is a DNA sequence and the second one is an RNA sequence.
  2. For the verified sequences, it preprocesses them to filter too-short sequences and remove gaps or inaccessible segments (the letter 'N' or 'n') in the DNA sequence.
  3. Show the longest common subsequence between the input sequences, which is useful to judge if the RNA sequence is transcripted from the DNA sequence.

Should you have any questions, please contact [Yijun Liao](yijun8909@gmail.com)
