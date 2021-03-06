#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>

cv::Mat readPng(char *filename) {
    int width, height;
    png_byte color_type;
    png_byte bit_depth;
    png_bytep *row_pointers;

  FILE *fp = fopen(filename, "rb");

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();

  png_infop info = png_create_info_struct(png);
  if(!info) abort();

  if(setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  png_read_info(png, info);

  width      = png_get_image_width(png, info);
  height     = png_get_image_height(png, info);
  color_type = png_get_color_type(png, info);
  bit_depth  = png_get_bit_depth(png, info);

  // Read any color_type into 8bit depth, RGBA format.
  // See http://www.libpng.org/pub/png/libpng-manual.txt

  if(bit_depth == 16)
    png_set_strip_16(png);

  //printf("color_type: %d ", color_type);
  if(color_type != PNG_COLOR_TYPE_PALETTE){
    printf("only surpport color_type: PNG_COLOR_TYPE_PALETTE \n");
    abort();
    //png_set_palette_to_rgb(png);
  }

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
  if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS)){
    printf("call png_set_tRNS_to_alpha \n");
    png_set_tRNS_to_alpha(png);
  }

  // These color_type don't have an alpha channel then fill it with 0xff.
  if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE){
    //png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
    //printf("call png_set_filler\n");
  }
  if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
  for(int y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }
  png_read_image(png, row_pointers);
  if(1!=png_get_rowbytes(png,info)/width){
    printf("Error: depth of pixel is %d bytes. only surpport 1 byte depth pixel. \n", png_get_rowbytes(png,info)/width);
    abort();
  }

  cv::Mat img = cv::Mat( height, width, CV_8U);
  for(int y = 0; y < height; y++) {
      memcpy(img.data+y*width, row_pointers[y], width);
      //printf("call %d,", *(img.data+y*width+width/2));
      free(row_pointers[y]);
  }
  free(row_pointers);
  fclose(fp);
  return img;
}




int main( int argc, char** argv )
{

  cv::Mat image;
  image = cv::imread( argv[1], 1 );
  cv::Mat a = readPng(argv[1]);
  cv::imshow("xx", image);
  cv::imshow("a", a);
  cv::imwrite("a.png", a);
  cv::waitKey(0);
  return 0;
}
