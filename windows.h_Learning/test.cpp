#include<windows.h>

const char g_szClassname[]="myWindowClass";

// Step 4: the window procedure

LRESULT CALLBACK WNDPROC( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){

    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd,msg,wparam,lparam);
        break;
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine,
 int nCmdShow){
    
    WNDCLASSEXW wc;
    HWND hwnd;
    MSG Msg;

    // Step 1: Registering the Window Class

    wc.cbSize       =sizeof(WNDCLASSEX);
    wc.style        =0;
    wc.lpfnWndProc  =WNDPROC;
    wc.cbClsExtra   =0;
    wc.cbWndExtra   =0;
    wc.hInstance    =hInstance;
    wc.hIcon        =LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor      =LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName =NULL;
    wc.lpszClassName=(LPCWSTR)g_szClassname;
    wc.hIconSm      =LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)){

        MessageBoxA(NULL,"Window Registration Failed! ",
        "Error! ",MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the window

    hwnd= CreateWindowEx(
        WS_EX_CLIENTEDGE,
        (LPCWSTR)g_szClassname,
        (LPCWSTR)"My First Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,CW_USEDEFAULT,240,120,
        NULL,NULL,hInstance,NULL
    );

    if( hwnd == NULL){
        MessageBoxA(NULL,"Window Creation Failed!","Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd,nCmdShow);
    UpdateWindow(hwnd);


    // Step3: The Message Loop

    while (GetMessage(&Msg,NULL,0,0)>0)
    {
        /* code */
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
    }
    

    return Msg.wParam;


 }    