#include "libft.h"
#include <unistd.h> // Required for write function


/// @brief Write a character to a file descriptor
/// 
/// This function writes the character `c` to the file descriptor `fd`.
/// 
/// @param c The character to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void ft_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}


#include <stdio.h>  // Library used in main for testing purposes
#include <fcntl.h>  // Required for open function in the test case
int main(void)
{
    // Test case: Write a character to standard output (stdout)
    printf("Writing to standard output: ");
    ft_putchar_fd('A', 1);  // Expected: A
    printf("\n");

    // Test case: Write a character to a file
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    ft_putchar_fd('B', fd);  // Expected: Write 'B' to the file "test_output.txt"
    close(fd);
    printf("Character 'B' written to 'test_output.txt'\n");

    return 0;
}