#include <stdio.h>
#include <string.h>

int main() {
    char word[2000][20];
    char compare[2000][20];
    int n = 0, i;
    FILE *datain;
    FILE *dataout;
    datain = fopen("t10.txt", "r");
    dataout = fopen("t11.txt", "r");

    if (datain != NULL && dataout != NULL) {
        // 讀取 word 資料
        while (fscanf(datain, "%s", word[n]) == 1) {
            if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
                word[n][strlen(word[n]) - 1] = '\0';
            }
            if (word[n][strlen(word[n]) - 1] >= 'A' && word[n][strlen(word[n]) - 1] <= 'Z')
                word[n][0] += 32;
            n++;
        }
        int len1 = n;

        // 讀取 compare 資料
        n = 0;
        while (fscanf(dataout, "%s", compare[n]) == 1) {
            if (!(compare[n][strlen(compare[n]) - 1] >= 'a' && compare[n][strlen(compare[n]) - 1] <= 'z')) {
                compare[n][strlen(compare[n]) - 1] = '\0';
            }
            if (compare[n][strlen(compare[n]) - 1] >= 'A' && compare[n][strlen(compare[n]) - 1] <= 'Z')
                compare[n][0] += 32;
            n++;
        }
        int len2 = n;
        int j = 0;
        int a;
        int ans = 0;
        int b; //
        // 用 visited 陣列標記已處理的元素
        int visited[2000] = {0};

        for (i = 0; i < n; i++) {
            // 檢查這個 compare[i] 是否已經處理過 : 這樣做還是沒辦法算到沒算到的
            //if (visited[i]) continue;

            for (j = 0; j < len1; j++) {
                ;
                if (strcmp(compare[i], word[j]) == 0) {
                    if  (visited[i])b+=1;
                    for (a = 1; a < 7; a++) {
                        if (!(strcmp(compare[i + a], word[j + a]) == 0)) break;
                        else if  (visited[i+a])b+=1;
                    }
                    if (a == 7) {
                        a++;
                        while (strcmp(compare[i + a], word[j + a]) == 0) {
                            if  (visited[i+a])b+=1;
                            a++;
                        }
                        a--;
                        ans += (a-b);
                        // 標記這些已經處理過的字串
                        for (int k = i; k < i + a; k++) {
                            visited[k] = 1;
                        }
                        //i += a - 1;  // 跳過已經處理的部分 :這樣做會直接跳過潛在的重複字串
                        //break;
                    }
                }
            }
        }

        printf("%d/%d = %.2f%%", ans, len1, (float)ans / len1 * 100);
    }

    return 0;
}
