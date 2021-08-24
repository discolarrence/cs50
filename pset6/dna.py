from cs50 import get_string
import sys
import csv


# given both a DNA sequence and an STR as inputs, returns the maximum number of times that the STR repeats.
def max_str_repeats(dna_seq, str_seq):
    repeats = 0
    max_repeats = 0
    dna_length = len(dna_seq)
    str_length = len(str_seq)
    for i in range(0, dna_length):
        if dna_seq[i: i + str_length] == str_seq:
            j = 0
            while dna_seq[i + j: i + j + str_length] == str_seq:
                repeats += 1
                j += str_length
        if repeats > max_repeats:
            max_repeats = repeats
        else:
            repeats = 0
    return max_repeats


# error if wrong number of arguments 
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    
# open csv read into memory-1st row column names,1st column "name", next STR seq
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    people_counts = list(reader)

str_sequences = []
for i in range(1, len(reader.fieldnames)):
    str_sequences.append(reader.fieldnames[i])
 
# open txt read contentsinto memory
with open(sys.argv[2]) as f:
    dna_sequence = f.read()
    
# for each STR, find longest run in each sequence
longest_runs = {}
for i in range(len(str_sequences)):
    max_repeats = max_str_repeats(dna_sequence, str_sequences[i])
    longest_runs[str_sequences[i]] = max_repeats


# if any str counts match exactly, print name
# if no match print no match
for people in people_counts:
    matches = 0
    for str_seq in str_sequences:
        if int(people[str_seq]) == int(longest_runs[str_seq]):
            matches += 1
    if matches == len(str_sequences):
        name = people['name']
        break
    name = "No match"
print(name)
