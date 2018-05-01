// Qual biblioteca chama o sys_mkdir??
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/unistd.h>
#include <linux/string.h>

int contaDigitos(const int n);

asmlinkage long sys_mkndir(const short int n, const char * nome, mode_t mode){
	int i;
	int len = strlen(nome);
	char * appended = (char*) malloc (len+1);
	char * index;

	for(i = 0; i < n; i++){
		strcpy(appended, nome);
		index = (char*) malloc (contaDigitos(i)+2);
		sprintf(index, "(%d)", i+1);
		strcat(appended, index); //concatena
		free(index);
		// Por default, se mkdir nao funciona, retorna -1
		if(sys_mkdir(appended, mode) == -1) return -1;
	}
	free(appended);
	// Se funciona, retorna 0
	return 0;
}

int contaDigitos(const int n){
	int aux = n;
	int d = 1;
	while(aux / 10 > 1){
		d++;
		aux = aux / 10;
	}
	return(d);
};
