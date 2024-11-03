#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"

typedef struct {
    char* algorithm;
    char* fileName;
} args;

static int hash(const char* string, const char* algorithm, uint8_t* output, size_t len) {
    if (strcasecmp(algorithm, "MD5") == 0) {
        md5(string, output, len);
        return 0;
    } else if(strcasecmp(algorithm, "SHA-256") == 0) {
        sha256(string, output, len);
        return 0;
    }

    return -1;
}

static void help(const char* const program) {
    printf("Program usage: \n\n");
    printf("%s -f [file] -a [algorithm]\t\thash the file\n", program);
    printf("%s --help | -h\t\t\t\tvisualize this message\n", program);

    printf("\nSupported algorithms are MD5, SHA-256\n\n");
    return;
}

static args parseArguments(int argc, char* argv[]) {
    args arguments = {NULL, NULL};

    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            arguments.fileName = argv[i + 1];
        } else if(strcmp(argv[i], "-a") == 0 && i + 1 < argc) {
            arguments.algorithm = argv[i + 1];
        }
    }

    return arguments;
}

static inline void printHash(const uint8_t* p, int size) {
    for(int i = 0; i < size; ++i)
        printf("%02x", p[i]);

    printf("\n");
}

static char* readFile(const char* const fileName, size_t* const fileSize) {
    FILE* const fd = fopen(fileName, "r");

    if (fd == NULL) {
        *fileSize = 0;
        return NULL;
    }

    fseek(fd, 0, SEEK_END);
    *fileSize = ftell(fd);
    rewind(fd);
    
    char* buffer = (char *)malloc(*fileSize + 1);
    if(buffer == NULL) {
        fclose(fd);
        return NULL;
    }

    fread(buffer, sizeof(char), *fileSize,  fd);
    fclose(fd);

    buffer[*fileSize] = '\0';

    return buffer;
}

static inline int getHashLength(const char* algorithmType) {
    return strcasecmp(algorithmType, "MD5") == 0 ? 16 : 32;
}

int main(int argc, char* argv[]) {

    const args arguments = parseArguments(argc, argv); 

    if (argc != 5 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        help(argv[0]);
        return EXIT_FAILURE;
    }

    size_t fileSize;
    char* const fileContents = readFile(arguments.fileName, &fileSize);

    if (fileContents == NULL) {
        printf("Error: couldn't open %s\n", arguments.fileName);
        return EXIT_FAILURE;
    }

    const int hashLen = getHashLength(arguments.algorithm);
    uint8_t* const hashOutput = (uint8_t*)malloc(hashLen * sizeof(uint8_t));

    if(hashOutput == NULL) {
        free(fileContents);
        printf("Error: couldn't allocate enough memory needed for hash calculation.\n");

        return EXIT_FAILURE;   
    }

    printf("Hashing %s with %s...\n", arguments.fileName, arguments.algorithm);

    if(hash(fileContents, arguments.algorithm, hashOutput, fileSize) == 0) {
        printHash(hashOutput, hashLen);
    } else {
        printf("Error: invalid hashing algorithm.\n");
    }

    free(fileContents);
    free(hashOutput);

    return 0;
}
