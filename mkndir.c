// Qual biblioteca chama o sys_mkdir??
#include <syscalls.h>
#include <linux/linkage.h>
#include <linux/unistd.h>
#include <strings.h>


asmlinkage long sys_mkndir(const short int n, const char * nome, mode_t mode){
	int i;	

	// Por default, se mkdir nao funciona, retorna -1
	for(i = 0; i < n; i++)
		/* TODO: Por "i" como char na frente de nome.
		 * 	 Lembrar de nao substituir o nome
		 */
		if(sys_mkdir(nome, mode) == -1) return -1;
		
	// Se funciona, retorna 0
	return 0;
}
