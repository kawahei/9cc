#include<stdio.h>
#include<stdlib.h>

int main( int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Wrong number of arguments.\n");
		return 1;
	}

	printf("	.arch armv8-a\n");
	printf("	.file	\"example.c\"\n");
	printf("	.text\n");
	printf("	.section	.text.startup,\"ax\",@progbits\n");
	printf("	.align	2\n");
	printf("	.global	main\n");
	printf("	.type	main, %%function\n");
	printf("main:\n");
	printf("	mov	w0, %d\n", atoi(argv[1]));
	printf("	ret\n");
	printf("	.size	main, .-main\n");
	printf("	.ident	\"GCC: (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) 7.5.0\"\n");
	printf("	.section	.note.GNU-stack,\"\",@progbits\n");

	return 0;
}
