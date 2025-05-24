### Knuth-Morris-Pratt string searching algorithm

String searching algorithms search for occurences in a word by matching each character to one another until a missmatch takes place.

Naive string searching shifts the pattern by only one character after a mismatch occured. This leads to a lot of double checking and an O(n*m) runtime at worse.

The Knuth-Morris-Pratt algorithm uses information about the pattern (self-repeating characters at the begining and the end of the word) to tell the algorithm how many characters can be skipped after a mismatch occured.

First, the pattern needs to get analyzed for similar prefixes and sufficex.

This leads to a look-up array that is used in the main algorithm to calculate the jump while searching the text and furthermore the place within the pattern to start the next search iteration. This eliminates the case of jumping back within the text, which leads to a linear O(m) run-time.

### Heapsort

Heapsort treats an array like a binary search tree. The search tree needs to fulfill a specific charatceristic called max heap. It basically ensures that the biggest value within the array is the root of the tree.

After initially converting the array into max heap, the root value switches places with the last value of the tree within the array. The new array gets converted to max heap, ignoring the last value, which is sorted. The next root value switches places with the last value of the tree within the array and so on. through every iteration the root value from the iteration before will be ignored, thats why the array gets shorter and shorter until its fully sorted.
