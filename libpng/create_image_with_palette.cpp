/*
 * A simple libpng example program
 * http://zarb.org/~gc/html/libpng.html
 *
 * Modified by Yoshimasa Niwa to make it much simpler
 * and support all defined color_type.
 *
 * To build, use the next instruction on OS X.
 * $ brew install libpng
 * $ clang -lz -lpng15 libpng_test.c
 *
 * Copyright 2002-2010 Guillaume Cottenceau.
 *
 * This software may be freely redistributed under the terms
 * of the X11 license.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <assert.h>
#include <time.h>
#include <vector>
/*
  param_layer_indices_.push_back(make_pair(layer_id, param_id));
  const pair<int, int>& owner_index =
  const pair<int, int>& owner_index =
  param_layer_indices_[owner_net_param_id];

  std::vector<std::pair<int, int> > param_layer_indices_;
*/
void write_png_file(char *filename, unsigned char *pixels, int width, int height) {
    png_byte color_type;
    png_byte bit_depth;
    png_bytep *row_pointers;


    //create file
    FILE *fp = fopen(filename, "wb");
    if(!fp) abort();

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();

    unsigned int paletteSize = 20;
    assert(paletteSize <= PNG_MAX_PALETTE_LENGTH);
    png_color* palette = (png_color*)png_malloc(png, paletteSize*sizeof(png));

    for (unsigned p = 0; p < paletteSize; p++) {
        png_color* col = &palette[p];
        col->red = 0;
        col->green = p*10; 
        col->blue = 0;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) abort();

    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    //png_set_strip_alpha(png_ptr);
    //png_read_update_info(png_ptr, info_ptr);

    // Output is 8bit depth, RGBA format.
    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_PALETTE,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    printf("rowbytes:%ld", png_get_rowbytes(png,info));
    png_set_PLTE(png, info, palette, paletteSize);
    png_write_info(png, info);

    //malloc pixel data
    row_pointers = (png_bytep*)malloc(sizeof(png_bytep)*height);
    for(int y = 0; y < height; y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
    }
    unsigned char *ptr = pixels;
    for(int y = 0; y < height; y++) {
        png_bytep row = row_pointers[y];
        for(int x = 0; x < width; x++) {
          png_bytep px = &(row[x * 1]);
          px[0] = *(ptr++);
          // Do something awesome for each pixel here...
          //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
        }
    }
    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    //free    
    for(int y = 0; y < height; y++) {
        free(row_pointers[y]);
    }
    free(row_pointers);

    png_destroy_write_struct(&png, &info);
    png_free(png, palette);
    fclose(fp);
}

int get_rand()
{
//随机数产生的范围      
    #define MIN 0    
    #define MAX 20
    return MIN+rand()%(MAX+MIN-1);
}

int main(int argc, char *argv[]) {
  if(argc != 2) abort();
  int width=500, height=200;
  unsigned char a[100000];
  srand((unsigned)time(NULL));  

  for(int y = 0; y < height; y++) {
      for(int x = 0; x < width; x++) {
          a[y*width+x] = get_rand();
      }
  }

  write_png_file(argv[1], a, width, height);

  return 0;
}
