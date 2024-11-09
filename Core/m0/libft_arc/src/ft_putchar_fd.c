#include "libft.h"
#include <unistd.h>


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


/*#include <stdio.h>*/
/*#include <fcntl.h>*/
/*int main(void)*/
/*{*/
/*    printf("Writing to standard output: ");*/
/*    ft_putchar_fd('A', 1);*/
/*    printf("\n");*/
/**/
/*    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);*/
/*    if (fd == -1)*/
/*    {*/
/*        perror("Error opening file");*/
/*        return (1);*/
/*    }*/
/*    ft_putchar_fd('B', fd);*/
/*    close(fd);*/
/*    printf("Character 'B' written to 'test_output.txt'\n");*/
/**/
/*    return 0;*/
/*}*/
