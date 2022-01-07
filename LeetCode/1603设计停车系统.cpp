typedef struct {
    int big, mid, small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *obj = (ParkingSystem *)malloc(sizeof(ParkingSystem));
    obj->small = small;
    obj->big = big;
    obj->mid = medium;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (carType == 1) {
        if (obj->big > 0) {
            obj->big--;
            return true;
        }
    } else if (carType == 2) {
        if (obj->mid > 0) {
            obj->mid--;
            return true;
        }
    } else if (carType == 3) {
        if (obj->small > 0) {
            obj->small--;
            return true;
        }
    }
    return false;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
    return ;
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/