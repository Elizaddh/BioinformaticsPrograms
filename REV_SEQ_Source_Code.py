# -*- coding: utf-8 -*-
"""
Created on Tue Oct 31 15:30:57 2017

@author: Eliza

Report Reverse Complement of a DNA Sequence:
"""
#usr/#!/usr/bin/env python

import sys

dna_seq = raw_input ("TYPE YOUR DNA SEQUENCE : ")
DNA_SEQ = dna_seq.upper()

BASES = list(DNA_SEQ)
BASES.reverse()

rev_com = []

for i in range(len(BASES)):
        if BASES[i] not in ["G", "T", "C", "A"]:
            sys.exit("* * ERROR : NOT A DNA")
        
        if BASES[i] == "A":
            rev_com.append("T")
        if BASES[i] == "T":
            rev_com.append("A")
        if BASES[i] == "G":
            rev_com.append("C")
        if BASES[i] == "C":
            rev_com.append("G")
reverse_complement = "".join(rev_com)
print "REVERSE COMPLEMENT DNA :" , reverse_complement            
        
        