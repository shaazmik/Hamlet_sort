#include "Hamlet.h"

//{
size_t count_line_in_text(FILE *in)
{
    if (!in) return -1;

    char not_used[100] = "";

    int quantity_lines = 0;

    while (fgets(not_used, 100, in) != NULL)
        quantity_lines++;

    return quantity_lines;
}


size_t find_file_size(FILE *in)
{

    assert (in != NULL);

    int size_of_file = 0;

    fseek (in, 0, SEEK_END);

    size_of_file = ftell (in);

    fseek (in, 0, SEEK_SET);

    return (size_of_file);
}
//}

//{
char* fill_text(FILE* in, size_t file_size)
{
    assert(in != NULL);

    char* text_array = (char*) calloc(file_size, sizeof(char));

    fread(text_array, sizeof(char), file_size, in);

    return text_array;
}

struct Line* navigation_in_line(struct Line* str_array, *char text_array, size_t quantity_lines)
{
    assert(text_array != NULL);
    assert(str_array != NULL);

    struct Line* str_array = (struct Line*) calloc(quantity_lines, sizeof(struct Line))

    char* pointer_start = text_array;
    char* pointer_ne_start = text_array;

    for (int i = 0; i < quantity_lines; i++)
    {
        pointer_ne_start = strchr(pointer_start, '\n');

        *pointer_ne_start = '\0';

        str_array[i].start_line = pointer_start;
        str_array[i].len = pointer_ne_start - pointer_start + 1;

        pointer_start = pointer_ne_start + 2; // +2 because in win10 end of line has \r symbol.
    }
    return str_array;
};
//}


//{
void zapuskTRTRv2(FILE* in, struct Text* Denmark_sht)
{
    assert(in != NULL);
    assert(Denmark_sht != NULL);

    Denmark_sht->size_of_text = find_file_size(in);
    Denmark_sht->quantity_lines = count_line_in_text(in);
    Denmark_sht->text_array = fill_text(in, Denmark_sht->size_of_text);
    Denmark_sht->linii = navigation_in_line(Denmark_sht->linii, Denmark_sht->text_array, Denmark_sht->quantity_lines);

    return;
}


void VJUXv2(FILE* out, const struct Text* Denmark_sht)
{
    assert(in != NULL);
    assert(Denmark_sht != NULL);

    for (int num_of_line = 0; num_of_line < Denmark_sht->quantity_lines, i++)  //
    {
        fputs(Denmark_sht->linii[num_of_line].start_line, out);
        fputc('\n', out);
    }
}
//}


int main()
{
    struct Text Denmark_sht = {};

    FILE *in = fopen ("Hamlet.bin", "r");

    zapuskTRTRv2(in, &Denmark_sht);

    //printf ("%d  %d", find_file_size(in), count_line_in_text(in));//171509

    fclose(in);
}
