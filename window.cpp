#include "window.h"
#include <Windows.h>

int Window::width = 25;
int Window::height = 25;

void Window::Init()
{
	// コンソールのハンドル取得
	/*
	 * STD_INPUT_HANDLE  標準入力ハンドル
	 * STD_OUTPUT_HANDLE 標準出力ハンドル
	 * STD_ERROR_HANDLE  標準エラーハンドル
	*/
	// 失敗すると、INVALID_HANDLE_VALUE が返る。
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);	// DWORD nStdHandle

	// コンソールウィンドウのサイズ

	// まずはバッファ
	// 文字数単位での幅と高さ
	COORD dwSize = { 9999, 9999 };
	SetConsoleScreenBufferSize(
		hConsoleOutput, // HANDLE hConsoleOutput
		dwSize);        // COORD dwSize

	// 次にウィンドウサイズ
	// 内部バッファや画面からはみ出てしまうサイズを設定すると、戻り値は FALSE となり設定は失敗するので、チェックが必要である。
	SMALL_RECT consoleWindow = { 0, 0, 60, 30 };
	SetConsoleWindowInfo(
		hConsoleOutput, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow
}
