# Sequence_Alignment

## Warning
**This is a sample code, includes the hint of basic sequencing index constructing method, it does not includes any data about DNA sequence**

## Description
**This program is to find the starting position of matching DNA sequence and 
    the ending position of matching DNA sequence in the reference DNA sequence.**

### Steps need to implement:

- Implement an first and secondary hash table to store the starting
          position of each 20bp Kmer in the reference list, the data is read
          from the input file. 

- Read the character from the NGS file and find the match key in the 
          table, store the starting position of reference and starting position
          of NGS to the query. 

- Use the priority queue to store the queries and implement the graph 
          which crafts the starting and ending position of the relative position 
          that mapping from the NGS to the reference. 
          
## Download:

- Download all files, unzip them, and place into same directory. 

 ## Configure:
 
 ***
 - This program support FASTA format, so you can download any reference DNA dataset and aligned dataset from national database or biomedical database. Search RAS, and you should get correspond database. 
- Replace the variable "originFile" in the main.cpp with your referencial database.
- Replace rest of file name with your preference: these are output files that store the referencial table. In rest two files: output stores the referencial database after randomization comtaminated or unmeasured DNA sequence; NGS_1 stores those unmatched sequence that need further aligned. 
- Firstly, run the main.cpp, then you got those unmatched sequence that will furhter aligned use global alignment. Matching time might process about a hour. 
- Secondly, run the NW_alorithm.cpp, then you got those aligned penalty score of those unmatched sequence. Alignment time might process a few hours. 
***

## Requirements:

- It is better to run this tool on Mac, preferable a M1 chip Mac. Make sure you have at least 32GB RAM memory on a Intel based Mac, and at least 16GB RAM memory on a M1 chip based Mac. 
- It is better to use Xcode to run this tool. 

## Normal Output

**Usually, the normal output should gives the query groups seperately and sequencially
    It should be printed out the relatively starting position and relatively ending
    position on the referencial list.**

## Abnormal Output

**The both position on above is out of the legal range of the referential list**
    

## Testing
    
- Threshold in the checkSameGroup in the Query class can be changed into any
    legal value. The testing result might seems different as long as the threshold
    changing.
    
- The find match process is strictly follows the search all policy. The result 
    might seems different to the referential result. Loops time can be furtherly
    optimized in the referentialPositionGraph class.
    
- Testing process used small groups of reference data and matching data. The 
    program seems to work in such testing.

## Attention

**In the FileIO object, there exists a parameter named target with type integer, 
    which might be removed later. Several details list below:**
    
- If the target is set to 1, then it create the two chain hashtable from
          a file, which created from a input file. The input file removes all 
          invalid character ('N' and the '\n'). But this way is time consuming. 
          The optimized method might be released later. 
          
        




