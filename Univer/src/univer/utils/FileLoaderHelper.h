// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// FileLoaderHelper.h                                                        //
// ========================================================================= //

#ifndef FILE_LOADER_HELPER_H
#define FILE_LOADER_HELPER_H

#ifdef __cplusplus
extern "C" {
namespace univer
{
#endif

typedef struct binary_data_t binary_data_t;
struct binary_data_t
{
    long size;
    void* data;
};
binary_data_t* read_file( const char* filename );

#ifdef __cplusplus
}
}
#endif

#endif // FILE_LOADER_HELPER_H

/* USAGE:

//Testing a non-zero sized file
//read_file() will return a binary_data_t where size will be non zero
binary_data_t* binary_data_non_zero = read_file( argv[0] );
//Testing for a non-existing file
//read_file() will return a NULL pointer
binary_data_t* binary_data_not_existing = read_file( "some file that does not exist..." );
const char* filename = "/tmp/some_empty_file";
//Creating an empty file
FILE* fout = fopen( filename, "w" );
fclose( fout );
//Testing for an empty file
//read_file() will return a binary_data_t where size will be zero
binary_data_t* binary_data_empty = read_file( filename );
*/