typedef struct {
    // User defined data may be declared here.
    int mutex_1, mutex_2;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    obj->mutex_1 = 1;
    obj->mutex_2 = 2;
    return obj;
}

void first(Foo* obj) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->mutex_1 = 0;
}

void second(Foo* obj) {
    while (obj->mutex_1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->mutex_2 = 0;
}

void third(Foo* obj) {
    while (obj->mutex_2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}