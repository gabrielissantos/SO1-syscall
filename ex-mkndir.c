#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char * nomeDir = "diretorio";
	int r = syscall(357,nomeDir, S_IRUSR | S_IWUSR | S_IXUSR); // tentativa de criacao em modo usuario
	if(r == -1)
		printf("Erro ao criar o diretorio.\n");
	if(r == 0)
		printf("Diretorio %s criado com sucesso!\n");
}
