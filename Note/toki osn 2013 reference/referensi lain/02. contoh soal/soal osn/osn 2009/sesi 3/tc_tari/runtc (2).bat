@echo off
if "%1" == "" goto showusage
if not exist %1 goto notfound
goto runtc

:showusage
echo Usage: RUNTC [exe]
goto end

:runtc
type tari1.in | %1 > tari1.out
type tari2.in | %1 > tari2.out
type tari3.in | %1 > tari3.out
type tari4.in | %1 > tari4.out
type tari5.in | %1 > tari5.out
type tari6.in | %1 > tari6.out
type tari7.in | %1 > tari7.out
type tari8.in | %1 > tari8.out
type tari9.in | %1 > tari9.out
type tari10.in | %1 > tari10.out
type tari11.in | %1 > tari11.out
type tari12.in | %1 > tari12.out
type tari13.in | %1 > tari13.out
type tari14.in | %1 > tari14.out
type tari15.in | %1 > tari15.out
type tari16.in | %1 > tari16.out
type tari17.in | %1 > tari17.out
type tari18.in | %1 > tari18.out
type tari19.in | %1 > tari19.out
type tari20.in | %1 > tari20.out
goto end

:notfound
echo Cannot find %1
goto end
 
:end
@echo on