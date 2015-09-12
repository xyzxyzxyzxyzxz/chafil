#include <stdlib.h>
#include <stdio.h>


#include "crypt.h"





int main (int argc,char * argv[])
{
    FILE *fpr,*fpw;

    char fv[4]={"\0\0\0\0"};
    int fvb;

    char frn[10]={"a.txt"},fwn[10]={"b.txt"};


    printf("input file to be recovered,the default file name is a.txt\n");
    scanf("%s",frn);


    if((fpr=fopen(frn,"rb"))==NULL)
    {
        printf("open file to be recovered failed\n");
        exit(1);
    }


    printf("input file to be writed in,the default file name is b.txt\n");
    scanf("%s",fwn);

    if((fpw=fopen(fwn,"wb"))==NULL)
    {
        printf("open file to be writed in failed\n");
        exit(1);
    }


    while (!feof(fpr))
    {
        fread(&fv,2,1,fpr);

        sscanf(fv,"%X",&fvb);

        fvb= decr(fvb);

        printf("%X",fvb);

        fwrite(&fvb,1,1,fpw);
    }




    return 0;
}


