//Nitis Jadipang 66070501020

//The Foundation of Set

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int createSet(int set[], int uniA, int uniB) {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int setSize = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num >= uniA && num <= uniB) {
            int exists = 0;
            for (int j = 0; j < setSize; j++) {
                if (num == set[j]) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                set[setSize] = num;
                setSize++;
            }
        }
    }

    free(arr);
    return setSize;
}

int createUnion(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int setSize = 0;

    for (int i = 0; i < sizeA; i++) {
        result[setSize++] = setA[i];
    }

    for (int i = 0; i < sizeB; i++) {
        int exists = 0;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            result[setSize++] = setB[i];
        }
    }

    qsort(result, setSize, sizeof(int), compare);

    return setSize;
}

int createIntersection(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int setSize = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                result[setSize++] = setA[i];
                break;
            }
        }
    }

    return setSize;
}

int createDifferenceAToB(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int setSize = 0;

    for (int i = 0; i < sizeA; i++) {
        int exists = 0;
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            result[setSize++] = setA[i];
        }
    }

    return setSize;
}

int createDifferenceBToA(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int setSize = 0;

    for (int i = 0; i < sizeB; i++) {
        int exists = 0;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            result[setSize++] = setB[i];
        }
    }

    return setSize;
}

int createComplementToUni(int set[], int size, int universe[], int universeSize, int result[]) {
    int setSize = 0;

    for (int i = 0; i < universeSize; i++) {
        int exists = 0;
        for (int j = 0; j < size; j++) {
            if (universe[i] == set[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            result[setSize++] = universe[i];
        }
    }

    return setSize;
}

void printSet(int set[], int size) {
    if (size == 0) {
        printf("empty");
        printf("\n");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
    }
}

int main() {
    int uniA, uniB;
    scanf("%d %d", &uniA, &uniB);
    int *setA = (int *)malloc(uniA * sizeof(int));
    int *setB = (int *)malloc(uniB * sizeof(int));

    int sizeA = createSet(setA, uniA, uniB);
    int sizeB = createSet(setB, uniA, uniB);

    int sizeUni = uniB - uniA + 1;
    int *universeSet = (int *)malloc(sizeUni * sizeof(int));
    int start = uniA;

    for (int i = 0; i < sizeUni; i++) {
        universeSet[i] = start;
        start++;
    }

    // printf("Set A: ");
    printSet(setA, sizeA);

    // printf("Set B: ");
    printSet(setB, sizeB);

    int unionSize = sizeA + sizeB;
    int *unionSet = (int *)malloc(unionSize * sizeof(int));

    int unionSetSize = createUnion(setA, sizeA, setB, sizeB, unionSet);
    // printf("Union Set (Sorted): ");
    printSet(unionSet, unionSetSize);

    int intersectionSize = sizeA < sizeB ? sizeA : sizeB;
    int *intersectionSet = (int *)malloc(intersectionSize * sizeof(int));

    int intersectionSetSize = createIntersection(setA, sizeA, setB, sizeB, intersectionSet);

    if (intersectionSetSize == 0) {
        printf("empty\n");
    } else {
        // printf("Intersection Set: ");
        printSet(intersectionSet, intersectionSetSize);
    }

    int differenceSizeAtoB = sizeA - intersectionSetSize;
    int *differenceSetAtoB = (int *)malloc(differenceSizeAtoB * sizeof(int));

    int differenceSetAtoBSize = createDifferenceAToB(setA, sizeA, setB, sizeB, differenceSetAtoB);
    // printf("Difference Set (A - B): ");
    printSet(differenceSetAtoB, differenceSetAtoBSize);

    int differenceSizeBtoA = sizeB - intersectionSetSize;
    int *differenceSetBtoA = (int *)malloc(differenceSizeBtoA * sizeof(int));

    int differenceSetBtoASize = createDifferenceBToA(setA, sizeA, setB, sizeB, differenceSetBtoA);
    // printf("Difference Set (B - A): ");
    printSet(differenceSetBtoA, differenceSetBtoASize);

    int complementSetAtoUniSize = sizeUni - sizeA;
    int *complementSetAtoUni = (int *)malloc(complementSetAtoUniSize * sizeof(int));

    createComplementToUni(setA, sizeA, universeSet, sizeUni, complementSetAtoUni);
    // printf("Complement Set (A with respect to Universe): ");
    printSet(complementSetAtoUni, complementSetAtoUniSize);

    int complementSetBtoUniSize = sizeUni - sizeB;
    int *complementSetBtoUni = (int *)malloc(complementSetBtoUniSize * sizeof(int));

    createComplementToUni(setB, sizeB, universeSet, sizeUni, complementSetBtoUni);
    // printf("Complement Set (B with respect to Universe): ");
    printSet(complementSetBtoUni, complementSetBtoUniSize);

    free(setA);
    free(setB);
    free(universeSet);
    free(unionSet);
    free(intersectionSet);
    free(differenceSetAtoB);
    free(differenceSetBtoA);
    free(complementSetAtoUni);
    free(complementSetBtoUni);

    return 0;
}