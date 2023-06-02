// Copyright 2023 <Seres67>

#pragma once

#ifndef MYSTD_PUBLIC
    #if defined _WIN32 || defined __CYGWIN__
        #define MYSTD_PUBLIC __declspec(dllimport)
    #else
        #define MYSTD_PUBLIC
    #endif
#endif
