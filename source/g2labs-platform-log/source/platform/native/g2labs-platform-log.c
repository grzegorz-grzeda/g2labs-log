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
#include "g2labs-platform-log.h"
#include <stdio.h>

static platform_log_level_t global_minimal_log_level =
    G2LABS_PLATFORM_LOG_LEVEL_INFO;

static const char* get_string_for_level(platform_log_level_t level) {
    static const char* levels_to_strings[] = {
        "DEBG",
        "INFO",
        "WARN",
        "ERRO",
    };

    if (level > _G2LABS_PLATFORM_LOG_LEVEL_COUNT) {
        return "";
    } else {
        return levels_to_strings[level];
    }
}

static const char* get_console_color_vt100_reset_escape_string(void) {
    return "\033[0m";
}

static const char* get_console_color_vt100_escape_string(
    platform_log_level_t level) {
    static const char* escape_codes[] = {
        "\033[0m",
        "\033[32m",
        "\033[33m",
        "\033[31m",
    };

    if (level > _G2LABS_PLATFORM_LOG_LEVEL_COUNT) {
        return get_console_color_vt100_reset_escape_string();
    } else {
        return escape_codes[level];
    }
}

void platform_log_set_minimal_log_level(
    platform_log_level_t minimal_log_level) {
    global_minimal_log_level = minimal_log_level;
}

void platform_log(platform_log_level_t level,
                  const char* name,
                  const char* format,
                  va_list args) {
    if (level < global_minimal_log_level) {
        return;
    }

    printf("%s[%s] {%s} ", get_console_color_vt100_escape_string(level),
           get_string_for_level(level), name);
    vprintf(format, args);
    printf("%s\n", get_console_color_vt100_reset_escape_string());
}