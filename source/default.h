#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef HEADER_H
#define HEADER_H

#define i8 int8_t
// int8 - 1Byte
#define i16 int16_t
// int16 - 2Byte
#define i32 int32_t
// int32 - 4Byte
#define i64 int64_t
// int64 - 8Byte

#define u8 uint8_t
// u_int8
#define u16 uint16_t
// u_int16
#define u32 uint32_t
// u_int32
#define u64 uint64_t
// u_int64

#define f32 float
// f32 - 4Byte

#define f64 double
// f64 - 8Byte

#define WIDTH_TILEMAP 18
#define HEIGHT_TILEMAP 32

#define SPRITE_RES 16

#define WIDTH_SCREEN 1280
#define HEIGHT_SCREEN 720

#endif


// ----- VECTOR INT 2 -----
/*
typedef struct s_i64_vector {
	i64 _v1;
	i64 _v2;
} i64_vector;

typedef struct s_i32_vector {
	i32 _v1;
	i32 _v2;
} i32_vector;

typedef struct s_i16_vector {
	i16 _v1;
	i16 _v2;
} i16_vector;

typedef struct s_i8_vector {
	i8 _v1;
	i8 _v2;
} i8_vector;

// ----- VECTOR INT 3 -----
typedef struct s_i64_vector3 {
	i64 _v1;
	i64 _v2;
	i64 _v3;
} i64_vector3;

typedef struct s_i32_vector3 {
	i32 _v1;
	i32 _v2;
	i32 _v3;
} i32_vector3;

typedef struct s_i16_vector3 {
	i16 _v1;
	i16 _v2;
	i16 _v3;
} i16_vector3;

typedef struct s_i8_vector3 {
	i8 _v1;
	i8 _v2;
	i8 _v3;
} i8_vector3;

// ----- VECTOR FLOAT 2 -----
typedef struct s_f64_vector {
	f64 _v1;
	f64 _v2;
} f64_vector;

typedef struct s_f32_vector {
	f32 _v1;
	f32 _v2;
} f32_vector;

// ----- VECTOR FLOAT 3 -----
typedef struct s_f64_vector3 {
	f64 _v1;
	f64 _v2;
	f64 _v3;
} f64_vector3;

typedef struct s_f32_vector3 {
	f32 _v1;
	f32 _v2;
	f32 _v3;
} f32_vector3;
*/