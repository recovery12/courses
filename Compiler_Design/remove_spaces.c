#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        1024

/********* FUNCTION DECLARATION *********/
bool is_empty(FILE *fp);
void rm_comments(FILE *ifp, FILE *ofp);
void rm_comments_mul(FILE *ifp, FILE *ofp);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    char       *ifile, *ofile;
    FILE       *ifp = NULL, *ofp = NULL;

    if (argc != 3)
    {
        fprintf(stderr, "Syntax: ./%s <in-name> <out-file>\n", argv[0]);
        exit(1);
    }

    ifile = argv[1];
    ofile = argv[2];

    ifp = fopen(ifile, "r");

    if (ifp == NULL)
    {
        printf("File does not exist\n");
        printf("Or it may not have the required permissions\n");
        exit(2);
    }

    ofp = fopen(ofile, "w");

    rm_comments(ifp, ofp);
    ifp = fopen(ifile, "r");
    ofp = fopen(ofile, "w");
    rm_comments_mul(ifp, ofp);

    exit(0);
}

/********* FUNCTION DEFINITION *********/
bool is_empty(FILE *fp)
{
    char       check;

    check = fgetc(fp);
    rewind(fp);
    if (check == EOF)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void rm_comments(FILE *ifp, FILE *ofp)
{
    int        i, j;
    bool       is_comment, cond1, cond2;
    char       outline[MAX], line[MAX];

    if (is_empty(ifp))
    {
        printf("The given input file is an empty file\n");
        exit(3);
    }

    while (fgets(line, MAX, ifp))
    {
        i = 0, j = 0;
        is_comment = false;
        outline[i] = '\0';
        while (line[i] != '\n')
        {
            if (!is_comment)
            {
                cond1 = (line[i] == '/' && line[i+1] == '/');
                cond2 = (line[i] == '/' && line[i+1] == '*');
                if (line[i] == '/' && line[i+1] == '/')
                {
                    is_comment = true;
                }
                else if (line[i] == '/' && line[i+1] == '*')
                {
                    is_comment = true;
                }
                else
                {
                    outline[j] = line[i];
                    j = j + 1;
                }
            }
            i = i + 1;
        }
        outline[j] = '\0';
        if (strlen(outline) != 0)
        {
            fprintf(ofp, "%s\n", outline);
        }
    }

    fclose(ifp);
    fclose(ofp);

    return ;
}

void rm_comments_mul(FILE *ifp, FILE *ofp)
{
    int        i, j;
    bool       is_comment = false;
    char       outline[MAX], line[MAX];

    if (is_empty(ifp))
    {
        printf("The given input file is an empty file\n");
        exit(3);
    }

    while (fgets(line, MAX, ifp))
    {
        i = 0, j = 0;
        outline[i] = '\0';
        while (line[i] != '\0')
        {
            if (!is_comment)
            {
                if (line[i] == '/' && line[i+1] == '*')
                {
                    is_comment = true;
                }
                else
                {
                    outline[j] = line[i];
                    j = j + 1;
                }
            }
            else
            {
                if (line[i] == '*' && line[i+1] == '/')
                {
                    is_comment = false;
                    i = i + 1;
                }
            }
            i = i + 1;
        }
        outline[j] = '\0';
        printf("%s is line %ld\n", line, strlen(outline));
        if (strlen(outline) != 0)
        {
            fprintf(ofp, "%s\n", outline);
        }
    }

    fclose(ifp);
    fclose(ofp);

    return ;
}