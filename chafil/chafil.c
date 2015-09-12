#include <stdlib.h>
#include <stdio.h>


#include "crypt.h"






int main (int argc,char * argv[])
{
    FILE *fpr,*fpw;

    int fv=0;
    char fvs[4]={"22\0\0"};

    char frn[10]={"a.txt"},fwn[10]={"b.txt"};


    printf("input file to be changed,the default file name is a.txt\n");
    scanf("%s",frn);


    if((fpr=fopen(frn,"rb"))==NULL)
    {
        printf("open file to be changed failed\n");
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
        fread(&fv,1,1,fpr);

        fv=encr(fv);

        //printf("%X\n",fv);
        sprintf(fvs,"%X",fv);
        printf("%s",fvs);

        fwrite(fvs,2,1,fpw);
    }

    return 0;
}


