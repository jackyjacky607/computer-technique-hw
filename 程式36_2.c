#include <stdio.h>
#include <string.h>

int main() {
    char ch, word[100][20], record[100][20];
    int count[100] = {0};  // ��l�ƩҦ������� 0
    FILE *DataIn;
    FILE *DataOut;
    int n = 0, j = 0;

    DataIn = fopen("t3.txt", "r");
    DataOut = fopen("t4.txt", "w");

    if (DataIn != NULL && DataOut != NULL) {
        while (fscanf(DataIn, "%s", word[n]) == 1) {
            // �p�G�̫�@�Ӧr�����O�j�g�^��r���A�h�R����
            if (!(word[n][strlen(word[n]) - 1] >= 'A' && word[n][strlen(word[n]) - 1] <= 'Z')) {
                word[n][strlen(word[n]) - 1] = '\0';
            }

            // �ˬd��e��r�O�_�w�g�b record ��
            int found = 0;
            for (int i = 0; i < j; i++) {
                if (strcmp(record[i], word[n]) == 0) {
                    count[i]++;  // �p�G���A�W�[�p��
                    found = 1;
                    break;
                }
            }

            // �p�G�o�ӳ�r�O�s��r�A�h�[�J record
            if (!found) {
                strcpy(record[j], word[n]);  // �ƻs�� record
                count[j] = 1;               // ��l�ƭp�Ƭ� 1
                j++;                        // ��s record ������
            }

            n++;  // �B�z�U�@�ӳ�r
        }

        // ��X�Ҧ�����r�M�p��
        for (int i = 0; i < j; i++) {
            printf("%s: %d\n", record[i], count[i]);
            fprintf(DataOut, "%s: %d\n", record[i], count[i]);
        }
    }

    fclose(DataIn);
    fclose(DataOut);
    return 0;
}
