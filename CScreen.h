/*
 * (c) 
 * GNU GPL
 *
 */

#ifndef __CSCREEN_H__
#define __CSCREEN_H__

#include <windows.h>

 /*
 ����� ���������� ��� ������ CScreen
 */

class CSScreenException {
public:
    CSScreenException(int _err) : err(_err) {}
    const char* what();         // ���������� ������ � ��������� ������
    int err;                    // ��� ������
};

/*
����� CScreen �������� ���������������� ������ ��� ������ �� �������.

������ ���������� ������������� ��� �� MS Windows 2000 Professional
� ����� �������.

������� ���������:
    (0, 0)  - ����� ������� ���� ������
    ��� X   - ������������� ������
    ��� Y   - ����������� ���� (������������� �����������)
*/

class CScreen {
public:
    CScreen();
    ~CScreen();
    void cursor_show(bool visible);                 // ��������/������ ������
    void text_attr(WORD attr);                      // ���������� ���� ������/����
    void pos(int x, int y, char ch = 0);            // ���������������� ������� �
    // ����� �������, ���� ch != 0
    void pos_str(int x, int y, const char* str);    // ���������������� �������
    // � ����� ������
    void cls();                                     // ������� ������

private:
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO oldCursorInfo, curCursorInfo;
    WORD oldTextAttr;
};

#endif // __CSCREEN_H__
