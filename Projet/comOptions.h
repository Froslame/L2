#ifndef COMOPTIONS_H
#define COMOPTIONS_H

#include <string>
#include "tabOptions.h"

tabOptions listOptions(int argc,char** argv);
void LoadOptions(tabOptions opts,int argc,char** argv);

#endif
