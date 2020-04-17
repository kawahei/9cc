#include<stdio.h>
#include<stdlib.h>

int main( int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Wrong number of arguments.\n");
		return 1;
	}

	char *p = argv[1];

	printf("	.arch armv8-a\n");
	printf("	.text\n");
	printf("	.section	.text.startup,\"ax\",@progbits\n");
	printf("	.align	2\n");
	printf("	.global	main\n");
	printf("	.type	main, %%function\n");
	printf("main:\n");
	printf("	mov	w0, %ld\n", strtol(p, &p, 10));
	while(*p) {
		if(*p == '+') {
			p++;
			printf("	add	w0, w0, %ld\n", strtol(p, &p, 10));
			continue;
		}
		if(*p == '-') {
			p++;
			printf("	sub	w0, w0, %ld\n", strtol(p, &p, 10));
			continue;
		}
		fprintf(stderr, "unexpected character : '%c'\n", *p);
		return 1;
	}
	printf("	ret\n");
	printf("	.size	main, .-main\n");
	printf("	.section	.note.GNU-stack,\"\",@progbits\n");

	return 0;
}
