#include <stdio.h>
#include <string.h>

int main() {
    char word[2000][20];    // t10.txt 的內容
    char compare[2000][20]; // t11.txt 的內容
    int n = 0, i;
    FILE *datain;
    FILE *dataout;

    // 開啟檔案
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (datain != NULL && dataout != NULL) {
        // 讀取 compare 資料（基準改為 t10.txt）
        while (fscanf(datain, "%s", compare[n]) == 1) {
            if (!(compare[n][strlen(compare[n]) - 1] >= 'a' && compare[n][strlen(compare[n]) - 1] <= 'z')) {
                compare[n][strlen(compare[n]) - 1] = '\0';
            }
            if (compare[n][0] >= 'A' && compare[n][0] <= 'Z')
                compare[n][0] += 32;
            n++;
        }
        int len1 = n;

        // 讀取 word 資料（要與 compare 比對）
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

        // 結果統計
        int ans = 0; // 符合的字串數
        int visited[2000] = {0}; // 標記已處理的位置

        // 開始比對
        for (i = 0; i < len1; i++) {
            if (visited[i]) continue; // 跳過已處理部分

            for (int j = 0; j < len2; j++) {
                if (strcmp(compare[i], word[j]) == 0) {
                    int match_count = 1;

                    // 檢查連續字串
                    while (match_count < 7 && i + match_count < len1 && j + match_count < len2 &&
                           strcmp(compare[i + match_count], word[j + match_count]) == 0) {
                        match_count++;
                    }

                    if (match_count >= 7) { // 超過 7 個視為有效片段
                        // 繼續延伸
                        while (i + match_count < len1 && j + match_count < len2 &&
                               strcmp(compare[i + match_count], word[j + match_count]) == 0) {
                            match_count++;
                        }

                        // 標記已處理的部分
                        for (int k = i; k < i + match_count; k++) {
                            visited[k] = 1;
                        }

                        ans += match_count; // 計算符合的長度
                    }
                }
            }
        }

        // 輸出結果
        printf("%d/%d = %.2f%%\n", ans, len1, (float)ans / len1 * 100);
    } else {
        printf("檔案讀取失敗\n");
    }

    // 關閉檔案
    if (datain) fclose(datain);
    if (dataout) fclose(dataout);

    return 0;
}
