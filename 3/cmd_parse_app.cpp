#include <iostream>

#include <getopt.h>

#include <string>

#include <cstring>

using namespace std;

void stoupper(char * s) {
  for (;* s; s++)
    if (('a' <= * s) && ( * s <= 'z'))
      *
      s = 'A' + ( * s - 'a');
}

void stolower(char * s) {
  for (;* s; s++)
    if (('A' <= * s) && ( * s <= 'Z'))
      *
      s = 'a' + ( * s - 'A');
}

void reverse(char * str) {
  char * start = str;
  char * end = start + strlen(str) - 1;

  while (start < end) {
    char temp = * end;
    * end = * start;
    * start = temp;
    start++;
    end--;
  }
}

int main(int argc, char * argv[]) {
  int choice, index;
  const struct option long_options[] = {
    {
      "help",
      0,
      0,
      'h'
    },
    {
      "version",
      0,
      0,
      'v'
    },
    {
      "uppercase",
      1,
      0,
      'u'
    },
    {
      "reverse",
      1,
      0,
      'r'
    },
    {
      "lowercase",
      1,
      0,
      'l'
    },
    {
      0,
      0,
      0,
      0
    }
  };

  bool h_flag, v_flag, u_flag, l_flag, r_flag = false;

  while ((choice = getopt_long(argc, argv, "hvu:l:r:", long_options, & index)) != -1) {
    switch (choice) {
    case 'h': {
      if (!h_flag) {
        h_flag = true;
        printf("Usage: cmd_parse_app [OPTIONS]\n\n  -h, --help\n  -v, --version\n  -l TEXT, --lowercase\n  -u TEXT, --uppercase\n  -r TEXT, --reverse\n\n");
      }

      break;
    }

    case 'v': {
      if (!v_flag) {
        v_flag = true;
        printf("cmd_parse_app 0.1\n");
      }

      break;
    }

    case 'u': {
      if (!u_flag) {
        u_flag = true;
        stoupper(optarg);
        printf("%s\n", optarg);
      }

      break;
    }

    case 'r': {
      if (!r_flag) {
        r_flag = true;
        reverse(optarg);
        printf("%s\n", optarg);
      }

      break;
    }
    case 'l': {
      if (!l_flag) {
        l_flag = true;
        stolower(optarg);
        printf("%s\n", optarg);
      }

      break;
    }

    case '?':
      printf("Try 'cmd_parse_app --help' or 'cmd_parse_app -h' for more information\n");
      break;
    }

  }

  return 0;
}
