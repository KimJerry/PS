#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int status;
    pid_t pid = fork();
    
    if(pid == 0) {
        sleep(15);
        return 24;
    }
    else {
        while(!waitpid(-1, &status, WNOHANG)) {
            sleep(3);
            puts("sleep 3sec.");
        }
        if(WIFEXITED(status))
            printf("Child sned %d \n", WEXITSTATUS(status));
    }
    return 0;
}