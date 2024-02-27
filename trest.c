545645554
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main ()
// {
// 	int fd;
// 	fd = open ("fiel.txt", O_RDONLY | O_CREAT | O_APPEND);
// 	printf("the file D number is %d \n", fd);
// 	write(fd, "hello", 5);
// 	write(1, "hello", 5);
// 	return (0);
// }

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open a file for writing
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate file descriptor 1 (standard output) to the file descriptor we just opened
    if (dup2(file_descriptor, 1) == -1) {
        perror("Error duplicating file descriptor");
        return 1;
    }

    // Now, anything written to standard output will be directed to the file

    // Example output
    printf("545645554\n");

    // Close the file descriptor
    close(file_descriptor);

    return 0;
}
