#include "Banner.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text))
{
    log(Trinity::StringFormat("[%s]", applicationName).c_str());
    log("<Ctrl-C> to stop.\n");
}
