#pragma once

#ifndef MACROS2_H
#define MACROS2_H

#include <iostream>

#define IS_EVEN(x) ((int)(x) % 2 == 0)
#define IS_POSITIVE(x) ((x) > 0)

#define INFO(msg) std::cout << "[INFO] " << msg << std::endl

#endif
