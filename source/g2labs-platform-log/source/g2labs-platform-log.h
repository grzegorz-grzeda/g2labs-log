/*
 * MIT License
 *
 * Copyright (c) 2023 Grzegorz Grzęda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef G2LABS_PLATFORM_LOG_H
#define G2LABS_PLATFORM_LOG_H

#include <stdarg.h>

typedef enum {
    G2LABS_PLATFORM_LOG_LEVEL_DEBUG,
    G2LABS_PLATFORM_LOG_LEVEL_INFO,
    G2LABS_PLATFORM_LOG_LEVEL_WARNING,
    G2LABS_PLATFORM_LOG_LEVEL_ERROR,
    _G2LABS_PLATFORM_LOG_LEVEL_COUNT,
} platform_log_level_t;

void platform_log_set_minimal_log_level(platform_log_level_t minimal_log_level);

void platform_log(platform_log_level_t level,
                  const char* name,
                  const char* format,
                  va_list args);

#endif  // G2LABS_PLATFORM_LOG_H