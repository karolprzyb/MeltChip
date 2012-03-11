//Defines for determining which code is compiled
#define LOGGING_CHIP8
#define DEBUG_INSTRUCT_LOGGING

#include "registers.h"
#include "cpu.h"
#include "display.h"
#include "stack.h"
#include "randGen.h"
#include "FileIO.h"
#include "memory.h"
#include "timer.h"
#include "render.h"
#include "controls.h"

#ifdef LOGGING_CHIP8
#include "log.h"
#endif

#include <time.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <string.h>
#include <sstream>

//Constants defined
#define logPath "/accounts/1000/shared/misc/logs/CHIP8/main.log"

