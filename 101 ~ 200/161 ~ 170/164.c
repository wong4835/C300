#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void main(void)
{
    char pathname[_MAX_PATH] = "c:\\temp";

    if(_chdir(pathname) == 0)
    {
        _getcwd(pathname, _MAX_PATH);
        puts(pathname);
    }
}
