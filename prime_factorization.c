#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push,1)
typedef struct {
    int age;
    char* name;
} Player;
#pragma pack(pop)

int TryDivide(int* Target, int devide) {
    if (*Target % devide == 0) {
        *Target /= devide;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main_prime_factorization()
{   
    int type,success,end,conti;
    unsigned int multiplication[25] = { 0, };
    unsigned int num[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
    scanf("%d",&type);
    while (1) {
        end = 0;
        conti = 0;
        for (int i = 0; i < sizeof(num) / sizeof(unsigned int); i++) {
            if (type == num[i]) {
                end = 1;
            }
        }
        if (end == 1)
            break;
        for (int i = 0; i < sizeof(num) / sizeof(unsigned int); i++) {
            success = TryDivide(&type, num[i]);
            if (success) {
                multiplication[i]++;
                conti = 1;
                break;
            }
        }
        if (conti) {
            continue;
        }
        break;
    }
    printf("%d", type);
    for (int i = 0; i < sizeof(multiplication) / sizeof(unsigned int); i++) {
        if (multiplication[i]) {
            while (!(multiplication[i] == 0)) {
                printf(" * %d", num[i]);
                multiplication[i]--;
            }
        }
    }
}