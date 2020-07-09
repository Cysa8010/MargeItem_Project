#include "window.h"
#include <Windows.h>

int Window::width = 25;
int Window::height = 25;

void Window::Init()
{
	// �R���\�[���̃n���h���擾
	/*
	 * STD_INPUT_HANDLE  �W�����̓n���h��
	 * STD_OUTPUT_HANDLE �W���o�̓n���h��
	 * STD_ERROR_HANDLE  �W���G���[�n���h��
	*/
	// ���s����ƁAINVALID_HANDLE_VALUE ���Ԃ�B
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);	// DWORD nStdHandle

	// �R���\�[���E�B���h�E�̃T�C�Y

	// �܂��̓o�b�t�@
	// �������P�ʂł̕��ƍ���
	COORD dwSize = { 9999, 9999 };
	SetConsoleScreenBufferSize(
		hConsoleOutput, // HANDLE hConsoleOutput
		dwSize);        // COORD dwSize

	// ���ɃE�B���h�E�T�C�Y
	// �����o�b�t�@���ʂ���͂ݏo�Ă��܂��T�C�Y��ݒ肷��ƁA�߂�l�� FALSE �ƂȂ�ݒ�͎��s����̂ŁA�`�F�b�N���K�v�ł���B
	SMALL_RECT consoleWindow = { 0, 0, 60, 30 };
	SetConsoleWindowInfo(
		hConsoleOutput, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow
}
