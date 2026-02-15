#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <tnl.h>
#include "sigc++/trackable.h"
#include "status.h"
#include <interfaces/IGame.h>
#include <modules/texman/TextureManager.h>

struct IFontMan;

class LoadingScreen : public sigc::trackable
{
public:
    LoadingScreen(IGame *, const std::string & bgtex_name);
    void update(Status *);
private:
    IGame *thegame;
    float last_status;
    TexPtr background;
    Ptr<IFontMan> fontman;
};

#endif
