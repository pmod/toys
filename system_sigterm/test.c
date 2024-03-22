

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int32_t result;
    //const char* cmd = "./test_not_found.sh";
    //const char* cmd = "./test_loop.sh";
    //const char* cmd = "./test_sleep.sh";
    //const char* cmd = "./test_exit_77.sh";
    //const char* cmd = "./test_no_perm.sh";
    //const char* cmd = "./test_ok.sh";
    //const char* cmd = "-xxx"; // UB ???
    //const char* cmd = " "; // neat: exit ok!
    //const char* cmd = "false"; //
    //const char* cmd = "kill -9 $$"; //
    //const char* cmd = "(exit 77)"; //
    const char* cmd = "/bin/sh -c \"exit 88\""; //

    result = system(cmd);
    if (result != 0) {
        if (WIFEXITED(result)) {
            printf("exit with %d\n", WEXITSTATUS(result));
        } else if (WIFSIGNALED(result)) {
            printf("killed by signal %d\n", WTERMSIG(result));
        }

        printf("Failed to execute %s, result %d\n",
                cmd, result);

    } else {
        printf("Exit ok!\n");
    }


    return 0;
}