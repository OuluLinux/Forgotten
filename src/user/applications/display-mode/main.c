#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fos_config.h>

void usage()
{
    printf("display-mode: List and select the Forgotten display modes.\n");
    printf("usage:\tdisplay-mode list\n");
    printf("\tdisplay-mode select <width>x<height>x<depth>\n");
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        usage();
        exit(1);
    }
/*
    char buf[256];
    int result;
    unsigned int width, height, depth;

    if(argc == 2 && !strcmp(argv[1], "list"))
    {
        result = fos_config_query("select * from 'display_modes'");
        if (result == -1)
            fprintf(stderr, "Unable to get the modes.\n");

        if (fos_config_was_successful(result) != 0)
        {
            fos_config_get_error_message(result, buf, 256);
            fprintf(stderr, "Error: %s\n", buf);
            return 1;
        }

        if (fos_config_numrows(result) == 0)
            printf("No modes\n");
        else
            while (fos_config_nextrow(result) == 0)
                printf("Display[%d]: Mode %dx%dx%d\n", fos_config_getnum_s(result, "display_id"), fos_config_getnum_s(result, "width"), fos_config_getnum_s(result, "height"), fos_config_getnum_s(result, "depth"));

        fos_config_freeresult(result);

    }
    else if(argc == 3 && !strcmp(argv[1], "select"))
    {
        if(sscanf(argv[2], "%dx%dx%d", &width, &height, &depth) == 3)
        {
            sprintf(buf, "select * from 'display_modes' where width = %d and height = %d and depth = %d and display_id = 0", width, height, depth);
            result = fos_config_query(buf);
            memset(buf, 0, 256);
            if (result == -1)
                fprintf(stderr, "Unable to get the mode.\n");

            if (fos_config_was_successful(result) != 0)
            {
                fos_config_get_error_message(result, buf, 256);
                fprintf(stderr, "Error: %s\n", buf);
                return 1;
            }

            if (fos_config_numrows(result) == 0 || fos_config_nextrow(result) != 0)
            {
                fos_config_freeresult(result);
                printf("No such mode\n");
            }
            else
            {
                memset(buf, 0, 256);
                sprintf(buf, "update displays set mode_id = %d where id = 0", fos_config_getnum_s(result, "mode_id"));
                fos_config_freeresult(result);
                printf("Setting mode %dx%dx%d...\n", width, height, depth);
                result = fos_config_query(buf);
                memset(buf, 0, 256);
                if (result == -1)
                    fprintf(stderr, "Unable to set the mode.\n");

                if (fos_config_was_successful(result) != 0)
                {
                    fos_config_get_error_message(result, buf, 256);
                    fprintf(stderr, "Error: %s\n", buf);
                    return 1;
                }
                fos_config_freeresult(result);
            }
        }
        else
        {
            usage();
            exit(1);
        }
    }
    else
    {
        usage();
        exit(1);
    }

    exit(0);*/
}
