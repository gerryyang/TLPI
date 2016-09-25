#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf env;

static void func(int rvar, int vvar)
{
	printf("jump(): rvar[%d] vvar[%d]\n", rvar, vvar);
	longjmp(env, 1);
}

int main(int argc, char *argv[])
{
	register int rvar = 1;          
	volatile int vvar = 2;          

	if (setjmp(env) == 0) {
		rvar = 3;
		vvar = 4;
		func(rvar, vvar);

	} else {
		printf("after longjmp(): rvar[%d] vvar[%d]\n", rvar, vvar);
	}
	
	return 0;
}
