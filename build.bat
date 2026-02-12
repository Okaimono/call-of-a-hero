@echo off
setlocal enabledelayedexpansion

if not exist bin mkdir bin

del bin\game.exe 2>nul

set SOURCES=
for /r src %%f in (*.cpp) do set SOURCES=!SOURCES! "%%f"
for /r src %%f in (*.c)   do set SOURCES=!SOURCES! "%%f"

set IMGUI=
for %%f in (
    ..\External\include\imgui\imgui.cpp
    ..\External\include\imgui\imgui_draw.cpp
    ..\External\include\imgui\imgui_tables.cpp
    ..\External\include\imgui\imgui_widgets.cpp
    ..\External\include\imgui\imgui_impl_glfw.cpp
    ..\External\include\imgui\imgui_impl_opengl3.cpp
) do set IMGUI=!IMGUI! "%%f"

g++ -std=c++17 ^
  %SOURCES% ^
  %IMGUI% ^
  -I..\External\include ^
  -I..\External\include\imgui ^
  -IHeaderFiles ^
  -Isrc ^
  -L..\External\lib -lglfw3 -lopengl32 -lgdi32 ^
  -o bin\game.exe

if %errorlevel% equ 0 (
    cls
    echo Build successful!
    bin\game.exe
) else (
    echo Build failed!
)