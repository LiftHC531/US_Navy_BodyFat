#include <stdio.h>
#include <math.h>

double cm2inch(double cm){
    double result;
    result = cm/2.54e0;
    return result;
}

void calculateMaleBodyFat(double height0, double neck0, double waist0, double* result) {
    *result = 86.01e0*log10(waist0-neck0)-70.041e0*log10(height0)+36.76e0;
    return;
}

void calculateFemaleBodyFat(double height0, double neck0, double waist0, double hip0, double* result) {
    *result = 163.205e0*log10(waist0+hip0-neck0)-97.684e0*log10(height0)-78.387e0;
    return;
}
