#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv){
	// Saia do programa caso exceda o numero de argumentos
	if(argc != 3){
		printf("Numero de argumentos (%d) invalido!\n", argc);
		return -1;
	}

	int numDir = strtol(argv[2], NULL, 10);

	// Saia do programa caso a ordem dos argumentos esteja trocada
	if(!numDir){
		printf("Ordem dos argumentos incorreta!\n");
		return -1;
	}

	char nomeDir[100];
	strcpy(nomeDir, argv[1]);

	int r = syscall(357, numDir, nomeDir, S_IRUSR | S_IWUSR | S_IXUSR); // tentativa de criacao em modo usuario
	if(r == -1){
		printf("Erro ao criar o diretorio.\n");
	}else if(r == 0){
		printf("Diretorio %s criado com sucesso!\n", nomeDir);
	}else{
		printf("Nao foi possivel acessar a chamada.\n");
		printf("%d\n", r);
	}
	return 0;
}
