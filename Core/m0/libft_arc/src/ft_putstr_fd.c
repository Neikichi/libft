#include "libft.h"

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
    ft_putchar_fd(*s, fd);
    s++;
  }
}

/*#include <fcntl.h>*/
/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    printf("Writing to standard output: ");*/
/*    ft_putstr_fd("Hello, world!", 1);*/
/*    printf("\n");*/
/**/
/*    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);*/
/*    if (fd == -1)*/
/*    {*/
/*        perror("Error opening file");*/
/*        return (1);*/
/*    }*/
/*    ft_putstr_fd("This is a test string.", fd);*/
/*    close(fd);*/
/*    printf("String written to 'test_output.txt'\n");*/
/**/
/*    return 0;*/
/*}*/
