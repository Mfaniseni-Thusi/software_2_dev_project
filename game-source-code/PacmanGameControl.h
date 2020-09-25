#ifndef PACMANGAMECONTROL_H
#define PACMANGAMECONTROL_H

#include "Grid.h"

class PacmanGameControl
{
    public:
        PacmanGameControl(/*Grid& grid_*/);

        void run();

        ~PacmanGameControl();

    private:
        Grid grid_;
};

#endif // PACMANGAMECONTROL_H
