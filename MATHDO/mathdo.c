# include <stdio.h>
# include <stdlib.h>
int main(int argc, char const *argv[]){
	int p1 = fork();
	if(p1==0){
		printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
		execlp("python", "python","addition.py",argv[1],argv[2],NULL);
	}
	else{
		int p2 = fork();
		if(p2==0){
			printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
			execlp("java", "java","subtraction.java",argv[1],argv[2],NULL);
		}
		else{
			int p3 = fork();
			if(p3==0){
				printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
				execlp("node", "node","node.js",argv[1],argv[2],NULL);
			}
			else{
				int p4 = fork();
				if(p4==0){
					printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
					execlp("bash", "bash","division.sh",argv[1],argv[2],NULL);
				}
				else{
					wait(0);
					wait(0);
					wait(0);
					wait(0);
					printf("parent: done.\n");
				}
			}
		}
	}
	return 0;
}
