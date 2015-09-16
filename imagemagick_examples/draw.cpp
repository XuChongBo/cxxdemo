#include <Magick++.h> 
#include <iostream> 
using namespace std; 
using namespace Magick; 
int main(int argc,char **argv) 
{ 
  // #include <Magick++.h>
  // Image *img = new Image(str);
  // X=img->columns();
  // Y=img->rows();

  //InitializeMagick(*argv);

    try {
        InitializeMagick(*argv);

        //create a base image
        Image image("400x100","white");

        //construct a drawing list
        std::list<Magick::Drawable> drawList;


        drawList.push_back(DrawableStrokeWidth(1)); 
        drawList.push_back(DrawablePointSize(20));
        // set the text font: the font is specified via a string representing 
        // a fully qualified X font name (wildcards '*' are allowed).   identify -list font | more.  get the Font Name
        //drawList.push_back(DrawableFont("WenQuanYi-Zen-Hei-Mono-Regular"));
        drawList.push_back(DrawableFont("WenQuanYi-Zen-Hei-Regular"));
       // drawList.push_back(DrawableStrokeColor(police_color)); 
        drawList.push_back(DrawableStrokeColor("black")); // Outline Color   //Color("black")
        // set the text to be drawn at specified position: x=101, y=50 this case
        drawList.push_back(DrawableText(10,70,"你好"));
        drawList.push_back(DrawableText(100,70,"dist ∞  α Σ  ∈  □  √  ance"));

        image.draw(drawList);
        image.write("draw.jpg");
    }
    catch(exception & error_)
    {
        cout<<"Caught exception : " << error_.what() << endl;
    }


}

