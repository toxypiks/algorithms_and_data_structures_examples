### Knuth-Morris-Pratt string searching algorithm

String searching algorithms search for occurences in a word by matching each character to one another until a missmatch takes place.

Naive string searching shifts the pattern by only one character after a mismatch occured. This leads to a lot of double checking.

The Knuth-Morris-Pratt algorithm uses information about the pattern to the algorithm how many characters can be skipped after a mismatch which is more efficient.

First, the pattern needs to get analyzed for similar prefixes and sufficex.

This leads to a look-up array that is used in the main algorithm to calculate the jump while searching in a text.
