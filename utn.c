#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
void pause()
{

	char tmp;
	fflush(stdin);

	do{
		tmp = getchar();
	} while( tmp != '\n' && tmp != 0);

	return;
}
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
	int ok = -1;
    char auxString[limit];

    if(pAux != 0 && msg != 0 && msgError != 0 && limit > 0 && retry >= 0){
        do{
        	printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                ok = 0;
                break;
            }else
            {
            	printf("%s", msgError);
            }
            retry--;

        }while(retry>=0);
    }

    return ok;
}
int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int ok = -1;

    if (pAux != 0 && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            ok=0;
        }
    }

    return ok;
}
int isChar(char str[])
{

	int ok = 0;

	for(int i = 0; str[i] != '\0'; i++)
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			ok = -1;
		}
	}

	return ok;
}
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int ok = -1;
    float auxFloat;

    if(pFloat != 0 && msg != 0 && msgError != 0 && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                ok = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return ok;
}
int getFloat(float*pAux)
{
    char auxString[200];
    int ok =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        ok = 0; //exito
    }
    return ok;
}
int isFloat(char* pAux)
{
    int ok = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        ok = 0;
    }
    return ok;
}
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int ok = -1;
    int auxInt;

    if(pEntero != 0 && msg != 0 && msgError != 0 && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                ok = 0; //exito
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return ok;
}
int getInt(int* pAux)
{
    char auxString[400];
    int ok = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
         ok = 0;
    }
    return ok;
}

int isInt(char *pAux)
{
    int ok = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        ok = 0;
    }

    return ok;
}
int strLwr(char* str)
{
	int ok = -1;
	int i = 0;

	if(str != 0)
	{
		while(str[i] != '\0')
		{
			str[i] = tolower(str[i]);
			i++;
		}
		ok = 0;
	}
	return ok;
}
int normalizeStr(char* str)
{
	int ok = -1;
	int i = 0;

	if(str != 0)
	{
		strLwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				ok = 0;
			}
			i++;
		}
	}
	return ok;
}
