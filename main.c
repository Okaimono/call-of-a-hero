#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;

typedef struct {
    u8* base;
    u64 size;
    u64 offset;
} mem_arena;

typedef struct {
    u32 rows, cols;
    f32* data;
} matrix;

typedef struct {
    matrix* W0;
    matrix* b0;
    matrix* W1;
    matrix* b1;
} mini_column;

typedef struct {
    mini_column* macro_columnW1;
    mini_column* macro_columnW2;

    matrix* W0;
    matrix* b0;
    matrix* W1;
    matrix* b1;
} macro_column;

mem_arena arena_create(u64 size);
void arena_destroy(mem_arena* arena);
void* arena_push(mem_arena* arena, u64 size);

matrix* mat_create(mem_arena* arena, u32 rows, u32 cols);
void mat_mul(matrix* out, const matrix* A, const matrix* B);
void mat_add(matrix* out, const matrix* A, const matrix* B);
void mat_fill_xavier(matrix* out);
void mat_relu(matrix* out, const matrix* A);
void mat_softmax(matrix* out, const matrix* A);
void mat_transpose(matrix* out, const matrix* A);

macro_column* mc_create(mem_arena* arena);

int main(void) {
    mem_arena arena = arena_create(MiB(512));
    macro_column* mc = mc_create(arena);

    return 0;
}

mem_arena arena_create(u64 size) {
    mem_arena arena;
    arena.base = malloc(size);
    arena.size = size;
    arena.offset = 0;
    return arena;
}

void arena_destroy(mem_arena* arena) {
    free(arena->base);
}

void* arena_push(mem_arena* arena, u64 size) {
    void* ptr = arena->base + arena->offset;
    arena->offset += size;
    return ptr;
}

matrix* mat_create(mem_arena* arena, u32 rows, u32 cols) {
    matrix* mat = arena_push(arena, sizeof(matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = arena_push(arena, rows * cols * sizeof(f32));
    return mat;
}

void mat_mul(matrix* out, const matrix* A, const matrix* B) {
    for (u32 i = 0; i < A->rows * B->cols; i++) out->data[i] = 0.0f;

    for (u32 i = 0; i < A->rows; i++) {
        for (u32 j = 0; j < B->cols; j++) {
            for (u32 k = 0; k < A->cols; k++) {
                out->data[i * out->cols + j] +=
                    A->data[i * A->cols + k] *
                    B->data[k * B->cols + j];
            } 
        }
    }
}

void mat_add(matrix* out, const matrix* A, const matrix* B) {
    for (u32 i = 0; i < B->rows * B->cols; i++) {
        out->data[i] = A->data[i] + B->data[i];
    }
}

void mat_fill_xavier(matrix* out) {
    f32 fan_in  = out->cols;
    f32 fan_out = out->rows;
    f32 bound = sqrtf(6.0f / (fan_in + fan_out));
    u64 size = (u64)out->rows * out->cols;
    for (u64 i = 0; i < size; i++) {
        f32 r = (f32)rand() / (f32)RAND_MAX;
        out->data[i] = r * bound * 2 - bound;
    }
}

void mat_fill_zero(matrix* out) {
    memset(out->data, 0, out->rows * out->cols * sizeof(f32));
}

void mat_relu(matrix* out, const matrix* A) {
    for (u32 i = 0; i < A->rows * A->cols; i++) {
        out->data[i] = A->data[i] > 0 ? A->data[i] : 0;
    }
}

void mat_softmax(matrix* out, const matrix* A) {
    f32 sum = 0;
    for (u32 i = 0; i < A->rows * A->cols; i++) {
        sum += expf(A->data[i]);
    }

    for (u32 i = 0; i < A->rows; i++) {
        out->data[i] = expf(A->data[i]) / sum;
    }
}

void mat_transpose(matrix* out, const matrix* A) {
    for (u32 i = 0; i < A->rows; i++) {
        for (u32 j = 0; j < A->cols; j++) {
            out->data[j * out->cols + i] = A->data[i * A->cols + j];
        }
    }
}

macro_column* macro_col_create(mem_arena* arena) {
    macro_column* macro = arena_push(arena, sizeof(macro_column));
    macro->macro_column

    mc->W0 = matrix_create(arena, )
}

mini_column* mini_col_create(mem_arena* arena) {
    mini_column* mini_col = arena_push(arena, sizeof(mini_column));

    mini_col->W0 = mat_create(arena, 20, 784);
    mini_col->b0 = mat_create(arena, 20, 1);
    mini_col->W1 = mat_create(arena, 1, 20);
    mini_col->b1 = mat_create(arena, 1, 1);

    mat_fill_xavier(mini_col->W0);
    mat_fill_zero(mini_col->b0);
    mat_fill_xavier(mini_col->W1);
    mat_fill_zero(mini_col->b1);

    return mini_col;
}