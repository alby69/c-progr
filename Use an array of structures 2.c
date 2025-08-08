// Use an array of structures 2
#include <stdio.h>

struct point {
    int x;
    int y;
};

void printPoint(struct point pt);
void readPoint(struct point *ptr);
void readPolygon(struct point *ptr, int nr);
void printPolygon(struct point *ptr, int nr);

int main(void) {
    int nr;
    
    printf("How many points does the polygon have? ");
    
    // Input validation
    if (scanf("%d", &nr) != 1 || nr <= 0) {
        printf("Error: Please enter a valid positive number.\n");
        return 1;
    }
    
    // Variable length array
    struct point polygon[nr];
    
    printf("\nEntering %d points for the polygon:\n", nr);
    readPolygon(polygon, nr);
    
    printf("\nYour polygon points are:\n");
    printPolygon(polygon, nr);
    
    return 0;
}

void readPoint(struct point *ptr) {
    printf("  x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("  y-coordinate: ");
    scanf("%d", &ptr->y);
}

void readPolygon(struct point *ptr, int nr) {
    for (int i = 0; i < nr; i++) {
        printf("Point %d of %d:\n", i + 1, nr);
        readPoint(&ptr[i]);
    }
}

void printPolygon(struct point *ptr, int nr) {
    for (int i = 0; i < nr; i++) {
        printf("Point %d: ", i + 1);
        printPoint(ptr[i]);
    }
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}
