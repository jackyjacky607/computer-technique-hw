#include <stdio.h>
#include <string.h>

int main() {
    char word[2000][20];    // t10.txt �����e
    char compare[2000][20]; // t11.txt �����e
    int n = 0, i;
    FILE *datain;
    FILE *dataout;

    // �}���ɮ�
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (datain != NULL && dataout != NULL) {
        // Ū�� compare ��ơ]��ǧאּ t10.txt�^
        while (fscanf(datain, "%s", compare[n]) == 1) {
            if (!(compare[n][strlen(compare[n]) - 1] >= 'a' && compare[n][strlen(compare[n]) - 1] <= 'z')) {
                compare[n][strlen(compare[n]) - 1] = '\0';
            }
            if (compare[n][0] >= 'A' && compare[n][0] <= 'Z')
                compare[n][0] += 32;
            n++;
        }
        int len1 = n;

        // Ū�� word ��ơ]�n�P compare ���^
        n = 0;
        while (fscanf(dataout, "%s", word[n]) == 1) {
            if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
                word[n][strlen(word[n]) - 1] = '\0';
            }
            if (word[n][0] >= 'A' && word[n][0] <= 'Z')
                word[n][0] += 32;
            n++;
        }
        int len2 = n;

        // ���G�έp
        int ans = 0; // �ŦX���r���
        int visited[2000] = {0}; // �аO�w�B�z����m

        // �}�l���
        for (i = 0; i < len1; i++) {
            if (visited[i]) continue; // ���L�w�B�z����

            for (int j = 0; j < len2; j++) {
                if (strcmp(compare[i], word[j]) == 0) {
                    int match_count = 1;

                    // �ˬd�s��r��
                    while (match_count < 7 && i + match_count < len1 && j + match_count < len2 &&
                           strcmp(compare[i + match_count], word[j + match_count]) == 0) {
                        match_count++;
                    }

                    if (match_count >= 7) { // �W�L 7 �ӵ������Ĥ��q
                        // �~�򩵦�
                        while (i + match_count < len1 && j + match_count < len2 &&
                               strcmp(compare[i + match_count], word[j + match_count]) == 0) {
                            match_count++;
                        }

                        // �аO�w�B�z������
                        for (int k = i; k < i + match_count; k++) {
                            visited[k] = 1;
                        }

                        ans += match_count; // �p��ŦX������
                    }
                }
            }
        }

        // ��X���G
        printf("%d/%d = %.2f%%\n", ans, len1, (float)ans / len1 * 100);
    } else {
        printf("�ɮ�Ū������\n");
    }

    // �����ɮ�
    if (datain) fclose(datain);
    if (dataout) fclose(dataout);

    return 0;
}
