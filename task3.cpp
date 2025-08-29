#include <stdio.h>
int main() {
    float a, b, c;
    float discriminant, realPart, imaginaryPart, root1, root2;

    printf("=== Quadratic Equation Solver ===\n");
    printf("Equation format: ax^2 + bx + c = 0\n\n");

    printf("Enter coefficient a: ");
    scanf("%f", &a);

    printf("Enter coefficient b: ");
    scanf("%f", &b);

    printf("Enter coefficient c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("\nThis is not a quadratic equation (a = 0).\n");
        return 0;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float sqrt_d = discriminant;
        float temp = 1;

        while (temp * temp <= sqrt_d) {
            temp += 0.0001;
        }
        temp -= 0.0001;

        root1 = (-b + temp) / (2 * a);
        root2 = (-b - temp) / (2 * a);

        printf("\nThe equation has two distinct real roots:\n");
        printf("Root 1 = %.4f\n", root1);
        printf("Root 2 = %.4f\n", root2);

    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("\nThe equation has one real repeated root:\n");
        printf("Root = %.4f\n", root1);

    } else {
        float sqrt_d = -discriminant;
        float temp = 1;

        while (temp * temp <= sqrt_d) {
            temp += 0.0001;
        }
        temp -= 0.0001;

        realPart = -b / (2 * a);
        imaginaryPart = temp / (2 * a);

        printf("\nThe equation has imaginary roots:\n");
        printf("Root 1 = %.4f + %.4fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.4f - %.4fi\n", realPart, imaginaryPart);
    }

    printf("\n=== Program Finished ===\n");
    return 0;
}

