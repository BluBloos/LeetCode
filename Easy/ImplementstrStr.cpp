#include <string>
#include <stdio.h>
#include <stdlib.h>

int strStr(std::string haystack, std::string needle) {
    // for this algorithm, we are basically trying to find
    // the needle in the haystack!
    //
    // this is effectively finding a substring in a string, and the first index
    // where this substring occurs!
    //
    // return -1 if the needle is not in the haystack.
    // if needle is an empty string, we return 0. Consistent with the actual function.
    char *pHaystack = (char *)haystack.c_str();
    char *pNeedle = (char *)needle.c_str();
    if (*pNeedle == 0) {
        return 0;
    } else {
        // Prepocess the needle to build the LPS (longest prefix suffix) index table.
        unsigned int M = needle.size();
        unsigned int *LPS = (unsigned int *)malloc( sizeof(unsigned int) * (M + 1) ); 
        LPS[1] = 0; // Pretty sure this is always the case
        for (unsigned int i = 2; i < M + 1; i++) {
            unsigned int starting_point = LPS[i-1];
            if ( needle[i-1] == needle[starting_point] ) {
                LPS[i] = starting_point + 1;
            } else {
                LPS[i] = (needle[0] == needle[i-1]);
            }   
        }
        for (unsigned int i = 0; i < M + 1; i++) {
            printf("LPS[%d]=%d\n", i, LPS[i]);
        }
        // algo for finding the subtring!
        // keep track of the first index.
        // keep track of the index in the needle.
        // just match as you go along, and if you fail, you simply reset. 
        char *needle_head = pNeedle;
        unsigned int N = 0;
        for (char *pStr = pHaystack; *pStr != 0;1) {
            if (*needle_head == *pStr) {
                // boom! We have found a match. 
                // iterate.
                needle_head++;
                N += 1;
                if (*needle_head == 0) {
                    // if we reach the null terminator, this means that we have found the entire                            substring!
                    return pStr - pHaystack - N + 1; // might be the right one? 
                }
                pStr++; // only iterate i on the match, not mismatch
            } else {
                // reset state, no longer have a match.
                unsigned int lps_shift = LPS[needle_head - pNeedle]; // want j, not j + 1!
                needle_head = pNeedle + lps_shift;
                if (!lps_shift) pStr++; // if we cannot go back any more!
                // NOTE: Always keep i at the same location. Only adjust how much we backtrace the needle_head by.
                //pStr -= N;
                N = 0;
            }               
        }
        return -1; // made it through and did not find the substring...
    }
}

int main() {
    int result = strStr("aabaaabaaac",
        "aabaaac");
    printf("%d\n", result);
}