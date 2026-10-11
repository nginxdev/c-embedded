/*
 * Practice 3, variant 13: find and replace a character in a string
 * Author: Mykhailo Renkas, group IP-z41 <renkas.mykhailo_ipz41@edu.kpi.ua>
 */

#include <stdio.h>

enum { max_len = 255, max_ascii = 127 };

/* returns the length of the line, -1 if it is too long or not ASCII */
static int read_line(const char *prompt, char *buf)
{
    int c, len = 0;

    printf("%s", prompt);
    while ((c = getchar()) != EOF && c != '\n') {
        if (len == max_len || c > max_ascii)
            return -1;
        buf[len++] = c;
    }
    buf[len] = '\0';
    return len;
}

static int replace_char(char *s, char from, char to)
{
    int count = 0;

    for (; *s; s++)
        if (*s == from) {
            *s = to;
            count++;
        }
    return count;
}

int main(void)
{
    char str[max_len + 1], from[max_len + 1], to[max_len + 1];
    int count;

    printf("Practice 3, variant 13\n");
    printf("Author: Mykhailo Renkas, group IP-z41\n");
    if (read_line("Enter a string: ", str) < 0 ||
        read_line("Enter the character to find: ", from) != 1 ||
        read_line("Enter the replacement character: ", to) != 1)
    {
        fprintf(stderr, "Error: expected an ASCII string of at most %d "
                "characters, then two single characters\n", max_len);
        return 1;
    }
    count = replace_char(str, *from, *to);
    printf("Result: %s\n", str);
    printf("Replacements: %d\n", count);
    return 0;
}
