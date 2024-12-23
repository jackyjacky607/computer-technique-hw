#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char ch, word[100][20], record[100][20];
    int count[100] = {0};  // ��l�ƩҦ������� 0
    FILE *DataIn;
    FILE *DataOut;
    int n = 0, j = 0;

    DataIn = fopen("t5.txt", "r");
    DataOut = fopen("t6.txt", "w");

    if (DataIn != NULL && DataOut != NULL) {
        while (fscanf(DataIn, "%s", word[n]) == 1) {
            // �p�G�̫�@�Ӧr�����O�j�g�^��r���A�h�R����
            if ((word[n][0] >= 'A' && word[n][0] <= 'Z'))
                word[n][0]=tolower(word[n][0]);
            if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
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
        
        int a;
        char temp[30];
        int numtemp;
        int i;
        for(i=1;i<j;i++){
            for (a=0;a<j-i;a++){
                if (strcmp(record[a],record[a+1])>0){
                    strcpy(temp,record[a+1]);
                    strcpy(record[a+1],record[a]);
                    strcpy(record[a],temp);

                    numtemp=count[a+1];
                    count[a+1]=count[a];
                    count[a]=numtemp;
                }
            }
        } 
        for (int i = 0; i < j; i++) {
            printf("%s: %d\n", record[i], count[i]);
            fprintf(DataOut, "%s: %d\n", record[i], count[i]);
        }
    }

    fclose(DataIn);
    fclose(DataOut);
    return 0;
}
