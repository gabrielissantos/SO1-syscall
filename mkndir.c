// Qual biblioteca chama o sys_mkdir??
#include <syscalls.h>
#include <linux/linkage.h>
#include <linux/unistd.h>
#include <string.h>


asmlinkage long sys_mkndir(const short int n, const char * nome, mode_t mode){
	int i;	

	// Por default, se mkdir nao funciona, retorna -1
	for(i = 0; i < n; i++){
		char palavra[3];
		int aux = i;
		sprintf(palavra, %i, aux);
		strcat(palavra, nome);
		

		/* TODO: Por "i" como char na frente de nome.
		 * 	 Lembrar de nao substituir o nome
		 */
		if(sys_mkdir(nome, mode) == -1) return -1;

	}
		
	// Se funciona, retorna 0
	return 0;
}
