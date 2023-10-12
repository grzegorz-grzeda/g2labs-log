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
#ifndef G2LABS_LOG_H
#define G2LABS_LOG_H

#include <stdarg.h>

// There has to be a LOG_MODULE_NAME for each source file
// #define G2LABS_LOG_MODULE_NAME "application"

// There has to be a G2LABS_LOG_MODULE_LEVEL defined. If not, the ERROR is used

#define G2LABS_LOG_MODULE_LEVEL_DEBUG (0)
#define G2LABS_LOG_MODULE_LEVEL_INFO (1)
#define G2LABS_LOG_MODULE_LEVEL_WARNING (2)
#define G2LABS_LOG_MODULE_LEVEL_ERROR (3)

#ifndef G2LABS_LOG_MODULE_NAME
#error "No g2labs-log module name was defined!"
#endif

#if defined(G2LABS_LOG_MODULE_LEVEL) && \
    (G2LABS_LOG_MODULE_LEVEL <= G2LABS_LOG_MODULE_LEVEL_DEBUG)
#define D(x, args...) \
    _log(G2LABS_LOG_MODULE_NAME, G2LABS_LOG_MODULE_LEVEL_DEBUG, x, ##args)
#else
#define D(x, args...)
#endif

#if defined(G2LABS_LOG_MODULE_LEVEL) && \
    (G2LABS_LOG_MODULE_LEVEL <= G2LABS_LOG_MODULE_LEVEL_INFO)
#define I(x, args...) \
    _log(G2LABS_LOG_MODULE_NAME, G2LABS_LOG_MODULE_LEVEL_INFO, x, ##args)
#else
#define I(x, args...)
#endif

#if defined(G2LABS_LOG_MODULE_LEVEL) && \
    (G2LABS_LOG_MODULE_LEVEL <= G2LABS_LOG_MODULE_LEVEL_WARNING)
#define W(x, args...) \
    _log(LOG_MODULE_NAME, G2LABS_LOG_MODULE_LEVEL_WARNING, x, ##args)
#else
#define W(x, args...)
#endif

#if defined(G2LABS_LOG_MODULE_LEVEL) && \
    (G2LABS_LOG_MODULE_LEVEL <= G2LABS_LOG_MODULE_LEVEL_ERROR)
#define E(x, args...) \
    _log(G2LABS_LOG_MODULE_NAME, G2LABS_LOG_MODULE_LEVEL_ERROR, x, ##args)
#else
#define E(x, args...)
#endif

void _log(const char* module_name, int level, const char* message, ...);

void _log_v(const char* module_name,
            int level,
            const char* message,
            va_list list_of_arguments);

#endif  // G2LABS_LOG_H