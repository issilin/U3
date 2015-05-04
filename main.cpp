#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
    FILE* f;
    FILE* out = fopen(argv[1], "w");
    int buf;
    long count=0;
    char gzipCommand[256]="gzip -c -d ";
    strncat(gzipCommand, argv[2], 200);
    f = popen(gzipCommand, "r");
    while (!feof(f))
    {
        buf = fgetc(f);
        if (buf == 0)
        {
            count++;
        }
        else
        {
            fseek(out, count, SEEK_CUR);
            fputc(buf, out);
            count=0;
        }
    }
    fseek(out, count, SEEK_CUR);
    fclose(f);
    fclose(out);
    return 0;
}