#include "superman.h"

superman::superman()
{
    setPixmap(QPixmap(":/imagenes/Super (1).png"));
    px=-178;
    py=200;
    vy=0;
    //vx=1;

}

superman::~superman()
{


}

void superman::advance(int phase){
    {
        if (phase){
              vy--;


            }
                py=vy+200;
                //px=vx+1;
            }
            setPos(px,py);
        }
