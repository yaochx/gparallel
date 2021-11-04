#pragma once


#define ERROR(...)                                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
        fprintf(stderr, "[ERROR]%s %s(Line %d): ", __FILE__, __FUNCTION__, __LINE__);                                  \
        fprintf(stderr, __VA_ARGS__);                                                                                  \
        fprintf(stderr, "\n");                                                                                         \
    } while (0)

#define WARN(...)                                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        fprintf(stdout, "[WARN ]%s %s(Line %d): ", __FILE__, __FUNCTION__, __LINE__);                                  \
        fprintf(stdout, __VA_ARGS__);                                                                                  \
        fprintf(stdout, "\n");                                                                                         \
    } while (0)

#define DEBUG(...)                                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
        fprintf(stdout, "[INFO ]%s %s(Line %d): ", __FILE__, __FUNCTION__, __LINE__);                                  \
        fprintf(stdout, __VA_ARGS__);                                                                                  \
        fprintf(stdout, "\n");                                                                                         \
    } while (0)

#define INFO(...)                                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        fprintf(stdout, "[INFO ]%s %s(Line %d): ", __FILE__, __FUNCTION__, __LINE__);                                  \
        fprintf(stdout, __VA_ARGS__);                                                                                  \
        fprintf(stdout, "\n");                                                                                         \
    } while (0)
