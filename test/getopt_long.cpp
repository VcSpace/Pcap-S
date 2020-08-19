#include<stdio.h>

#include <getopt.h>

#include<iostream>

#include<string>

#include<stdlib.h>

using namespace std;

void showUsage() {

  //cout << "Usage: " << PACKAGE_NAME << " [options] URL ..." << endl;

  cout << "Options:" << endl;

  cout << " -d, --dir=DIR              The directory to store downloaded file." << endl;

}

int main(int argc, char* argv[]) {

  bool stdoutLog = false;

  string logfile;

  string dir;

  string ufilename;

  int split = 0;

  bool daemonMode = false;

  int c;

  while(1) {

    int optIndex = 0;

    int lopt;

    static struct option longOpts[] = {

      { "daemon", no_argument, NULL, 'D' },

      { "dir", required_argument, NULL, 'd' },

      { "out", required_argument, NULL, 'o' },

      { "log", required_argument, NULL, 'l' },

      { "split", required_argument, NULL, 's' },

      { "http-proxy", required_argument, &lopt, 1 },

      { "http-user", required_argument, &lopt, 2 },

      { "http-passwd", required_argument, &lopt, 3 },

      { "http-proxy-user", required_argument, &lopt, 4 },

      { "http-proxy-passwd", required_argument, &lopt, 5 },

      { "http-auth-scheme", required_argument, &lopt, 6 },

      { "version", no_argument, NULL, 'v' },

      { "help", no_argument, NULL, 'h' },

      { 0, 0, 0, 0 }

    };

    c = getopt_long(argc, argv, "Dd:o:l:s:vh", longOpts, &optIndex);

    printf("返回值： %c\n",c);

    if(c == -1) {

      break;

    }

    switch(c) {

    case 0:{

      switch(lopt) {

      case 1: {

printf("1: %s\n",optarg);

break;

      }

      case 2:

printf("2: %s\n",optarg);

break;

      case 3:

printf("3: %s\n",optarg);

break;

      case 4:

printf("4: %s\n",optarg);

break;

      case 5:

printf("5: %s\n",optarg);

break;

      case 6:

printf("6: %s\n",optarg);

break;

      }

      break;

    }

    case 'D':

      printf("D: %s\n",optarg);

      break;

    case 'd':

      printf("d: %s\n",optarg);

      break;

    case 'o':

      printf("o: %s\n",optarg);

      break;

    case 'l':

    printf("l: %s\n",optarg);

      break;

    case 's':

      printf("s: %s\n",optarg);

      break;

    case 'v':

      printf("s: %s\n",optarg);

      //showVersion();

      exit(0);

    case 'h':

      showUsage();

      exit(0);

    default:

      showUsage();

      exit(1);

    }

  }

  return 0;

}
