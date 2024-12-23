#include <stdio.h>
#include <string.h>

int main() {
    int max;
    FILE* filein;
    FILE* fileout;

    printf("enter width: ");
    scanf("%d%*c", &max);

    filein = fopen("test12.txt", "r");
    fileout = fopen("test13.txt", "w");

    if (filein == NULL || fileout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int currentsize = 0;  // ��e�檺����
    char word[101];       // �x�sŪ������r
    int isNewLine = 1;    // �P�_�O�_���s��]�v�T�O�_��X�Ů�^

    while (fscanf(filein, "%s", word) == 1) {
        int len = strlen(word);

        // �p�G��r���׶W�L�̤j�e�סA���γ�r
        if (len > max) {
            int start = 0;
            while (len - start > max) {
                // �p�G��e�榳���e�A����
                if (currentsize > 0) {
                    fprintf(fileout, "\n");
                    currentsize = 0;
                }
                // ��X���γ���
                for (int i = 0; i < max; i++) {
                    fprintf(fileout, "%c", word[start + i]);
                }
                fprintf(fileout, "\n");
                start += max;
                currentsize = 0;
                isNewLine = 1; // ���Ϋᴫ������s��
            }

            // �ѤU������
            if (len - start > 0) {
                if (!isNewLine) {
                    fprintf(fileout, " ");
                    currentsize += 1;
                }
                fprintf(fileout, "%s", &word[start]);
                currentsize += len - start;
                isNewLine = 0;
            }
        } else {
            // ��r���פ��W�L�̤j�e��
            if (currentsize + (isNewLine ? 0 : 1) + len > max) {
                // ����
                fprintf(fileout, "\n");
                currentsize = 0;
                isNewLine = 1;
            }

            if (!isNewLine) {
                fprintf(fileout, " ");
                currentsize += 1;
            }

            fprintf(fileout, "%s", word);
            currentsize += len;
            isNewLine = 0;
        }
    }

    // �̫�ɤW�@�Ӵ����
    fprintf(fileout, "\n");
    fclose(filein);
    fclose(fileout);

    return 0;
}
