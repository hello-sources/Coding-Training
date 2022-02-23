#define CAT 0
#define DOG 1
#define MAX_ANI 20000
typedef struct {
    int front;
    int rear;
    int count;
    int animalNum[MAX_ANI];
}AnimalQueue;
typedef struct {
    AnimalQueue animalQueue[2];
} AnimalShelf;

AnimalShelf* animalShelfCreate() {
    return (AnimalShelf *)calloc(1, sizeof(AnimalShelf));
}

void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize) {
    if (obj->animalQueue[CAT].count + obj->animalQueue[DOG].count < MAX_ANI) {
        AnimalQueue *aq = &obj->animalQueue[animal[1]];
        aq->animalNum[aq->rear] = animal[0];
        aq->rear = (aq->rear + 1) % MAX_ANI;
        aq->count++;
    }
}

int *initRet(int *retSize) {
    int *ret = (int *)calloc(2, sizeof(int));
    *retSize = 2;
    ret[0] = -1;
    ret[1] = -1;
    return ret;
}

void setRet(AnimalShelf* obj, int type, int *ret) {
    AnimalQueue *aq = &obj->animalQueue[type];
    if (aq->count > 0) {
        ret[0] = aq->animalNum[aq->front];
        ret[1] = type;
        aq->front = (aq->front + 1) % MAX_ANI;
        aq->count--;
    }
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize) {
    int *ret = initRet(retSize);
    AnimalQueue *cat = &obj->animalQueue[CAT];
    AnimalQueue *dog = &obj->animalQueue[DOG];
    if (cat->count > 0 && dog->count > 0) {
        if (cat->animalNum[cat->front] < dog->animalNum[dog->front]) {
            setRet(obj, CAT, ret);
        } else {
            setRet(obj, DOG, ret);
        }
    } else if (cat->count > 0) {
        setRet(obj, CAT, ret);
    } else if (dog->count > 0) {
        setRet(obj, DOG, ret);
    }
    return ret;
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize) {
    int *ret = initRet(retSize);
    setRet(obj, DOG, ret);
    return ret;
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize) {
    int *ret = initRet(retSize);
    setRet(obj, CAT, ret);
    return ret;
}

void animalShelfFree(AnimalShelf* obj) {
    free(obj);
}
/**
 * Your AnimalShelf struct will be instantiated and called as such:
 * AnimalShelf* obj = animalShelfCreate();
 * animalShelfEnqueue(obj, animal, animalSize);

 * int* param_2 = animalShelfDequeueAny(obj, retSize);

 * int* param_3 = animalShelfDequeueDog(obj, retSize);

 * int* param_4 = animalShelfDequeueCat(obj, retSize);

 * animalShelfFree(obj);
*/