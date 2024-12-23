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

    int currentsize = 0;  // 當前行的長度
    char word[101];       // 儲存讀取的單字
    int isNewLine = 1;    // 判斷是否為新行（影響是否輸出空格）

    while (fscanf(filein, "%s", word) == 1) {
        int len = strlen(word);

        // 如果單字長度超過最大寬度，切割單字
        if (len > max) {
            int start = 0;
            while (len - start > max) {
                // 如果當前行有內容，換行
                if (currentsize > 0) {
                    fprintf(fileout, "\n");
                    currentsize = 0;
                }
                // 輸出切割部分
                for (int i = 0; i < max; i++) {
                    fprintf(fileout, "%c", word[start + i]);
                }
                fprintf(fileout, "\n");
                start += max;
                currentsize = 0;
                isNewLine = 1; // 切割後換行視為新行
            }

            // 剩下的部分
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
            // 單字長度不超過最大寬度
            if (currentsize + (isNewLine ? 0 : 1) + len > max) {
                // 換行
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

    // 最後補上一個換行符
    fprintf(fileout, "\n");
    fclose(filein);
    fclose(fileout);

    return 0;
}
