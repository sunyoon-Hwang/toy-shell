#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#define MAX_LEN_LINE    100
#define LEN_HOSTNAME    30

#ifndef _MAX_PATH
#define _MAX_PATH 	260
#endif

int parse_background(char *cmd);

int main(void) {
    char command[MAX_LEN_LINE];
    char *arg1, *arg2, *arg3;
    char *args[] = {command, arg1, arg2, arg3, NULL};
    int ret, status;
    pid_t pid, cpid;

    char hostname[LEN_HOSTNAME + 1];
    memset(hostname, 0x00, sizeof(hostname));
    gethostname(hostname, LEN_HOSTNAME);

    while (true) {
        char *s;
        int len;
        bool cd = false;

	char strBuffer[_MAX_PATH] = { 0, };
	char *pstrBuffer = NULL;
	pstrBuffer = getcwd( strBuffer, _MAX_PATH );
	char bin[30] = "/bin/";

        printf("\033[92m%s@%s\033[0m:\033[94m%s\033[0m$ ",getpwuid(getuid())->pw_name,hostname,pstrBuffer);
        s = fgets(command, MAX_LEN_LINE, stdin);
        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        
        len = strlen(command);
        printf("%d\n", len);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }

    	if(!strcmp(command,"exit")){
	    	printf("program exit!\n");
		exit(0);
    	}

	arg1 = strtok(command," ");

    	if(!strcmp(arg1,"cd")){
	    	cd = true;
		arg1 = strtok(NULL, " ");
		if(chdir(arg1)<0){
		    printf("ERROR : Inexistence Directory [%s].\n",arg1);
		    continue;
		}
		else{
		    printf("change directory successfully!\n");
		    continue;
		}
	 }

        printf("[%s]\n\n", command);

	if(!cd) {
	    pid = fork();
	    if (pid < 0) {
       	        fprintf(stderr, "fork failed\n");
         	    exit(1);
            }
       	    if (pid != 0) {  /* parent */
          	    cpid = waitpid(pid, &status, 0);
           	    if (cpid != pid) {
                    fprintf(stderr, "waitpid failed\n");
           	    }
                printf("\nChild process terminated\n");
        	    if (WIFEXITED(status)) {
              	    printf("Exit status is %d\n", WEXITSTATUS(status));
        	    }
       	    }
	        else {	/* child */
		        strcat(bin,arg1);
        		arg1 = bin;
	        	args[0] = arg1;
   		    	args[1] = strtok(NULL," ");
    		        args[2] = strtok(NULL," ");
    	    		args[3] = strtok(NULL," ");
	    
		        ret = execve(args[0], args, NULL);
   			    if (ret < 0) {
            	    fprintf(stderr, "execve failed\n");
               	    return 1;
   			    }
   		    }
	    }
    }	
    return 0;
}
