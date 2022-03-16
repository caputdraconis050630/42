#include "bsq.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    // argv[1] = FileName
    int fd; // File Descriptor

    fd = open(argv[1], O_RDONLY);
    if (fd <= 0 )
    {
        ft_putstr("Fail To Open File\n");
    }
    else
    {
        // If map has just one line(expected ans : 1)
        // Map has zero space(density : 100, expected ans : 0)
        
    }
    return (0);
}