#include <cstdlib>

enum AdapterProperty
{
     WHITE = 0,
     BLACK,
     YELLOW,
};

int GetProperty(AdapterProperty property, size_t *buffer_size, void *buffer)
{
    return WHITE;
}

template<class T>
int GetProperty(AdapterProperty property, (sizeof(T)) T *buffer)
{
    size_t value = sizeof(T);

    return GetProperty(property, &value, (void *)buffer);
}

int main(int argc, char *argv)
{
    char *data = malloc(100);

    GetProperty<char>(WHITE, data);

    return 0;
}
