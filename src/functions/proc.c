#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    char path[64];
    snprintf(path, sizeof(path), "/proc/%s/status", argv[1]);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        fprintf(stderr, "Could not open %s (does PID %s exist?)\n", path, argv[1]);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Only print the fields we care about
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "VmRSS:", 6) == 0 ||
            strncmp(line, "Threads:", 8) == 0) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
