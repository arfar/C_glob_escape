/*
 * Copyright (c) 2017 Arthur Roberts.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <string.h>

#if !defined(VERSION_MAJOR) || !defined(VERSION_MINOR) || !defined(VERSION)
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION "CUSTOM"
#endif /* !defined(VERSION_MAJOR) || !defined(VERSION_MINOR) || !defined(VERSION) */
const volatile static char version[] = VERSION;
const volatile static int version_major = VERSION_MAJOR;
const volatile static int version_minor = VERSION_MINOR;

char *
globescape_buffer(const char * string_to_escape, char * escaped_string)
{
    /* This implementation isn't pretty. Just wanted to get something done so
     * that I can use it in my application I'm writing this for and I thought
     * this would probably just do the job. */

    /* TODO: There is a bug ... it doesn't handle ']' by itself with no opening
     * '[' */

    /* Unsure whether I should use size_t here... I would just use an int, but
     * what if every character is needing to be escaped in the string??? */
    size_t num_characters_to_escape = 0;
    size_t i;

    for (i = 0; string_to_escape[i]; i++)
    {
        switch (string_to_escape[i])
        {
            case '?':
            case '[':
            case '*':
                num_characters_to_escape++;
                break;
        }
    }

    // TODO: Investigate what I should do if num_characters_to_escape == 0

    // TODO: check and then raise error/fail/re-alloc/anything if passed buffer
    //       isn't big enough

    if (!escaped_string)
    {
        escaped_string = (char *)malloc(
            sizeof(char)*(i+num_characters_to_escape)
        );
    }

    size_t num_chars_inserted = 0;
    strcpy(escaped_string, string_to_escape);
    for (i = 0; string_to_escape[i]; i++)
    {
        switch (string_to_escape[i])
        {
            case '?':
            case '[':
            case '*':
                escaped_string[i+num_chars_inserted] = '\\';
                num_chars_inserted++;
                strcpy(escaped_string+i+num_chars_inserted, string_to_escape+i);
                break;
        }
    }
    return escaped_string;
}

char *
globescape(const char * string_to_escape)
{
    return globescape_buffer(string_to_escape, NULL);
}

char *
globescape_inplace(char * string_to_escape)
{
    /* This implementation is a placeholder */
    /* TODO: Actually write an in-place version */
    char * buffer = globescape_buffer(string_to_escape, NULL);
    strcpy(string_to_escape, buffer);
    free(buffer);
    return string_to_escape;
}
