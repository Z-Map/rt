#include "rt_ui_display.h"
#include "mathex/vector.h"

int     add_rgb_in_img(mglimg *img, unsigned int index, t_v4i color)
{
        if (index + 3 >= img->memlen)
                return (0);
        img->pixels[index] = color.x;
        img->pixels[index + 1] = color.y;
        img->pixels[index + 2] = color.z;
        img->pixels[index + 3] = color.w;
        return (1);
}
