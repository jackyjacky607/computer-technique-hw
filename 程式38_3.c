#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[2000][20];    // t11.txt 的內容
    char compare[2000][20]; // t10.txt 的內容
    int n = 0, i;
    FILE *datain, *dataout;

    // 開啟檔案
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (!datain) {
        printf("無法開啟 t10.txt\n");
        return 1;
    }
    if (!dataout) {
        printf("無法開啟 t11.txt\n");
        fclose(datain);
        return 1;
    }

    // 讀取 compare 資料
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
            printf("compare 超過支援的字串數量上限\n");
            fclose(datain);
            fclose(dataout);
            return 1;
        }
    }
    int len1 = n;

    // 讀取 word 資料
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
            printf("word 超過支援的字串數量上限\n");
            fclose(datain);
            fclose(dataout);
            return 1;
        }
    }
    int len2 = n;

    // 結果統計
int ans = 0;              // 符合的字串數
int visited[2000] = {0};  // 標記 t10 的字串是否已使用

// 開始比對
for (i = 0; i < len1; i++) {
    if (visited[i]) continue; // 如果該字串已使用，跳過

    int max_match = 0;        // 最大匹配長度
    int best_start_t11 = -1;  // t11 中最佳匹配起點

    for (int j = 0; j < len2; j++) {
        if (strcmp(compare[i], word[j]) == 0) {
            int match_count = 1;

            // 檢查連續字串
            while (i + match_count < len1 && j + match_count < len2 &&
                   strcmp(compare[i + match_count], word[j + match_count]) == 0 &&
                   !visited[i + match_count]) {
                match_count++;
            }

            // 如果找到更長的匹配，更新最佳匹配
            if (match_count > max_match) {
                max_match = match_count;
                best_start_t11 = j;
            }
        }
    }

    // 如果找到有效匹配
    if (max_match >= 7) {
        // 標記 t10 的匹配部分
        for (int k = i; k < i + max_match; k++) {
            visited[k] = 1;
        }
        ans += max_match; // 計算符合的長度
    }
}

// 輸出結果
printf("%d/%d = %.2f%%\n", ans, len1, (float)ans / len1 * 100);

    fclose(datain);
    fclose(dataout);

    return 0;
}
