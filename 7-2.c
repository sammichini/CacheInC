// prob 7-2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
    long a;
    long r;
    long g;
    long b;
};

struct ColorPoint** create2DArray(int n) {
    // Array to hold a pointer to the beginning of each row
    struct ColorPoint **points =
            (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
    for (int i = 0; i < n; ++i) {
        // Array to hold each row
        points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
        for (int j = 0; j < n; ++j) {
            // Init the ColorPoint struct
            points[i][j].a = rand();
            points[i][j].r = rand();
            points[i][j].g = rand();
            points[i][j].b = rand();
        }
    }
    return points;
}
void free2DArray(struct ColorPoint** points, int n) {
    for (int i = 0; i < n; ++i) {
        free(points[i]);
    }
    free(points);
}


long f(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[j][i].a;
            sum += points[j][i].r;
            sum += points[j][i].g;
            sum += points[j][i].b;
        }
    }
    return sum;
}

long g(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[i][j].a;
            sum += points[i][j].r;
            sum += points[i][j].g;
            sum += points[i][j].b;
        }
    }
    return sum;
}


int main() {
    int size = 2048;
    double totalTime1;
    double totalTime2;
    struct ColorPoint ** arr = create2DArray(size);
    float fl = 0;
    float gl = 0;


        //  Timing f(arr)
    clock_t start = clock();

    for (size_t i = 0; i < 1000; ++i) {
        fl = f(arr, size);
    }


    clock_t end = clock();
    totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    // f is column major
    printf("Size: %ld\n", size);
    printf("f(arr): %f\n", totalTime1);


    // Timing g(arr):
    start = clock();

    for (size_t i = 0; i < 1000; ++i) {
        gl = g(arr, size);
    }
    end = clock();
    totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("Size: %ld\n", size);
    // g is row major
    printf("g(arr): %f\n", totalTime2);

    // g(arr) consistently runs faster
    // This is likely because more cache hits happen in g(arr), as calculated in 2.b
    // f(arr) makes column-major requests and g(arr) makes row major requests
    // memory is stored contiguously in row major order


    free2DArray(arr, size);
}