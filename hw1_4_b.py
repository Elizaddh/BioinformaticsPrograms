#!/usr/bin/env python
from Bio.Seq import Seq
from Bio.Alphabet import generic_dna
dna_seq = raw_input('type the seq: ')
my_DNA = Seq(dna_seq, generic_dna)

reverseComplement = my_DNA.reverse_complement()
print  "Reverse complement DNA :",  reverseComplement
