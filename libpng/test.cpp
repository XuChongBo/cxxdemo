unsigned paletteSize = ...;

assert(paletteSize <= PNG_MAX_PALETTE_LENGTH);

png_color* palette = (png_color*)png_malloc(png_ptr, paletteSize*sizeof(png_color));

for (unsigned p = 0; p < paletteSize; p++)
{
      png_color* col = &palette[p];
        col->red = ...;
          col->green = ...;
            col->blue = ...;
}

png_set_PLTE(png_ptr, info_ptr, palette, paletteSize);

png_write_info(png_ptr, info_ptr);

// ... png_write_image, png_write_end

png_destroy_write_struct(&png_ptr, &info_ptr);

png_free(png_ptr, palette);
