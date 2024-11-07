#include "libft.h"
#include <unistd.h> // Required for write function


/// @brief Write a string to a file descriptor
/// 
/// This function writes the string `s` to the file descriptor `fd`.
/// 
/// @param s The string to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void ft_putstr_fd(char *s, int fd)
{
  while (*s)
  {
    write(fd, &*s, 1);
    s++;
  }
}

#include <fcntl.h>  // Required for open function in the test case
#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: Write a string to standard output (stdout)
    printf("Writing to standard output: ");
    ft_putstr_fd("Hello, world!", 1);  // Expected: Hello, world!
    printf("\n");

    // Test case: Write a string to a file
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    ft_putstr_fd("This is a test string.", fd);  // Expected: Write to the file "test_output.txt"
    close(fd);
    printf("String written to 'test_output.txt'\n");

    return 0;
}