@ECHO OFF

ECHO Generating to Visual Studio Project...

IF NOT EXIST Build MKDIR Build

CD Build
CMAKE -DCMAKE_GENERATOR_PLATFORM=x64 ../
CD..

PAUSE