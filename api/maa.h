/*
 * Author: Brendan Le Foll
 *
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

/** @file
 *
 * This file defines the basic shared values for libmaa
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * MAA return codes
 */
typedef enum {
    MAA_SUCCESS                              =  0, /**< Expected response */
    MAA_ERROR_FEATURE_NOT_IMPLEMENTED        =  1, /**< Feature TODO */
    MAA_ERROR_FEATURE_NOT_SUPPORTED          =  2, /**< Feature not supported by HW */
    MAA_ERROR_INVALID_VERBOSITY_LEVEL        =  3, /**< Verbosity level wrong */
    MAA_ERROR_INVALID_PARAMETER              =  4, /**< Parameter invalid */
    MAA_ERROR_INVALID_HANDLE                 =  5, /**< Handle invalid */
    MAA_ERROR_NO_RESOURCES                   =  6, /**< No resource of that type avail */
    MAA_ERROR_INVALID_RESOURCE               =  7, /**< Resource invalid */
    MAA_ERROR_INVALID_QUEUE_TYPE             =  8, /**< Queue type incorrect */
    MAA_ERROR_NO_DATA_AVAILABLE              =  9, /**< No data available */
    MAA_ERROR_INVALID_PLATFORM               = 10, /**< Platform not recognised */
    MAA_ERROR_PLATFORM_NOT_INITIALISED       = 11, /**< Board information not initialised */

    MAA_ERROR_UNSPECIFIED                    = 99 /**< Unknown Error */
} maa_result_t;

typedef unsigned int maa_boolean_t;

typedef struct {
        maa_boolean_t valid:1;
        maa_boolean_t gpio:1;
        maa_boolean_t pwm:1;
        maa_boolean_t fast_gpio:1;
        maa_boolean_t spi:1;
        maa_boolean_t i2c:1;
    }
     maa_pincapabilities_t;

typedef struct {
    unsigned int pin;
    unsigned int value;
} maa_mux_t;

typedef struct {
    char name[8];// do we need this
    unsigned int pin;
    int parent_id;
    maa_pincapabilities_t capabilites;
    maa_mux_t mux[4];
    unsigned int mux_total;
} maa_pininfo_t;

typedef struct {
    unsigned int gpio_count;
    unsigned int aio_count;
    unsigned int pwm_count;
    maa_pininfo_t* pins;
} maa_board_t;

unsigned int maa_check_gpio(int pin);
//unsigned int maa_check_aio(int pin);
//unsigned int maa_check_pwm(int pin);

/** Get the version string of maa autogenerated from git tag
 *
 * The version returned may not be what is expected however it is a reliable
 * number associated with the git tag closest to that version at build time
 * @return version string from version.h
 */
const char* maa_get_version();

#ifdef __cplusplus
}
#endif
