// Qual biblioteca chama o sys_mkdir??
#include <syscalls.h>
#include <linux/linkage.h>
#include <linux/unistd.h>
#include <string.h>


asmlinkage long sys_mkndir(const short int n, const char * nome, mode_t mode){
	int i;	

	// Por default, se mkdir nao funciona, retorna -1
	for(i = 0; i < n; i++){

		//tentativa de por "i" como char na frente de nome.
		char palavra[3]; //numero de pastas de até 3 algarismos
		int aux = i; //conteudo de aux será transformado em char
		sprintf(palavra, %i, aux); //transforma aux em palavra
		strcat(palavra, nome); //concatena 
		

		/* TODO: Por "i" como char na frente de nome.
		 * 	 Lembrar de nao substituir o nome
		 */
		if(sys_mkdir(nome, mode) == -1) return -1;

	}
		
	// Se funciona, retorna 0
	return 0;
}
