#include <iostream>

struct ivector3d {
    int array[3];
};

struct ivector3d_ {
    int *array;
};

void scale(ivector3d *v, int k) {
    for (int i = 0; i != 3; ++i)
        v->array[i] *= k;
}

void scale(ivector3d v, int k) {
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
}

void scale(ivector3d_ v, int k) {
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
}

int main(int argc, const char * argv[]) {
    struct ivector3d iv3d;
    
    // test 1
    iv3d.array[0] = iv3d.array[1] = iv3d.array[2] = 1;
    scale(&iv3d, 2);
    printf("%d %d %d\n", iv3d.array[0], iv3d.array[1], iv3d.array[2]);
    
    // test 2
    iv3d.array[0] = iv3d.array[1] = iv3d.array[2] = 1;
    scale(iv3d, 2);
    printf("%d %d %d\n", iv3d.array[0], iv3d.array[1], iv3d.array[2]);

    // test 3
    struct ivector3d_ iv3d_;
    iv3d_.array = new int[3];
    iv3d_.array[0] = iv3d_.array[1] = iv3d_.array[2] = 1;
    scale(iv3d_, 2);
    printf("%d %d %d\n", iv3d_.array[0], iv3d_.array[1], iv3d_.array[2]);
    delete[] iv3d_.array;
    
    return 0;
}
