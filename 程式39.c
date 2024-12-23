#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char ch, word[100][20], record[100][20];
    int count[100] = {0};  // 初始化所有元素為 0
    FILE *DataIn;
    FILE *DataOut;
    int n = 0, j = 0;

    DataIn = fopen("t5.txt", "r");
    DataOut = fopen("t6.txt", "w");

    if (DataIn != NULL && DataOut != NULL) {
        while (fscanf(DataIn, "%s", word[n]) == 1) {
            // 如果最後一個字元不是大寫英文字母，則刪掉它
            if ((word[n][0] >= 'A' && word[n][0] <= 'Z'))
                word[n][0]=tolower(word[n][0]);
            if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
                word[n][strlen(word[n]) - 1] = '\0';
                
            }
            
            // 檢查當前單字是否已經在 record 中
            int found = 0;
            for (int i = 0; i < j; i++) {
                if (strcmp(record[i], word[n]) == 0) {
                    count[i]++;  // 如果找到，增加計數
                    found = 1;
                    break;
                }
            }

            // 如果這個單字是新單字，則加入 record
            if (!found) {
                strcpy(record[j], word[n]);  // 複製到 record
                count[j] = 1;               // 初始化計數為 1
                j++;                        // 更新 record 的索引
            }

            n++;  // 處理下一個單字
        }

        // 輸出所有的單字和計數
        
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
