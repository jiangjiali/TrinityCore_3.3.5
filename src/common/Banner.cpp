#include "Banner.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
    log(Trinity::StringFormat("[%s]", applicationName).c_str());
    log("<Ctrl-C> to stop.\n");

    if (logExtraInfo)
        logExtraInfo();
}
