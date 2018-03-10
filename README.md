# XORStreamer
XOR Encoder with experimental streaming support

## Build
`CFLAGS="-O3" make`

## Usage
`./XORStreamer [-b buffer size] [-k XORKey] [-o output file] [input file(s) ...]`

if `XORKey` is empty, it uses the default key `23333333`

if `output file` and/or `input file(s)` are not specified, `XORStreamer` will work on stdin/stdout.
