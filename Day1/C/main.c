#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NEW_LINE_CHAR '\n'
#define MAXIMUM_CHAR 10
#define FIRST_CHAR 0
#define PUZZLEINPUT_FILE_PATH "../puzzleInput/adventofcode.com_2022_day_1_input.txt"
#define NB_SUMS_TO_SUM 3


void main(void) {
    FILE* pFile;
        
    fopen_s(&pFile, PUZZLEINPUT_FILE_PATH, "r");
    // ON FILE ERROR
    if(pFile == NULL) {
        printf("File doesn't exist!");
        return;
    }

    // ON FILE OPEN
    char textLine[MAXIMUM_CHAR];
    long highestSums[NB_SUMS_TO_SUM] = {0}; 
    long currSum = 0;

    while (fgets(textLine, MAXIMUM_CHAR, pFile) != NULL) 
    {
        if(textLine[FIRST_CHAR] == NEW_LINE_CHAR) {
            int iSum = 0;
            while(iSum < NB_SUMS_TO_SUM && currSum >= highestSums[iSum]) iSum++;
            iSum -= 1;
            for(int iSum2 = 0; iSum2 < iSum; iSum2++) highestSums[iSum2] = highestSums[iSum2 + 1];
            highestSums[iSum] = currSum;
            currSum = 0;
            continue;
        } // SKIP FULL ITERATION BECAUSE OF CONTINUE

        long value = (long) strtol(textLine, (char**)NULL, 10);
        currSum += value;
    }
    fclose(pFile);
    long highestSum = 0;
    for(int iSum = 0; iSum < NB_SUMS_TO_SUM; iSum++) highestSum += highestSums[iSum];
    printf("%ld", highestSum);
}
