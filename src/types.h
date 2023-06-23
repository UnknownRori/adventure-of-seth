/**
 * @file types.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Custom type of every my project
 * @version 0.1
 * @date 2023-06-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_TYPES_H
#define UNKNOWNRORI_TYPES_H

#if defined(__cplusplus)
#include <cstdint>
#else // __cplusplus
#include <stdint.h>
#endif // __cplusplus

typedef float f32;
typedef double f64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef __int128_t i128;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;
typedef size_t usize;
typedef ssize_t isize;

#if defined(__cplusplus) == 0
#define nullptr NULL
#endif // __cplusplus

#endif // UNKNOWNRORI_TYPES_H