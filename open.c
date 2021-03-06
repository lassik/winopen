#define _UNICODE
#define UNICODE

#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGNAME L"open"

#define COUNTOF(x) (sizeof(x) / sizeof(x[0]))

static void diesys(const wchar_t *msg)
{
    static wchar_t errbuf[128];

    FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        0, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        errbuf, COUNTOF(errbuf), 0);
    errbuf[COUNTOF(errbuf)-1] = 0;
    // There's no newline in the format string because WinAPI error
    // messages end in a newline.
    fwprintf(stderr, L"%s: %s: %s", PROGNAME, msg, errbuf);
    exit(1);
}

static void usage(int exitcode, FILE *stream)
{
    fwprintf(stream, L"usage: " PROGNAME L" filename\n");
    exit(exitcode);
}

static void open(const wchar_t *filename)
{
    static SHELLEXECUTEINFOW sei;

    memset(&sei, 0, sizeof(sei));
    sei.cbSize = sizeof(sei);
    sei.lpFile = filename;
    sei.nShow = SW_SHOW;
    if (!ShellExecuteExW(&sei))
        diesys(L"cannot open file");
}

extern int wmain(int argc, wchar_t **argv)
{
    if (argc != 2)
        usage(1, stderr);
    if (!wcscmp(argv[1], L"-h") || !wcscmp(argv[1], L"--help"))
        usage(0, stdout);
    if ((argv[1][0] == '-') || (argv[1][0] == '/'))
        usage(1, stderr);
    open(argv[1]);
    return 0;
}
