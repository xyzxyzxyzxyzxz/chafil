
int encr(int odat)
{
    int edat;
    char ohes[4]={"\0\0\0\0"},ehes[4]={"\0\0\0\0"};


    sprintf(ohes,"%X",odat);
    //printf("%s",ohes);

    ehes[0]=ohes[1],ehes[1]=ohes[0];

    sscanf(ehes,"%X",&edat);
    //printf("%s",ehes);

    return edat;
}


int decr(int odat)
{
    int ddat;
    char ohes[4]={"\0\0\0\0"},dhes[4]={"\0\0\0\0"};


    sprintf(ohes,"%X",odat);
    //printf("%s",ohes);

    dhes[0]=ohes[1],dhes[1]=ohes[0];

    sscanf(dhes,"%X",&ddat);
    //printf("%s",dhes);

    return ddat;
}





