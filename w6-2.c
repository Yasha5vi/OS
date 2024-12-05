// reader
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd,nbr;
	char ar[100];
	mknod("myfifo",S_IFIFO|0666,0);
	printf("Writing for reader process :\n\t");
	fd = open("myfifo",O_RDONLY);
	printf("If you got a writer process then type some data \n");
	do{
		nbr = read(fd,ar,sizeof(ar));
		ar[nbr] = '\0';
		printf("Reader process read %d bytes: %s\n",nbr,ar);
	}while(nbr > 0);
	return 0;
}
