#ifndef HAMLET_H
#define HAMLET_H

#include "TXLib.h"
#include "string.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"



//=================================

struct Line
    {
        char* start_line;
        size_t size_of_line;
    };


struct Text
    {
        size_t quantity_lines;
        size_t size_of_text;
        char * text_array;
        struct Line* linii;
    };


size_t count_line_in_text(FILE *in);


size_t find_file_size(FILE *in);


char* fill_text(FILE* in, size_t file_size);


struct Line* navigation_in_line(struct Line* str_array, *char text_array, size_t quantity_lines);


void zapuskTRTRv2(FILE* in, struct Text* Denmark_sht);


void VJUXv2(FILE* out, const struct Text* Denmark_sht);


#endif // HAMLET_H
