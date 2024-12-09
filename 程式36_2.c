#include <stdio.h>
#include <string.h>

int main() {
    char ch, word[100][20], record[100][20];
    int count[100] = {0};  // 初始化所有元素為 0
    FILE *DataIn;
    FILE *DataOut;
    int n = 0, j = 0;

    DataIn = fopen("t3.txt", "r");
    DataOut = fopen("t4.txt", "w");

    if (DataIn != NULL && DataOut != NULL) {
        while (fscanf(DataIn, "%s", word[n]) == 1) {
            // 如果最後一個字元不是大寫英文字母，則刪掉它
            if (!(word[n][strlen(word[n]) - 1] >= 'A' && word[n][strlen(word[n]) - 1] <= 'Z')) {
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
        for (int i = 0; i < j; i++) {
            printf("%s: %d\n", record[i], count[i]);
            fprintf(DataOut, "%s: %d\n", record[i], count[i]);
        }
    }

    fclose(DataIn);
    fclose(DataOut);
    return 0;
}
