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
    printf("%s -> %s\n", string_to_escape, string_escaped);
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "[]test"));
    printf("%s -> %s\n", string_to_escape, string_escaped);
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "test[]"));
    printf("%s -> %s\n", string_to_escape, string_escaped);
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "[test]"));
    printf("%s -> %s\n", string_to_escape, string_escaped);
    free(string_escaped);

    string_escaped = globescape((string_to_escape = "\\[test\\]"));
    printf("%s -> %s\n", string_to_escape, string_escaped);
    free(string_escaped);

    char * buffer = malloc(sizeof(char)*100);
    globescape_buffer((string_to_escape = "\\[test\\]"), buffer);
    printf("%s -> %s\n", string_to_escape, buffer);

    strcpy(buffer, "test");
    string_escaped = globescape_inplace(buffer);
    printf("%s -> %s\n", "test", buffer);

    strcpy(buffer, "[]test");
    string_escaped = globescape_inplace(buffer);
    printf("%s -> %s\n", "[]test", buffer);

    strcpy(buffer, "test[]");
    string_escaped = globescape_inplace(buffer);
    printf("%s -> %s\n", "test[]", buffer);

    strcpy(buffer, "[test]");
    string_escaped = globescape_inplace(buffer);
    printf("%s -> %s\n", "[test]", buffer);

    strcpy(buffer, "\\[test\\]");
    string_escaped = globescape_inplace(buffer);
    printf("%s -> %s\n", "\\[test\\]", buffer);
}
