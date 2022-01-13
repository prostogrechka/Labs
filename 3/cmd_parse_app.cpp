#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]) {
    // -f, --force
    // -h, --help
    // -v, --value
    // -L, --list=LIST

    int rez, index;

    const struct option longopts[] = {
        {"force", 0, 0, 'f'},
        {"help", 0, 0, 'h'},
        {"version", 0, 0, 'v'},
        {"list", 1, 0, 'L'},
        {0, 0, 0, 0}
    };

    bool f_flag, h_flag, v_flag, L_flag = false;

    while ((rez = getopt_long(argc, argv, "fhvL:", longopts, &index)) != -1) {
        switch (rez) {
            case 'f': {
                if (!f_flag) {
                    f_flag = true;
                    printf("force\n");
                }

                break;
            }

            case 'h': {
                if (!h_flag) {
                    h_flag = true;
                    printf("Usage: cmd_parse_app [OPTIONS]\n\n  -f, --force\n  -h, --help\n  -v, --version\n  -L, --list=LIST\n\n"); 
                }

                break;
            }

            case 'v': {
                if (!v_flag) {
                    v_flag = true;
                    printf("cmd_parse_app 1.0.0\n"); 
                }

                break;
            }

            case 'L': {
                if (!L_flag) {
                    L_flag = true;
                    printf("list = %s\n", optarg);
                }

                break;
            }

            case '?': printf("Try 'cmd_parse_app --help' or 'cmd_parse_app -h' for more information\n"); break;
        }
    }

    return 0;
}	
