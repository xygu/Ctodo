#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include "ctodo.h"

const char * program_name;
static void print_usage (FILE * stream, int exit_code)
{
    fprintf (stream, "Usage: %s options [ inputfile ... ]\n", program_name);
    fprintf (stream, " -h --help .\n"
             " -o --output filename.\n"
             " -v --version.\n");
}

static void printf_invalid (void)
{
    printf ("Try '%s -h' or '%s --help'for more information.\n", program_name, program_name);
    exit(0);
}

void get_args (int argc, char * argv[])
{
    


    int next_option;

    const char* const short_options = "m:ho:v";
    const struct option long_options[] = {
        { "help", 0, NULL, 'h' },
        { "mem", 1, NULL, 'm'},
        { "output", 1, NULL, 'o' },
        { "version", 0, NULL, 'v' },
        { "NULL", 0, NULL, 0 },
    };
    const char * output_filename = NULL;
    const char * exp_name = NULL;
    program_name = argv[0];
    do
    {
        next_option = getopt_long (argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
        case 'h':
            print_usage (stdout, 0);
            break;
        case 'o':
            output_filename = optarg;
            execl ("/bin/cat", "cat", output_filename, NULL);
            break;
        case 'm':
            exp_name = optarg;
            mem_exp_exec(exp_name);
            break;
        case 'v':
            printf ("the version is v1.0\n");
            break;
        case ':':
            break;
        case '?':
            printf_invalid ();
            break;
        default:
            print_usage (stdout, 1);
            printf_invalid ();
            break;
        }
    }while (next_option !=-1);

}
