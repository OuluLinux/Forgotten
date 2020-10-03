#include <stdio.h>

extern void fos_reboot();

int main(void)
{
    //printf("Rebooting Forgotten...\n");
    fos_reboot();
    return 0;
}
