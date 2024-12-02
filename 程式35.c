#include <stdio.h>
#include <ctype.h>
int main()
 {
    int a[5]={0};
    char ch;
    FILE *DataIn;
    FILE *DataOut;
    DataIn=fopen("t1.txt","r"); 
    DataOut=fopen("t2.txt","w");
    if (DataIn != NULL && DataOut != NULL){
        while((ch=fgetc(DataIn)) != EOF){ 
            switch (tolower(ch))
            {
            case 'a':
                a[0]++;
                break;
            case 'e':
                a[1]++;
                break;
            
            case 'i':
                a[2]++;
                break;
            
            case 'o':
                a[3]++;
                break;
            
            case 'u':
                a[4]++;
                break;
            
            default:
                break;
            }

        }
    }
    fprintf(DataOut,"A E I O U\n");
    fprintf(DataOut,"%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
    fclose(DataIn);
    fclose(DataOut);
    return 0;
}