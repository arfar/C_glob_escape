#include "globescape.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
int
main (void)
{
    char * string_to_escape;
    char * string_escaped;

    string_escaped = globescape((string_to_escape = "test"));
    if (0 != strcmp(string_escaped, "test"))
    {
        printf("Error with escaping %s, recieved %s, expected %s\n",
               string_to_escape, string_escaped, "test");
        goto cleanup;
    }
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "[]test"));
    if (0 != strcmp(string_escaped, "\\[]test"))
    {
        printf("Error with escaping %s, recieved %s, expected %s\n",
               string_to_escape, string_escaped, "\\[]test");
        goto cleanup;
    }
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "test[]"));
    if (0 != strcmp(string_escaped, "test\\[]"))
    {
        printf("Error with escaping %s, recieved %s, expected %s\n",
               string_to_escape, string_escaped, "test\\[]");
        goto cleanup;
    }
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "[test]"));
    if (0 != strcmp(string_escaped, "\\[test]"))
    {
        printf("Error with escaping %s, recieved %s, expected %s\n",
               string_to_escape, string_escaped, "\\[test]");
        goto cleanup;
    }
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "\\[test\\]"));
    if (0 != strcmp(string_escaped, "\\\\[test\\]"))
    {
        printf("Error with escaping %s, recieved %s, expected %s\n",
               string_to_escape, string_escaped, "\\\\[test]\\");
        goto cleanup;
    }

    printf("All tests passed\n");

cleanup:
    free(string_escaped);
}
