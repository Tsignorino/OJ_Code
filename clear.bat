@echo off
setlocal enabledelayedexpansion

REM 设置文件夹路径数组，使用分号分隔不同的路径
set "folders=D:\Code\OJ_Code\.cph;D:\Code\OJ_Code\build"

REM 遍历文件夹路径数组
for %%i in (%folders%) do (
    REM 检查文件夹是否存在
    if exist "%%i\" (
        pushd "%%i"
        del /q *
        popd
    ) else (
        echo The specified path %%i does not exist.
    )
)

REM 结束批处理文件，恢复环境变量
endlocal