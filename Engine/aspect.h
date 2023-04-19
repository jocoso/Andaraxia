#ifndef ASPECT_H
#define ASPECT_H

#include <string>

class Aspect {
    private:
        std::string type;
    protected:
        virtual void run();
};

#endif // ASPECT_H