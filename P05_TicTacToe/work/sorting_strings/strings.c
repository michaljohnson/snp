#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

void createWordArray(char (*words)[MAX_WORD_LENGTH]);
void lowerToUpper(char (*words)[MAX_WORD_LENGTH]);
void quickSort(char (*words)[MAX_WORD_LENGTH], int first, int last);
int partition(char (*words)[MAX_WORD_LENGTH], int low, int high);
void swap(char *a, char *b);

int main(void){
    char words [MAX_WORDS][MAX_WORD_LENGTH];
    createWordArray(words);
    lowerToUpper(words);
    quickSort(words, 0, MAX_WORDS-1);
    for(int i=0; i<MAX_WORDS; i++) {
        if(strcmp(words[i], "ZZZ") == 0) {
            break;
        }
        printf("%s\n", words[i]);
    }
    return 0;
}

void createWordArray(char (*words)[MAX_WORD_LENGTH]) {
    for(int i=0; i<MAX_WORDS; i++) {
        printf("Geben Sie ein Wort ein oder 'ZZZ' um zu beenden: ");
        scanf("%s", words[i]);

        if(strcmp(words[i], "ZZZ") == 0) {
            break;
        }
        for(int j=0; j<i; j++) {
            if(strcmp(words[j], words[i]) == 0) {
                printf("Word bereits eingegeben, bitte ein anderes Wort eingeben.\n");
                i--;
                break;
            }
        }
    }
}

void lowerToUpper(char (*words)[MAX_WORD_LENGTH]){
    for(int i = 0; i < MAX_WORDS; i++){
        for(int j = 0; j < MAX_WORD_LENGTH; j++){
            words[i][j] = toupper(words[i][j]);
        }
    }
}

void swap(char *a, char *b) {
    char temp[MAX_WORD_LENGTH];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition (char (*words)[MAX_WORD_LENGTH], int low, int high) {
    char pivot[MAX_WORD_LENGTH];
    strcpy(pivot, words[high]);
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) {
        if (strcmp(words[j], pivot) < 0) {
            i++;
            swap(words[i], words[j]);
        }
    }
    swap(words[i + 1], words[high]);
    return (i + 1);
}

void quickSort(char (*words)[MAX_WORD_LENGTH], int low, int high){
    if (low < high) {
        int pi = partition(words, low, high);
        quickSort(words, low, pi - 1);
        quickSort(words, pi + 1, high);
    }
}