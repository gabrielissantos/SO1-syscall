#include <stdio.h>
#include <string.h>

void concatena();

/*
int main(void)
{
    concatena("astolfo", 12);
    return 0;
}
*/

void concatena(char* nome, int Quantidade)
{
	char name[100], indice[3];

    for (int i = 1; i < (Quantidade+1); i++)
    {
		sprintf(indice, "%d", i); //passa i de int para char
		strcpy(name,nome);
		strcat(name, indice); 
		printf("%s\n",name);
    }
}
