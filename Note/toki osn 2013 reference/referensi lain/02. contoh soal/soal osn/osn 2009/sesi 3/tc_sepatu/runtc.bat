@echo off
if "%1" == "" goto showusage
if not exist %1 goto notfound
goto runtc

:showusage
echo Usage: RUNTC [exe]
goto end

:runtc
if exist sepatu1.in type sepatu1.in | %1 > sepatu1.out
if exist sepatu2.in type sepatu2.in | %1 > sepatu2.out
if exist sepatu3.in type sepatu3.in | %1 > sepatu3.out
if exist sepatu4.in type sepatu4.in | %1 > sepatu4.out
if exist sepatu5.in type sepatu5.in | %1 > sepatu5.out
if exist sepatu6.in type sepatu6.in | %1 > sepatu6.out
if exist sepatu7.in type sepatu7.in | %1 > sepatu7.out
if exist sepatu8.in type sepatu8.in | %1 > sepatu8.out
if exist sepatu9.in type sepatu9.in | %1 > sepatu9.out
if exist sepatu10.in type sepatu10.in | %1 > sepatu10.out
if exist sepatu11.in type sepatu11.in | %1 > sepatu11.out
if exist sepatu12.in type sepatu12.in | %1 > sepatu12.out
if exist sepatu13.in type sepatu13.in | %1 > sepatu13.out
if exist sepatu14.in type sepatu14.in | %1 > sepatu14.out
if exist sepatu15.in type sepatu15.in | %1 > sepatu15.out
if exist sepatu16.in type sepatu16.in | %1 > sepatu16.out
if exist sepatu17.in type sepatu17.in | %1 > sepatu17.out
if exist sepatu18.in type sepatu18.in | %1 > sepatu18.out
if exist sepatu19.in type sepatu19.in | %1 > sepatu19.out
if exist sepatu20.in type sepatu20.in | %1 > sepatu20.out
goto end

:notfound
echo Cannot find %1
goto end
 
:end
@echo on