#include <stdio.h>
#include <string.h>

int main() {
    // Must be a mutable character array, NOT a string literal
    char str[] = "cd -1 /home/dinesh-p/"; 
    const char delims[] = " ";
    
    // First call: pass the source string
    char *token = strtok(str, delims);
    
    // Loop through the remaining tokens
        printf("Token: %s\n", token);
        
        // Subsequent calls: pass NULL
        token = strtok(NULL, delims);

	printf("Token: %s\n", token);

	token = strtok(NULL, delims);

	printf("Tokens: %s\n", token);

    
    return 0;
}

