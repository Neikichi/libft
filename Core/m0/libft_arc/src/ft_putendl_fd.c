#include "libft.h"


/// @brief Write a string followed by a newline to a file descriptor
/// 
/// This function writes the string `s` to the file descriptor `fd`, followed by a newline character.
/// 
/// @param s The string to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void ft_putendl_fd(char *s, int fd)
{
  ft_putstr_fd(s, fd);
  ft_putchar_fd('\n', fd);
}


/*#include <stdio.h>*/
/*#include <fcntl.h>*/
/*int main(void)*/
/*{*/
/*    printf("Writing to standard output: ");*/
/*    ft_putendl_fd("Hello, world!", 1);*/
/**/
/*    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);*/
/*    if (fd == -1)*/
/*    {*/
/*        perror("Error opening file");*/
/*        return (1);*/
/*    }*/
/*    ft_putendl_fd("This is the first line.", fd);*/
/*    ft_putendl_fd("This is the second line.", fd);*/
/*    ft_putendl_fd("This is the third line.", fd);*/
/*    close(fd);*/
/*    printf("String written to 'test_output.txt'\n");*/
/**/
/*    return 0;*/
/*}*/
