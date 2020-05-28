
@echo off

echo ==================== ADDING FILES ====================
echo.
git add --all --verbose

echo.
echo ==================== COMMITTING ====================
echo.

set /p message=" > Enter commit message: "
git commit -m ^"%message%^"

echo.
echo ==================== PUSHING CHANGES ====================
echo.
git push -u origin master

echo.
pause