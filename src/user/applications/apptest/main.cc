#ifdef X86

#include <types.h>
#include <test.h>

#include <stdio.h>
#include <string.h>
#include <alloca.h>

#include <iostream>

using namespace std;

#include <graphics/Graphics.h>

ForgottenGraphics::Framebuffer *pRootFramebuffer = 0;
ForgottenGraphics::Framebuffer *pFramebuffer = 0;

int main(int argc, char **argv)
{
    printf("Userspace graphics framework test!\n");
    
    // Connects to the display automatically
    pRootFramebuffer = new ForgottenGraphics::Framebuffer();
    pFramebuffer = pRootFramebuffer->createChild(64, 64, 128, 128);
    
    // Check for a valid framebuffer (will return null on error)
    if(!pFramebuffer->getRawBuffer())
    {
        printf("Couldn't get a valid framebuffer.\n");
        return 0;
    }
    
    // Draw a red rectangle
    pFramebuffer->rect(0, 0, 128, 128, 0xff0000, ForgottenGraphics::Bits24_Rgb);
    pFramebuffer->redraw(0, 0, 128, 128, true);
    
    printf("Should now be a red square on the screen.\n");
    
    cout << "C++ output for the win!" << endl;
    
    return 0;
}

#else

// Architectures which don't support the native interface will pretend :)

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Boring old printf works... No native API on this architecture yet");
    return 0;
}

#endif
