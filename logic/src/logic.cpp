#include "engine.h"
#include "data.h"
#include "subs.h"
#include "cmdparse.h"
#include "publishcmdhandle.h"
#include "timelinecmdhandle.h"
#include "followcmdhandle.h"
#include "wallcmdhandle.h"

#include "logic.h"

Logic::Logic() :
    data( new Data() )
    , subs( new Subs() )
    , cmdparse( new CmdParse() )
    , pubcmdh( new PublishCmdHandle( data, subs ) )
    , tlcmdh( new TimelineCmdHandle( data, subs ) )
    , flwcmdh( new FollowCmdHandle( data, subs ) )
    , wcmdh( new WallCmdHandle( data, subs ) )
    , eng( new Engine(cmdparse, {pubcmdh, tlcmdh, flwcmdh, wcmdh}) )
{}

Logic::~Logic() {
    delete eng;
    delete tlcmdh;
    delete pubcmdh;
    delete cmdparse;
    delete data;
}

Engine * Logic::engine() const { return eng; }
