#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int mib = argc > 1 ? atoi(argv[1]) : 50;
    printf("allocating %d MiB...\n", mib);
    fflush(stdout);
    
    char *p = malloc(mib * 1024 * 1024);
    if (!p) { printf("malloc failed\n"); return 1; }
    
    /* touch every page so RSS actually goes up */
    memset(p, 0xAB, mib * 1024 * 1024);
    printf("allocated %d MiB, sleeping...\n", mib);
    fflush(stdout);
    
    sleep(120);
    free(p);
    return 0;
}