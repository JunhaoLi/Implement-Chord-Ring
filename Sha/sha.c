/*
 *  sha.cpp
 *
 *  Copyright (C) 1998, 2009
 *  Paul E. Jones <paulej@packetizer.com>
 *  All Rights Reserved
 *
 *****************************************************************************
 *  $Id: sha.c 12 2009-06-22 19:34:25Z paulej $
 *****************************************************************************
 *
 *  Description:
 *      This utility will display the message digest (fingerprint) for
 *      the specified file(s).
 *
 *  Portability Issues:
 *      None.
 */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
#include <io.h>
#endif
#include <fcntl.h>
#include "sha1.h"


void usage()
{
	printf("usage: sha <file> [<file> ...]\n");
	printf("\tThis program will display the message digest\n");
	printf("\tfor files using the Secure Hashing Algorithm (SHA-1).\n");
}

void SHA_1(char *c,unsigned result[5])
{
    SHA1Context sha;                /* SHA-1 context                 */
    FILE        *fp;                /* File pointer for reading files*/
   // char        c;                  /* Character read from file      */
    int         i;                  /* Counter                       */
    int         reading_stdin;      /* Are we reading standard in?   */
    int         read_stdin = 0;     /* Have we read stdin?           */
	
	if (c == NULL || strlen(c) == 0){
		fprintf(stderr, "Empty string.");
		return;
	}
	SHA1Reset(&sha);
	SHA1Input(&sha, c, 1);

	if (!SHA1Result(&sha))
	{
		fprintf(stderr,
			"sha: could not compute message digest for %s\n",c);
	}
    else
	{
            /*printf( "%08X %08X %08X %08X %08X - %s\n",
                    sha.Message_Digest[0],
                    sha.Message_Digest[1],
                    sha.Message_Digest[2],
                    sha.Message_Digest[3],
                    sha.Message_Digest[4],
                   c);*/
			result[0] = sha.Message_Digest[0];
			result[1] = sha.Message_Digest[1];
			result[2] = sha.Message_Digest[2];
			result[3] = sha.Message_Digest[3];
			result[4] = sha.Message_Digest[4];
        }


    }

int main(int argc, char *argv[])
{
	
	if (argc != 2){
	  fprintf(stderr,"Wrong arguments!quit");
	  return;
	}
	unsigned result[5];
	SHA_1(argv[1],result);

	printf("%08X %08X %08X %08X %08X - %s\n",result[0],result[1],result[2],result[3],result[4],argv[1]); 
	system("pause");
	return 0;
}
