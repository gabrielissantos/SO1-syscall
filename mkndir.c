// Qual biblioteca chama o sys_mkdir??
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/unistd.h>
#include <linux/string.h>

asmlinkage long sys_mkndir(const short int n, const char * nome, mode_t mode){
	int i;
	if(strlen(nome) >= 100 || n >= 999) return -1;

	char appended[100];
	char index[5];

	for(i = 0; i < n; i++){
		strcpy(appended, nome);
		sprintf(index, "(%d)", i+1);
		strcat(appended, index); //concatena
		// Por default, se mkdir nao funciona, retorna -1
		if(sys_mkdir(appended, mode) == -1) return -1;
	}
	// Se funciona, retorna 0
	return 0;
}