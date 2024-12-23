#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[2000][20];    // t11.txt �����e
    char compare[2000][20]; // t10.txt �����e
    int n = 0, i;
    FILE *datain, *dataout;

    // �}���ɮ�
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (!datain) {
        printf("�L�k�}�� t10.txt\n");
        return 1;
    }
    if (!dataout) {
        printf("�L�k�}�� t11.txt\n");
        fclose(datain);
        return 1;
    }

    // Ū�� compare ���
    while (fscanf(datain, "%s", compare[n]) == 1) {
        int len = strlen(compare[n]);
        if (!isalpha(compare[n][len - 1])) {
            compare[n][len - 1] = '\0';
        }
        for (int k = 0; k < strlen(compare[n]); k++) {
            compare[n][k] = tolower(compare[n][k]);
        }
        n++;
        if (n >= 2000) {
            printf("compare �W�L�䴩���r��ƶq�W��\n");
            fclose(datain);
            fclose(dataout);
            return 1;
        }
    }
    int len1 = n;

    // Ū�� word ���
    n = 0;
    while (fscanf(dataout, "%s", word[n]) == 1) {
        int len = strlen(word[n]);
        if (!isalpha(word[n][len - 1])) {
            word[n][len - 1] = '\0';
        }
        for (int k = 0; k < strlen(word[n]); k++) {
            word[n][k] = tolower(word[n][k]);
        }
        n++;
        if (n >= 2000) {
            printf("word �W�L�䴩���r��ƶq�W��\n");
            fclose(datain);
            fclose(dataout);
            return 1;
        }
    }
    int len2 = n;

    // ���G�έp
int ans = 0;              // �ŦX���r���
int visited[2000] = {0};  // �аO t10 ���r��O�_�w�ϥ�

// �}�l���
for (i = 0; i < len1; i++) {
    if (visited[i]) continue; // �p�G�Ӧr��w�ϥΡA���L

    int max_match = 0;        // �̤j�ǰt����
    int best_start_t11 = -1;  // t11 ���̨Τǰt�_�I

    for (int j = 0; j < len2; j++) {
        if (strcmp(compare[i], word[j]) == 0) {
            int match_count = 1;

            // �ˬd�s��r��
            while (i + match_count < len1 && j + match_count < len2 &&
                   strcmp(compare[i + match_count], word[j + match_count]) == 0 &&
                   !visited[i + match_count]) {
                match_count++;
            }

            // �p�G��������ǰt�A��s�̨Τǰt
            if (match_count > max_match) {
                max_match = match_count;
                best_start_t11 = j;
            }
        }
    }

    // �p�G��즳�Ĥǰt
    if (max_match >= 7) {
        // �аO t10 ���ǰt����
        for (int k = i; k < i + max_match; k++) {
            visited[k] = 1;
        }
        ans += max_match; // �p��ŦX������
    }
}

// ��X���G
printf("%d/%d = %.2f%%\n", ans, len1, (float)ans / len1 * 100);

    fclose(datain);
    fclose(dataout);

    return 0;
}
