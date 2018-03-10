# XORStreamer
XOR Encoder with experimental streaming support

## Build
`CFLAGS="-O3" make`

## Usage
`./XORStreamer [-b BufferSize] [-k XORKey] [-o OutputFile]`

if `XORKey` is empty, it uses the default key `23333333`
