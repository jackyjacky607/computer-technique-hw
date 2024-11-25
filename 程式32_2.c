#include <stdio.h>

int gcd(int n1, int n2) {
    while (n1 != 0 && n2 != 0) {
        if (n1 > n2) n1 -= n2;
        else n2 -= n1;
    }
    return (n1 > n2 ? n1 : n2);
}

void sort_fraction(int (*arr)[2], int n) {
    int i, j, temp[2];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((arr[j][0] * arr[j + 1][1]) > (arr[j][1] * arr[j + 1][0])) {
                temp[0] = arr[j][0];
                temp[1] = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp[0];
                arr[j + 1][1] = temp[1];
            }
        }
    }
}

int main() {
    printf("Please input a number: ");
    int n, i, j, a = 0;
    int frac[1000][2];  // increase array size if needed
    scanf("%d", &n);

    // Generate fractions
    for (i = 2; i <= n; i++) {  // start from 2 to n
        for (j = 1; j < i; j++) {
            if (gcd(i, j) == 1) {  // check if i and j are coprime
                frac[a][0] = j;
                frac[a][1] = i;
                a++;
            }
        }
    }

    // Print unsorted fractions
    /*printf("Generated fractions:\n");
    for (i = 0; i < a; i++) {
        printf("%d/%d\n", frac[i][0], frac[i][1]);
    }*/

    // Sort fractions
    sort_fraction(frac, a);

    // Print sorted fractions
    //printf("\nSorted fractions:\n");
    printf("0,");
    for (i = 0; i < a; i++) {
        printf("%d/%d,", frac[i][0], frac[i][1]);
    }
    printf("1");
    printf("(total numbers: %d)",a+2);
    return 0;
}
