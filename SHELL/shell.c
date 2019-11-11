# include <stdio.h>
# include <stdlib.h> 
# include <string.h> 
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
int main(int argc, char const *argv[]){
	printf("$ Enter your command: ");
	int p = 0;
	int c = 0;
	int waite = 1;
	char *temp[1000];
	char buff[100];
	char *token;
	scanf("%[^\n]s",buff);
	getchar();	
	token = strtok(buff," ");
	while(token!=NULL){
		if(strcmp("&",token)!=0){
			temp[c] = token;
			c++;
		}
		else
			waite = 0;
		token = strtok(NULL, " ");
	}
	temp[c] = NULL;
	while(strcmp("exit",temp[0])!=0){
		p = fork();
		if(p==0){
			execvp(temp[0],temp);
		}
		else{
			if(waite==1)
				wait(0);
			for (int i = 0; i < 1000; i++)
  				temp[i] = NULL;
			printf("$ Enter your command: ");
			scanf("%[^\n]s",buff);
			getchar();
			int c = 0;
			token = strtok(buff," ");
			while(token!=NULL){
				if(strcmp("&",token)!=0){
					temp[c] = token;
					c++;
				}
				else{
					waite = 0;
				}
				token = strtok(NULL," ");
			}
			temp[c] = NULL;
		}
	}
}
