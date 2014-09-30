#include<stdio.h>

int main (void)
{
    FILE *fp_out;

    char str1[]="chaitali";
    char str2[] = "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
    char str4 = '\0';
    char str5[] = "sssssssss";

    fp_out=fopen("my_file", "w");

    if(fp_out!=NULL)
    {
      fprintf(fp_out,"%s\n%s%c%s%c%s%c", str1,str2,str4,str2,str4);
        fclose(fp_out);
    }
    else
        printf("The file \"my_file\" couldn't be opened\n");

    return 0;
}
