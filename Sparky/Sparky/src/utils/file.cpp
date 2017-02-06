#include "file.h"

namespace cphong {

    std::string read_file(const char* filePath)
    {
        FILE* file = fopen(filePath, "rt");
        if (!file)
        {
            fprintf(stderr, "Could not open file");
            return NULL;
        }

        fseek(file, 0, SEEK_END);
        unsigned long length = ftell(file);
        fseek(file, 0, SEEK_SET);

        char* data = new char[length + 1];
        memset(data, 0, length + 1);
        fread(data, 1, length, file);

        fclose(file);

        std::string result(data);
        delete[] data;
        return result;
    }

}