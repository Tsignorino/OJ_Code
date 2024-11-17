@echo off
setlocal enabledelayedexpansion

REM 设置文件夹路径数组，使用分号分隔不同的路径
set "folders=D:\Code\OJ_Code\.cph;D:\Code\OJ_Code\build"
for %%i in (%folders%) do (
    if exist "%%i\" (
        pushd "%%i"
        del /q *
        popd
        echo The specified path %%i has been cleared.
    ) else (
        echo The specified path %%i does not exist.
    )
)

REM 为 Python 导入的包排序
echo Python files' packages have been sorted.
isort .

endlocal