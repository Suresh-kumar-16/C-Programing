CLIENT:
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERV_TCP_PORT 5035
#define MAX 4096 // Increased buffer size for better efficiency

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send[MAX], recvline[MAX];
    char name[MAX];

    // Check if source file name is provided as argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_filename>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Get source file name from command line argument
    strcpy(name, argv[1]);

    // Send the source file name to the server
    write(sockfd, name, strlen(name) + 1); // Include null terminator in the message

    // Receive and print the response from the server
    while ((n = read(sockfd, recvline, MAX - 1)) > 0) {
        recvline[n] = '\0'; // Null-terminate the received data
        printf("%s", recvline);
    }

    // Check if read encountered an error
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
