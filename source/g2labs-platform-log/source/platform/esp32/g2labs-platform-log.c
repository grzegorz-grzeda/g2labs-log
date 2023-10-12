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
#include <esp_log.h>

static platform_log_level_t global_log_level = G2LABS_PLATFORM_LOG_LEVEL_INFO;

void platform_log_set_minimal_log_level(
    platform_log_level_t minimal_log_level) {
    global_log_level = minimal_log_level;
}

void platform_log(platform_log_level_t level,
                  const char* name,
                  const char* format,
                  va_list args) {
    if (level < global_log_level) {
        return;
    }
    esp_log_level_t esp_level;
    switch (level) {
        case G2LABS_PLATFORM_LOG_LEVEL_DEBUG:
            esp_level = ESP_LOG_DEBUG;
            esp_log_write(esp_level, name,
                          LOG_COLOR_D "D (%lu) %s: ", esp_log_timestamp(),
                          name);
            break;
        case G2LABS_PLATFORM_LOG_LEVEL_INFO:
            esp_level = ESP_LOG_INFO;
            esp_log_write(esp_level, name,
                          LOG_COLOR_I "I (%lu) %s: ", esp_log_timestamp(),
                          name);
            break;
        case G2LABS_PLATFORM_LOG_LEVEL_WARNING:
            esp_level = ESP_LOG_WARN;
            esp_log_write(esp_level, name,
                          LOG_COLOR_W "W (%lu) %s: ", esp_log_timestamp(),
                          name);
            break;
        case G2LABS_PLATFORM_LOG_LEVEL_ERROR:
            esp_level = ESP_LOG_ERROR;
            esp_log_write(esp_level, name,
                          LOG_COLOR_E "E (%lu) %s: ", esp_log_timestamp(),
                          name);
            break;
        default:
            return;
    }
    esp_log_writev(esp_level, name, format, args);
    esp_log_write(esp_level, name, LOG_RESET_COLOR "\n");
}