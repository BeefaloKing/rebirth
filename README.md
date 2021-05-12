# Rebirth
Currently nothing. Maybe one day it'll be something.

## Building
Download and install [MSYS2](https://www.msys2.org/).  
Ensure packages are up to date and install build tools.
```
pacman -Syu
pacman -S git make rsync
```
Install the 32 or 64 bit toolchain and build dependencies.
```
pacman -S mingw-w64-i686-toolchain \
	mingw-w64-i686-SDL2

pacman -S mingw-w64-x86_64-toolchain \
	mingw-w64-x86_64-SDL2
```
Launch `MSYS2 MinGW 32-bit` or `MSYS2 MinGW 64-bit` to start MSYS2 with the appropriate subsystem.  
From the project root, run `make`. Binaries will be located in `./bin/<Architecture>/<BuildType>/`.
```
make
```
`make` and `make all` default to the `debug` target.  
Possible make targets include:  
- `debug` performs a debug build.
- `release` performs a release build.
- `clean` deletes all build files.
- `build` allows for a custom user specified build.
