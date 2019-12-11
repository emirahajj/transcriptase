# transcriptase

DNA, or deoxyribonucleic acid, is the hereditary material in humans and almost all other organisms. It serves as a 
biological blueprint which is unique to every organism. The information in DNA is stored as a "code" made up of 
four chemical bases: adenine (A), guanine (G), cytosine (C), and thymine (T). 

Human DNA consists of about 3 billion bases, and more than 99 percent of those bases are the same in all people. 
The order, or sequence, of these bases determines the information available for building and maintaining an organism, 
similar to the way in which letters of the alphabet appear in a certain order to form words and sentences.

Since DNA is just the "blueprint," there are other processes that need to occur at the microscopic level to convert
the raw data encoded in DNA, into larger protein structures that serve various functions on the cellular level.
```
A DNA strand                   : TTCGCTGGAGCCGGGCGTTACCTAAACGTTATTTCACGGAAGCTT
It's complementary mRNA strand : AAGCGACCUCGGCCCGCAAUGGAUUUGCAAUAAAGUGCCUUCGAA
```
Transcription is the process of creating an mRNA sequence (precursor to amino acid sequence) from a DNA sequence and 
translation is the process of creating an amino acid sequence (precursor to larger proteins) from an mRNA sequence.

As we can see above, when we transcribe from DNA to mRNA:

```
T -> A
A -> U
C -> G
G -> C
```


When DNA is replicated, minor mutations can happen over long periods of time. Two such types of mutations are **deletion** and
**insertion**. Deletion occurs when one or some bases are deleted from the sequence and the insertion occurs when one or more
bases are added to the sequence. 

-------------------

This C++ program performs transcription and translation on DNA sequences and highlights the effect that even just one
insertion or deletion can have on a DNA sequence.

It reads in from the file "frameshift_mutations.txt" where each even line contains a DNA sequence and each odd 
line contains the same DNA sequence with either a deletion or insertion of one base, anywhere in the sequence.

Amino acid sequences are created by reading 3 bases of an mRNA sequence at a time (called codons), so a dictionary file named "codons.tsv" is included to allow for the translation of mRNA to an amino acid sequence. 

Amino acid sequences have dedicated "start" and "stop" codons to flag the start and end of an amino acid chain.
The start codon is "AUG" and there are 3 stop codons: "UAA," "UGA," and "UAG."
