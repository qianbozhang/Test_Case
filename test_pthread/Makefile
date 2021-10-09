C = gcc
G = g++
CFLAGS = -Wall -O -g

#工程里的文件夹
CURPATH = $(shell pwd)
SRCDIRS = $(CURPATH)/

#要生成的程序
TARGET = task

#搜索每个文件夹里的cpp文件
SRCS=$(foreach dir,$(SRCDIRS),$(wildcard $(dir)*.cpp))

#每个cpp文件所对应的.o文件
#OBJS = $(patsubst %.cpp, %.o, $(SRCS))等价下面这句。
OBJS = $(SRCS:%.cpp=%.o)

#需要的动态库
LIBS := -lpthread

all:$(OBJS)
	$(G) $(CFLAGS) -o $(TARGET)  $(OBJS) $(LIBS)

#make show 命令会输出OBJS中的所有值
show:
	@echo $(OBJS)

.PHONY : clean
clean:
	-rm  $(TARGET) $(OBJS)