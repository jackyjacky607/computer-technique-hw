#include <stdio.h>
#include <string.h>

int main() {
    char word[2000][20];
    char compare[2000][20];
    int n = 0, i;
    FILE *datain;
    FILE *dataout;
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (datain != NULL && dataout != NULL) {
        // Ū�� word ���
        while (fscanf(datain, "%s", word[n]) == 1) {
            if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
                word[n][strlen(word[n]) - 1] = '\0';
            }
            if (word[n][strlen(word[n]) - 1] >= 'A' && word[n][strlen(word[n]) - 1] <= 'Z')
                word[n][0] += 32;
            n++;
        }
        int len1 = n;

        // Ū�� compare ���
        n = 0;
        while (fscanf(dataout, "%s", compare[n]) == 1) {
            if (!(compare[n][strlen(compare[n]) - 1] >= 'a' && compare[n][strlen(compare[n]) - 1] <= 'z')) {
                compare[n][strlen(compare[n]) - 1] = '\0';
            }
            if (compare[n][strlen(compare[n]) - 1] >= 'A' && compare[n][strlen(compare[n]) - 1] <= 'Z')
                compare[n][0] += 32;
            n++;
        }
        int len2 = n;
        int j = 0;
        int a;
        int ans = 0;
        int b; //
        // �� visited �}�C�аO�w�B�z������
        int visited[2000] = {0};

        for (i = 0; i < n; i++) {
            // �ˬd�o�� compare[i] �O�_�w�g�B�z�L : �o�˰��٬O�S��k���S��쪺
            //if (visited[i]) continue;

            for (j = 0; j < len1; j++) {
                ;
                if (strcmp(compare[i], word[j]) == 0) {
                    if  (visited[i])b+=1;
                    for (a = 1; a < 7; a++) {
                        if (!(strcmp(compare[i + a], word[j + a]) == 0)) break;
                        else if  (visited[i+a])b+=1;
                    }
                    if (a == 7) {
                        a++;
                        while (strcmp(compare[i + a], word[j + a]) == 0) {
                            if  (visited[i+a])b+=1;
                            a++;
                        }
                        a--;
                        ans += (a-b);
                        // �аO�o�Ǥw�g�B�z�L���r��
                        for (int k = i; k < i + a; k++) {
                            visited[k] = 1;
                        }
                        //i += a - 1;  // ���L�w�g�B�z������ :�o�˰��|�������L��b�����Ʀr��
                        //break;
                    }
                }
            }
        }

        printf("%d/%d = %.2f%%", ans, len1, (float)ans / len1 * 100);
    }

    return 0;
}
