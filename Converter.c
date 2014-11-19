#include<stdio.h>
#include<string.h>

FILE *fp,*fp1;
void convert();

main()
{
    char file_name[20],file_new[25];
    printf("Enter file name :");
    scanf("%s",file_name);
    strcpy(file_new,file_name);
    file_new[strlen(file_new)-3]='\0';
    strcat(file_new,"txt");
    if((fp=fopen(file_name,"r"))==NULL)
    {
        printf("\nError! File Not found!!");
        return;
    }
    fp1=fopen(file_new,"w");
    convert();
    fclose(fp);
    fclose(fp1);

}

void convert()
{
    char ch,ch1,ch2;
    long double phone_no;
    while(1)
    {
        ch=ch1;
        ch1=ch2;
        ch2=fgetc(fp);
        if(ch=='L'&&ch1=='E'&&ch2==':')
        break;

        if(ch=='L'&&ch1=='L'&&ch2==':')/*Sender*/
        {
            fgetc(fp);
            fscanf(fp,"%lf",&phone_no);
            fprintf(fp1,"From:+%.0lf\n",phone_no);
            ch1=fgetc(fp);
            ch2=fgetc(fp);
        }
    }

    ch1=fgetc(fp);
    ch2=fgetc(fp);
    if(ch1==EOF||ch2==EOF)
        return;
    while(1)
    {
        ch=ch1;
        ch1=ch2;
        ch2=fgetc(fp);

        if(ch=='E'&&ch1=='N'&&ch2=='D')
            return;


        if(ch=='='&&ch1=='2'&&ch2=='0')
        {
            fputc(' ',fp1);
            ch1=fgetc(fp);
            ch2=fgetc(fp);
        }
        else if(ch=='='&&ch1=='0'&&ch2=='A')
        {
            fputc('\n',fp1);
            ch1=fgetc(fp);
            ch2=fgetc(fp);
        }
        else if(ch=='=')
        {
            ch=ch1;
            ch1=ch2;
            ch2=fgetc(fp);
        }
        else
        fputc(ch,fp1);

        if(ch2==EOF)
            break;
    }
}
