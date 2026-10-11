/*
 * Practice 4: the Harry Potter book series in a linked list
 * Author: Mykhailo Renkas, group IP-z41 <renkas.mykhailo_ipz41@edu.kpi.ua>
 */

#include <stdio.h>

struct book {
    const char *title;
    double price;
    int pages;
    const char *language;
    double weight;
    int year;
    struct book *next;
};

static struct book book7 = {
    "Harry Potter and the Deathly Hallows",
    9.99, 607, "English", 0.56, 2007, NULL
};
static struct book book6 = {
    "Harry Potter and the Half-Blood Prince",
    9.99, 607, "English", 0.56, 2005, &book7
};
static struct book book5 = {
    "Harry Potter and the Order of the Phoenix",
    9.99, 766, "English", 0.70, 2003, &book6
};
static struct book book4 = {
    "Harry Potter and the Goblet of Fire",
    9.99, 636, "English", 0.60, 2000, &book5
};
static struct book book3 = {
    "Harry Potter and the Prisoner of Azkaban",
    8.99, 317, "English", 0.33, 1999, &book4
};
static struct book book2 = {
    "Harry Potter and the Chamber of Secrets",
    8.99, 251, "English", 0.28, 1998, &book3
};
static struct book book1 = {
    "Harry Potter and the Philosopher's Stone",
    8.99, 223, "English", 0.25, 1997, &book2
};

int main(void)
{
    const struct book *b;

    printf("Practice 4: the Harry Potter book series\n");
    printf("Author: Mykhailo Renkas, group IP-z41\n\n");
    printf("%-41s %5s %5s %-8s %6s %4s\n",
           "Title", "Price", "Pages", "Language", "Weight", "Year");
    for (b = &book1; b != NULL; b = b->next)
        printf("%-41s %5.2f %5d %-8s %6.2f %4d\n", b->title, b->price,
               b->pages, b->language, b->weight, b->year);
    return 0;
}
