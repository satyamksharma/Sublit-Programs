/* VowelGig

Spotify was facing a major challenge. Despite having a vast library of songs, users were finding it difficult and time-consuming to search for their desired songs. This was causing frustration and leading many users to switch to other music streaming services. The team at Spotify was determined to find a solution to this problem. Spotify’s team of developers have approached you to write a program that will generate the number of strings that contain only vowels which are in dictionary order, to provide better user experience for searching. Write a program that takes an integer input and returns an integer indicating the number of songs that have only vowels and are sorted based on their dictionary representation.
Hint: Use decrease by constant approach.
Explanation: In the given sample test case, the number of vowel strings of length 2 that are lexicographically sorted are 'aa', 'ae', 'ai', 'ao', 'au', 'ee', 'ei', 'eo', 'eu', 'ii', 'io', 'iu', 'oo', 'ou', 'uu'. Hence, the output must be 15.

Input Format

n - integer representing the number of characters in the vowel string

Output Format

num_songs - integer representing number of vowel strings in sorted order

Testcase 1
Input

2
Output

15 
*/


// Code------>
#include<stdio.h>

int count(int n)
{
    return (n+1)*(n+2)*(n+3)*(n+4)/24;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", count(n));
    return 0;
}