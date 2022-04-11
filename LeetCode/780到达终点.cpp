bool reachingPoints(int sx, int sy, int tx, int ty){
    while (tx > sx && ty > sy && tx != ty) {
        if (ty > tx) {
            ty %= tx;
        } else {
            tx %= ty;
        }
    }
    if (tx == sx && ty == sy) return true;
    else if (tx == sx) {
        return ty > sy && (ty - sy) % tx == 0;
    } else if (ty == sy) {
        return tx > sx && (tx - sx) % ty == 0;
    }
    return false;
}