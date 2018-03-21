@ECHO off
SETLOCAL enabledelayedexpansion
cls
COLOR 1f

ECHO.
ECHO.  
ECHO   ##############################################################
ECHO   #               欢迎使用 TeamTalk 工程配置向导               #
ECHO   #                   version 1.0                              #
ECHO   ##############################################################
ECHO.
ECHO.

rem 拷贝PB协议文件
echo make IM protocol buffer files...
cd %~dp0
mkdir %~dp0..\..\include\ProtocolBuffer
xcopy %~dp0..\..\..\pb\*.proto %~dp0\proto\*.proto
echo Copy IM protocol buffer files finished
rem 生成PB协议的C++版本
protoc.exe --proto_path=%~dp0proto\ --cpp_out=%~dp0..\..\include\ProtocolBuffer %~dp0proto\*.proto
echo make the pb files of c++ version has finished.
pause