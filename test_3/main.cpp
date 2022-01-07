#include <iostream>
#include <stdio.h>

#include "log.h"
using namespace std;

#undef CLASSNAME
#define CLASSNAME     "MAIN"

/****************************************************************
 * level:ALWAYS, ERROR, WAR, INFO, DETAIL
 * default level: ERROR, 默认情况下，只打印ALWAYS, ERROR
 * 
 * SET_LOG_LEVEL(level) :这个函数用来手动设置level:
 * 例如:
 * SET_LOG_LEVEL(ALWAYS), 可以打印ALWAYS
 * SET_LOG_LEVEL(ERROR), 可以打印ALWAYS, ERROR
 * SET_LOG_LEVEL(WAR), 可以打印ALWAYS, ERROR, WAR
 * SET_LOG_LEVEL(INFO), 可以打印ALWAYS, ERROR, WAR, INFO
 * SET_LOG_LEVEL(DETAIL), 可以打印ALWAYS, ERROR, WAR, INFO, DETAIL
 * 
 * log打印函数:
 * LOG_PRINTF(level, fmt, ...)
 * 示例:
 * LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
 * LOG_PRINTF(ERROR, "test level error, %d.", 1);
 * LOG_PRINTF(WAR, "test level warring, %d.", 2);
 * LOG_PRINTF(INFO, "test level info, %d.", 3);
 * LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
 * 
 * 打印的信息:
 * [    3877.34964384  ] [ALWAYS] MAIN: main.cpp:73:testLevel_Detail():  test level always, 0.
 * [    3877.34965914  ] [ ERROR] MAIN: main.cpp:74:testLevel_Detail():  test level error, 1.
 * [    3877.34967412  ] [   WAR] MAIN: main.cpp:75:testLevel_Detail():  test level warring, 2.
 * [    3877.34968886  ] [  INFO] MAIN: main.cpp:76:testLevel_Detail():  test level info, 3.
 * [    3877.34970402  ] [DETAIL] MAIN: main.cpp:77:testLevel_Detail():  test level detail, 4.
 * 
 * 说明: [s.ns] [level] CLASSNAME: filename:line:fun(): txt
 * 1.打印时间为系统启动开始计算，到当前程序运行时间, 可使用clock_gettime 获取
 * 2.秒:占8位，右对齐; 纳秒:占10位，左对齐
 * 3.level: 占6位，右对齐
 * 4.CLASSNAME:单当前文件未定义时显示 "unknown", 如果有定义，则显示定义的内容.
 * 
 * 
 ****************************************************************/
void testLevel_Default()
{
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}

void testLevel_Always()
{
    SET_LOG_LEVEL(ALWAYS);
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}

void testLevel_Error()
{
    SET_LOG_LEVEL(ERROR);
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}

void testLevel_War()
{
    SET_LOG_LEVEL(WAR);
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}

void testLevel_Info()
{
    SET_LOG_LEVEL(INFO);
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}

void testLevel_Detail()
{
    SET_LOG_LEVEL(DETAIL);
    LOG_PRINTF(ALWAYS, "test level always, %d.", 0);
    LOG_PRINTF(ERROR, "test level error, %d.", 1);
    LOG_PRINTF(WAR, "test level warring, %d.", 2);
    LOG_PRINTF(INFO, "test level info, %d.", 3);
    LOG_PRINTF(DETAIL, "test level detail, %d.", 4);
}


int main(int argc, char const *argv[])
{
    testLevel_Default();
    printf("*******************************************\n");
    testLevel_Always();
    printf("*******************************************\n");
    testLevel_Error();
    printf("*******************************************\n");
    testLevel_War();
    printf("*******************************************\n");
    testLevel_Info();
    printf("*******************************************\n");
    testLevel_Detail();

    //输出:
    /* 
    [    4612.179002136 ] [ALWAYS] MAIN: main.cpp:48:testLevel_Default():  test level always, 0.
    [    4612.179046231 ] [ ERROR] MAIN: main.cpp:49:testLevel_Default():  test level error, 1.
    *******************************************
    [    4612.179051260 ] [ALWAYS] MAIN: main.cpp:58:testLevel_Always():  test level always, 0.
    *******************************************
    [    4612.179054040 ] [ALWAYS] MAIN: main.cpp:68:testLevel_Error():  test level always, 0.
    [    4612.179055654 ] [ ERROR] MAIN: main.cpp:69:testLevel_Error():  test level error, 1.
    *******************************************
    [    4612.179058307 ] [ALWAYS] MAIN: main.cpp:78:testLevel_War():  test level always, 0.
    [    4612.179059812 ] [ ERROR] MAIN: main.cpp:79:testLevel_War():  test level error, 1.
    [    4612.179061559 ] [   WAR] MAIN: main.cpp:80:testLevel_War():  test level warring, 2.
    *******************************************
    [    4612.179077669 ] [ALWAYS] MAIN: main.cpp:88:testLevel_Info():  test level always, 0.
    [    4612.179080246 ] [ ERROR] MAIN: main.cpp:89:testLevel_Info():  test level error, 1.
    [    4612.179081824 ] [   WAR] MAIN: main.cpp:90:testLevel_Info():  test level warring, 2.
    [    4612.179083330 ] [  INFO] MAIN: main.cpp:91:testLevel_Info():  test level info, 3.
    *******************************************
    [    4612.179085858 ] [ALWAYS] MAIN: main.cpp:98:testLevel_Detail():  test level always, 0.
    [    4612.179087366 ] [ ERROR] MAIN: main.cpp:99:testLevel_Detail():  test level error, 1.
    [    4612.179088969 ] [   WAR] MAIN: main.cpp:100:testLevel_Detail():  test level warring, 2.
    [    4612.179090552 ] [  INFO] MAIN: main.cpp:101:testLevel_Detail():  test level info, 3.
    [    4612.179092135 ] [DETAIL] MAIN: main.cpp:102:testLevel_Detail():  test level detail, 4. 
    */
    return 0;
}
