/** Encodes a URL to a shortened URL. */
char *encode(char *longUrl)
{
    int len = strlen(longUrl);
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * (len + 1));

    int i;
    for (i = 0; i < len; i++) {
        if (longUrl[i] >= 'A' && longUrl[i] <= 'Z') {
            ret[i] = tolower(longUrl[i]);
        } else if (longUrl[i] >= 'a' && longUrl[i] <= 'z') {
            ret[i] = toupper(longUrl[i]);
        } else {
            ret[i] = longUrl[i];
        }
    }

    return ret;
}

/** Decodes a shortened URL to its original URL. */
char *decode(char *shortUrl)
{
    int len = strlen(shortUrl);
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * (len + 1));

    int i;
    for (i = 0; i < len; i++) {
        if (shortUrl[i] >= 'A' && shortUrl[i] <= 'Z') {
            ret[i] = tolower(shortUrl[i]);
        } else if (shortUrl[i] >= 'a' && shortUrl[i] <= 'z') {
            ret[i] = toupper(shortUrl[i]);
        } else {
            ret[i] = shortUrl[i];
        }
    }

    return ret; 
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);

/********************骚一点，啥也不干************************/
char* encode(char* longUrl) {
    return longUrl;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    return shortUrl;
}